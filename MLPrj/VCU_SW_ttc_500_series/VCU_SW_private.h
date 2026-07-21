/*
 * File: VCU_SW_private.h
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.437
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Jul  6 11:47:51 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VCU_SW_private_h_
#define RTW_HEADER_VCU_SW_private_h_
#include "rtwtypes.h"
#include "VCU_SW.h"

// External statement of message object handler and message frame for RX
extern IO_CAN_DATA_FRAME read_message_PLC_StateM_msg_rx;
extern ubyte2 read_message_PLC_StateM_handler_rx;

// External statement of message object handler and message frame for TX
extern IO_CAN_DATA_FRAME transmit_message_hyd_fluid_temp_msg_tx;
extern ubyte2 transmit_message_hyd_fluid_temp_handler_tx;
extern void VCU_SW_GetDI10msec_Init(void);
extern void VCU_SW_GetDI10msec(void);
extern void VCU_SW_DigitalInput_Init(void);
extern void VCU_SW_DigitalInput(void);
extern void VCU_SW_InputInterfaces1_Init(void);
extern void VCU_SW_InputInterfaces1(void);
extern void VCU_SW_InputNetwork_Init(void);
extern void VCU_SW_InputNetwork(void);
extern void VCU_SW_InputLayer_Init(void);
extern void VCU_SW_InputLayer(void);
extern void VCU_SW_OutputNetwork_Init(void);
extern void VCU_SW_OutputNetwork(void);
extern void VCU_SW_OutputLayer_Init(void);
extern void VCU_SW_OutputLayer(void);

#endif                                 /* RTW_HEADER_VCU_SW_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
