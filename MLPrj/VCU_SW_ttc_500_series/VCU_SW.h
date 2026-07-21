/*
 * File: VCU_SW.h
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

#ifndef RTW_HEADER_VCU_SW_h_
#define RTW_HEADER_VCU_SW_h_
#include <stddef.h>
#include <string.h>
#ifndef VCU_SW_COMMON_INCLUDES_
#define VCU_SW_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "IO_DIO.h"
#include "can_message.h"
#endif                                 /* VCU_SW_COMMON_INCLUDES_ */

#include "VCU_SW_types.h"

/* Child system includes */
#include "convDIOSttToEnum_private.h"
#include "convDIOSttToEnum.h"
#include "fatal_error_callback_private.h"
#include "fatal_error_callback.h"
#include "non_fatal_error_callback_private.h"
#include "non_fatal_error_callback.h"
#include "IO_PIN.h"
#include "IO_POWER.h"
#include "IO_CAN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "swcAppEnumTypes.h"
#include "IO_CAN.h"

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_BUS CANPack_hyd_Fluid_temp;/* '<S11>/CANPack_hyd_Fluid_temp' */
  CAN_MESSAGE_BUS msg_419365114;       /* '<S8>/read_message_PLC_StateM' */
  ubyte2 DataStoreRead;                /* '<S11>/Data Store Read' */
  ubyte1 CAN_Unpack_PLC_StateM_o1;     /* '<S8>/CAN_Unpack_PLC_StateM' */
  ubyte1 CAN_Unpack_PLC_StateM_o2;     /* '<S8>/CAN_Unpack_PLC_StateM' */
} B_VCU_SW_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  CANOutputStruct CANOutput;           /* '<Root>/CANOutput' */
  int_T CANPack_hyd_Fluid_temp_ModeSign;/* '<S11>/CANPack_hyd_Fluid_temp' */
  int_T CAN_Unpack_PLC_StateM_ModeSigna;/* '<S8>/CAN_Unpack_PLC_StateM' */
  int_T CAN_Unpack_PLC_StateM_StatusPor;/* '<S8>/CAN_Unpack_PLC_StateM' */
} DW_VCU_SW_T;

/* Real-time Model Data Structure */
struct tag_RTM_VCU_SW_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_VCU_SW_T VCU_SW_B;

/* Block states (default storage) */
extern DW_VCU_SW_T VCU_SW_DW;

/* External data declarations for dependent source files */
extern const DIAG_ERRORCODE VCU_SW_rtZDIAG_ERRORCODE;/* DIAG_ERRORCODE ground */

/* Model entry point functions */
extern void VCU_SW_initialize(void);
extern void VCU_SW_step(void);
extern void VCU_SW_terminate(void);

/* Real-time Model object */
extern RT_MODEL_VCU_SW_T *const VCU_SW_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VCU_SW'
 * '<S1>'   : 'VCU_SW/InputLayer'
 * '<S2>'   : 'VCU_SW/OutputLayer'
 * '<S3>'   : 'VCU_SW/call_callbacks'
 * '<S4>'   : 'VCU_SW/convDIOSttToEnum'
 * '<S5>'   : 'VCU_SW/fatal_error_callback'
 * '<S6>'   : 'VCU_SW/non_fatal_error_callback'
 * '<S7>'   : 'VCU_SW/InputLayer/InputInterfaces1'
 * '<S8>'   : 'VCU_SW/InputLayer/InputNetwork'
 * '<S9>'   : 'VCU_SW/InputLayer/InputInterfaces1/DigitalInput'
 * '<S10>'  : 'VCU_SW/InputLayer/InputInterfaces1/DigitalInput/GetDI10msec'
 * '<S11>'  : 'VCU_SW/OutputLayer/OutputNetwork'
 * '<S12>'  : 'VCU_SW/convDIOSttToEnum/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_VCU_SW_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
