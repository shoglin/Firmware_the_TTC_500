#include "Pin_Init_DeInit.h"

void Pin_Init(ubyte1 group_idx, ubyte1 pin_idx, ubyte1 pin_value)
{

    // Внутренний номер пина (0..95)
    ubyte1 internal_numb_pin = (group_idx * 4U) + pin_idx;

    // Получаем запрошенный режим из CAN-команды
    ubyte1 current_config = Get_Pin_Config(&g_groups[group_idx].current_cmd,
                                           pin_idx);

    Pin_modes_t current_pin_mode = (Pin_modes_t) current_config;

    // Предварительный расчет значений (если потребуется)

    // PVG принимает значение в формате "проценты * 100" (строго 1000 .. 9000)

    ubyte1 safe_pin_value = pin_value;
    if (safe_pin_value > 100U) {
        safe_pin_value = 100U;
    }

    // 2. Линейное преобразование: 0 -> 1000, 100 -> 9000
    // Формула: 1000 + (safe_pin_value * 80)
    // Максимальное значение: 1000 + (100 * 80) = 9000. Переполнения ubyte2 не будет.

    ubyte2 pvg_set_value = 1000U + ((ubyte2)safe_pin_value * 80U);

    // PWM принимает скважность 0..65535 (0%..100%)

    ubyte2 pwm_duty_cycle = (ubyte2) (((ubyte4) pin_value * 65535U) / 100U);

    // VOUT принимает напряжение в мВ (0..32000)
    // Допустим, pin_value здесь - это проценты от 32В (32000 мВ)
    ubyte2 vout_voltage_mv = (ubyte2) (((ubyte4) pin_value * 32000U) / 100U);

    switch (current_pin_mode)
    {
    case PIN_MODE_DI:
        IO_DI_Init(g_pin_configs[internal_numb_pin].di_cfg.pin_channel,
                   g_pin_configs[internal_numb_pin].di_cfg.pupd,
                   g_pin_configs[internal_numb_pin].di_cfg.limits);

        break;

    case PIN_MODE_ADC:
        IO_ADC_ChannelInit(
                g_pin_configs[internal_numb_pin].adc_cfg.pin_channel,
                g_pin_configs[internal_numb_pin].adc_cfg.input_type,
                g_pin_configs[internal_numb_pin].adc_cfg.voltage_range,
                g_pin_configs[internal_numb_pin].adc_cfg.pupd,
                g_pin_configs[internal_numb_pin].adc_cfg.supply_source,
                g_pin_configs[internal_numb_pin].adc_cfg.safety_settings);
        break;

    case PIN_MODE_PWD:
        // PWD - это вход. Мы его инициализируем в режиме Complex (наиболее универсальный).
        // Значение pin_value здесь игнорируется, так как PWD только измеряет, а не генерирует.
        IO_PWD_ComplexInit(
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.pin_channel,
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.pulse_duration_mode,
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.frequency_edge_mode,
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.sample_accumulation_count,
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.pupd,
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.complex_safety_settings);
        break;

    case PIN_MODE_PVG:
        // Инициализируем и сразу задаем выходное значение
        IO_PVG_Init(g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel,
                    pvg_set_value);
        break;

    case PIN_MODE_DO:
        IO_DO_Init(g_pin_configs[internal_numb_pin].do_cfg.pin_channel,
                   g_pin_configs[internal_numb_pin].do_cfg.enable_diagnostics,
                   g_pin_configs[internal_numb_pin].do_cfg.safety_settings);

        // Если нужно сразу установить состояние DO на основе pin_value (0 или 1)
        if (pin_value > 0U)
        {
            IO_DO_Set(g_pin_configs[internal_numb_pin].do_cfg.pin_channel,
            TRUE);
        }
        else
        {
            IO_DO_Set(g_pin_configs[internal_numb_pin].do_cfg.pin_channel,
            FALSE);
        }
        break;

    case PIN_MODE_PWM:
        // Инициализируем PWM
        IO_PWM_Init(
                g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel,
                g_pin_configs[internal_numb_pin].pwm_cfg.target_frequency,
                g_pin_configs[internal_numb_pin].pwm_cfg.signal_polarity,
                g_pin_configs[internal_numb_pin].pwm_cfg.enable_diagnostic_margin,
                g_pin_configs[internal_numb_pin].pwm_cfg.safety_settings);

        // Устанавливаем скважность, рассчитанную из pin_value
        IO_PWM_SetDuty(g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel,
                       pwm_duty_cycle, (ubyte2*) NULL, // Явное приведение типа для high_time_fb
                       (ubyte2*) NULL); // Явное приведение типа для period_fb
        break;

    case PIN_MODE_VOUT:
        // Инициализируем VOUT
        IO_VOUT_Init(g_pin_configs[internal_numb_pin].vout_cfg.pin_channel);

        // Устанавливаем напряжение
        IO_VOUT_SetVoltage(
                g_pin_configs[internal_numb_pin].vout_cfg.pin_channel,
                vout_voltage_mv);
        break;

    case PIN_MODE_UNUSED:
    default:
        // Ничего не делаем, пин не используется или режим неизвестен
        // Можно добавить IO_xxx_DeInit, если пин нужно гарантированно отключить
        break;
    }
}

void Pin_DeInit(ubyte1 group_idx, ubyte1 pin_idx)
{

    // Внутренний номер пина (0..95)
    ubyte1 internal_numb_pin = (group_idx * 4U) + pin_idx;

    // Получаем запрошенный режим из CAN-команды
    ubyte1 old_config = Get_Pin_Config(&g_groups[group_idx].old_cmd, pin_idx);

    Pin_modes_t old_pin_mode = (Pin_modes_t) old_config;

    switch (old_pin_mode)
    {
    case PIN_MODE_DI:
        IO_DI_DeInit(g_pin_configs[internal_numb_pin].di_cfg.pin_channel);
        break;
    case PIN_MODE_ADC:
        IO_ADC_ChannelDeInit(
                g_pin_configs[internal_numb_pin].adc_cfg.pin_channel);
        break;

    case PIN_MODE_PWD:
        IO_PWD_ComplexDeInit(
                g_pin_configs[internal_numb_pin].pwd_complex_cfg.pin_channel);
        break;

    case PIN_MODE_PVG:
        IO_PVG_DeInit(g_pin_configs[internal_numb_pin].pvg_cfg.pin_channel);
        break;

    case PIN_MODE_DO:
        IO_DO_DeInit(g_pin_configs[internal_numb_pin].do_cfg.pin_channel);
        break;

    case PIN_MODE_PWM:
        IO_PWM_DeInit(g_pin_configs[internal_numb_pin].pwm_cfg.pin_channel);
        break;

    case PIN_MODE_VOUT:
        IO_VOUT_DeInit(g_pin_configs[internal_numb_pin].vout_cfg.pin_channel);
        break;

    case PIN_MODE_UNUSED:
    default:
        // Ничего не делаем, пин не используется или режим неизвестен
        // Можно добавить IO_xxx_DeInit, если пин нужно гарантированно отключить
        break;
    }
}
