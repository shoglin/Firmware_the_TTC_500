#include "Pin_Settings.h"

PinConfigUnion_t g_pin_configs[96];

void Pin_Properties()
{

    ubyte1 i;

    for(i = 0; i < PINS; i++)
    {
        g_pin_configs[i].di_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].adc_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].pwd_complex_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].pwd_count_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].pwd_incremental_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].pwd_universal_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].pvg_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].do_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].pwm_cfg.pin_channel = IO_PIN_NONE;
        g_pin_configs[i].vout_cfg.pin_channel = IO_PIN_NONE;
    }

    /*============================
     * IO_PIN_103 (Internal 0)
     * IO_ADC_00 (3-mode: 0-5V, 0-25mA, 0-100kOhm)
     * IO_DI_48
     * ===========================
     */

    // Digital Input конфигурация
    g_pin_configs[0].di_cfg.pin_channel = IO_DI_48;
    g_pin_configs[0].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[0].di_cfg.voltage_limits = NULL;

    // ADC конфигурация (3-mode, используем как voltage 0-5V)
    g_pin_configs[0].adc_cfg.pin_channel = IO_ADC_00;
    g_pin_configs[0].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[0].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[0].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[0].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[0].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_127 (Internal 1)
     * IO_ADC_01 (3-mode)
     * IO_DI_49
     * ===========================
     */
    g_pin_configs[1].di_cfg.pin_channel = IO_DI_49;
    g_pin_configs[1].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[1].di_cfg.voltage_limits = NULL;

    g_pin_configs[1].adc_cfg.pin_channel = IO_ADC_01;
    g_pin_configs[1].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[1].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[1].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[1].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[1].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_104 (Internal 2)
     * IO_ADC_02 (3-mode)
     * IO_DI_50
     * ===========================
     */
    g_pin_configs[2].di_cfg.pin_channel = IO_DI_50;
    g_pin_configs[2].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[2].di_cfg.voltage_limits = NULL;

    g_pin_configs[2].adc_cfg.pin_channel = IO_ADC_02;
    g_pin_configs[2].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[2].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[2].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[2].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[2].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_128 (Internal 3)
     * IO_ADC_03 (3-mode)
     * IO_DI_51
     * ===========================
     */
    g_pin_configs[3].di_cfg.pin_channel = IO_DI_51;
    g_pin_configs[3].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[3].di_cfg.voltage_limits = NULL;

    g_pin_configs[3].adc_cfg.pin_channel = IO_ADC_03;
    g_pin_configs[3].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[3].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[3].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[3].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[3].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_105 (Internal 4)
     * IO_ADC_04 (3-mode)
     * IO_DI_52
     * ===========================
     */
    g_pin_configs[4].di_cfg.pin_channel = IO_DI_52;
    g_pin_configs[4].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[4].di_cfg.voltage_limits = NULL;

    g_pin_configs[4].adc_cfg.pin_channel = IO_ADC_04;
    g_pin_configs[4].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[4].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[4].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[4].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[4].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_129 (Internal 5)
     * IO_ADC_05 (3-mode)
     * IO_DI_53
     * ===========================
     */
    g_pin_configs[5].di_cfg.pin_channel = IO_DI_53;
    g_pin_configs[5].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[5].di_cfg.voltage_limits = NULL;

    g_pin_configs[5].adc_cfg.pin_channel = IO_ADC_05;
    g_pin_configs[5].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[5].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[5].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[5].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[5].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_106 (Internal 6)
     * IO_ADC_06 (3-mode)
     * IO_DI_54
     * ===========================
     */
    g_pin_configs[6].di_cfg.pin_channel = IO_DI_54;
    g_pin_configs[6].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[6].di_cfg.voltage_limits = NULL;

    g_pin_configs[6].adc_cfg.pin_channel = IO_ADC_06;
    g_pin_configs[6].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[6].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[6].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[6].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[6].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_130 (Internal 7)
     * IO_ADC_07 (3-mode)
     * IO_DI_55
     * ===========================
     */
    g_pin_configs[7].di_cfg.pin_channel = IO_DI_55;
    g_pin_configs[7].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[7].di_cfg.voltage_limits = NULL;

    g_pin_configs[7].adc_cfg.pin_channel = IO_ADC_07;
    g_pin_configs[7].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[7].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[7].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[7].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[7].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_107 (Internal 8)
     * IO_ADC_08 (2-mode 10V: 0-5V/0-10V, 0-25mA)
     * IO_DI_56
     * ===========================
     */
    g_pin_configs[8].di_cfg.pin_channel = IO_DI_56;
    g_pin_configs[8].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[8].di_cfg.voltage_limits = NULL;

    g_pin_configs[8].adc_cfg.pin_channel = IO_ADC_08;
    g_pin_configs[8].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[8].adc_cfg.voltage_range = IO_ADC_RANGE_10V;  // 10V range
    g_pin_configs[8].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[8].adc_cfg.supply_source = IO_PIN_NONE; // Не используется для absolute
    g_pin_configs[8].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_131 (Internal 9)
     * IO_ADC_09 (2-mode 10V)
     * IO_DI_57
     * ===========================
     */
    g_pin_configs[9].di_cfg.pin_channel = IO_DI_57;
    g_pin_configs[9].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[9].di_cfg.voltage_limits = NULL;

    g_pin_configs[9].adc_cfg.pin_channel = IO_ADC_09;
    g_pin_configs[9].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[9].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[9].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[9].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[9].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_108 (Internal 10)
     * IO_ADC_10 (2-mode 10V)
     * IO_DI_58
     * ===========================
     */
    g_pin_configs[10].di_cfg.pin_channel = IO_DI_58;
    g_pin_configs[10].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[10].di_cfg.voltage_limits = NULL;

    g_pin_configs[10].adc_cfg.pin_channel = IO_ADC_10;
    g_pin_configs[10].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[10].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[10].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[10].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[10].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_132 (Internal 11)
     * IO_ADC_11 (2-mode 10V)
     * IO_DI_59
     * ===========================
     */
    g_pin_configs[11].di_cfg.pin_channel = IO_DI_59;
    g_pin_configs[11].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[11].di_cfg.voltage_limits = NULL;

    g_pin_configs[11].adc_cfg.pin_channel = IO_ADC_11;
    g_pin_configs[11].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[11].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[11].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[11].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[11].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_109 (Internal 12)
     * IO_ADC_12 (2-mode 10V)
     * IO_DI_60
     * ===========================
     */
    g_pin_configs[12].di_cfg.pin_channel = IO_DI_60;
    g_pin_configs[12].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[12].di_cfg.voltage_limits = NULL;

    g_pin_configs[12].adc_cfg.pin_channel = IO_ADC_12;
    g_pin_configs[12].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[12].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[12].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[12].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[12].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_133 (Internal 13)
     * IO_ADC_13 (2-mode 10V)
     * IO_DI_61
     * ===========================
     */
    g_pin_configs[13].di_cfg.pin_channel = IO_DI_61;
    g_pin_configs[13].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[13].di_cfg.voltage_limits = NULL;

    g_pin_configs[13].adc_cfg.pin_channel = IO_ADC_13;
    g_pin_configs[13].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[13].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[13].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[13].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[13].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_110 (Internal 14)
     * IO_ADC_14 (2-mode 10V)
     * IO_DI_62
     * ===========================
     */
    g_pin_configs[14].di_cfg.pin_channel = IO_DI_62;
    g_pin_configs[14].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[14].di_cfg.voltage_limits = NULL;

    g_pin_configs[14].adc_cfg.pin_channel = IO_ADC_14;
    g_pin_configs[14].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[14].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[14].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[14].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[14].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_134 (Internal 15)
     * IO_ADC_15 (2-mode 10V)
     * IO_DI_63
     * ===========================
     */
    g_pin_configs[15].di_cfg.pin_channel = IO_DI_63;
    g_pin_configs[15].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[15].di_cfg.voltage_limits = NULL;

    g_pin_configs[15].adc_cfg.pin_channel = IO_ADC_15;
    g_pin_configs[15].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[15].adc_cfg.voltage_range = IO_ADC_RANGE_10V;
    g_pin_configs[15].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[15].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[15].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_111 (Internal 16)
     * IO_ADC_16 (2-mode 32V: 0-5V/0-32V, 0-25mA)
     * IO_DI_64
     * ===========================
     */
    g_pin_configs[16].di_cfg.pin_channel = IO_DI_64;
    g_pin_configs[16].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[16].di_cfg.voltage_limits = NULL;

    g_pin_configs[16].adc_cfg.pin_channel = IO_ADC_16;
    g_pin_configs[16].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[16].adc_cfg.voltage_range = IO_ADC_RANGE_32V;  // 32V range
    g_pin_configs[16].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[16].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[16].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_135 (Internal 17)
     * IO_ADC_17 (2-mode 32V)
     * IO_DI_65
     * ===========================
     */
    g_pin_configs[17].di_cfg.pin_channel = IO_DI_65;
    g_pin_configs[17].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[17].di_cfg.voltage_limits = NULL;

    g_pin_configs[17].adc_cfg.pin_channel = IO_ADC_17;
    g_pin_configs[17].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[17].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[17].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[17].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[17].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_112 (Internal 18)
     * IO_ADC_18 (2-mode 32V)
     * IO_DI_66
     * ===========================
     */
    g_pin_configs[18].di_cfg.pin_channel = IO_DI_66;
    g_pin_configs[18].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[18].di_cfg.voltage_limits = NULL;

    g_pin_configs[18].adc_cfg.pin_channel = IO_ADC_18;
    g_pin_configs[18].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[18].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[18].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[18].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[18].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_136 (Internal 19)
     * IO_ADC_19 (2-mode 32V)
     * IO_DI_67
     * ===========================
     */
    g_pin_configs[19].di_cfg.pin_channel = IO_DI_67;
    g_pin_configs[19].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[19].di_cfg.voltage_limits = NULL;

    g_pin_configs[19].adc_cfg.pin_channel = IO_ADC_19;
    g_pin_configs[19].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[19].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[19].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[19].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[19].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_113 (Internal 20)
     * IO_ADC_20 (2-mode 32V)
     * IO_DI_68
     * ===========================
     */
    g_pin_configs[20].di_cfg.pin_channel = IO_DI_68;
    g_pin_configs[20].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[20].di_cfg.voltage_limits = NULL;

    g_pin_configs[20].adc_cfg.pin_channel = IO_ADC_20;
    g_pin_configs[20].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[20].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[20].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[20].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[20].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_137 (Internal 21)
     * IO_ADC_21 (2-mode 32V)
     * IO_DI_69
     * ===========================
     */
    g_pin_configs[21].di_cfg.pin_channel = IO_DI_69;
    g_pin_configs[21].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[21].di_cfg.voltage_limits = NULL;

    g_pin_configs[21].adc_cfg.pin_channel = IO_ADC_21;
    g_pin_configs[21].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[21].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[21].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[21].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[21].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_114 (Internal 22)
     * IO_ADC_22 (2-mode 32V)
     * IO_DI_70
     * ===========================
     */
    g_pin_configs[22].di_cfg.pin_channel = IO_DI_70;
    g_pin_configs[22].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[22].di_cfg.voltage_limits = NULL;

    g_pin_configs[22].adc_cfg.pin_channel = IO_ADC_22;
    g_pin_configs[22].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[22].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[22].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[22].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[22].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_138 (Internal 23)
     * IO_ADC_23 (2-mode 32V)
     * IO_DI_71
     * ===========================
     */
    g_pin_configs[23].di_cfg.pin_channel = IO_DI_71;
    g_pin_configs[23].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[23].di_cfg.voltage_limits = NULL;

    g_pin_configs[23].adc_cfg.pin_channel = IO_ADC_23;
    g_pin_configs[23].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[23].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[23].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[23].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[23].adc_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_115 (Internal 24)
     * IO_PWD_00 (Complex mode: frequency + pulse-width)
     * IO_ADC_24
     * IO_DI_36
     * ===========================
     */

    // PWD Complex конфигурация
    g_pin_configs[24].pwd_complex_cfg.pin_channel = IO_PWD_00;
    g_pin_configs[24].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME; // измеряем high time
    g_pin_configs[24].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR; // частота измеряется по rising edges
    g_pin_configs[24].pwd_complex_cfg.sample_accumulation_count = 8; // накапливаем 8 samples
    g_pin_configs[24].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K; // pull-up 10k
    g_pin_configs[24].pwd_complex_cfg.complex_safety_settings = NULL; // не safety critical

    // ADC конфигурация (дополнительная)
    g_pin_configs[24].adc_cfg.pin_channel = IO_ADC_24;
    g_pin_configs[24].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[24].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[24].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[24].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[24].adc_cfg.safety_settings = NULL;

    // Digital Input конфигурация
    g_pin_configs[24].di_cfg.pin_channel = IO_DI_36;
    g_pin_configs[24].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[24].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_139 (Internal 25)
     * IO_PWD_01 (Complex mode)
     * IO_ADC_25
     * IO_DI_37
     * ===========================
     */
    g_pin_configs[25].pwd_complex_cfg.pin_channel = IO_PWD_01;
    g_pin_configs[25].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[25].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[25].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[25].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[25].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[25].adc_cfg.pin_channel = IO_ADC_25;
    g_pin_configs[25].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[25].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[25].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[25].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[25].adc_cfg.safety_settings = NULL;

    g_pin_configs[25].di_cfg.pin_channel = IO_DI_37;
    g_pin_configs[25].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[25].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_116 (Internal 26)
     * IO_PWD_02 (Complex mode)
     * IO_ADC_26
     * IO_DI_38
     * ===========================
     */
    g_pin_configs[26].pwd_complex_cfg.pin_channel = IO_PWD_02;
    g_pin_configs[26].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[26].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[26].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[26].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[26].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[26].adc_cfg.pin_channel = IO_ADC_26;
    g_pin_configs[26].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[26].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[26].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[26].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[26].adc_cfg.safety_settings = NULL;

    g_pin_configs[26].di_cfg.pin_channel = IO_DI_38;
    g_pin_configs[26].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[26].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_140 (Internal 27)
     * IO_PWD_03 (Complex mode)
     * IO_ADC_27
     * IO_DI_39
     * ===========================
     */
    g_pin_configs[27].pwd_complex_cfg.pin_channel = IO_PWD_03;
    g_pin_configs[27].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[27].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[27].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[27].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[27].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[27].adc_cfg.pin_channel = IO_ADC_27;
    g_pin_configs[27].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[27].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[27].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[27].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[27].adc_cfg.safety_settings = NULL;

    g_pin_configs[27].di_cfg.pin_channel = IO_DI_39;
    g_pin_configs[27].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[27].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_117 (Internal 28)
     * IO_PWD_04 (Complex mode)
     * IO_ADC_28
     * IO_DI_40
     * ===========================
     */
    g_pin_configs[28].pwd_complex_cfg.pin_channel = IO_PWD_04;
    g_pin_configs[28].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[28].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[28].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[28].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[28].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[28].adc_cfg.pin_channel = IO_ADC_28;
    g_pin_configs[28].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[28].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[28].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[28].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[28].adc_cfg.safety_settings = NULL;

    g_pin_configs[28].di_cfg.pin_channel = IO_DI_40;
    g_pin_configs[28].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[28].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_141 (Internal 29)
     * IO_PWD_05 (Complex mode)
     * IO_ADC_29
     * IO_DI_41
     * ===========================
     */
    g_pin_configs[29].pwd_complex_cfg.pin_channel = IO_PWD_05;
    g_pin_configs[29].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[29].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[29].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[29].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[29].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[29].adc_cfg.pin_channel = IO_ADC_29;
    g_pin_configs[29].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[29].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[29].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[29].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[29].adc_cfg.safety_settings = NULL;

    g_pin_configs[29].di_cfg.pin_channel = IO_DI_41;
    g_pin_configs[29].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[29].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_122 (Internal 30)
     * IO_PWD_06 (Complex mode)
     * IO_ADC_30
     * IO_DI_42
     * ===========================
     */
    g_pin_configs[30].pwd_complex_cfg.pin_channel = IO_PWD_06;
    g_pin_configs[30].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[30].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[30].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[30].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[30].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[30].adc_cfg.pin_channel = IO_ADC_30;
    g_pin_configs[30].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[30].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[30].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[30].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[30].adc_cfg.safety_settings = NULL;

    g_pin_configs[30].di_cfg.pin_channel = IO_DI_42;
    g_pin_configs[30].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[30].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_146 (Internal 31)
     * IO_PWD_07 (Complex mode)
     * IO_ADC_31
     * IO_DI_43
     * ===========================
     */
    g_pin_configs[31].pwd_complex_cfg.pin_channel = IO_PWD_07;
    g_pin_configs[31].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[31].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[31].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[31].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[31].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[31].adc_cfg.pin_channel = IO_ADC_31;
    g_pin_configs[31].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[31].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[31].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[31].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[31].adc_cfg.safety_settings = NULL;

    g_pin_configs[31].di_cfg.pin_channel = IO_DI_43;
    g_pin_configs[31].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[31].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_123 (Internal 32)
     * IO_PWD_08 (Complex mode)
     * IO_ADC_32
     * IO_DI_44
     * ===========================
     */
    g_pin_configs[32].pwd_complex_cfg.pin_channel = IO_PWD_08;
    g_pin_configs[32].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[32].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[32].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[32].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[32].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[32].adc_cfg.pin_channel = IO_ADC_32;
    g_pin_configs[32].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[32].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[32].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[32].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[32].adc_cfg.safety_settings = NULL;

    g_pin_configs[32].di_cfg.pin_channel = IO_DI_44;
    g_pin_configs[32].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[32].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_147 (Internal 33)
     * IO_PWD_09 (Complex mode)
     * IO_ADC_33
     * IO_DI_45
     * ===========================
     */
    g_pin_configs[33].pwd_complex_cfg.pin_channel = IO_PWD_09;
    g_pin_configs[33].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[33].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[33].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[33].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[33].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[33].adc_cfg.pin_channel = IO_ADC_33;
    g_pin_configs[33].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[33].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[33].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[33].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[33].adc_cfg.safety_settings = NULL;

    g_pin_configs[33].di_cfg.pin_channel = IO_DI_45;
    g_pin_configs[33].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[33].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_124 (Internal 34)
     * IO_PWD_10 (Complex mode)
     * IO_ADC_34
     * IO_DI_46
     * ===========================
     */
    g_pin_configs[34].pwd_complex_cfg.pin_channel = IO_PWD_10;
    g_pin_configs[34].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[34].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[34].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[34].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[34].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[34].adc_cfg.pin_channel = IO_ADC_34;
    g_pin_configs[34].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[34].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[34].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[34].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[34].adc_cfg.safety_settings = NULL;

    g_pin_configs[34].di_cfg.pin_channel = IO_DI_46;
    g_pin_configs[34].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[34].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_148 (Internal 35)
     * IO_PWD_11 (Complex mode)
     * IO_ADC_35
     * IO_DI_47
     * ===========================
     */
    g_pin_configs[35].pwd_complex_cfg.pin_channel = IO_PWD_11;
    g_pin_configs[35].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[35].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[35].pwd_complex_cfg.sample_accumulation_count = 8;
    g_pin_configs[35].pwd_complex_cfg.pull_resistor = IO_PWD_PU_10K;
    g_pin_configs[35].pwd_complex_cfg.complex_safety_settings = NULL;

    g_pin_configs[35].adc_cfg.pin_channel = IO_ADC_35;
    g_pin_configs[35].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[35].adc_cfg.voltage_range = IO_ADC_RANGE_32V;
    g_pin_configs[35].adc_cfg.pull_resistor = IO_ADC_NO_PULL;
    g_pin_configs[35].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[35].adc_cfg.safety_settings = NULL;

    g_pin_configs[35].di_cfg.pin_channel = IO_DI_47;
    g_pin_configs[35].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[35].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_149 (Internal 36)
     * IO_DO_00 (Complex mode)
     * IO_ADC_36
     * IO_DI_72
     * ===========================
     */
    g_pin_configs[36].adc_cfg.pin_channel = IO_ADC_36;
    g_pin_configs[36].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[36].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[36].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[36].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[36].adc_cfg.safety_settings = NULL;

    g_pin_configs[36].di_cfg.pin_channel = IO_DI_72;
    g_pin_configs[36].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[36].di_cfg.voltage_limits = NULL;

    g_pin_configs[36].do_cfg.pin_channel = IO_DO_00;
    g_pin_configs[36].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[36].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_173 (Internal 37)
     * IO_DO_01
     * IO_ADC_37
     * IO_DI_73
     * ===========================
     */
    g_pin_configs[37].adc_cfg.pin_channel = IO_ADC_37;
    g_pin_configs[37].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[37].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[37].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[37].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[37].adc_cfg.safety_settings = NULL;

    g_pin_configs[37].di_cfg.pin_channel = IO_DI_73;
    g_pin_configs[37].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[37].di_cfg.voltage_limits = NULL;

    g_pin_configs[37].do_cfg.pin_channel = IO_DO_01;
    g_pin_configs[37].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[37].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_152 (Internal 38)
     * IO_DO_02
     * IO_ADC_38
     * IO_DI_74
     * ===========================
     */
    g_pin_configs[38].adc_cfg.pin_channel = IO_ADC_38;
    g_pin_configs[38].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[38].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[38].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[38].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[38].adc_cfg.safety_settings = NULL;

    g_pin_configs[38].di_cfg.pin_channel = IO_DI_74;
    g_pin_configs[38].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[38].di_cfg.voltage_limits = NULL;

    g_pin_configs[38].do_cfg.pin_channel = IO_DO_02;
    g_pin_configs[38].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[38].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_176 (Internal 39)
     * IO_DO_03
     * IO_ADC_39
     * IO_DI_75
     * ===========================
     */
    g_pin_configs[39].adc_cfg.pin_channel = IO_ADC_39;
    g_pin_configs[39].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[39].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[39].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[39].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[39].adc_cfg.safety_settings = NULL;

    g_pin_configs[39].di_cfg.pin_channel = IO_DI_75;
    g_pin_configs[39].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[39].di_cfg.voltage_limits = NULL;

    g_pin_configs[39].do_cfg.pin_channel = IO_DO_03;
    g_pin_configs[39].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[39].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_155 (Internal 40)
     * IO_DO_04
     * IO_ADC_40
     * IO_DI_76
     * ===========================
     */
    g_pin_configs[40].adc_cfg.pin_channel = IO_ADC_40;
    g_pin_configs[40].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[40].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[40].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[40].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[40].adc_cfg.safety_settings = NULL;

    g_pin_configs[40].di_cfg.pin_channel = IO_DI_76;
    g_pin_configs[40].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[40].di_cfg.voltage_limits = NULL;

    g_pin_configs[40].do_cfg.pin_channel = IO_DO_04;
    g_pin_configs[40].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[40].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_179 (Internal 41)
     * IO_DO_05
     * IO_ADC_41
     * IO_DI_77
     * ===========================
     */
    g_pin_configs[41].adc_cfg.pin_channel = IO_ADC_41;
    g_pin_configs[41].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[41].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[41].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[41].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[41].adc_cfg.safety_settings = NULL;

    g_pin_configs[41].di_cfg.pin_channel = IO_DI_77;
    g_pin_configs[41].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[41].di_cfg.voltage_limits = NULL;

    g_pin_configs[41].do_cfg.pin_channel = IO_DO_05;
    g_pin_configs[41].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[41].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_158 (Internal 42)
     * IO_DO_06
     * IO_ADC_42
     * IO_DI_78
     * ===========================
     */
    g_pin_configs[42].adc_cfg.pin_channel = IO_ADC_42;
    g_pin_configs[42].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[42].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[42].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[42].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[42].adc_cfg.safety_settings = NULL;

    g_pin_configs[42].di_cfg.pin_channel = IO_DI_78;
    g_pin_configs[42].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[42].di_cfg.voltage_limits = NULL;

    g_pin_configs[42].do_cfg.pin_channel = IO_DO_06;
    g_pin_configs[42].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[42].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_182 (Internal 43)
     * IO_DO_07
     * IO_ADC_43
     * IO_DI_79
     * ===========================
     */
    g_pin_configs[43].adc_cfg.pin_channel = IO_ADC_43;
    g_pin_configs[43].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[43].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[43].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[43].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[43].adc_cfg.safety_settings = NULL;

    g_pin_configs[43].di_cfg.pin_channel = IO_DI_79;
    g_pin_configs[43].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[43].di_cfg.voltage_limits = NULL;

    g_pin_configs[43].do_cfg.pin_channel = IO_DO_07;
    g_pin_configs[43].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[43].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_251 (Internal 44)
     * IO_DO_08
     * IO_ADC_44
     * IO_DI_80
     * ===========================
     */
    g_pin_configs[44].adc_cfg.pin_channel = IO_ADC_44;
    g_pin_configs[44].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[44].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[44].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[44].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[44].adc_cfg.safety_settings = NULL;

    g_pin_configs[44].di_cfg.pin_channel = IO_DI_80;
    g_pin_configs[44].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[44].di_cfg.voltage_limits = NULL;

    g_pin_configs[44].do_cfg.pin_channel = IO_DO_08;
    g_pin_configs[44].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[44].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_238 (Internal 45)
     * IO_DO_09
     * IO_ADC_45
     * IO_DI_81
     * ===========================
     */
    g_pin_configs[45].adc_cfg.pin_channel = IO_ADC_45;
    g_pin_configs[45].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[45].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[45].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[45].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[45].adc_cfg.safety_settings = NULL;

    g_pin_configs[45].di_cfg.pin_channel = IO_DI_81;
    g_pin_configs[45].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[45].di_cfg.voltage_limits = NULL;

    g_pin_configs[45].do_cfg.pin_channel = IO_DO_09;
    g_pin_configs[45].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[45].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_252 (Internal 46)
     * IO_DO_10
     * IO_ADC_46
     * IO_DI_82
     * ===========================
     */
    g_pin_configs[46].adc_cfg.pin_channel = IO_ADC_46;
    g_pin_configs[46].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[46].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[46].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[46].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[46].adc_cfg.safety_settings = NULL;

    g_pin_configs[46].di_cfg.pin_channel = IO_DI_82;
    g_pin_configs[46].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[46].di_cfg.voltage_limits = NULL;

    g_pin_configs[46].do_cfg.pin_channel = IO_DO_10;
    g_pin_configs[46].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[46].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_239 (Internal 47)
     * IO_DO_11
     * IO_ADC_47
     * IO_DI_83
     * ===========================
     */
    g_pin_configs[47].adc_cfg.pin_channel = IO_ADC_47;
    g_pin_configs[47].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[47].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[47].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[47].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[47].adc_cfg.safety_settings = NULL;

    g_pin_configs[47].di_cfg.pin_channel = IO_DI_83;
    g_pin_configs[47].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[47].di_cfg.voltage_limits = NULL;

    g_pin_configs[47].do_cfg.pin_channel = IO_DO_11;
    g_pin_configs[47].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[47].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_253 (Internal 48)
     * IO_DO_12
     * IO_ADC_48
     * IO_DI_84
     * ===========================
     */
    g_pin_configs[48].adc_cfg.pin_channel = IO_ADC_48;
    g_pin_configs[48].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[48].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[48].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[48].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[48].adc_cfg.safety_settings = NULL;

    g_pin_configs[48].di_cfg.pin_channel = IO_DI_84;
    g_pin_configs[48].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[48].di_cfg.voltage_limits = NULL;

    g_pin_configs[48].do_cfg.pin_channel = IO_DO_12;
    g_pin_configs[48].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[48].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_240 (Internal 49)
     * IO_DO_13
     * IO_ADC_49
     * IO_DI_85
     * ===========================
     */
    g_pin_configs[49].adc_cfg.pin_channel = IO_ADC_49;
    g_pin_configs[49].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[49].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[49].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[49].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[49].adc_cfg.safety_settings = NULL;

    g_pin_configs[49].di_cfg.pin_channel = IO_DI_85;
    g_pin_configs[49].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[49].di_cfg.voltage_limits = NULL;

    g_pin_configs[49].do_cfg.pin_channel = IO_DO_13;
    g_pin_configs[49].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[49].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_254 (Internal 50)
     * IO_DO_14
     * IO_ADC_50
     * IO_DI_86
     * ===========================
     */
    g_pin_configs[50].adc_cfg.pin_channel = IO_ADC_50;
    g_pin_configs[50].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[50].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[50].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[50].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[50].adc_cfg.safety_settings = NULL;

    g_pin_configs[50].di_cfg.pin_channel = IO_DI_86;
    g_pin_configs[50].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[50].di_cfg.voltage_limits = NULL;

    g_pin_configs[50].do_cfg.pin_channel = IO_DO_14;
    g_pin_configs[50].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[50].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_241 (Internal 51)
     * IO_DO_15
     * IO_ADC_51
     * IO_DI_87
     * ===========================
     */
    g_pin_configs[51].adc_cfg.pin_channel = IO_ADC_51;
    g_pin_configs[51].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[51].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[51].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[51].adc_cfg.supply_source = IO_SENSOR_SUPPLY_0;
    g_pin_configs[51].adc_cfg.safety_settings = NULL;

    g_pin_configs[51].di_cfg.pin_channel = IO_DI_87;
    g_pin_configs[51].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[51].di_cfg.voltage_limits = NULL;

    g_pin_configs[51].do_cfg.pin_channel = IO_DO_15;
    g_pin_configs[51].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[51].do_cfg.safety_settings = NULL;

    /*============================
     * IO_PIN_153 (Internal 52)
     * IO_PWM_00
     * IO_DO_16
     * IO_DI_00
     * ===========================
     */
    g_pin_configs[52].pwm_cfg.pin_channel = IO_PWM_00;
    g_pin_configs[52].pwm_cfg.target_frequency = 100;
    g_pin_configs[52].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[52].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[52].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[52].pwm_cfg.safety_settings = NULL;

    g_pin_configs[52].do_cfg.pin_channel = IO_DO_16;
    g_pin_configs[52].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[52].do_cfg.safety_settings = NULL;

    g_pin_configs[52].di_cfg.pin_channel = IO_DI_00;
    g_pin_configs[52].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[52].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_177 (Internal 53)
     * IO_PWM_01
     * IO_DO_17
     * IO_DI_01
     * ===========================
     */
    g_pin_configs[53].pwm_cfg.pin_channel = IO_PWM_01;
    g_pin_configs[53].pwm_cfg.target_frequency = 100;
    g_pin_configs[53].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[53].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[53].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[53].pwm_cfg.safety_settings = NULL;

    g_pin_configs[53].do_cfg.pin_channel = IO_DO_17;
    g_pin_configs[53].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[53].do_cfg.safety_settings = NULL;

    g_pin_configs[53].di_cfg.pin_channel = IO_DI_01;
    g_pin_configs[53].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[53].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_156 (Internal 54)
     * IO_PWM_02
     * IO_DO_18
     * IO_DI_02
     * ===========================
     */
    g_pin_configs[54].pwm_cfg.pin_channel = IO_PWM_02;
    g_pin_configs[54].pwm_cfg.target_frequency = 100;
    g_pin_configs[54].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[54].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[54].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[54].pwm_cfg.safety_settings = NULL;

    g_pin_configs[54].do_cfg.pin_channel = IO_DO_18;
    g_pin_configs[54].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[54].do_cfg.safety_settings = NULL;

    g_pin_configs[54].di_cfg.pin_channel = IO_DI_02;
    g_pin_configs[54].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[54].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_180 (Internal 55)
     * IO_PWM_03
     * IO_DO_19
     * IO_DI_03
     * ===========================
     */
    g_pin_configs[55].pwm_cfg.pin_channel = IO_PWM_03;
    g_pin_configs[55].pwm_cfg.target_frequency = 100;
    g_pin_configs[55].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[55].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[55].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[55].pwm_cfg.safety_settings = NULL;

    g_pin_configs[55].do_cfg.pin_channel = IO_DO_19;
    g_pin_configs[55].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[55].do_cfg.safety_settings = NULL;

    g_pin_configs[55].di_cfg.pin_channel = IO_DI_03;
    g_pin_configs[55].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[55].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_159 (Internal 56)
     * IO_PWM_04
     * IO_DO_20
     * IO_DI_04
     * ===========================
     */
    g_pin_configs[56].pwm_cfg.pin_channel = IO_PWM_04;
    g_pin_configs[56].pwm_cfg.target_frequency = 100;
    g_pin_configs[56].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[56].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[56].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[56].pwm_cfg.safety_settings = NULL;

    g_pin_configs[56].do_cfg.pin_channel = IO_DO_20;
    g_pin_configs[56].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[56].do_cfg.safety_settings = NULL;

    g_pin_configs[56].di_cfg.pin_channel = IO_DI_04;
    g_pin_configs[56].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[56].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_183 (Internal 57)
     * IO_PWM_05
     * IO_DO_21
     * IO_DI_05
     * ===========================
     */
    g_pin_configs[57].pwm_cfg.pin_channel = IO_PWM_05;
    g_pin_configs[57].pwm_cfg.target_frequency = 100;
    g_pin_configs[57].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[57].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[57].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[57].pwm_cfg.safety_settings = NULL;

    g_pin_configs[57].do_cfg.pin_channel = IO_DO_21;
    g_pin_configs[57].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[57].do_cfg.safety_settings = NULL;

    g_pin_configs[57].di_cfg.pin_channel = IO_DI_05;
    g_pin_configs[57].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[57].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_186 (Internal 58)
     * IO_PWM_06
     * IO_DO_22
     * IO_DI_06
     * ===========================
     */
    g_pin_configs[58].pwm_cfg.pin_channel = IO_PWM_06;
    g_pin_configs[58].pwm_cfg.target_frequency = 100;
    g_pin_configs[58].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[58].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[58].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[58].pwm_cfg.safety_settings = NULL;

    g_pin_configs[58].do_cfg.pin_channel = IO_DO_22;
    g_pin_configs[58].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[58].do_cfg.safety_settings = NULL;

    g_pin_configs[58].di_cfg.pin_channel = IO_DI_06;
    g_pin_configs[58].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[58].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_162 (Internal 59)
     * IO_PWM_07
     * IO_DO_23
     * IO_DI_07
     * ===========================
     */
    g_pin_configs[59].pwm_cfg.pin_channel = IO_PWM_07;
    g_pin_configs[59].pwm_cfg.target_frequency = 100;
    g_pin_configs[59].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[59].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[59].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[59].pwm_cfg.safety_settings = NULL;

    g_pin_configs[59].do_cfg.pin_channel = IO_DO_23;
    g_pin_configs[59].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[59].do_cfg.safety_settings = NULL;

    g_pin_configs[59].di_cfg.pin_channel = IO_DI_07;
    g_pin_configs[59].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[59].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_189 (Internal 60)
     * IO_PWM_08
     * IO_DO_24
     * IO_DI_08
     * ===========================
     */
    g_pin_configs[60].pwm_cfg.pin_channel = IO_PWM_08;
    g_pin_configs[60].pwm_cfg.target_frequency = 100;
    g_pin_configs[60].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[60].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[60].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[60].pwm_cfg.safety_settings = NULL;

    g_pin_configs[60].do_cfg.pin_channel = IO_DO_24;
    g_pin_configs[60].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[60].do_cfg.safety_settings = NULL;

    g_pin_configs[60].di_cfg.pin_channel = IO_DI_08;
    g_pin_configs[60].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[60].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_165 (Internal 61)
     * IO_PWM_09
     * IO_DO_25
     * IO_DI_09
     * ===========================
     */
    g_pin_configs[61].pwm_cfg.pin_channel = IO_PWM_09;
    g_pin_configs[61].pwm_cfg.target_frequency = 100;
    g_pin_configs[61].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[61].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[61].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[61].pwm_cfg.safety_settings = NULL;

    g_pin_configs[61].do_cfg.pin_channel = IO_DO_25;
    g_pin_configs[61].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[61].do_cfg.safety_settings = NULL;

    g_pin_configs[61].di_cfg.pin_channel = IO_DI_09;
    g_pin_configs[61].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[61].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_192 (Internal 62)
     * IO_PWM_10
     * IO_DO_26
     * IO_DI_10
     * ===========================
     */
    g_pin_configs[62].pwm_cfg.pin_channel = IO_PWM_10;
    g_pin_configs[62].pwm_cfg.target_frequency = 100;
    g_pin_configs[62].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[62].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[62].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[62].pwm_cfg.safety_settings = NULL;

    g_pin_configs[62].do_cfg.pin_channel = IO_DO_26;
    g_pin_configs[62].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[62].do_cfg.safety_settings = NULL;

    g_pin_configs[62].di_cfg.pin_channel = IO_DI_10;
    g_pin_configs[62].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[62].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_168 (Internal 63)
     * IO_PWM_11
     * IO_DO_27
     * IO_DI_11
     * ===========================
     */
    g_pin_configs[63].pwm_cfg.pin_channel = IO_PWM_11;
    g_pin_configs[63].pwm_cfg.target_frequency = 100;
    g_pin_configs[63].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[63].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[63].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[63].pwm_cfg.safety_settings = NULL;

    g_pin_configs[63].do_cfg.pin_channel = IO_DO_27;
    g_pin_configs[63].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[63].do_cfg.safety_settings = NULL;

    g_pin_configs[63].di_cfg.pin_channel = IO_DI_11;
    g_pin_configs[63].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[63].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_195 (Internal 64)
     * IO_PWM_12
     * IO_DO_28
     * IO_DI_12
     * ===========================
     */
    g_pin_configs[64].pwm_cfg.pin_channel = IO_PWM_12;
    g_pin_configs[64].pwm_cfg.target_frequency = 100;
    g_pin_configs[64].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[64].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[64].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[64].pwm_cfg.safety_settings = NULL;

    g_pin_configs[64].do_cfg.pin_channel = IO_DO_28;
    g_pin_configs[64].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[64].do_cfg.safety_settings = NULL;

    g_pin_configs[64].di_cfg.pin_channel = IO_DI_12;
    g_pin_configs[64].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[64].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_171 (Internal 65)
     * IO_PWM_13
     * IO_DO_29
     * IO_DI_13
     * ===========================
     */
    g_pin_configs[65].pwm_cfg.pin_channel = IO_PWM_13;
    g_pin_configs[65].pwm_cfg.target_frequency = 100;
    g_pin_configs[65].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[65].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[65].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[65].pwm_cfg.safety_settings = NULL;

    g_pin_configs[65].do_cfg.pin_channel = IO_DO_29;
    g_pin_configs[65].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[65].do_cfg.safety_settings = NULL;

    g_pin_configs[65].di_cfg.pin_channel = IO_DI_13;
    g_pin_configs[65].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[65].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_154 (Internal 66)
     * IO_PWM_14
     * IO_DO_30
     * IO_DI_14
     * ===========================
     */
    g_pin_configs[66].pwm_cfg.pin_channel = IO_PWM_14;
    g_pin_configs[66].pwm_cfg.target_frequency = 100;
    g_pin_configs[66].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[66].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[66].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[66].pwm_cfg.safety_settings = NULL;

    g_pin_configs[66].do_cfg.pin_channel = IO_DO_30;
    g_pin_configs[66].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[66].do_cfg.safety_settings = NULL;

    g_pin_configs[66].di_cfg.pin_channel = IO_DI_14;
    g_pin_configs[66].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[66].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_178 (Internal 67)
     * IO_PWM_15
     * IO_DO_31
     * IO_DI_15
     * ===========================
     */
    g_pin_configs[67].pwm_cfg.pin_channel = IO_PWM_15;
    g_pin_configs[67].pwm_cfg.target_frequency = 100;
    g_pin_configs[67].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[67].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[67].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[67].pwm_cfg.safety_settings = NULL;

    g_pin_configs[67].do_cfg.pin_channel = IO_DO_31;
    g_pin_configs[67].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[67].do_cfg.safety_settings = NULL;

    g_pin_configs[67].di_cfg.pin_channel = IO_DI_15;
    g_pin_configs[67].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[67].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_157 (Internal 68)
     * IO_PWM_16
     * IO_DO_32
     * IO_DI_16
     * ===========================
     */
    g_pin_configs[68].pwm_cfg.pin_channel = IO_PWM_16;
    g_pin_configs[68].pwm_cfg.target_frequency = 100;
    g_pin_configs[68].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[68].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[68].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[68].pwm_cfg.safety_settings = NULL;

    g_pin_configs[68].do_cfg.pin_channel = IO_DO_32;
    g_pin_configs[68].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[68].do_cfg.safety_settings = NULL;

    g_pin_configs[68].di_cfg.pin_channel = IO_DI_16;
    g_pin_configs[68].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[68].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_181 (Internal 69)
     * IO_PWM_17
     * IO_DO_33
     * IO_DI_17
     * ===========================
     */
    g_pin_configs[69].pwm_cfg.pin_channel = IO_PWM_17;
    g_pin_configs[69].pwm_cfg.target_frequency = 100;
    g_pin_configs[69].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[69].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[69].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[69].pwm_cfg.safety_settings = NULL;

    g_pin_configs[69].do_cfg.pin_channel = IO_DO_33;
    g_pin_configs[69].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[69].do_cfg.safety_settings = NULL;

    g_pin_configs[69].di_cfg.pin_channel = IO_DI_17;
    g_pin_configs[69].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[69].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_160 (Internal 70)
     * IO_PWM_18
     * IO_DO_34
     * IO_DI_18
     * ===========================
     */
    g_pin_configs[70].pwm_cfg.pin_channel = IO_PWM_18;
    g_pin_configs[70].pwm_cfg.target_frequency = 100;
    g_pin_configs[70].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[70].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[70].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[70].pwm_cfg.safety_settings = NULL;

    g_pin_configs[70].do_cfg.pin_channel = IO_DO_34;
    g_pin_configs[70].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[70].do_cfg.safety_settings = NULL;

    g_pin_configs[70].di_cfg.pin_channel = IO_DI_18;
    g_pin_configs[70].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[70].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_184 (Internal 71)
     * IO_PWM_19
     * IO_DO_35
     * IO_DI_19
     * ===========================
     */
    g_pin_configs[71].pwm_cfg.pin_channel = IO_PWM_19;
    g_pin_configs[71].pwm_cfg.target_frequency = 100;
    g_pin_configs[71].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[71].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[71].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[71].pwm_cfg.safety_settings = NULL;

    g_pin_configs[71].do_cfg.pin_channel = IO_DO_35;
    g_pin_configs[71].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[71].do_cfg.safety_settings = NULL;

    g_pin_configs[71].di_cfg.pin_channel = IO_DI_19;
    g_pin_configs[71].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[71].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_187 (Internal 72)
     * IO_PWM_20
     * IO_DO_36
     * IO_DI_20
     * ===========================
     */
    g_pin_configs[72].pwm_cfg.pin_channel = IO_PWM_20;
    g_pin_configs[72].pwm_cfg.target_frequency = 100;
    g_pin_configs[72].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[72].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[72].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[72].pwm_cfg.safety_settings = NULL;

    g_pin_configs[72].do_cfg.pin_channel = IO_DO_36;
    g_pin_configs[72].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[72].do_cfg.safety_settings = NULL;

    g_pin_configs[72].di_cfg.pin_channel = IO_DI_20;
    g_pin_configs[72].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[72].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_163 (Internal 73)
     * IO_PWM_21
     * IO_DO_37
     * IO_DI_21
     * ===========================
     */
    g_pin_configs[73].pwm_cfg.pin_channel = IO_PWM_21;
    g_pin_configs[73].pwm_cfg.target_frequency = 100;
    g_pin_configs[73].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[73].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[73].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[73].pwm_cfg.safety_settings = NULL;

    g_pin_configs[73].do_cfg.pin_channel = IO_DO_37;
    g_pin_configs[73].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[73].do_cfg.safety_settings = NULL;

    g_pin_configs[73].di_cfg.pin_channel = IO_DI_21;
    g_pin_configs[73].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[73].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_190 (Internal 74)
     * IO_PWM_22
     * IO_DO_38
     * IO_DI_22
     * ===========================
     */
    g_pin_configs[74].pwm_cfg.pin_channel = IO_PWM_22;
    g_pin_configs[74].pwm_cfg.target_frequency = 100;
    g_pin_configs[74].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[74].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[74].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[74].pwm_cfg.safety_settings = NULL;

    g_pin_configs[74].do_cfg.pin_channel = IO_DO_38;
    g_pin_configs[74].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[74].do_cfg.safety_settings = NULL;

    g_pin_configs[74].di_cfg.pin_channel = IO_DI_22;
    g_pin_configs[74].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[74].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_166 (Internal 75)
     * IO_PWM_23
     * IO_DO_39
     * IO_DI_23
     * ===========================
     */
    g_pin_configs[75].pwm_cfg.pin_channel = IO_PWM_23;
    g_pin_configs[75].pwm_cfg.target_frequency = 100;
    g_pin_configs[75].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[75].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[75].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[75].pwm_cfg.safety_settings = NULL;

    g_pin_configs[75].do_cfg.pin_channel = IO_DO_39;
    g_pin_configs[75].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[75].do_cfg.safety_settings = NULL;

    g_pin_configs[75].di_cfg.pin_channel = IO_DI_23;
    g_pin_configs[75].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[75].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_193 (Internal 76)
     * IO_PWM_24
     * IO_DO_40
     * IO_DI_24
     * ===========================
     */
    g_pin_configs[76].pwm_cfg.pin_channel = IO_PWM_24;
    g_pin_configs[76].pwm_cfg.target_frequency = 100;
    g_pin_configs[76].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[76].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[76].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[76].pwm_cfg.safety_settings = NULL;

    g_pin_configs[76].do_cfg.pin_channel = IO_DO_40;
    g_pin_configs[76].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[76].do_cfg.safety_settings = NULL;

    g_pin_configs[76].di_cfg.pin_channel = IO_DI_24;
    g_pin_configs[76].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[76].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_169 (Internal 77)
     * IO_PWM_25
     * IO_DO_41
     * IO_DI_25
     * ===========================
     */
    g_pin_configs[77].pwm_cfg.pin_channel = IO_PWM_25;
    g_pin_configs[77].pwm_cfg.target_frequency = 100;
    g_pin_configs[77].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[77].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[77].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[77].pwm_cfg.safety_settings = NULL;

    g_pin_configs[77].do_cfg.pin_channel = IO_DO_41;
    g_pin_configs[77].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[77].do_cfg.safety_settings = NULL;

    g_pin_configs[77].di_cfg.pin_channel = IO_DI_25;
    g_pin_configs[77].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[77].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_196 (Internal 78)
     * IO_PWM_26
     * IO_DO_42
     * IO_DI_26
     * ===========================
     */
    g_pin_configs[78].pwm_cfg.pin_channel = IO_PWM_26;
    g_pin_configs[78].pwm_cfg.target_frequency = 100;
    g_pin_configs[78].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[78].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[78].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[78].pwm_cfg.safety_settings = NULL;

    g_pin_configs[78].do_cfg.pin_channel = IO_DO_42;
    g_pin_configs[78].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[78].do_cfg.safety_settings = NULL;

    g_pin_configs[78].di_cfg.pin_channel = IO_DI_26;
    g_pin_configs[78].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[78].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_172 (Internal 79)
     * IO_PWM_27
     * IO_DO_43
     * IO_DI_27
     * ===========================
     */
    g_pin_configs[79].pwm_cfg.pin_channel = IO_PWM_27;
    g_pin_configs[79].pwm_cfg.target_frequency = 100;
    g_pin_configs[79].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[79].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[79].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[79].pwm_cfg.safety_settings = NULL;

    g_pin_configs[79].do_cfg.pin_channel = IO_DO_43;
    g_pin_configs[79].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[79].do_cfg.safety_settings = NULL;

    g_pin_configs[79].di_cfg.pin_channel = IO_DI_27;
    g_pin_configs[79].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[79].di_cfg.voltage_limits = NULL;

    /*============================
     * IO_PIN_101 (Internal 80)
     * IO_PWM_28
     * IO_DO_44
     * IO_DI_28, IO_PWD_12
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[80].pwm_cfg.pin_channel = IO_PWM_28;
    g_pin_configs[80].pwm_cfg.target_frequency = 100;
    g_pin_configs[80].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[80].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[80].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[80].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[80].do_cfg.pin_channel = IO_DO_44;
    g_pin_configs[80].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[80].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[80].di_cfg.pin_channel = IO_DI_28;
    g_pin_configs[80].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[80].di_cfg.voltage_limits = NULL;

    // PWD конфигурация (Complex mode, только для IO_PWD_12..19)
    g_pin_configs[80].pwd_complex_cfg.pin_channel = IO_PWD_12;
    g_pin_configs[80].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[80].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[80].pwd_complex_cfg.sample_accumulation_count = 1; // Игнорируется для PWD_12..19
    g_pin_configs[80].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[80].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_125 (Internal 81)
     * IO_PWM_29
     * IO_DO_45
     * IO_DI_29
     * IO_PWD_13
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[81].pwm_cfg.pin_channel = IO_PWM_29;
    g_pin_configs[81].pwm_cfg.target_frequency = 100;
    g_pin_configs[81].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[81].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[81].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[81].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[81].do_cfg.pin_channel = IO_DO_45;
    g_pin_configs[81].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[81].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[81].di_cfg.pin_channel = IO_DI_29;
    g_pin_configs[81].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[81].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[81].pwd_complex_cfg.pin_channel = IO_PWD_13;
    g_pin_configs[81].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[81].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[81].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[81].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[81].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_150 (Internal 82)
     * IO_PWM_30
     * IO_DO_46
     * IO_DI_30
     * IO_PWD_14
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[82].pwm_cfg.pin_channel = IO_PWM_30;
    g_pin_configs[82].pwm_cfg.target_frequency = 100;
    g_pin_configs[82].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[82].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[82].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[82].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[82].do_cfg.pin_channel = IO_DO_46;
    g_pin_configs[82].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[82].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[82].di_cfg.pin_channel = IO_DI_30;
    g_pin_configs[82].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[82].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[82].pwd_complex_cfg.pin_channel = IO_PWD_14;
    g_pin_configs[82].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[82].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[82].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[82].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[82].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_174 (Internal 83)
     * IO_PWM_31
     * IO_DO_47
     * IO_DI_31
     * IO_PWD_15
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[83].pwm_cfg.pin_channel = IO_PWM_31;
    g_pin_configs[83].pwm_cfg.target_frequency = 100;
    g_pin_configs[83].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[83].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[83].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[83].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[83].do_cfg.pin_channel = IO_DO_47;
    g_pin_configs[83].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[83].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[83].di_cfg.pin_channel = IO_DI_31;
    g_pin_configs[83].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[83].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[83].pwd_complex_cfg.pin_channel = IO_PWD_15;
    g_pin_configs[83].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[83].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[83].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[83].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[83].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_102 (Internal 84)
     * IO_PWM_32
     * IO_DO_48
     * IO_DI_32
     * IO_PWD_16
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[84].pwm_cfg.pin_channel = IO_PWM_32;
    g_pin_configs[84].pwm_cfg.target_frequency = 100;
    g_pin_configs[84].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[84].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[84].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[84].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[84].do_cfg.pin_channel = IO_DO_48;
    g_pin_configs[84].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[84].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[84].di_cfg.pin_channel = IO_DI_32;
    g_pin_configs[84].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[84].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[84].pwd_complex_cfg.pin_channel = IO_PWD_16;
    g_pin_configs[84].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[84].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[84].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[84].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[84].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_126 (Internal 85)
     * IO_PWM_33
     * IO_DO_49
     * IO_DI_33
     * IO_PWD_17
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[85].pwm_cfg.pin_channel = IO_PWM_33;
    g_pin_configs[85].pwm_cfg.target_frequency = 100;
    g_pin_configs[85].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[85].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[85].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[85].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[85].do_cfg.pin_channel = IO_DO_49;
    g_pin_configs[85].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[85].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[85].di_cfg.pin_channel = IO_DI_33;
    g_pin_configs[85].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[85].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[85].pwd_complex_cfg.pin_channel = IO_PWD_17;
    g_pin_configs[85].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[85].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[85].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[85].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[85].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_151 (Internal 86)
     * IO_PWM_34
     * IO_DO_50
     * IO_DI_34
     * IO_PWD_18
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[86].pwm_cfg.pin_channel = IO_PWM_34;
    g_pin_configs[86].pwm_cfg.target_frequency = 100;
    g_pin_configs[86].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[86].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[86].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[86].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[86].do_cfg.pin_channel = IO_DO_50;
    g_pin_configs[86].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[86].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[86].di_cfg.pin_channel = IO_DI_34;
    g_pin_configs[86].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[86].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[86].pwd_complex_cfg.pin_channel = IO_PWD_18;
    g_pin_configs[86].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[86].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[86].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[86].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[86].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_175 (Internal 87)
     * IO_PWM_35
     * IO_DO_51
     * IO_DI_35
     * IO_PWD_19
     * ===========================
     */

    // PWM конфигурация
    g_pin_configs[87].pwm_cfg.pin_channel = IO_PWM_35;
    g_pin_configs[87].pwm_cfg.target_frequency = 100;
    g_pin_configs[87].pwm_cfg.signal_polarity = TRUE;
    g_pin_configs[87].pwm_cfg.enable_diagnostic_margin = FALSE;
    g_pin_configs[87].pwm_cfg.enable_lowside_pairing = FALSE;
    g_pin_configs[87].pwm_cfg.safety_settings = NULL;

    // DO конфигурация
    g_pin_configs[87].do_cfg.pin_channel = IO_DO_51;
    g_pin_configs[87].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[87].do_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[87].di_cfg.pin_channel = IO_DI_35;
    g_pin_configs[87].di_cfg.pull_resistor = IO_DI_NO_PULL;
    g_pin_configs[87].di_cfg.voltage_limits = NULL;

    // PWD конфигурация
    g_pin_configs[87].pwd_complex_cfg.pin_channel = IO_PWD_19;
    g_pin_configs[87].pwd_complex_cfg.pulse_duration_mode = IO_PWD_HIGH_TIME;
    g_pin_configs[87].pwd_complex_cfg.frequency_edge_mode = IO_PWD_FALLING_VAR;
    g_pin_configs[87].pwd_complex_cfg.sample_accumulation_count = 1;
    g_pin_configs[87].pwd_complex_cfg.pull_resistor = IO_PWD_NO_PULL;
    g_pin_configs[87].pwd_complex_cfg.complex_safety_settings = NULL;

    /*============================
     * IO_PIN_161 (Internal 88)
     * IO_PVG_00
     * IO_VOUT_00
     * IO_DO_52
     * IO_ADC_52
     * IO_DI_88
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[88].pvg_cfg.pin_channel = IO_PVG_00;
    g_pin_configs[88].pvg_cfg.initial_percentage_value = 5000;  // 50% по умолчанию

    // VOUT конфигурация
    g_pin_configs[88].vout_cfg.pin_channel = IO_VOUT_00;
    g_pin_configs[88].vout_cfg.startup_voltage_mv = 0;  // 0V по умолчанию

    // DO конфигурация
    g_pin_configs[88].do_cfg.pin_channel = IO_DO_52;
    g_pin_configs[88].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[88].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[88].adc_cfg.pin_channel = IO_ADC_52;
    g_pin_configs[88].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[88].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[88].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[88].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[88].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[88].di_cfg.pin_channel = IO_DI_88;
    g_pin_configs[88].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[88].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_185 (Internal 89)
     * IO_PVG_01
     * IO_VOUT_01
     * IO_DO_53
     * IO_ADC_53
     * IO_DI_89
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[89].pvg_cfg.pin_channel = IO_PVG_01;
    g_pin_configs[89].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[89].vout_cfg.pin_channel = IO_VOUT_01;
    g_pin_configs[89].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[89].do_cfg.pin_channel = IO_DO_53;
    g_pin_configs[89].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[89].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[89].adc_cfg.pin_channel = IO_ADC_53;
    g_pin_configs[89].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[89].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[89].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[89].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[89].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[89].di_cfg.pin_channel = IO_DI_89;
    g_pin_configs[89].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[89].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_188 (Internal 90)
     * IO_PVG_02
     * IO_VOUT_02
     * IO_DO_54
     * IO_ADC_54
     * IO_DI_90
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[90].pvg_cfg.pin_channel = IO_PVG_02;
    g_pin_configs[90].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[90].vout_cfg.pin_channel = IO_VOUT_02;
    g_pin_configs[90].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[90].do_cfg.pin_channel = IO_DO_54;
    g_pin_configs[90].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[90].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[90].adc_cfg.pin_channel = IO_ADC_54;
    g_pin_configs[90].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[90].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[90].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[90].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[90].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[90].di_cfg.pin_channel = IO_DI_90;
    g_pin_configs[90].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[90].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_164 (Internal 91)
     * IO_PVG_03
     * IO_VOUT_03
     * IO_DO_55
     * IO_ADC_55
     * IO_DI_91
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[91].pvg_cfg.pin_channel = IO_PVG_03;
    g_pin_configs[91].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[91].vout_cfg.pin_channel = IO_VOUT_03;
    g_pin_configs[91].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[91].do_cfg.pin_channel = IO_DO_55;
    g_pin_configs[91].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[91].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[91].adc_cfg.pin_channel = IO_ADC_55;
    g_pin_configs[91].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[91].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[91].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[91].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[91].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[91].di_cfg.pin_channel = IO_DI_91;
    g_pin_configs[91].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[91].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_191 (Internal 92)
     * IO_PVG_04
     * IO_VOUT_04
     * IO_DO_56
     * IO_ADC_56
     * IO_DI_92
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[92].pvg_cfg.pin_channel = IO_PVG_04;
    g_pin_configs[92].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[92].vout_cfg.pin_channel = IO_VOUT_04;
    g_pin_configs[92].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[92].do_cfg.pin_channel = IO_DO_56;
    g_pin_configs[92].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[92].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[92].adc_cfg.pin_channel = IO_ADC_56;
    g_pin_configs[92].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[92].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[92].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[92].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[92].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[92].di_cfg.pin_channel = IO_DI_92;
    g_pin_configs[92].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[92].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_167 (Internal 93)
     * IO_PVG_05
     * IO_VOUT_05
     * IO_DO_57
     * IO_ADC_57
     * IO_DI_93
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[93].pvg_cfg.pin_channel = IO_PVG_05;
    g_pin_configs[93].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[93].vout_cfg.pin_channel = IO_VOUT_05;
    g_pin_configs[93].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[93].do_cfg.pin_channel = IO_DO_57;
    g_pin_configs[93].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[93].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[93].adc_cfg.pin_channel = IO_ADC_57;
    g_pin_configs[93].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[93].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[93].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[93].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[93].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[93].di_cfg.pin_channel = IO_DI_93;
    g_pin_configs[93].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[93].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_194 (Internal 94)
     * IO_PVG_06
     * IO_VOUT_06
     * IO_DO_58
     * IO_ADC_58
     * IO_DI_94
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[94].pvg_cfg.pin_channel = IO_PVG_06;
    g_pin_configs[94].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[94].vout_cfg.pin_channel = IO_VOUT_06;
    g_pin_configs[94].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[94].do_cfg.pin_channel = IO_DO_58;
    g_pin_configs[94].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[94].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[94].adc_cfg.pin_channel = IO_ADC_58;
    g_pin_configs[94].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[94].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[94].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[94].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[94].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[94].di_cfg.pin_channel = IO_DI_94;
    g_pin_configs[94].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[94].di_cfg.voltage_limits = &s_di_limits_default;

    /*============================
     * IO_PIN_170 (Internal 95)
     * IO_PVG_07
     * IO_VOUT_07
     * IO_DO_59
     * IO_ADC_59
     * IO_DI_95
     * ===========================
     */

    // PVG конфигурация
    g_pin_configs[95].pvg_cfg.pin_channel = IO_PVG_07;
    g_pin_configs[95].pvg_cfg.initial_percentage_value = 5000;

    // VOUT конфигурация
    g_pin_configs[95].vout_cfg.pin_channel = IO_VOUT_07;
    g_pin_configs[95].vout_cfg.startup_voltage_mv = 0;

    // DO конфигурация
    g_pin_configs[95].do_cfg.pin_channel = IO_DO_59;
    g_pin_configs[95].do_cfg.enable_diagnostics = TRUE;
    g_pin_configs[95].do_cfg.safety_settings = NULL;

    // ADC конфигурация
    g_pin_configs[95].adc_cfg.pin_channel = IO_ADC_59;
    g_pin_configs[95].adc_cfg.input_type = IO_ADC_ABSOLUTE;
    g_pin_configs[95].adc_cfg.voltage_range = IO_ADC_NO_RANGE;
    g_pin_configs[95].adc_cfg.pull_resistor = IO_ADC_PU_10K;
    g_pin_configs[95].adc_cfg.supply_source = IO_PIN_NONE;
    g_pin_configs[95].adc_cfg.safety_settings = NULL;

    // DI конфигурация
    g_pin_configs[95].di_cfg.pin_channel = IO_DI_95;
    g_pin_configs[95].di_cfg.pull_resistor = IO_DI_PU_10K;
    g_pin_configs[95].di_cfg.voltage_limits = &s_di_limits_default;
}
