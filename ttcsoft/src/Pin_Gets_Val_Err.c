#include "Pin_Gets_Val_Err.h"

void Update_Pin_FB_and_DIAG(ubyte1 group_idx, ubyte1 pin_idx)
{
    // Проверка границ
    if (group_idx >= NUM_GROUPS || pin_idx >= 4U)
    {
        return;
    }

    // Вычисляем внутренний номер пина (0..95)
    ubyte1 internal_pin = (group_idx * 4U) + pin_idx;

    // Получаем текущий режим из CAN-команды
    ubyte1 current_mode = Get_Pin_Config(&g_groups[group_idx].current_cmd,
                                         pin_idx);

    ubyte2 fb_value = 0U;
    ubyte2 diag_value = IO_E_OK; // По умолчанию ошибок нет

    // Логика в зависимости от режима
    switch (current_mode)
    {
    case PIN_MODE_DI:
    {
        bool di_val = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].di_cfg.pin_channel;

        diag_value = IO_DI_Get(channel, &di_val);

        convDIOSttToEnum(di_val, diag_value, &fb_value);

        break;
    }

    case PIN_MODE_ADC:
    {
        ubyte4 adc_val = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].adc_cfg.pin_channel;

        diag_value = IO_ADC_Get(channel, &adc_val, &fresh);

        if (g_pin_configs[internal_pin].adc_cfg.input_type == IO_ADC_RATIOMETRIC)
        {
            convAIVoltageData(adc_val, diag_value, &fb_value);
        }

        if (g_pin_configs[internal_pin].adc_cfg.input_type == IO_ADC_ABSOLUTE)
        {
            convAIVoltageData(adc_val, diag_value, &fb_value);
        }

        if (g_pin_configs[internal_pin].adc_cfg.input_type == IO_ADC_CURRENT)
        {
            convAICurrenteData(adc_val, diag_value, &fb_value);
        }

        if (g_pin_configs[internal_pin].adc_cfg.input_type == IO_ADC_RESISTIVE)
        {
            convAIResistanceData(adc_val, diag_value, &fb_value);
        }

        break;
    }

    case PIN_MODE_PWD:
    {
        ubyte4 freq_Hz = 0U;

        ubyte4 pulse_width = 0U;
        bool pin_val = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].pwd_complex_cfg.pin_channel;

        // Читаем Complex mode (наиболее универсальный)
        diag_value = IO_PWD_ComplexGet(channel, &freq_Hz, &pulse_width,
                                       &pin_val,
                                       NULL);

        convPWDData(freq_Hz, diag_value, &fb_value);

        break;
    }

    case PIN_MODE_PVG:
    {
        ubyte2 voltage_mv = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].pvg_cfg.pin_channel;

        diag_value = IO_PVG_GetVoltage(channel, &voltage_mv, &fresh);

        convAIVoltageData(voltage_mv, diag_value, &fb_value);
        break;
    }

    case PIN_MODE_DO:
    {
        ubyte2 current_ma = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].do_cfg.pin_channel;

        // Для DO читаем ток, чтобы убедиться, что нагрузка действительно подключена и работает
        diag_value = IO_DO_GetCur(channel, &current_ma, &fresh);

        convAICurrentData(current_ma, diag_value, &fb_value);
        break;
    }

    case PIN_MODE_PWM:
    {
        ubyte2 current_ma = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].pwm_cfg.pin_channel;

        diag_value = IO_PWM_GetCur(channel, &current_ma, &fresh);

        convAICurrentData(current_ma, diag_value, &fb_value);
        break;
    }

    case PIN_MODE_VOUT:
    {
        ubyte2 voltage_mv = 0U;
        bool fresh = FALSE;
        ubyte1 channel = g_pin_configs[internal_pin].vout_cfg.pin_channel;

        diag_value = IO_VOUT_GetVoltage(channel, &voltage_mv, &fresh);

        convAIVoltageData(voltage_mv, diag_value, &fb_value);
        break;
    }

    case PIN_MODE_UNUSED:
    default:
    {
        fb_value = 0U;
        diag_value = IO_E_RESOLVING_FAILED;
        break;
    }
    }

    // Записываем результаты в структуры группы
    Set_Pin_FB(&g_groups[group_idx].fb, pin_idx, fb_value);
    Set_Pin_Diag(&g_groups[group_idx].diag, pin_idx, diag_value);
}
