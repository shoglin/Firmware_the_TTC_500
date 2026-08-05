#ifndef CAN_Properties_h_
#define CAN_Properties_h_

#include "IO_Driver.h"
#include "IO_CAN.h"
#include <stdbool.h>

// 1. Constants

#define NUM_GROUPS 24U  // 24 groups

// 2. Data structures

typedef struct {
    ubyte1 config[4];
    ubyte1 value[4];
} CMD_Values;

typedef struct {
    ubyte2 val[4];
} FB_Values;

typedef struct {
    ubyte2 val[4];
} DIAG_Values;

typedef struct {
    ubyte2 handle_CMD;
    ubyte2 handle_FB;
    ubyte2 handle_DIAG;

    IO_CAN_DATA_FRAME frame_CMD;
    IO_CAN_DATA_FRAME frame_FB;
    IO_CAN_DATA_FRAME frame_DIAG;
} CAN_Msg_Props;

typedef struct {
    CAN_Msg_Props can;
    CMD_Values old_cmd;        // Previously applied configuration
    CMD_Values current_cmd;    // Newly received configuration
    FB_Values fb;
    DIAG_Values diag;
} GroupData_t;

// Global array of all 24 groups

extern GroupData_t g_groups[NUM_GROUPS];

// Generate ID with bits mask

extern void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB, ubyte4 *ptr_DIAG);

// Settings messages by default

extern void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id);

// Functions for pack and unpack messages

extern void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd);

extern void Pack_FB(const FB_Values *fb, ubyte1 *can_data);

extern void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data);

// Setters and getters (static inline to prevent multiple definition errors)

/**
 * @brief Gets the configuration of a specific pin from the CMD structure.
 */

extern ubyte1 Get_Pin_Config(const CMD_Values *cmd, ubyte1 pin_idx);

/**
 * @brief Gets the value of a specific pin from the CMD structure.
 */

extern ubyte1 Get_Pin_Value(const CMD_Values *cmd, ubyte1 pin_idx);
/**
 * @brief Sets the value for the feedback (FB) of a specific pin.
 */

extern void Set_Pin_FB(FB_Values *fb, ubyte1 pin_idx, ubyte2 value);

/**
 * @brief Sets the value for the diagnostic (DIAG) of a specific pin.
 */

extern void Set_Pin_DIAG(DIAG_Values *diag, ubyte1 pin_idx, ubyte2 value);

// Initialization functions

extern IO_ErrorType Init_CAN_Group(ubyte1 group_idx);

extern IO_ErrorType Init_CAN_System_All(void);

// Read/Write message methods

extern void Process_CAN_RX(ubyte1 group_idx);

extern void Process_CAN_TX(ubyte1 group_idx);

// Update old configuration with new values

extern void Update_Old_CMD_Values(ubyte1 group_idx);

// Compare old and current configs for this pin

extern bool Compare_Confs(ubyte1 group_idx, ubyte1 pin_idx);

#endif /* CAN_Properties_h_ */
