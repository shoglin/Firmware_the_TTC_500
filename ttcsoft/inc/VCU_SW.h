/*
 * File: VCU_SW.h
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
#include "convAIVoltageData.h"
#include "convAIVoltageData_private.h"
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

/* Block signals (default storage) */               // Структуры скорее всего на удаление
typedef struct {
  CAN_MESSAGE_BUS CANPack_VLVCMD_HYD1; /* '<S7>/CANPack_VLVCMD_HYD1' */
  CAN_MESSAGE_BUS msg_419365114;     /* '<S5>/read_message_Pin101_Pin104_CMD' */
  CAN_MESSAGE_BUS CANPack_VLVCMD_HYD1_h;/* '<S2>/CANPack_VLVCMD_HYD1' */
  ubyte2 di_104_error;
  ubyte2 adc_104_error;  /* '<S7>/EngineAirFilterClogSens' */
  ubyte2 DataStoreRead;                /* '<S2>/Data Store Read' */
  ubyte1 CANUnpack_Pin101_Pin104_CMD_o1;/* '<S5>/CANUnpack_Pin101_Pin104_CMD' */
  ubyte1 CANUnpack_Pin101_Pin104_CMD_o2;/* '<S5>/CANUnpack_Pin101_Pin104_CMD' */
} B_VCU_SW_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  CANOutputStruct OutputNetworkData;   /* '<Root>/OutputNetworkDS' */
  int_T CANPack_VLVCMD_HYD1_ModeSignalI;/* '<S7>/CANPack_VLVCMD_HYD1' */
  int_T CANUnpack_Pin101_Pin104_CMD_Mod;/* '<S5>/CANUnpack_Pin101_Pin104_CMD' */
  int_T CANUnpack_Pin101_Pin104_CMD_Sta;/* '<S5>/CANUnpack_Pin101_Pin104_CMD' */
  int_T CANPack_VLVCMD_HYD1_ModeSigna_f;/* '<S2>/CANPack_VLVCMD_HYD1' */
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
extern const float8 VCU_SW_RGND;       /* float8 ground */

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
 * '<S1>'   : 'VCU_SW/InputData'
 * '<S2>'   : 'VCU_SW/OutputData'
 * '<S3>'   : 'VCU_SW/convDIOSttToEnum'
 * '<S4>'   : 'VCU_SW/InputData/InputData'
 * '<S5>'   : 'VCU_SW/InputData/Pin101_Pin104_CMD_fa'
 * '<S6>'   : 'VCU_SW/InputData/InputData/AnalogInputs'
 * '<S7>'   : 'VCU_SW/InputData/InputData/DigitalInputs'
 * '<S8>'   : 'VCU_SW/convDIOSttToEnum/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_VCU_SW_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
