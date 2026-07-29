/*
 * File: VCU_SW_types.h
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

#ifndef RTW_HEADER_VCU_SW_types_h_
#define RTW_HEADER_VCU_SW_types_h_
#include "rtwtypes.h"
#include "swcAppEnumTypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  ubyte1 Extended;
  ubyte1 Length;
  ubyte1 Remote;
  ubyte1 Error;
  ubyte4 ID;
  float8 Timestamp;
  ubyte1 Data[8];
} CAN_MESSAGE_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PinCMDStruct_
#define DEFINED_TYPEDEF_FOR_PinCMDStruct_

typedef struct {
  ubyte1 Pin0_value;
  ubyte1 Pin1_value;
  ubyte1 Pin2_value;
  ubyte1 Pin3_value;
} PinCMDStruct;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PinCFGStruct_
#define DEFINED_TYPEDEF_FOR_PinCFGStruct_

typedef struct {
  ubyte1 Pin0_config;
  ubyte1 Pin1_config;
  ubyte1 Pin2_config;
  ubyte1 Pin3_config;
} PinCFGStruct;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PinInputStruct_
#define DEFINED_TYPEDEF_FOR_PinInputStruct_

typedef struct {
  PinCMDStruct PinCMD;
  PinCFGStruct PinCFG;
} PinInputStruct;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CANInputStruct_
#define DEFINED_TYPEDEF_FOR_CANInputStruct_

typedef struct {
  PinInputStruct Pin101_Pin104_CMD;
} CANInputStruct;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PinFBStruct_
#define DEFINED_TYPEDEF_FOR_PinFBStruct_

typedef struct {
  ubyte2 Pin0_feedback;
  ubyte2 Pin1_feedback;
  ubyte2 Pin2_feedback;
  ubyte2 Pin3_feedback;
} PinFBStruct;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CANOutputStruct_
#define DEFINED_TYPEDEF_FOR_CANOutputStruct_

typedef struct {
  PinFBStruct Pin101_Pin104_FB;
} CANOutputStruct;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_VCU_SW_T RT_MODEL_VCU_SW_T;

#endif                                 /* RTW_HEADER_VCU_SW_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
