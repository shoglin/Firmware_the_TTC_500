/*
 * File: non_fatal_error_callback.c
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

#include "non_fatal_error_callback.h"

/* Include model header file for global data */
#include "VCU_SW.h"
#include "VCU_SW_private.h"

/* Output and update for Simulink Function: '<Root>/non_fatal_error_callback' */
ubyte1 non_fatal_error_callback(ubyte1 rtu_diag_state, ubyte1 rtu_watchdog_state,
  const DIAG_ERRORCODE *rtu_error)
{
  UNUSED_PARAMETER(rtu_diag_state);
  UNUSED_PARAMETER(rtu_watchdog_state);
  UNUSED_PARAMETER(rtu_error);

  /* SignalConversion generated from: '<S6>/y' */
  return 0U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
