/*
 * File: convDIOSttToEnum.c
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

#include "convDIOSttToEnum.h"

/* Include model header file for global data */
#include "VCU_SW.h"
#include "VCU_SW_private.h"

/* Output and update for Simulink Function: '<Root>/convDIOSttToEnum' */
void convDIOSttToEnum(BOOL rtu_rawValue, ubyte2 rtu_errorSts, StateModeTypes
                      *rty_enumValue)
{
  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  SignalConversion generated from: '<S4>/errorSts'
   *  SignalConversion generated from: '<S4>/rawValue'
   */
  if (rtu_errorSts == 0) {
    if (rtu_rawValue) {
      /* SignalConversion generated from: '<S4>/enumValue' */
      *rty_enumValue = STT_ENABLE;
    } else {
      /* SignalConversion generated from: '<S4>/enumValue' */
      *rty_enumValue = STT_DISABLE;
    }
  } else {
    /* SignalConversion generated from: '<S4>/enumValue' */
    *rty_enumValue = STT_ERROR;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
