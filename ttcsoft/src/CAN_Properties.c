#include "CAN_Properties.h"
#include <stdbool.h>

// Global array definition

GroupData_t g_groups[NUM_GROUPS];

// 1. ID Generation & Frame Defaults

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

void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id)
{
    frame->id = id;
    frame->id_format = IO_CAN_EXT_FRAME;
    frame->length = 8U;
}

// 2. Pack and Unpack Functions

void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd)
{

    ubyte1 pin_idx;

    for (pin_idx = 0U; pin_idx < 4U; pin_idx++)
    {
        ubyte1 offset = pin_idx * 2U;
        cmd->config[pin_idx] = can_data[offset] & 0x07U;
        cmd->value[pin_idx] = can_data[offset + 1U];
    }
}

void Pack_FB(const FB_Values *fb, ubyte1 *can_data)
{

    ubyte1 pin_idx;

    for (pin_idx = 0U; pin_idx < 4U; pin_idx++)
    {
        ubyte1 offset = pin_idx * 2U;
        can_data[offset] = (ubyte1) (fb->val[pin_idx] & 0xFFU);
        can_data[offset + 1U] = (ubyte1) ((fb->val[pin_idx] >> 8U) & 0xFFU);
    }
}

void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data)
{

    ubyte1 pin_idx;

    for (pin_idx = 0U; pin_idx < 4U; pin_idx++)
    {
        ubyte1 offset = pin_idx * 2U;
        can_data[offset] = (ubyte1) (diag->val[pin_idx] & 0xFFU);
        can_data[offset + 1U] = (ubyte1) ((diag->val[pin_idx] >> 8U) & 0xFFU);
    }
}

// Setters and getters (static inline to prevent multiple definition errors)

/**
 * @brief Gets the configuration of a specific pin from the CMD structure.
 */

inline ubyte1 Get_Pin_Config(const CMD_Values *cmd, ubyte1 pin_idx) {
    if (pin_idx < 4U) {
        return cmd->config[pin_idx];
    }
    return 0U;
}

/**
 * @brief Gets the value of a specific pin from the CMD structure.
 */

inline ubyte1 Get_Pin_Value(const CMD_Values *cmd, ubyte1 pin_idx) {
    if (pin_idx < 4U) {
        return cmd->value[pin_idx];
    }
    return 0U;
}

/**
 * @brief Sets the value for the feedback (FB) of a specific pin.
 */

inline void Set_Pin_FB(FB_Values *fb, ubyte1 pin_idx, ubyte2 value) {
    if (pin_idx < 4U) {
        fb->val[pin_idx] = value;
    }
}

/**
 * @brief Sets the value for the diagnostic (DIAG) of a specific pin.
 */

inline void Set_Pin_DIAG(DIAG_Values *diag, ubyte1 pin_idx, ubyte2 value) {
    if (pin_idx < 4U) {
        diag->val[pin_idx] = value;
    }
}

// 3. CAN Initialization

IO_ErrorType Init_CAN_Channels(void)
{
    ubyte2 err;

    // Channel 0: RX (CMD) + TX (FB)
    err = IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    if (err != IO_E_OK)
        return err;

    // Channel 1: TX (DIAG)
    err = IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);
    return err;
}

IO_ErrorType Init_CAN_Group(ubyte1 group_idx)
{
    ubyte2 err;

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

// 4. Read / Write Message Methods

void Process_CAN_RX(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS)
        return;

    if (IO_CAN_MsgStatus(g_groups[group_idx].can.handle_CMD) == IO_E_OK)
    {
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

// 5. Configuration Management

/**
 * @brief Updates old configuration with new values from CAN message.
 */
void Update_Old_CMD_Values(ubyte1 group_idx)
{
    if (group_idx >= NUM_GROUPS)
        return;

    ubyte1 i;

    for (i = 0; i < 4; i++)
    {
        g_groups[group_idx].old_cmd.config[i] =
                g_groups[group_idx].current_cmd.config[i];
        g_groups[group_idx].old_cmd.value[i] =
                g_groups[group_idx].current_cmd.value[i];
    }
}

/**
 * @brief Compare old and current configs for this pin.
 */
bool Compare_Confs(ubyte1 group_idx, ubyte1 pin_idx)
{
    if (group_idx >= NUM_GROUPS || pin_idx >= 4)
    {
        return FALSE;
    }

    ubyte1 curr_cfg = Get_Pin_Config(&g_groups[group_idx].current_cmd, pin_idx);
    ubyte1 old_cfg = Get_Pin_Config(&g_groups[group_idx].old_cmd, pin_idx);

    return (curr_cfg != old_cfg);
}
