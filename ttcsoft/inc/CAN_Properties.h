#ifndef CAN_Properties_h_
#define CAN_Properties_h_

#include "IO_Driver.h"
#include "IO_CAN.h"

#include <stdbool.h>

// 1. Constant

#define NUM_GROUPS 24U  // 24 groups

// 2. Data structures

typedef struct
{
    ubyte1 config_Pin0;
    ubyte1 value_Pin0;
    ubyte1 config_Pin1;
    ubyte1 value_Pin1;
    ubyte1 config_Pin2;
    ubyte1 value_Pin2;
    ubyte1 config_Pin3;
    ubyte1 value_Pin3;
} CMD_Values;

typedef struct
{
    ubyte2 val_Pin0;
    ubyte2 val_Pin1;
    ubyte2 val_Pin2;
    ubyte2 val_Pin3;
} FB_Values;

typedef struct
{
    ubyte2 val_Pin0;
    ubyte2 val_Pin1;
    ubyte2 val_Pin2;
    ubyte2 val_Pin3;
} DIAG_Values;

typedef struct
{
    ubyte2 handle_CMD;
    ubyte2 handle_FB;
    ubyte2 handle_DIAG;

    IO_CAN_DATA_FRAME frame_CMD;
    IO_CAN_DATA_FRAME frame_FB;
    IO_CAN_DATA_FRAME frame_DIAG;
} CAN_Msg_Props;

typedef struct
{
    CAN_Msg_Props can;
    CMD_Values old_cmd;           // new massage
    CMD_Values current_cmd;    // current massage
    FB_Values fb;
    DIAG_Values diag;
} GroupData_t;

// Global array of all 24 groups
GroupData_t g_groups[NUM_GROUPS];

// Generate ID with bits mask

extern void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB,
                               ubyte4 *ptr_DIAG);

// Settings messages by default

extern void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id);
// Functions for pack and unpack massages

extern void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd);

extern void Pack_FB(const FB_Values *fb, ubyte1 *can_data);

extern void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data);

// MAY BE DELETED??7 YOU SHOULD TO SEE ERTMAIN.C AND THINKING!!!!!!!!!!

/*
 * Initialization of physical CAN channels.
 * Called ONCE at system startup.
 */
IO_ErrorType Init_CAN_Channels(void);
/*
 * Initialization of ONE specific group.
 * Called for each group separately.
 * @param group_idx Group index (0 .. NUM_GROUPS-1)
 */

extern IO_ErrorType Init_CAN_Group(ubyte1 group_idx);

/*
 * CONVENIENT WRAPPER: Initialization of the ENTIRE system at once.
 * If you don't need step-by-step initialization, just call this function.
 */
IO_ErrorType Init_CAN_System_All(void);

// Read massage method

extern void Process_CAN_RX(ubyte1 group_idx);
// Write massage method

extern void Process_CAN_TX(ubyte1 group_idx);

/**
 * @brief Updates old configuration with new values from CAN message.
 *
 * Copies all config and value fields from cmd (new) to old_cmd
 * for the specified group.
 *
 * @param group_idx Group index (0..23)
 */

extern void Update_Old_CMD_Values(ubyte1 group_idx);

/**
 * @brief Compare old and current configs for this pin.
 *
 * @param group_idx index group (0..23)
 * @param pin_idx   index pin internal group (0..3)
 * @return true     if config this pin changed
 * @return false    else not changed
 */

extern bool Compare_Confs(ubyte1 group_idx, ubyte1 pin_idx);

#endif                                 /* CAN_Properties_h_ */
