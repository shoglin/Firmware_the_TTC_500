#include "Pin_Gets_Val_Err.h"
#include "convRawData.h"

void Update_Pin_FB_and_DIAG(ubyte1 group_idx, ubyte1 pin_idx)
{
    ubyte1 internal_pin;
    ubyte1 current_mode;
    ubyte2 fb_value = 0U;
    ubyte2 diag_value = (ubyte2) IO_E_OK;

    if ((group_idx >= NUM_GROUPS) || (pin_idx >= 4U))
    {
        return;
    }

    internal_pin = (group_idx * 4U) + pin_idx;
    if (internal_pin >= PINS)
    {
        return;
    }

    current_mode = Get_Pin_Config(&g_groups[group_idx].current_cmd, pin_idx);

    switch (current_mode)
    {
    case PIN_MODE_DI:
    {
        bool di_val = FALSE;
        StateModeTypes di_state = STT_DISABLE;
        ubyte1 channel = g_pin_configs[internal_pin].di_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            diag_value = (ubyte2) IO_DI_Get(channel, &di_val);
            convDIOSttToEnum((BOOL) di_val, diag_value, &di_state);
            fb_value = (ubyte2) di_state;
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_ADC:
    {
        ubyte4 adc_val = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].adc_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            diag_value = (ubyte2) IO_ADC_Get(channel, &adc_val, &fresh);

            switch (g_pin_configs[internal_pin].adc_cfg.input_type)
            {
            case IO_ADC_RATIOMETRIC:
            case IO_ADC_ABSOLUTE:
                convAIVoltageData(adc_val, diag_value, &fb_value);
                break;

            case IO_ADC_CURRENT:
                convAICurrentData(adc_val, diag_value, &fb_value);
                break;

            case IO_ADC_RESISTIVE:
                convAIResistanceData(adc_val, diag_value, &fb_value);
                break;

            default:
                fb_value = 0U;
                break;
            }
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_PWD:
    {
        ubyte4 freq_mHz = 0U;
        ubyte4 pulse_width_us = 0U;
        bool pin_val = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].pwd_complex_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            diag_value = (ubyte2) IO_PWD_ComplexGet(channel, &freq_mHz,
                                                    &pulse_width_us, &pin_val,
                                                    NULL);

            convPWDData(freq_mHz, diag_value, &fb_value);
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_PVG:
    {
        ubyte2 voltage_mv = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].pvg_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            diag_value = (ubyte2) IO_PVG_GetVoltage(channel, &voltage_mv,
                                                    &fresh);
            convAIVoltageData((ubyte4) voltage_mv, diag_value, &fb_value);
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_DO:
    {
        ubyte2 current_ma = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].do_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            ubyte1 cmd_val = Get_Pin_Value(&g_groups[group_idx].current_cmd,
                                           pin_idx);
            bool target_state = (cmd_val > 0U) ? TRUE : FALSE;
            IO_ErrorType do_err = IO_DO_Set(channel, target_state);

            /* After pause */
            if (do_err == IO_E_FET_PROT_REENABLE)
            {
                (void) IO_DO_ResetProtection(channel, NULL);
                do_err = IO_DO_Set(channel, target_state);
            }

            diag_value = (ubyte2) IO_DO_GetCur(channel, &current_ma, &fresh);
            if (do_err != IO_E_OK)
            {
                diag_value = (ubyte2) do_err;
            }
            convAIVoltageData((ubyte4) current_ma, diag_value, &fb_value);
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_PWM:
    {
        ubyte2 current_ma = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].pwm_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            ubyte1 cmd_val = Get_Pin_Value(&g_groups[group_idx].current_cmd,
                                           pin_idx);
            ubyte2 duty_cycle;
            IO_ErrorType pwm_err;

            if (cmd_val > 100U)
            {
                cmd_val = 100U;
            }
            duty_cycle = (ubyte2) (((ubyte4) cmd_val * 65535U) / 100U);

            pwm_err = IO_PWM_SetDuty(channel, duty_cycle, NULL, NULL);

            if (pwm_err == IO_E_FET_PROT_REENABLE)
            {
                (void) IO_PWM_ResetProtection(channel, NULL);
                pwm_err = IO_PWM_SetDuty(channel, duty_cycle, NULL, NULL);
            }

            diag_value = (ubyte2) IO_PWM_GetCur(channel, &current_ma, &fresh);

            if ((pwm_err != IO_E_OK) && (pwm_err != IO_E_PWM_NO_DIAG)
                    && (pwm_err != IO_E_STARTUP))
            {
                diag_value = (ubyte2) pwm_err;
            }

            convAICurrentData((ubyte4) current_ma, diag_value, &fb_value);
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_VOUT:
    {
        ubyte2 voltage_mv = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].vout_cfg.pin_channel;

        if (channel != IO_PIN_NONE)
        {
            diag_value = (ubyte2) IO_VOUT_GetVoltage(channel, &voltage_mv,
                                                     &fresh);
            convAIVoltageData((ubyte4) voltage_mv, diag_value, &fb_value);
        }
        else
        {
            diag_value = (ubyte2) IO_E_INVALID_CHANNEL_ID;
            fb_value = 0U;
        }
        break;
    }

    case PIN_MODE_UNUSED:
    default:
    {
        fb_value = 0U;
        diag_value = (ubyte2) IO_E_OK;
        break;
    }
    }

    Set_Pin_FB(&g_groups[group_idx].fb, pin_idx, fb_value);
    Set_Pin_DIAG(&g_groups[group_idx].diag, pin_idx, diag_value);
}
