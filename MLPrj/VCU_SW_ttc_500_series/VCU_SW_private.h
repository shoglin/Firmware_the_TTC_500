/*
 * File: VCU_SW_private.h
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul 14 11:26:00 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VCU_SW_private_h_
#define RTW_HEADER_VCU_SW_private_h_
#include "rtwtypes.h"

// External statement of message object handler and message frame for TX
extern IO_CAN_DATA_FRAME transmit_message_vlvcmd_hyd1_msg_tx;
extern ubyte2 transmit_message_vlvcmd_hyd1_handler_tx;

// External statement of message object handler and message frame for RX
extern IO_CAN_DATA_FRAME read_message_Pin101_Pin104_CMD_msg_rx;
extern ubyte2 read_message_Pin101_Pin104_CMD_handler_rx;

// External statement of message object handler and message frame for TX
extern IO_CAN_DATA_FRAME transmit_message_vlvcmd_hyd1_k_msg_tx;
extern ubyte2 transmit_message_vlvcmd_hyd1_k_handler_tx;

#endif                                 /* RTW_HEADER_VCU_SW_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
