#include "convRawData.h"

/* Include model header file for global data */
#include "VCU_SW.h"
#include "VCU_SW_private.h"

/* Output and update for Simulink Function: '<Root>/convDIOSttToEnum' */
void convDIOSttToEnum(BOOL rtu_rawValue, ubyte2 rtu_errorSts, StateModeTypes *rty_enumValue)
{

    if (rty_enumValue == NULL)
    {
        return;
    }

    if (rtu_errorSts == 0U)
    {
        if (rtu_rawValue)
        {
            *rty_enumValue = STT_ENABLE;
        }
        else
        {
            *rty_enumValue = STT_DISABLE;
        }
    }
    else
    {
        *rty_enumValue = STT_ERROR;
    }
}

/* Output and update for Simulink Function: '<Root>/convAIVoltageData' */
void convAIVoltageData(ubyte4 inpValue, ubyte2 errorSts, ubyte2 *outADCValue)
{
    if (outADCValue == NULL)
    {
        return;
    }

    if (errorSts == 0U)
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

    if (errorSts == 0U)
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

    if (errorSts == 0U)
    {
        // Convert 0–100,000 ohms to kOm (0–100 kOm)
        *outADCValue = (ubyte2) (inpValue / 1000U);
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

    if (errorSts == 0U)
    {
        // inpValue is provided in mHz (1/1000 Hz); we convert it to Hz
        *outPWDValue = (ubyte2) (inpValue / 1000U);
    }
    else
    {
        *outPWDValue = (ubyte2) FREQ_ERROR_VALUE;
    }
}
