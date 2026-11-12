#include "CAN_Properties.h"
#include <string.h>

GroupData_t g_groups[NUM_GROUPS];

// Handles for massages

static ubyte2 handle_rx   = 0xFFFFU; /* CAN0 - read the configs and values */
static ubyte2 handle_tx0  = 0xFFFFU; /* CAN0 transmit FB */
static ubyte2 handle_tx1  = 0xFFFFU; /* CAN1 transmit DIAG */

// Queue for transmit massages

static ubyte1 tx_turn = 0U;

// Function for generate ID's for massages

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

// Function writing defaults values in some fields settings massages

void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id)
{
    if (frame == NULL)
    {
        return;
    }

    frame->id = id;
    frame->id_format = IO_CAN_EXT_FRAME;
    frame->length = 8U;
    memset(frame->data, 0, 8);
}

// Function unpacking massages with congigs and values

void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd)
{
    ubyte1 pin_idx;
    if ((can_data == NULL) || (cmd == NULL))
    {
        return;
    }

    for (pin_idx = 0U; pin_idx < 4U; pin_idx++) {
        ubyte1 offset = pin_idx * 2U;
        cmd->config[pin_idx] = can_data[offset] & 0x07U;
        cmd->value[pin_idx]  = can_data[offset + 1U];
    }
}

// Function packing massages for feedbacks from pins

void Pack_FB(const FB_Values *fb, ubyte1 *can_data)
{
    ubyte1 pin_idx;
    if ((fb == NULL) || (can_data == NULL))
    {
        return;
    }

    for (pin_idx = 0U; pin_idx < 4U; pin_idx++) {
        ubyte1 offset = pin_idx * 2U;
        can_data[offset]      = (ubyte1)(fb->val[pin_idx] & 0xFFU);
        can_data[offset + 1U] = (ubyte1)((fb->val[pin_idx] >> 8U) & 0xFFU);
    }
}

// Function packing massages for diags from pins

void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data)
{
    ubyte1 pin_idx;
    if ((diag == NULL) || (can_data == NULL))    {
        return;
    }

    for (pin_idx = 0U; pin_idx < 4U; pin_idx++) {
        ubyte1 offset = pin_idx * 2U;
        can_data[offset]      = (ubyte1)(diag->val[pin_idx] & 0xFFU);
        can_data[offset + 1U] = (ubyte1)((diag->val[pin_idx] >> 8U) & 0xFFU);
    }
}

// Function settings CAN frame for group

IO_ErrorType Init_CAN_Group(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS) {
        return IO_E_INVALID_PARAMETER;
    }

    Generate_Group_IDs(group_idx,
                       &g_groups[group_idx].can.frame_CMD.id,
                       &g_groups[group_idx].can.frame_FB.id,
                       &g_groups[group_idx].can.frame_DIAG.id);

    Init_CAN_Frame_Defaults(&g_groups[group_idx].can.frame_CMD, g_groups[group_idx].can.frame_CMD.id);
    Init_CAN_Frame_Defaults(&g_groups[group_idx].can.frame_FB, g_groups[group_idx].can.frame_FB.id);
    Init_CAN_Frame_Defaults(&g_groups[group_idx].can.frame_DIAG, g_groups[group_idx].can.frame_DIAG.id);

    return IO_E_OK;
}

// Function Init CAN for all groups

IO_ErrorType Init_CAN_System_All(void)
{
    IO_ErrorType err;
    ubyte1 i;

    memset(g_groups, 0, sizeof(g_groups));

    // 1. Initialize CAN 0 and CAN 1 channels (250 kbit/s)
    err = IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    if (err != IO_E_OK) return err;

    err = IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    if (err != IO_E_OK) return err;

    // 2. Configures a message object for the CAN0 channel (read msg).

    err = IO_CAN_ConfigMsg(&handle_rx, IO_CAN_CHANNEL_0,
                           IO_CAN_MSG_READ, IO_CAN_EXT_FRAME,
                           CAN_CMD_BASE_ID, CAN_CMD_ACCEPTANCE_MASK);
    if (err != IO_E_OK) return err;

    // 3. Configures a message object for the CAN0 channel (transmit FB msg).

    err = IO_CAN_ConfigMsg(&handle_tx0, IO_CAN_CHANNEL_0,
                           IO_CAN_MSG_WRITE, IO_CAN_EXT_FRAME,
                           CAN_FB_BASE_ID, 0U);
    if (err != IO_E_OK) return err;

    // 4. Configures a message object for the CAN1 channel (transmit DIAG msg).

    err = IO_CAN_ConfigMsg(&handle_tx1, IO_CAN_CHANNEL_1,
                           IO_CAN_MSG_WRITE, IO_CAN_EXT_FRAME,
                           CAN_DIAG_BASE_ID, 0U);
    if (err != IO_E_OK) return err;

    // 5. Setting all structs frames msgs

    for (i = 0U; i < NUM_GROUPS; i++) {
        err = Init_CAN_Group(i);
        if (err != IO_E_OK) return err;
    }

    return IO_E_OK;
}

// Functions - getters and setters

ubyte1 Get_Pin_Config(const CMD_Values *cmd, ubyte1 pin_idx)
{
    if ((cmd != NULL) && (pin_idx < 4U)) {
        return cmd->config[pin_idx];
    }
    return 0U;
}

ubyte1 Get_Pin_Value(const CMD_Values *cmd, ubyte1 pin_idx)
{
    if ((cmd != NULL) && (pin_idx < 4U)) {
        return cmd->value[pin_idx];
    }
    return 0U;
}

void Set_Pin_FB(FB_Values *fb, ubyte1 pin_idx, ubyte2 value)
{
    if ((fb != NULL) && (pin_idx < 4U)) {
        fb->val[pin_idx] = value;
    }
}

void Set_Pin_DIAG(DIAG_Values *diag, ubyte1 pin_idx, ubyte2 value)
{
    if ((diag != NULL) && (pin_idx < 4U)) {
        diag->val[pin_idx] = value;
    }
}

// Read massages methods

void Process_CAN_RX(ubyte1 group_idx)
{
    IO_CAN_DATA_FRAME rx_frame;

    if (group_idx >= NUM_GROUPS) return;

    // Read the accumulated messages

    while (IO_CAN_MsgStatus(handle_rx) == IO_E_OK) {
        if (IO_CAN_ReadMsg(handle_rx, &rx_frame) == IO_E_OK) {
            if (rx_frame.length == 8U) {

                // Extract the group number from the ID (bits 8-15)

                ubyte1 rx_grp = (ubyte1)((rx_frame.id >> 8U) & 0xFFU);
                if (rx_grp < NUM_GROUPS) {
                    Unpack_CMD(rx_frame.data, &g_groups[rx_grp].current_cmd);
                }
            }
        } else {
            break;
        }
    }
}

// Write massages methods

void Process_CAN_TX(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS) return;

    // We send a group message only when its turn comes

    if (group_idx == tx_turn) {

        /* FB in the CAN0 */

        if (IO_CAN_MsgStatus(handle_tx0) == IO_E_OK) {
            Pack_FB(&g_groups[group_idx].fb, g_groups[group_idx].can.frame_FB.data);
            (void)IO_CAN_WriteMsg(handle_tx0, &g_groups[group_idx].can.frame_FB);
        }

        /* DIAG in the CAN1 */

        if (IO_CAN_MsgStatus(handle_tx1) == IO_E_OK) {
            Pack_DIAG(&g_groups[group_idx].diag, g_groups[group_idx].can.frame_DIAG.data);
            (void)IO_CAN_WriteMsg(handle_tx1, &g_groups[group_idx].can.frame_DIAG);
        }
    }

    // When transmit the last msg shift queue in next step process

    if (group_idx == (NUM_GROUPS - 1U)) {
        tx_turn++;
        if (tx_turn >= NUM_GROUPS) {
            tx_turn = 0U;
        }
    }
}

// Function update CMD values

void Update_Old_CMD_Values(ubyte1 group_idx)
{
    ubyte1 i;
    if (group_idx >= NUM_GROUPS) return;

    for (i = 0U; i < 4U; i++) {
        g_groups[group_idx].old_cmd.config[i] = g_groups[group_idx].current_cmd.config[i];
        g_groups[group_idx].old_cmd.value[i]  = g_groups[group_idx].current_cmd.value[i];
    }
}

// Function compare configs

bool Compare_Confs(ubyte1 group_idx, ubyte1 pin_idx)
{
    if ((group_idx >= NUM_GROUPS) || (pin_idx >= 4U)) return FALSE;

    return (g_groups[group_idx].current_cmd.config[pin_idx] !=
            g_groups[group_idx].old_cmd.config[pin_idx]);
}

// Function compare values

bool Compare_Values(ubyte1 group_idx, ubyte1 pin_idx)
{
    if ((group_idx >= NUM_GROUPS) || (pin_idx >= 4U)) return FALSE;

    return (g_groups[group_idx].current_cmd.value[pin_idx] !=
            g_groups[group_idx].old_cmd.value[pin_idx]);
}
