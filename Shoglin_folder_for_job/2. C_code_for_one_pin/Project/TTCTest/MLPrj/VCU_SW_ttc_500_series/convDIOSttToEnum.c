/*
 * File: convDIOSttToEnum.c
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul  7 15:46:48 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "convDIOSttToEnum.h"

/* Include model header file for global data */
#include "VCU_SW.h"
#include "VCU_SW_private.h"

/* Output and update for Simulink Function: '<Root>/convDIOSttToEnum' */
void convDIOSttToEnum(BOOL rtu_rawValue, ubyte2 rtu_errorSts, StateModeTypes
                      *rty_enumValue)
{
  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  SignalConversion generated from: '<S3>/errorSts'
   *  SignalConversion generated from: '<S3>/rawValue'
   */
  if (rtu_errorSts == 0) {
    if (rtu_rawValue) {
      /* SignalConversion generated from: '<S3>/enumValue' */
      *rty_enumValue = STT_ENABLE;
    } else {
      /* SignalConversion generated from: '<S3>/enumValue' */
      *rty_enumValue = STT_DISABLE;
    }
  } else {
    /* SignalConversion generated from: '<S3>/enumValue' */
    *rty_enumValue = STT_ERROR;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
