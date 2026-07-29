#include "CAN_Properties.h"
#include <stdbool.h>

// Generate ID with bits mask

void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB,
                               ubyte4 *ptr_DIAG)
{
    ubyte4 base_cmd = 0x18FF00FAU;
    ubyte4 base_fb = 0x18FF0027U;
    ubyte4 base_diag = 0x18FF0027U;
    ubyte4 mask = 0x0000FF00U; // Bits 8-15

    *ptr_CMD = (base_cmd & ~mask) | ((ubyte4) index << 8);
    *ptr_FB = (base_fb & ~mask) | ((ubyte4) (index * 2) << 8);
    *ptr_DIAG = (base_diag & ~mask) | ((ubyte4) ((index * 2) + 1) << 8);
}

// Settings messages by default

void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id)
{
    frame->id = id;
    frame->id_format = IO_CAN_EXT_FRAME;
    frame->length = 8U;
}

// Functions for pack and unpack massages

void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd)
{
    cmd->config_Pin0 = can_data[0] & 0x07U;
    cmd->value_Pin0 = can_data[1];
    cmd->config_Pin1 = can_data[2] & 0x07U;
    cmd->value_Pin1 = can_data[3];
    cmd->config_Pin2 = can_data[4] & 0x07U;
    cmd->value_Pin2 = can_data[5];
    cmd->config_Pin3 = can_data[6] & 0x07U;
    cmd->value_Pin3 = can_data[7];
}

void Pack_FB(const FB_Values *fb, ubyte1 *can_data)
{
    can_data[0] = (ubyte1) (fb->val_Pin0 & 0xFFU);
    can_data[1] = (ubyte1) ((fb->val_Pin0 >> 8) & 0xFFU);
    can_data[2] = (ubyte1) (fb->val_Pin1 & 0xFFU);
    can_data[3] = (ubyte1) ((fb->val_Pin1 >> 8) & 0xFFU);
    can_data[4] = (ubyte1) (fb->val_Pin2 & 0xFFU);
    can_data[5] = (ubyte1) ((fb->val_Pin2 >> 8) & 0xFFU);
    can_data[6] = (ubyte1) (fb->val_Pin3 & 0xFFU);
    can_data[7] = (ubyte1) ((fb->val_Pin3 >> 8) & 0xFFU);
}

void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data)
{
    can_data[0] = (ubyte1) (diag->val_Pin0 & 0xFFU);
    can_data[1] = (ubyte1) ((diag->val_Pin0 >> 8) & 0xFFU);
    can_data[2] = (ubyte1) (diag->val_Pin1 & 0xFFU);
    can_data[3] = (ubyte1) ((diag->val_Pin1 >> 8) & 0xFFU);
    can_data[4] = (ubyte1) (diag->val_Pin2 & 0xFFU);
    can_data[5] = (ubyte1) ((diag->val_Pin2 >> 8) & 0xFFU);
    can_data[6] = (ubyte1) (diag->val_Pin3 & 0xFFU);
    can_data[7] = (ubyte1) ((diag->val_Pin3 >> 8) & 0xFFU);
}

// MAY BE DELETED??7 YOU SHOULD TO SEE ERTMAIN.C AND THINKING!!!!!!!!!!

/*
 * Initialization of physical CAN channels.
 * Called ONCE at system startup.
 */
IO_ErrorType Init_CAN_Channels(void)
{
    IO_ErrorType err;

    // Channel 0: RX (CMD) + TX (FB)
    IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    if (err != IO_E_OK)
        return err;

    // Channel 1: TX (DIAG)
    IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    return err;
}

/*
 * Initialization of ONE specific group.
 * Called for each group separately.
 * @param group_idx Group index (0 .. NUM_GROUPS-1)
 */

IO_ErrorType Init_CAN_Group(ubyte1 group_idx)
{
    IO_ErrorType err;

    // Protection against array out of bounds
    if (group_idx >= NUM_GROUPS)
    {
        return IO_E_INVALID_PARAMETER;
    }

    // 1. Generate IDs for this group
    Generate_Group_IDs(group_idx, &g_groups[group_idx].can.frame_CMD.id,
                       &g_groups[group_idx].can.frame_FB.id,
                       &g_groups[group_idx].can.frame_DIAG.id);

    // 2. Fill frame templates
    Init_CAN_Frame_Defaults(&g_groups[group_idx].can.frame_CMD,
                            g_groups[group_idx].can.frame_CMD.id);
    Init_CAN_Frame_Defaults(&g_groups[group_idx].can.frame_FB,
                            g_groups[group_idx].can.frame_FB.id);
    Init_CAN_Frame_Defaults(&g_groups[group_idx].can.frame_DIAG,
                            g_groups[group_idx].can.frame_DIAG.id);

    // 3. Configure reception buffer (CMD) on Channel 0
    err = IO_CAN_ConfigMsg(&g_groups[group_idx].can.handle_CMD,
                           IO_CAN_CHANNEL_0,
                           IO_CAN_MSG_READ,
                           IO_CAN_EXT_FRAME,
                           g_groups[group_idx].can.frame_CMD.id, 0x1FFFFFFFU); // Strict mask
    if (err != IO_E_OK)
        return err;

    // 4. Configure transmission buffer (FB) on Channel 0
    err = IO_CAN_ConfigMsg(&g_groups[group_idx].can.handle_FB, IO_CAN_CHANNEL_0,
    IO_CAN_MSG_WRITE,
                           IO_CAN_EXT_FRAME,
                           g_groups[group_idx].can.frame_FB.id, 0U);
    if (err != IO_E_OK)
        return err;

    // 5. Configure transmission buffer (DIAG) on Channel 1
    err = IO_CAN_ConfigMsg(&g_groups[group_idx].can.handle_DIAG,
                           IO_CAN_CHANNEL_1,
                           IO_CAN_MSG_WRITE,
                           IO_CAN_EXT_FRAME,
                           g_groups[group_idx].can.frame_DIAG.id, 0U);

    return err;
}

/*
 * CONVENIENT WRAPPER: Initialization of the ENTIRE system at once.
 * If you don't need step-by-step initialization, just call this function.
 */
IO_ErrorType Init_CAN_System_All(void)
{
    IO_ErrorType err = Init_CAN_Channels();
    if (err != IO_E_OK)
        return err;

    ubyte1 i;

    for (i = 0; i < NUM_GROUPS; i++)
    {
        err = Init_CAN_Group(i);
        if (err != IO_E_OK)
            return err; // Break at the first error
    }
    return IO_E_OK;
}

// Read massage method

void Process_CAN_RX(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS)
        return;

    if (IO_CAN_MsgStatus(g_groups[group_idx].can.handle_CMD) == IO_E_OK)
    {
        // Read DIRECTLY into the global template (without local variables)
        if (IO_CAN_ReadMsg(g_groups[group_idx].can.handle_CMD,
                           &g_groups[group_idx].can.frame_CMD) == IO_E_OK)
        {

            if (g_groups[group_idx].can.frame_CMD.length == 8U)
            {
                Unpack_CMD(g_groups[group_idx].can.frame_CMD.data,
                           &g_groups[group_idx].current_cmd);
            }
        }
    }
}

// Write massage method

void Process_CAN_TX(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS)
        return;

    // FB (Channel 0)
    Pack_FB(&g_groups[group_idx].fb, g_groups[group_idx].can.frame_FB.data);
    IO_CAN_WriteMsg(g_groups[group_idx].can.handle_FB,
                    &g_groups[group_idx].can.frame_FB);

    // DIAG (Channel 1)
    Pack_DIAG(&g_groups[group_idx].diag,
              g_groups[group_idx].can.frame_DIAG.data);
    IO_CAN_WriteMsg(g_groups[group_idx].can.handle_DIAG,
                    &g_groups[group_idx].can.frame_DIAG);
}

/**
 * @brief Updates old configuration with new values from CAN message.
 *
 * Copies all config and value fields from cmd (new) to old_cmd
 * for the specified group.
 *
 * @param group_idx Group index (0..23)
 */

void Update_Old_CMD_Values(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS)
        return;

    // Copy all 4 config fields

    g_groups[group_idx].old_cmd.config_Pin0 =
            g_groups[group_idx].current_cmd.config_Pin0;
    g_groups[group_idx].old_cmd.config_Pin1 =
            g_groups[group_idx].current_cmd.config_Pin1;
    g_groups[group_idx].old_cmd.config_Pin2 =
            g_groups[group_idx].current_cmd.config_Pin2;
    g_groups[group_idx].old_cmd.config_Pin3 =
            g_groups[group_idx].current_cmd.config_Pin3;

    // Copy all 4 value fields

    g_groups[group_idx].old_cmd.value_Pin0 =
            g_groups[group_idx].current_cmd.value_Pin0;
    g_groups[group_idx].old_cmd.value_Pin1 =
            g_groups[group_idx].current_cmd.value_Pin1;
    g_groups[group_idx].old_cmd.value_Pin2 =
            g_groups[group_idx].current_cmd.value_Pin2;
    g_groups[group_idx].old_cmd.value_Pin3 =
            g_groups[group_idx].current_cmd.value_Pin3;
}

/**
 * @brief Compare old and current configs for this pin.
 *
 * @param group_idx index group (0..23)
 * @param pin_idx   index pin internal group (0..3)
 * @return true     if config this pin changed
 * @return false    else not changed
 */

bool Compare_Confs(ubyte1 group_idx, ubyte1 pin_idx) {

    // 1. Protection against going beyond the boundaries

    if (group_idx >= NUM_GROUPS || pin_idx >= 4) {
        return false;
    }

    // 2. Get pointers to a specific pin (0..3) in both structures.

    ubyte1* curr_cfg = &g_groups[group_idx].current_cmd.config_Pin0 + pin_idx;
    ubyte1* old_cfg  = &g_groups[group_idx].old_cmd.config_Pin0 + pin_idx;

    // 3. Compare.
    return (*curr_cfg != *old_cfg);
}
