#ifndef CAN_PROPERTIES_H_
#define CAN_PROPERTIES_H_

#include "IO_Driver.h"
#include "IO_CAN.h"
#include <stdbool.h>

/* 1. CAN constants    */

#define NUM_GROUPS                  24U   /* 24 groups (4 pins each = 96 channels) */
#define PINS_PER_GROUP              4U

/* Base 29-bit IDs */
#define CAN_CMD_BASE_ID             0x18FF00FAU
#define CAN_FB_BASE_ID              0x18FF0027U
#define CAN_DIAG_BASE_ID            0x18FF0027U
#define CAN_HEARTBEAT_ID            0x18FFFE27U

/* Acceptance mask for CAN0 */

#define CAN_CMD_ACCEPTANCE_MASK     0x1FFF00FFU

/* 2. Data structures*/

typedef struct {
    ubyte1 config[PINS_PER_GROUP];
    ubyte1 value[PINS_PER_GROUP];
} CMD_Values;

typedef struct {
    ubyte2 val[PINS_PER_GROUP];
} FB_Values;

typedef struct {
    ubyte2 val[PINS_PER_GROUP];
} DIAG_Values;

typedef struct {
    ubyte4      id_CMD;
    ubyte4      id_FB;
    ubyte4      id_DIAG;

    CMD_Values  current_cmd;
    CMD_Values  old_cmd;
    FB_Values   fb;
    DIAG_Values diag;

    bool        new_cmd_received;
} GroupData_t;

/* Statistics for real-time debugging */

typedef struct {
    ubyte4 tx_frames_count;
    ubyte4 rx_frames_count;
    ubyte4 last_rx_id;
    ubyte1 last_rx_data[8];
    ubyte1 can0_rx_err;
    ubyte1 can0_tx_err;
    ubyte1 can1_rx_err;
    ubyte1 can1_tx_err;
} CAN_Debug_Stats_t;


/* 3. Global variables and functions                                         */


extern GroupData_t       g_groups[NUM_GROUPS];
extern CAN_Debug_Stats_t g_can_stats;

void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB, ubyte4 *ptr_DIAG);
void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd);

IO_ErrorType Init_CAN_System_All(void);
void Process_CAN_RX_All(void);
void Process_CAN_TX_Scheduler(void);

#endif /* CAN_PROPERTIES_H_ */
