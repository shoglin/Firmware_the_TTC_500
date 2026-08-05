/*
 * File: convRawData.c
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

#include "convRawData.h"

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

/* Output and update for Simulink Function: '<Root>/convAIVoltageData' */
void convAIVoltageData(ubyte4 inpValue, ubyte2 errorSts, ubyte2 *outADCValue)
{
    if (outADCValue == NULL)
    {
        return;
    }
    if (errorSts == 0)
    {
        *outADCValue = (ubyte2) inpValue;
    }
    else
    {
        *outADCValue = (ubyte2) VOLTAGE_ERROR_VALUE;
    }
}

/* Output and update for Simulink Function: '<Root>/convAICurrentData' */
void convAICurrentData(ubyte4 inpValue, ubyte2 errorSts, ubyte2 *outADCValue)
{
    if (outADCValue == NULL)
    {
        return;
    }
    if (errorSts == 0)
    {
        *outADCValue = (ubyte2) inpValue;
    }
    else
    {
        *outADCValue = (ubyte2) CURRENT_ERROR_VALUE;
    }
}

/* Output and update for Simulink Function: '<Root>/convAIResistance' */
void convAIResistanceData(ubyte4 inpValue, ubyte2 errorSts, ubyte2 *outADCValue)
{
    if (outADCValue == NULL)
    {
        return;
    }
    if (errorSts == 0)
    {
        // because IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm) inpValue / 1000 for -> ubyte2
        *outADCValue = (ubyte2) (inpValue / 1000);
    }
    else
    {
        *outADCValue = (ubyte2) RESISTANSE_ERROR_VALUE;
    }
}

/* Output and update for Simulink Function: '<Root>/convPWDData' */
void convPWDData(ubyte4 inpValue, ubyte2 errorSts, ubyte2 *outPWDValue)
{
    if (outPWDValue == NULL)
    {
        return;
    }
    if (errorSts == 0)
    {
        *outPWDValue = (ubyte2) (inpValue / 1000);
    }
    else
    {
        *outPWDValue = (ubyte2) FREQ_ERROR_VALUE;
    }
}



/*
 * File trailer for generated code.
 *
 * [EOF]
 */
