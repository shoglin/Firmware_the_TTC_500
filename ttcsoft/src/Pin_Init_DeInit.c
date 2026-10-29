#include "Pin_Init_DeInit.h"

void Pin_Init(ubyte1 group_idx, ubyte1 pin_idx, ubyte1 pin_value)
{
    ubyte1 internal_numb_pin;
    ubyte1 current_config;
    Pin_modes_t current_pin_mode;
    ubyte1 safe_pin_value;
    ubyte2 pvg_set_value;
    ubyte2 pwm_duty_cycle;
    ubyte2 vout_voltage_mv;

    // Protection against array bounds violations

    if ((group_idx >= 24U) || (pin_idx >= 4U))
    {
        return;
    }

    internal_numb_pin = (group_idx * 4U) + pin_idx;
    if (internal_numb_pin >= PINS)
    {
        return;
    }

    current_config = Get_Pin_Config(&g_groups[group_idx].current_cmd, pin_idx);
    current_pin_mode = (Pin_modes_t) current_config;

    // Limiting the input value to 100

    safe_pin_value = pin_value;
    if (safe_pin_value > 100U)
    {
        safe_pin_value = 100U;
    }

    // Linear scaling values

    pvg_set_value   = 1000U + ((ubyte2)safe_pin_value * 80U);
    pwm_duty_cycle  = (ubyte2)(((ubyte4)safe_pin_value * 65535U) / 100U);
    vout_voltage_mv = (ubyte2)(((ubyte4)safe_pin_value * 32000U) / 100U);

    switch (current_pin_mode)
    {
    case PIN_MODE_DI:
        if (g_pin_configs[internal_numb_pin].di_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_DI_Init(g_pin_configs[internal_numb_pin].di_cfg.pin_channel,
                       g_pin_configs[internal_numb_pin].di_cfg.pupd,
                       g_pin_configs[internal_numb_pin].di_cfg.limits);
        }
        break;

    case PIN_MODE_ADC:
        if (g_pin_configs[internal_numb_pin].adc_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_ADC_ChannelInit(
                    g_pin_configs[internal_numb_pin].adc_cfg.pin_channel,
                    g_pin_configs[internal_numb_pin].adc_cfg.input_type,
                    g_pin_configs[internal_numb_pin].adc_cfg.voltage_range,
                    g_pin_configs[internal_numb_pin].adc_cfg.pupd,
                    g_pin_configs[internal_numb_pin].adc_cfg.supply_source,
                    g_pin_configs[internal_numb_pin].adc_cfg.safety_settings);
        }
        break;

    case PIN_MODE_PWD:
        if (g_pin_configs[internal_numb_pin].pwd_complex_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_PWD_ComplexInit(
                    g_pin_configs[internal_numb_pin].pwd_complex_cfg.pin_channel,
                    g_pin_configs[internal_numb_pin].pwd_complex_cfg.pulse_duration_mode,
                    g_pin_configs[internal_numb_pin].pwd_complex_cfg.frequency_edge_mode,
                    g_pin_configs[internal_numb_pin].pwd_complex_cfg.sample_accumulation_count,
                    g_pin_configs[internal_numb_pin].pwd_complex_cfg.pupd,
                    g_pin_configs[internal_numb_pin].pwd_complex_cfg.complex_safety_settings);
        }
        break;

    case PIN_MODE_PVG:
        if (g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_PVG_Init(g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel,
                        pvg_set_value);
        }
        break;

    case PIN_MODE_DO:
        if (g_pin_configs[internal_numb_pin].do_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_DO_Init(g_pin_configs[internal_numb_pin].do_cfg.pin_channel,
                       g_pin_configs[internal_numb_pin].do_cfg.enable_diagnostics,
                       g_pin_configs[internal_numb_pin].do_cfg.safety_settings);

            IO_DO_Set(g_pin_configs[internal_numb_pin].do_cfg.pin_channel,
                      (safe_pin_value > 0U) ? TRUE : FALSE);
        }
        break;

    case PIN_MODE_PWM:
        if (g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_PWM_Init(
                    g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel,
                    g_pin_configs[internal_numb_pin].pwm_cfg.target_frequency,
                    g_pin_configs[internal_numb_pin].pwm_cfg.signal_polarity,
                    g_pin_configs[internal_numb_pin].pwm_cfg.enable_diagnostic_margin,
                    g_pin_configs[internal_numb_pin].pwm_cfg.safety_settings);

            IO_PWM_SetDuty(g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel,
                           pwm_duty_cycle,
                           (ubyte2*) NULL,
                           (ubyte2*) NULL);
        }
        break;

    case PIN_MODE_VOUT:
        if (g_pin_configs[internal_numb_pin].vout_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_VOUT_Init(g_pin_configs[internal_numb_pin].vout_cfg.pin_channel);
            IO_VOUT_SetVoltage(g_pin_configs[internal_numb_pin].vout_cfg.pin_channel,
                               vout_voltage_mv);
        }
        break;

    case PIN_MODE_UNUSED:
    default:
        break;
    }
}

void Pin_DeInit(ubyte1 group_idx, ubyte1 pin_idx)
{
    ubyte1 internal_numb_pin;
    ubyte1 old_config;
    Pin_modes_t old_pin_mode;

    if ((group_idx >= 24U) || (pin_idx >= 4U))
    {
        return;
    }

    internal_numb_pin = (group_idx * 4U) + pin_idx;
    if (internal_numb_pin >= PINS)
    {
        return;
    }

    old_config = Get_Pin_Config(&g_groups[group_idx].old_cmd, pin_idx);
    old_pin_mode = (Pin_modes_t) old_config;

    switch (old_pin_mode)
    {
    case PIN_MODE_DI:
        if (g_pin_configs[internal_numb_pin].di_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_DI_DeInit(g_pin_configs[internal_numb_pin].di_cfg.pin_channel);
        }
        break;

    case PIN_MODE_ADC:
        if (g_pin_configs[internal_numb_pin].adc_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_ADC_ChannelDeInit(g_pin_configs[internal_numb_pin].adc_cfg.pin_channel);
        }
        break;

    case PIN_MODE_PWD:
        if (g_pin_configs[internal_numb_pin].pwd_complex_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_PWD_ComplexDeInit(g_pin_configs[internal_numb_pin].pwd_complex_cfg.pin_channel);
        }
        break;

    case PIN_MODE_PVG:
        if (g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_PVG_DeInit(g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel);
        }
        break;

    case PIN_MODE_DO:
        if (g_pin_configs[internal_numb_pin].do_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_DO_DeInit(g_pin_configs[internal_numb_pin].do_cfg.pin_channel);
        }
        break;

    case PIN_MODE_PWM:
        if (g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_PWM_DeInit(g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel);
        }
        break;

    case PIN_MODE_VOUT:
        if (g_pin_configs[internal_numb_pin].vout_cfg.pin_channel != IO_PIN_NONE)
        {
            IO_VOUT_DeInit(g_pin_configs[internal_numb_pin].vout_cfg.pin_channel);
        }
        break;

    case PIN_MODE_UNUSED:
    default:
        break;
    }
}

void Pin_Write_Value(ubyte1 group_idx, ubyte1 pin_idx, ubyte1 pin_value)
{
    ubyte1 internal_numb_pin;
    ubyte1 current_config;
    Pin_modes_t current_pin_mode;
    ubyte1 safe_pin_value;

    if ((group_idx >= NUM_GROUPS) || (pin_idx >= 4U))
    {
        return;
    }

    internal_numb_pin = (group_idx * 4U) + pin_idx;
    if (internal_numb_pin >= PINS)
    {
        return;
    }

    current_config = Get_Pin_Config(&g_groups[group_idx].current_cmd, pin_idx);
    current_pin_mode = (Pin_modes_t)current_config;

    safe_pin_value = pin_value;
    if (safe_pin_value > 100U)
    {
        safe_pin_value = 100U;
    }

    switch (current_pin_mode)
    {
    case PIN_MODE_DO:
        if (g_pin_configs[internal_numb_pin].do_cfg.pin_channel != IO_PIN_NONE)
        {
            (void)IO_DO_Set(g_pin_configs[internal_numb_pin].do_cfg.pin_channel,
                            (safe_pin_value > 0U) ? TRUE : FALSE);
        }
        break;

    case PIN_MODE_PWM:
        if (g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel != IO_PIN_NONE)
        {
            ubyte2 pwm_duty_cycle = (ubyte2)(((ubyte4)safe_pin_value * 65535U) / 100U);
            (void)IO_PWM_SetDuty(g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel,
                                 pwm_duty_cycle,
                                 (ubyte2*)NULL,
                                 (ubyte2*)NULL);
        }
        break;

    case PIN_MODE_PVG:
        if (g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel != IO_PIN_NONE)
        {
            ubyte2 pvg_set_value = 1000U + ((ubyte2)safe_pin_value * 80U);
            (void)IO_PVG_SetOutput(g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel,
                                   pvg_set_value);
        }
        break;

    case PIN_MODE_VOUT:
        if (g_pin_configs[internal_numb_pin].vout_cfg.pin_channel != IO_PIN_NONE)
        {
            ubyte2 vout_voltage_mv = (ubyte2)(((ubyte4)safe_pin_value * 32000U) / 100U);
            (void)IO_VOUT_SetVoltage(g_pin_configs[internal_numb_pin].vout_cfg.pin_channel,
                                     vout_voltage_mv);
        }
        break;

    default:

        break;
    }
}
