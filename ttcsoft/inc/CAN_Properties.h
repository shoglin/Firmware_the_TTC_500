#ifndef CAN_PROPERTIES_H_
#define CAN_PROPERTIES_H_

#include "IO_Driver.h"
#include "IO_CAN.h"
#include <stdbool.h>

#define NUM_GROUPS          24U  // Quantity groups

// ID's for massages

#define CAN_CMD_BASE_ID     0x18FF00FAU
#define CAN_FB_BASE_ID      0x18FF0027U
#define CAN_DIAG_BASE_ID    0x18FF0027U

// Mask for msgs, which read in CAN0 cannel

#define CAN_CMD_ACCEPTANCE_MASK 0x1FFF00FFU

// All needing structs

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
    CMD_Values    old_cmd;
    CMD_Values    current_cmd;
    FB_Values     fb;
    DIAG_Values   diag;
} GroupData_t;

// Array for all groups

extern GroupData_t g_groups[NUM_GROUPS];

// Function init CAN and setting massages

void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB, ubyte4 *ptr_DIAG);
void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id);
IO_ErrorType Init_CAN_Group(ubyte1 group_idx);
IO_ErrorType Init_CAN_System_All(void);

// Function pack and unpack massages

void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd);
void Pack_FB(const FB_Values *fb, ubyte1 *can_data);
void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data);

// Function read and write massages

void Process_CAN_RX(ubyte1 group_idx);
void Process_CAN_TX(ubyte1 group_idx);

// Helper functions for ÑÜÂ

void Update_Old_CMD_Values(ubyte1 group_idx);
bool Compare_Confs(ubyte1 group_idx, ubyte1 pin_idx);
bool Compare_Values(ubyte1 group_idx, ubyte1 pin_idx);

// Function setters and getters

ubyte1 Get_Pin_Config(const CMD_Values *cmd, ubyte1 pin_idx);
ubyte1 Get_Pin_Value(const CMD_Values *cmd, ubyte1 pin_idx);
void   Set_Pin_FB(FB_Values *fb, ubyte1 pin_idx, ubyte2 value);
void   Set_Pin_DIAG(DIAG_Values *diag, ubyte1 pin_idx, ubyte2 value);

#endif /* CAN_PROPERTIES_H_ */
