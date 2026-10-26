#include "CAN_Properties.h"
#include <string.h>

/* Global structures for CAN */

GroupData_t       g_groups[NUM_GROUPS];
CAN_Debug_Stats_t g_can_stats;

/* Handles for massages */

static ubyte2 handle_cmd_rx  = 0xFFFFU;
static ubyte2 handle_can0_tx = 0xFFFFU;
static ubyte2 handle_can1_tx = 0xFFFFU;

/* Values for queue process */

static ubyte1 tx_group_index = 0U;
static ubyte2 heartbeat_tick = 0U;
static ubyte4 alive_counter  = 0U;

void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB, ubyte4 *ptr_DIAG)
{
    ubyte4 mask = 0x0000FF00U;

    if (ptr_CMD != NULL) {
        *ptr_CMD = (CAN_CMD_BASE_ID & ~mask) | ((ubyte4)index << 8);
    }
    if (ptr_FB != NULL) {
        *ptr_FB = (CAN_FB_BASE_ID & ~mask) | ((ubyte4)(index * 2U) << 8);
    }
    if (ptr_DIAG != NULL) {
        *ptr_DIAG = (CAN_DIAG_BASE_ID & ~mask) | ((ubyte4)((index * 2U) + 1U) << 8);
    }
}

void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd)
{
    ubyte1 pin_idx;
    if ((can_data == NULL) || (cmd == NULL)) {
        return;
    }

    for (pin_idx = 0U; pin_idx < PINS_PER_GROUP; pin_idx++) {
        ubyte1 offset = pin_idx * 2U;
        cmd->config[pin_idx] = can_data[offset] & 0x07U;
        cmd->value[pin_idx]  = can_data[offset + 1U];
    }
}

IO_ErrorType Init_CAN_System_All(void)
{
    IO_ErrorType err;
    ubyte1 i;

    memset(g_groups, 0, sizeof(g_groups));
    memset(&g_can_stats, 0, sizeof(g_can_stats));

    /* 1. ID's generation for 24's groups */

    for (i = 0U; i < NUM_GROUPS; i++) {
        Generate_Group_IDs(i,
                           &g_groups[i].id_CMD,
                           &g_groups[i].id_FB,
                           &g_groups[i].id_DIAG);
    }

    /* 2. Initialization of CAN0 and CAN1 at a speed of 250 kbps */

    err = IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    if (err != IO_E_OK) {
        return err;
    }

    err = IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    if (err != IO_E_OK) {
        return err;
    }

    /* 3. 1. Make handlers for CMD massages */

    err = IO_CAN_ConfigMsg(&handle_cmd_rx,
                           IO_CAN_CHANNEL_0,
                           IO_CAN_MSG_READ,
                           IO_CAN_EXT_FRAME,
                           CAN_CMD_BASE_ID,
                           CAN_CMD_ACCEPTANCE_MASK);
    if (err != IO_E_OK) {
        return err;
    }

    /* 4. 1 Make handlers for FB massages */

    err = IO_CAN_ConfigMsg(&handle_can0_tx,
                           IO_CAN_CHANNEL_0,
                           IO_CAN_MSG_WRITE,
                           IO_CAN_EXT_FRAME,
                           CAN_FB_BASE_ID,
                           0U);
    if (err != IO_E_OK) {
        return err;
    }

    /* 5. 1 Make handlers for DIAG massages */

    err = IO_CAN_ConfigMsg(&handle_can1_tx,
                           IO_CAN_CHANNEL_1,
                           IO_CAN_MSG_WRITE,
                           IO_CAN_EXT_FRAME,
                           CAN_DIAG_BASE_ID,
                           0U);
    if (err != IO_E_OK) {
        return err;
    }

    return IO_E_OK;
}

void Process_CAN_RX_All(void)
{
    IO_CAN_DATA_FRAME rx_frame;
    IO_ErrorType status;

    /* Read massage */

    status = IO_CAN_MsgStatus(handle_cmd_rx);
    while ((status == IO_E_OK) || (status == IO_E_CAN_OVERFLOW)) {
        if (IO_CAN_ReadMsg(handle_cmd_rx, &rx_frame) == IO_E_OK) {
            g_can_stats.rx_frames_count++;
            g_can_stats.last_rx_id = rx_frame.id;
            memcpy(g_can_stats.last_rx_data, rx_frame.data, 8);

            /* Compare ID */

            if ((rx_frame.id & 0x1FFF00FFU) == CAN_CMD_BASE_ID) {
                ubyte1 grp = (ubyte1)((rx_frame.id >> 8U) & 0xFFU);
                if ((grp < NUM_GROUPS) && (rx_frame.length == 8U)) {
                    Unpack_CMD(rx_frame.data, &g_groups[grp].current_cmd);
                    g_groups[grp].new_cmd_received = true;
                }
            }
        } else {
            break;
        }
        status = IO_CAN_MsgStatus(handle_cmd_rx);
    }
}

void Process_CAN_TX_Scheduler(void)
{
    IO_CAN_DATA_FRAME tx_frame;
    ubyte1 grp = tx_group_index;

    /* Read the current hardware error counters */

    IO_CAN_Status(IO_CAN_CHANNEL_0, &g_can_stats.can0_rx_err, &g_can_stats.can0_tx_err);
    IO_CAN_Status(IO_CAN_CHANNEL_1, &g_can_stats.can1_rx_err, &g_can_stats.can1_tx_err);

    /* 1. Sending a "heartbeat" signal once every 100 ms (every 10 calls) */

    heartbeat_tick++;
    if (heartbeat_tick >= 10U) {
        heartbeat_tick = 0U;
        alive_counter++;

        if (IO_CAN_MsgStatus(handle_can0_tx) == IO_E_OK) {
            tx_frame.id        = CAN_HEARTBEAT_ID;
            tx_frame.id_format = IO_CAN_EXT_FRAME;
            tx_frame.length    = 8U;

            /* Bytes 0..3: operation counter */

            tx_frame.data[0] = (ubyte1)(alive_counter & 0xFFU);
            tx_frame.data[1] = (ubyte1)((alive_counter >> 8U) & 0xFFU);
            tx_frame.data[2] = (ubyte1)((alive_counter >> 16U) & 0xFFU);
            tx_frame.data[3] = (ubyte1)((alive_counter >> 24U) & 0xFFU);

            /* Bytes 4..5: number of received packets */

            tx_frame.data[4] = (ubyte1)(g_can_stats.rx_frames_count & 0xFFU);
            tx_frame.data[5] = (ubyte1)((g_can_stats.rx_frames_count >> 8U) & 0xFFU);

            /* Байт 6, 7: ошибки передачи CAN0 и CAN1 */

            tx_frame.data[6] = g_can_stats.can0_tx_err;
            tx_frame.data[7] = g_can_stats.can1_tx_err;

            (void)IO_CAN_WriteMsg(handle_can0_tx, &tx_frame);
            g_can_stats.tx_frames_count++;
        }
    }


    /* 2. Sending the FB for the current group via CAN0               */

    if (IO_CAN_MsgStatus(handle_can0_tx) == IO_E_OK) {
        tx_frame.id        = g_groups[grp].id_FB;
        tx_frame.id_format = IO_CAN_EXT_FRAME;
        tx_frame.length    = 8U;

        /* Sending the FB for the current group via CAN0 */

        tx_frame.data[0] = grp;
        tx_frame.data[1] = (ubyte1)(alive_counter & 0xFFU);
        tx_frame.data[2] = 0xAAU;
        tx_frame.data[3] = 0x55U;
        tx_frame.data[4] = 0x00U;
        tx_frame.data[5] = 0x00U;
        tx_frame.data[6] = 0x00U;
        tx_frame.data[7] = 0x00U;

        (void)IO_CAN_WriteMsg(handle_can0_tx, &tx_frame);
        g_can_stats.tx_frames_count++;
    }


    /* 3. Sending DIAG for the current group via CAN1                  */

    if (IO_CAN_MsgStatus(handle_can1_tx) == IO_E_OK) {
        tx_frame.id        = g_groups[grp].id_DIAG;
        tx_frame.id_format = IO_CAN_EXT_FRAME;
        tx_frame.length    = 8U;

        /* Test data for diagnostics */

        tx_frame.data[0] = grp;
        tx_frame.data[1] = (ubyte1)(alive_counter & 0xFFU);
        tx_frame.data[2] = 0x00U;
        tx_frame.data[3] = 0x00U;
        tx_frame.data[4] = 0x00U;
        tx_frame.data[5] = 0x00U;
        tx_frame.data[6] = 0x00U;
        tx_frame.data[7] = 0x00U;

        (void)IO_CAN_WriteMsg(handle_can1_tx, &tx_frame);
        g_can_stats.tx_frames_count++;
    }

    /* Move to the next group (Round-Robin) */

    tx_group_index++;
    if (tx_group_index >= NUM_GROUPS) {
        tx_group_index = 0U;
    }
}
