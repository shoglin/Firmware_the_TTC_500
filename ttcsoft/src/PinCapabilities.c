#include "PinCapabilities.h"

// Array pins capabilities

PinCapabilities_t g_pin_capabilities[96];

void Init_PinCapabilities(void)
{
    ubyte1 i;

    // Инициализируем все элементы значением IO_PIN_NONE
    for (i = 0; i < 96; i++)
    {
        g_pin_capabilities[i].connector_pin = IO_PIN_NONE;
        g_pin_capabilities[i].internal_pin = i;

        // Очищаем все режимы
        ubyte1 mode;

        for (mode = 0; mode < PIN_MODE_COUNT; mode++)
        {
            g_pin_capabilities[i].modes[mode] = IO_PIN_NONE;
        }
    }

    // Internal pin 0 (Connector Pin 103)
    g_pin_capabilities[0].connector_pin = IO_PIN_103;
    g_pin_capabilities[0].modes[PIN_MODE_ADC] = IO_ADC_00;
    g_pin_capabilities[0].modes[PIN_MODE_DI] = IO_DI_48;

    // Internal pin 1 (Connector Pin 127)
    g_pin_capabilities[1].connector_pin = IO_PIN_127;
    g_pin_capabilities[1].modes[PIN_MODE_ADC] = IO_ADC_01;
    g_pin_capabilities[1].modes[PIN_MODE_DI] = IO_DI_49;

    // Internal pin 2 (Connector Pin 104)
    g_pin_capabilities[2].connector_pin = IO_PIN_104;
    g_pin_capabilities[2].modes[PIN_MODE_ADC] = IO_ADC_02;
    g_pin_capabilities[2].modes[PIN_MODE_DI] = IO_DI_50;

    // Internal pin 3 (Connector Pin 128)
    g_pin_capabilities[3].connector_pin = IO_PIN_128;
    g_pin_capabilities[3].modes[PIN_MODE_ADC] = IO_ADC_03;
    g_pin_capabilities[3].modes[PIN_MODE_DI] = IO_DI_51;

    // Internal pin 4 (Connector Pin 105)
    g_pin_capabilities[4].connector_pin = IO_PIN_105;
    g_pin_capabilities[4].modes[PIN_MODE_ADC] = IO_ADC_04;
    g_pin_capabilities[4].modes[PIN_MODE_DI] = IO_DI_52;

    // Internal pin 5 (Connector Pin 129)
    g_pin_capabilities[5].connector_pin = IO_PIN_129;
    g_pin_capabilities[5].modes[PIN_MODE_ADC] = IO_ADC_05;
    g_pin_capabilities[5].modes[PIN_MODE_DI] = IO_DI_53;

    // Internal pin 6 (Connector Pin 106)
    g_pin_capabilities[6].connector_pin = IO_PIN_106;
    g_pin_capabilities[6].modes[PIN_MODE_ADC] = IO_ADC_06;
    g_pin_capabilities[6].modes[PIN_MODE_DI] = IO_DI_54;

    // Internal pin 7 (Connector Pin 130)
    g_pin_capabilities[7].connector_pin = IO_PIN_130;
    g_pin_capabilities[7].modes[PIN_MODE_ADC] = IO_ADC_07;
    g_pin_capabilities[7].modes[PIN_MODE_DI] = IO_DI_55;

    // Internal pin 8 (Connector Pin 107)
    g_pin_capabilities[8].connector_pin = IO_PIN_107;
    g_pin_capabilities[8].modes[PIN_MODE_ADC] = IO_ADC_08;
    g_pin_capabilities[8].modes[PIN_MODE_DI] = IO_DI_56;

    // Internal pin 9 (Connector Pin 131)
    g_pin_capabilities[9].connector_pin = IO_PIN_131;
    g_pin_capabilities[9].modes[PIN_MODE_ADC] = IO_ADC_09;
    g_pin_capabilities[9].modes[PIN_MODE_DI] = IO_DI_57;

    // Internal pin 10 (Connector Pin 108)
    g_pin_capabilities[10].connector_pin = IO_PIN_108;
    g_pin_capabilities[10].modes[PIN_MODE_ADC] = IO_ADC_10;
    g_pin_capabilities[10].modes[PIN_MODE_DI] = IO_DI_58;

    // Internal pin 11 (Connector Pin 132)
    g_pin_capabilities[11].connector_pin = IO_PIN_132;
    g_pin_capabilities[11].modes[PIN_MODE_ADC] = IO_ADC_11;
    g_pin_capabilities[11].modes[PIN_MODE_DI] = IO_DI_59;

    // Internal pin 12 (Connector Pin 109)
    g_pin_capabilities[12].connector_pin = IO_PIN_109;
    g_pin_capabilities[12].modes[PIN_MODE_ADC] = IO_ADC_12;
    g_pin_capabilities[12].modes[PIN_MODE_DI] = IO_DI_60;

    // Internal pin 13 (Connector Pin 133)
    g_pin_capabilities[13].connector_pin = IO_PIN_133;
    g_pin_capabilities[13].modes[PIN_MODE_ADC] = IO_ADC_13;
    g_pin_capabilities[13].modes[PIN_MODE_DI] = IO_DI_61;

    // Internal pin 14 (Connector Pin 110)
    g_pin_capabilities[14].connector_pin = IO_PIN_110;
    g_pin_capabilities[14].modes[PIN_MODE_ADC] = IO_ADC_14;
    g_pin_capabilities[14].modes[PIN_MODE_DI] = IO_DI_62;

    // Internal pin 15 (Connector Pin 134)
    g_pin_capabilities[15].connector_pin = IO_PIN_134;
    g_pin_capabilities[15].modes[PIN_MODE_ADC] = IO_ADC_15;
    g_pin_capabilities[15].modes[PIN_MODE_DI] = IO_DI_63;

    // Internal pin 16 (Connector Pin 111)
    g_pin_capabilities[16].connector_pin = IO_PIN_111;
    g_pin_capabilities[16].modes[PIN_MODE_ADC] = IO_ADC_16;
    g_pin_capabilities[16].modes[PIN_MODE_DI] = IO_DI_64;

    // Internal pin 17 (Connector Pin 135)
    g_pin_capabilities[17].connector_pin = IO_PIN_135;
    g_pin_capabilities[17].modes[PIN_MODE_ADC] = IO_ADC_17;
    g_pin_capabilities[17].modes[PIN_MODE_DI] = IO_DI_65;

    // Internal pin 18 (Connector Pin 112)
    g_pin_capabilities[18].connector_pin = IO_PIN_112;
    g_pin_capabilities[18].modes[PIN_MODE_ADC] = IO_ADC_18;
    g_pin_capabilities[18].modes[PIN_MODE_DI] = IO_DI_66;

    // Internal pin 19 (Connector Pin 136)
    g_pin_capabilities[19].connector_pin = IO_PIN_136;
    g_pin_capabilities[19].modes[PIN_MODE_ADC] = IO_ADC_19;
    g_pin_capabilities[19].modes[PIN_MODE_DI] = IO_DI_67;

    // Internal pin 20 (Connector Pin 113)
    g_pin_capabilities[20].connector_pin = IO_PIN_113;
    g_pin_capabilities[20].modes[PIN_MODE_ADC] = IO_ADC_20;
    g_pin_capabilities[20].modes[PIN_MODE_DI] = IO_DI_68;

    // Internal pin 21 (Connector Pin 137)
    g_pin_capabilities[21].connector_pin = IO_PIN_137;
    g_pin_capabilities[21].modes[PIN_MODE_ADC] = IO_ADC_21;
    g_pin_capabilities[21].modes[PIN_MODE_DI] = IO_DI_69;

    // Internal pin 22 (Connector Pin 114)
    g_pin_capabilities[22].connector_pin = IO_PIN_114;
    g_pin_capabilities[22].modes[PIN_MODE_ADC] = IO_ADC_22;
    g_pin_capabilities[22].modes[PIN_MODE_DI] = IO_DI_70;

    // Internal pin 23 (Connector Pin 138)
    g_pin_capabilities[23].connector_pin = IO_PIN_138;
    g_pin_capabilities[23].modes[PIN_MODE_ADC] = IO_ADC_23;
    g_pin_capabilities[23].modes[PIN_MODE_DI] = IO_DI_71;

    // Internal pin 24 (Connector Pin 115)
    g_pin_capabilities[24].connector_pin = IO_PIN_115;
    g_pin_capabilities[24].modes[PIN_MODE_PWD] = IO_PWD_00;
    g_pin_capabilities[24].modes[PIN_MODE_ADC] = IO_ADC_24;
    g_pin_capabilities[24].modes[PIN_MODE_DI] = IO_DI_36;

    // Internal pin 25 (Connector Pin 139)
    g_pin_capabilities[25].connector_pin = IO_PIN_139;
    g_pin_capabilities[25].modes[PIN_MODE_PWD] = IO_PWD_01;
    g_pin_capabilities[25].modes[PIN_MODE_ADC] = IO_ADC_25;
    g_pin_capabilities[25].modes[PIN_MODE_DI] = IO_DI_37;

    // Internal pin 26 (Connector Pin 116)
    g_pin_capabilities[26].connector_pin = IO_PIN_116;
    g_pin_capabilities[26].modes[PIN_MODE_PWD] = IO_PWD_02;
    g_pin_capabilities[26].modes[PIN_MODE_ADC] = IO_ADC_26;
    g_pin_capabilities[26].modes[PIN_MODE_DI] = IO_DI_38;

    // Internal pin 27 (Connector Pin 140)
    g_pin_capabilities[27].connector_pin = IO_PIN_140;
    g_pin_capabilities[27].modes[PIN_MODE_PWD] = IO_PWD_03;
    g_pin_capabilities[27].modes[PIN_MODE_ADC] = IO_ADC_27;
    g_pin_capabilities[27].modes[PIN_MODE_DI] = IO_DI_39;

    // Internal pin 28 (Connector Pin 117)
    g_pin_capabilities[28].connector_pin = IO_PIN_117;
    g_pin_capabilities[28].modes[PIN_MODE_PWD] = IO_PWD_04;
    g_pin_capabilities[28].modes[PIN_MODE_ADC] = IO_ADC_28;
    g_pin_capabilities[28].modes[PIN_MODE_DI] = IO_DI_40;

    // Internal pin 29 (Connector Pin 141)
    g_pin_capabilities[29].connector_pin = IO_PIN_141;
    g_pin_capabilities[29].modes[PIN_MODE_PWD] = IO_PWD_05;
    g_pin_capabilities[29].modes[PIN_MODE_ADC] = IO_ADC_29;
    g_pin_capabilities[29].modes[PIN_MODE_DI] = IO_DI_41;

    // Internal pin 30 (Connector Pin 122)
    g_pin_capabilities[30].connector_pin = IO_PIN_122;
    g_pin_capabilities[30].modes[PIN_MODE_PWD] = IO_PWD_06;
    g_pin_capabilities[30].modes[PIN_MODE_ADC] = IO_ADC_30;
    g_pin_capabilities[30].modes[PIN_MODE_DI] = IO_DI_42;

    // Internal pin 31 (Connector Pin 146)
    g_pin_capabilities[31].connector_pin = IO_PIN_146;
    g_pin_capabilities[31].modes[PIN_MODE_PWD] = IO_PWD_07;
    g_pin_capabilities[31].modes[PIN_MODE_ADC] = IO_ADC_31;
    g_pin_capabilities[31].modes[PIN_MODE_DI] = IO_DI_43;

    // Internal pin 32 (Connector Pin 123)
    g_pin_capabilities[32].connector_pin = IO_PIN_123;
    g_pin_capabilities[32].modes[PIN_MODE_PWD] = IO_PWD_08;
    g_pin_capabilities[32].modes[PIN_MODE_ADC] = IO_ADC_32;
    g_pin_capabilities[32].modes[PIN_MODE_DI] = IO_DI_44;

    // Internal pin 33 (Connector Pin 147)
    g_pin_capabilities[33].connector_pin = IO_PIN_147;
    g_pin_capabilities[33].modes[PIN_MODE_PWD] = IO_PWD_09;
    g_pin_capabilities[33].modes[PIN_MODE_ADC] = IO_ADC_33;
    g_pin_capabilities[33].modes[PIN_MODE_DI] = IO_DI_45;

    // Internal pin 34 (Connector Pin 124)
    g_pin_capabilities[34].connector_pin = IO_PIN_124;
    g_pin_capabilities[34].modes[PIN_MODE_PWD] = IO_PWD_10;
    g_pin_capabilities[34].modes[PIN_MODE_ADC] = IO_ADC_34;
    g_pin_capabilities[34].modes[PIN_MODE_DI] = IO_DI_46;

    // Internal pin 35 (Connector Pin 148)
    g_pin_capabilities[35].connector_pin = IO_PIN_148;
    g_pin_capabilities[35].modes[PIN_MODE_PWD] = IO_PWD_11;
    g_pin_capabilities[35].modes[PIN_MODE_ADC] = IO_ADC_35;
    g_pin_capabilities[35].modes[PIN_MODE_DI] = IO_DI_47;

    // Internal pin 36 (Connector Pin 149)
    g_pin_capabilities[36].connector_pin = IO_PIN_149;
    g_pin_capabilities[36].modes[PIN_MODE_DO] = IO_DO_00;
    g_pin_capabilities[36].modes[PIN_MODE_ADC] = IO_ADC_36;
    g_pin_capabilities[36].modes[PIN_MODE_DI] = IO_DI_72;

    // Internal pin 37 (Connector Pin 173)
    g_pin_capabilities[37].connector_pin = IO_PIN_173;
    g_pin_capabilities[37].modes[PIN_MODE_DO] = IO_DO_01;
    g_pin_capabilities[37].modes[PIN_MODE_ADC] = IO_ADC_37;
    g_pin_capabilities[37].modes[PIN_MODE_DI] = IO_DI_73;

    // Internal pin 38 (Connector Pin 152)
    g_pin_capabilities[38].connector_pin = IO_PIN_152;
    g_pin_capabilities[38].modes[PIN_MODE_DO] = IO_DO_02;
    g_pin_capabilities[38].modes[PIN_MODE_ADC] = IO_ADC_38;
    g_pin_capabilities[38].modes[PIN_MODE_DI] = IO_DI_74;

    // Internal pin 39 (Connector Pin 176)
    g_pin_capabilities[39].connector_pin = IO_PIN_176;
    g_pin_capabilities[39].modes[PIN_MODE_DO] = IO_DO_03;
    g_pin_capabilities[39].modes[PIN_MODE_ADC] = IO_ADC_39;
    g_pin_capabilities[39].modes[PIN_MODE_DI] = IO_DI_75;

    // Internal pin 40 (Connector Pin 155)
    g_pin_capabilities[40].connector_pin = IO_PIN_155;
    g_pin_capabilities[40].modes[PIN_MODE_DO] = IO_DO_04;
    g_pin_capabilities[40].modes[PIN_MODE_ADC] = IO_ADC_40;
    g_pin_capabilities[40].modes[PIN_MODE_DI] = IO_DI_76;

    // Internal pin 41 (Connector Pin 179)
    g_pin_capabilities[41].connector_pin = IO_PIN_179;
    g_pin_capabilities[41].modes[PIN_MODE_DO] = IO_DO_05;
    g_pin_capabilities[41].modes[PIN_MODE_ADC] = IO_ADC_41;
    g_pin_capabilities[41].modes[PIN_MODE_DI] = IO_DI_77;

    // Internal pin 42 (Connector Pin 158)
    g_pin_capabilities[42].connector_pin = IO_PIN_158;
    g_pin_capabilities[42].modes[PIN_MODE_DO] = IO_DO_06;
    g_pin_capabilities[42].modes[PIN_MODE_ADC] = IO_ADC_42;
    g_pin_capabilities[42].modes[PIN_MODE_DI] = IO_DI_78;

    // Internal pin 43 (Connector Pin 182)
    g_pin_capabilities[43].connector_pin = IO_PIN_182;
    g_pin_capabilities[43].modes[PIN_MODE_DO] = IO_DO_07;
    g_pin_capabilities[43].modes[PIN_MODE_ADC] = IO_ADC_43;
    g_pin_capabilities[43].modes[PIN_MODE_DI] = IO_DI_79;

    // Internal pin 44 (Connector Pin 251)
    g_pin_capabilities[44].connector_pin = IO_PIN_251;
    g_pin_capabilities[44].modes[PIN_MODE_DO] = IO_DO_08;
    g_pin_capabilities[44].modes[PIN_MODE_ADC] = IO_ADC_44;
    g_pin_capabilities[44].modes[PIN_MODE_DI] = IO_DI_80;

    // Internal pin 45 (Connector Pin 238)
    g_pin_capabilities[45].connector_pin = IO_PIN_238;
    g_pin_capabilities[45].modes[PIN_MODE_DO] = IO_DO_09;
    g_pin_capabilities[45].modes[PIN_MODE_ADC] = IO_ADC_45;
    g_pin_capabilities[45].modes[PIN_MODE_DI] = IO_DI_81;

    // Internal pin 46 (Connector Pin 252)
    g_pin_capabilities[46].connector_pin = IO_PIN_252;
    g_pin_capabilities[46].modes[PIN_MODE_DO] = IO_DO_10;
    g_pin_capabilities[46].modes[PIN_MODE_ADC] = IO_ADC_46;
    g_pin_capabilities[46].modes[PIN_MODE_DI] = IO_DI_82;

    // Internal pin 47 (Connector Pin 239)
    g_pin_capabilities[47].connector_pin = IO_PIN_239;
    g_pin_capabilities[47].modes[PIN_MODE_DO] = IO_DO_11;
    g_pin_capabilities[47].modes[PIN_MODE_ADC] = IO_ADC_47;
    g_pin_capabilities[47].modes[PIN_MODE_DI] = IO_DI_83;

    // Internal pin 48 (Connector Pin 253)
    g_pin_capabilities[48].connector_pin = IO_PIN_253;
    g_pin_capabilities[48].modes[PIN_MODE_DO] = IO_DO_12;
    g_pin_capabilities[48].modes[PIN_MODE_ADC] = IO_ADC_48;
    g_pin_capabilities[48].modes[PIN_MODE_DI] = IO_DI_84;

    // Internal pin 49 (Connector Pin 240)
    g_pin_capabilities[49].connector_pin = IO_PIN_240;
    g_pin_capabilities[49].modes[PIN_MODE_DO] = IO_DO_13;
    g_pin_capabilities[49].modes[PIN_MODE_ADC] = IO_ADC_49;
    g_pin_capabilities[49].modes[PIN_MODE_DI] = IO_DI_85;

    // Internal pin 50 (Connector Pin 254)
    g_pin_capabilities[50].connector_pin = IO_PIN_254;
    g_pin_capabilities[50].modes[PIN_MODE_DO] = IO_DO_14;
    g_pin_capabilities[50].modes[PIN_MODE_ADC] = IO_ADC_50;
    g_pin_capabilities[50].modes[PIN_MODE_DI] = IO_DI_86;

    // Internal pin 51 (Connector Pin 241)
    g_pin_capabilities[51].connector_pin = IO_PIN_241;
    g_pin_capabilities[51].modes[PIN_MODE_DO] = IO_DO_15;
    g_pin_capabilities[51].modes[PIN_MODE_ADC] = IO_ADC_51;
    g_pin_capabilities[51].modes[PIN_MODE_DI] = IO_DI_87;

    // Internal pin 52 (Connector Pin 153)
    g_pin_capabilities[52].connector_pin = IO_PIN_153;
    g_pin_capabilities[52].modes[PIN_MODE_PWM] = IO_PWM_00;
    g_pin_capabilities[52].modes[PIN_MODE_DO] = IO_DO_16;
    g_pin_capabilities[52].modes[PIN_MODE_DI] = IO_DI_00;

    // Internal pin 53 (Connector Pin 177)
    g_pin_capabilities[53].connector_pin = IO_PIN_177;
    g_pin_capabilities[53].modes[PIN_MODE_PWM] = IO_PWM_01;
    g_pin_capabilities[53].modes[PIN_MODE_DO] = IO_DO_17;
    g_pin_capabilities[53].modes[PIN_MODE_DI] = IO_DI_01;

    // Internal pin 54 (Connector Pin 156)
    g_pin_capabilities[54].connector_pin = IO_PIN_156;
    g_pin_capabilities[54].modes[PIN_MODE_PWM] = IO_PWM_02;
    g_pin_capabilities[54].modes[PIN_MODE_DO] = IO_DO_18;
    g_pin_capabilities[54].modes[PIN_MODE_DI] = IO_DI_02;

    // Internal pin 55 (Connector Pin 180)
    g_pin_capabilities[55].connector_pin = IO_PIN_180;
    g_pin_capabilities[55].modes[PIN_MODE_PWM] = IO_PWM_03;
    g_pin_capabilities[55].modes[PIN_MODE_DO] = IO_DO_19;
    g_pin_capabilities[55].modes[PIN_MODE_DI] = IO_DI_03;

    // Internal pin 56 (Connector Pin 159)
    g_pin_capabilities[56].connector_pin = IO_PIN_159;
    g_pin_capabilities[56].modes[PIN_MODE_PWM] = IO_PWM_04;
    g_pin_capabilities[56].modes[PIN_MODE_DO] = IO_DO_20;
    g_pin_capabilities[56].modes[PIN_MODE_DI] = IO_DI_04;

    // Internal pin 57 (Connector Pin 183)
    g_pin_capabilities[57].connector_pin = IO_PIN_183;
    g_pin_capabilities[57].modes[PIN_MODE_PWM] = IO_PWM_05;
    g_pin_capabilities[57].modes[PIN_MODE_DO] = IO_DO_21;
    g_pin_capabilities[57].modes[PIN_MODE_DI] = IO_DI_05;

    // Internal pin 58 (Connector Pin 186)
    g_pin_capabilities[58].connector_pin = IO_PIN_186;
    g_pin_capabilities[58].modes[PIN_MODE_PWM] = IO_PWM_06;
    g_pin_capabilities[58].modes[PIN_MODE_DO] = IO_DO_22;
    g_pin_capabilities[58].modes[PIN_MODE_DI] = IO_DI_06;

    // Internal pin 59 (Connector Pin 162)
    g_pin_capabilities[59].connector_pin = IO_PIN_162;
    g_pin_capabilities[59].modes[PIN_MODE_PWM] = IO_PWM_07;
    g_pin_capabilities[59].modes[PIN_MODE_DO] = IO_DO_23;
    g_pin_capabilities[59].modes[PIN_MODE_DI] = IO_DI_07;

    // Internal pin 60 (Connector Pin 189)
    g_pin_capabilities[60].connector_pin = IO_PIN_189;
    g_pin_capabilities[60].modes[PIN_MODE_PWM] = IO_PWM_08;
    g_pin_capabilities[60].modes[PIN_MODE_DO] = IO_DO_24;
    g_pin_capabilities[60].modes[PIN_MODE_DI] = IO_DI_08;

    // Internal pin 61 (Connector Pin 165)
    g_pin_capabilities[61].connector_pin = IO_PIN_165;
    g_pin_capabilities[61].modes[PIN_MODE_PWM] = IO_PWM_09;
    g_pin_capabilities[61].modes[PIN_MODE_DO] = IO_DO_25;
    g_pin_capabilities[61].modes[PIN_MODE_DI] = IO_DI_09;

    // Internal pin 62 (Connector Pin 192)
    g_pin_capabilities[62].connector_pin = IO_PIN_192;
    g_pin_capabilities[62].modes[PIN_MODE_PWM] = IO_PWM_10;
    g_pin_capabilities[62].modes[PIN_MODE_DO] = IO_DO_26;
    g_pin_capabilities[62].modes[PIN_MODE_DI] = IO_DI_10;

    // Internal pin 63 (Connector Pin 168)
    g_pin_capabilities[63].connector_pin = IO_PIN_168;
    g_pin_capabilities[63].modes[PIN_MODE_PWM] = IO_PWM_11;
    g_pin_capabilities[63].modes[PIN_MODE_DO] = IO_DO_27;
    g_pin_capabilities[63].modes[PIN_MODE_DI] = IO_DI_11;

    // Internal pin 64 (Connector Pin 195)
    g_pin_capabilities[64].connector_pin = IO_PIN_195;
    g_pin_capabilities[64].modes[PIN_MODE_PWM] = IO_PWM_12;
    g_pin_capabilities[64].modes[PIN_MODE_DO] = IO_DO_28;
    g_pin_capabilities[64].modes[PIN_MODE_DI] = IO_DI_12;

    // Internal pin 65 (Connector Pin 171)
    g_pin_capabilities[65].connector_pin = IO_PIN_171;
    g_pin_capabilities[65].modes[PIN_MODE_PWM] = IO_PWM_13;
    g_pin_capabilities[65].modes[PIN_MODE_DO] = IO_DO_29;
    g_pin_capabilities[65].modes[PIN_MODE_DI] = IO_DI_13;

    // Internal pin 66 (Connector Pin 154)
    g_pin_capabilities[66].connector_pin = IO_PIN_154;
    g_pin_capabilities[66].modes[PIN_MODE_PWM] = IO_PWM_14;
    g_pin_capabilities[66].modes[PIN_MODE_DO] = IO_DO_30;
    g_pin_capabilities[66].modes[PIN_MODE_DI] = IO_DI_14;

    // Internal pin 67 (Connector Pin 178)
    g_pin_capabilities[67].connector_pin = IO_PIN_178;
    g_pin_capabilities[67].modes[PIN_MODE_PWM] = IO_PWM_15;
    g_pin_capabilities[67].modes[PIN_MODE_DO] = IO_DO_31;
    g_pin_capabilities[67].modes[PIN_MODE_DI] = IO_DI_15;

    // Internal pin 68 (Connector Pin 157)
    g_pin_capabilities[68].connector_pin = IO_PIN_157;
    g_pin_capabilities[68].modes[PIN_MODE_PWM] = IO_PWM_16;
    g_pin_capabilities[68].modes[PIN_MODE_DO] = IO_DO_32;
    g_pin_capabilities[68].modes[PIN_MODE_DI] = IO_DI_16;

    // Internal pin 69 (Connector Pin 181)
    g_pin_capabilities[69].connector_pin = IO_PIN_181;
    g_pin_capabilities[69].modes[PIN_MODE_PWM] = IO_PWM_17;
    g_pin_capabilities[69].modes[PIN_MODE_DO] = IO_DO_33;
    g_pin_capabilities[69].modes[PIN_MODE_DI] = IO_DI_17;

    // Internal pin 70 (Connector Pin 160)
    g_pin_capabilities[70].connector_pin = IO_PIN_160;
    g_pin_capabilities[70].modes[PIN_MODE_PWM] = IO_PWM_18;
    g_pin_capabilities[70].modes[PIN_MODE_DO] = IO_DO_34;
    g_pin_capabilities[70].modes[PIN_MODE_DI] = IO_DI_18;

    // Internal pin 71 (Connector Pin 184)
    g_pin_capabilities[71].connector_pin = IO_PIN_184;
    g_pin_capabilities[71].modes[PIN_MODE_PWM] = IO_PWM_19;
    g_pin_capabilities[71].modes[PIN_MODE_DO] = IO_DO_35;
    g_pin_capabilities[71].modes[PIN_MODE_DI] = IO_DI_19;

    // Internal pin 72 (Connector Pin 187)
    g_pin_capabilities[72].connector_pin = IO_PIN_187;
    g_pin_capabilities[72].modes[PIN_MODE_PWM] = IO_PWM_20;
    g_pin_capabilities[72].modes[PIN_MODE_DO] = IO_DO_36;
    g_pin_capabilities[72].modes[PIN_MODE_DI] = IO_DI_20;

    // Internal pin 73 (Connector Pin 163)
    g_pin_capabilities[73].connector_pin = IO_PIN_163;
    g_pin_capabilities[73].modes[PIN_MODE_PWM] = IO_PWM_21;
    g_pin_capabilities[73].modes[PIN_MODE_DO] = IO_DO_37;
    g_pin_capabilities[73].modes[PIN_MODE_DI] = IO_DI_21;

    // Internal pin 74 (Connector Pin 190)
    g_pin_capabilities[74].connector_pin = IO_PIN_190;
    g_pin_capabilities[74].modes[PIN_MODE_PWM] = IO_PWM_22;
    g_pin_capabilities[74].modes[PIN_MODE_DO] = IO_DO_38;
    g_pin_capabilities[74].modes[PIN_MODE_DI] = IO_DI_22;

    // Internal pin 75 (Connector Pin 166)
    g_pin_capabilities[75].connector_pin = IO_PIN_166;
    g_pin_capabilities[75].modes[PIN_MODE_PWM] = IO_PWM_23;
    g_pin_capabilities[75].modes[PIN_MODE_DO] = IO_DO_39;
    g_pin_capabilities[75].modes[PIN_MODE_DI] = IO_DI_23;

    // Internal pin 76 (Connector Pin 193)
    g_pin_capabilities[76].connector_pin = IO_PIN_193;
    g_pin_capabilities[76].modes[PIN_MODE_PWM] = IO_PWM_24;
    g_pin_capabilities[76].modes[PIN_MODE_DO] = IO_DO_40;
    g_pin_capabilities[76].modes[PIN_MODE_DI] = IO_DI_24;

    // Internal pin 77 (Connector Pin 169)
    g_pin_capabilities[77].connector_pin = IO_PIN_169;
    g_pin_capabilities[77].modes[PIN_MODE_PWM] = IO_PWM_25;
    g_pin_capabilities[77].modes[PIN_MODE_DO] = IO_DO_41;
    g_pin_capabilities[77].modes[PIN_MODE_DI] = IO_DI_25;

    // Internal pin 78 (Connector Pin 196)
    g_pin_capabilities[78].connector_pin = IO_PIN_196;
    g_pin_capabilities[78].modes[PIN_MODE_PWM] = IO_PWM_26;
    g_pin_capabilities[78].modes[PIN_MODE_DO] = IO_DO_42;
    g_pin_capabilities[78].modes[PIN_MODE_DI] = IO_DI_26;

    // Internal pin 79 (Connector Pin 172)
    g_pin_capabilities[79].connector_pin = IO_PIN_172;
    g_pin_capabilities[79].modes[PIN_MODE_PWM] = IO_PWM_27;
    g_pin_capabilities[79].modes[PIN_MODE_DO] = IO_DO_43;
    g_pin_capabilities[79].modes[PIN_MODE_DI] = IO_DI_27;

    // Internal pin 80 (Connector Pin 101)
    g_pin_capabilities[80].connector_pin = IO_PIN_101;
    g_pin_capabilities[80].modes[PIN_MODE_PWM] = IO_PWM_28;
    g_pin_capabilities[80].modes[PIN_MODE_DO] = IO_DO_44;
    g_pin_capabilities[80].modes[PIN_MODE_DI] = IO_DI_28;
    g_pin_capabilities[80].modes[PIN_MODE_PWD] = IO_PWD_12;

    // Internal pin 81 (Connector Pin 125)
    g_pin_capabilities[81].connector_pin = IO_PIN_125;
    g_pin_capabilities[81].modes[PIN_MODE_PWM] = IO_PWM_29;
    g_pin_capabilities[81].modes[PIN_MODE_DO] = IO_DO_45;
    g_pin_capabilities[81].modes[PIN_MODE_DI] = IO_DI_29;
    g_pin_capabilities[81].modes[PIN_MODE_PWD] = IO_PWD_13;

    // Internal pin 82 (Connector Pin 150)
    g_pin_capabilities[82].connector_pin = IO_PIN_150;
    g_pin_capabilities[82].modes[PIN_MODE_PWM] = IO_PWM_30;
    g_pin_capabilities[82].modes[PIN_MODE_DO] = IO_DO_46;
    g_pin_capabilities[82].modes[PIN_MODE_DI] = IO_DI_30;
    g_pin_capabilities[82].modes[PIN_MODE_PWD] = IO_PWD_14;

    // Internal pin 83 (Connector Pin 174)
    g_pin_capabilities[83].connector_pin = IO_PIN_174;
    g_pin_capabilities[83].modes[PIN_MODE_PWM] = IO_PWM_31;
    g_pin_capabilities[83].modes[PIN_MODE_DO] = IO_DO_47;
    g_pin_capabilities[83].modes[PIN_MODE_DI] = IO_DI_31;
    g_pin_capabilities[83].modes[PIN_MODE_PWD] = IO_PWD_15;

    // Internal pin 84 (Connector Pin 102)
    g_pin_capabilities[84].connector_pin = IO_PIN_102;
    g_pin_capabilities[84].modes[PIN_MODE_PWM] = IO_PWM_32;
    g_pin_capabilities[84].modes[PIN_MODE_DO] = IO_DO_48;
    g_pin_capabilities[84].modes[PIN_MODE_DI] = IO_DI_32;
    g_pin_capabilities[84].modes[PIN_MODE_PWD] = IO_PWD_16;

    // Internal pin 85 (Connector Pin 126)
    g_pin_capabilities[85].connector_pin = IO_PIN_126;
    g_pin_capabilities[85].modes[PIN_MODE_PWM] = IO_PWM_33;
    g_pin_capabilities[85].modes[PIN_MODE_DO] = IO_DO_49;
    g_pin_capabilities[85].modes[PIN_MODE_DI] = IO_DI_33;
    g_pin_capabilities[85].modes[PIN_MODE_PWD] = IO_PWD_17;

    // Internal pin 86 (Connector Pin 151)
    g_pin_capabilities[86].connector_pin = IO_PIN_151;
    g_pin_capabilities[86].modes[PIN_MODE_PWM] = IO_PWM_34;
    g_pin_capabilities[86].modes[PIN_MODE_DO] = IO_DO_50;
    g_pin_capabilities[86].modes[PIN_MODE_DI] = IO_DI_34;
    g_pin_capabilities[86].modes[PIN_MODE_PWD] = IO_PWD_18;

    // Internal pin 87 (Connector Pin 175)
    g_pin_capabilities[87].connector_pin = IO_PIN_175;
    g_pin_capabilities[87].modes[PIN_MODE_PWM] = IO_PWM_35;
    g_pin_capabilities[87].modes[PIN_MODE_DO] = IO_DO_51;
    g_pin_capabilities[87].modes[PIN_MODE_DI] = IO_DI_35;
    g_pin_capabilities[87].modes[PIN_MODE_PWD] = IO_PWD_19;

    // Internal pin 88 (Connector Pin 161)
    g_pin_capabilities[88].connector_pin = IO_PIN_161;
    g_pin_capabilities[88].modes[PIN_MODE_PVG] = IO_PVG_00;
    g_pin_capabilities[88].modes[PIN_MODE_VOUT] = IO_VOUT_00;
    g_pin_capabilities[88].modes[PIN_MODE_DO] = IO_DO_52;
    g_pin_capabilities[88].modes[PIN_MODE_ADC] = IO_ADC_52;
    g_pin_capabilities[88].modes[PIN_MODE_DI] = IO_DI_88;

    // Internal pin 89 (Connector Pin 185)
    g_pin_capabilities[89].connector_pin = IO_PIN_185;
    g_pin_capabilities[89].modes[PIN_MODE_PVG] = IO_PVG_01;
    g_pin_capabilities[89].modes[PIN_MODE_VOUT] = IO_VOUT_01;
    g_pin_capabilities[89].modes[PIN_MODE_DO] = IO_DO_53;
    g_pin_capabilities[89].modes[PIN_MODE_ADC] = IO_ADC_53;
    g_pin_capabilities[89].modes[PIN_MODE_DI] = IO_DI_89;

    // Internal pin 90 (Connector Pin 188)
    g_pin_capabilities[90].connector_pin = IO_PIN_188;
    g_pin_capabilities[90].modes[PIN_MODE_PVG] = IO_PVG_02;
    g_pin_capabilities[90].modes[PIN_MODE_VOUT] = IO_VOUT_02;
    g_pin_capabilities[90].modes[PIN_MODE_DO] = IO_DO_54;
    g_pin_capabilities[90].modes[PIN_MODE_ADC] = IO_ADC_54;
    g_pin_capabilities[90].modes[PIN_MODE_DI] = IO_DI_90;

    // Internal pin 91 (Connector Pin 164)
    g_pin_capabilities[91].connector_pin = IO_PIN_164;
    g_pin_capabilities[91].modes[PIN_MODE_PVG] = IO_PVG_03;
    g_pin_capabilities[91].modes[PIN_MODE_VOUT] = IO_VOUT_03;
    g_pin_capabilities[91].modes[PIN_MODE_DO] = IO_DO_55;
    g_pin_capabilities[91].modes[PIN_MODE_ADC] = IO_ADC_55;
    g_pin_capabilities[91].modes[PIN_MODE_DI] = IO_DI_91;

    // Internal pin 92 (Connector Pin 191)
    g_pin_capabilities[92].connector_pin = IO_PIN_191;
    g_pin_capabilities[92].modes[PIN_MODE_PVG] = IO_PVG_04;
    g_pin_capabilities[92].modes[PIN_MODE_VOUT] = IO_VOUT_04;
    g_pin_capabilities[92].modes[PIN_MODE_DO] = IO_DO_56;
    g_pin_capabilities[92].modes[PIN_MODE_ADC] = IO_ADC_56;
    g_pin_capabilities[92].modes[PIN_MODE_DI] = IO_DI_92;

    // Internal pin 93 (Connector Pin 167)
    g_pin_capabilities[93].connector_pin = IO_PIN_167;
    g_pin_capabilities[93].modes[PIN_MODE_PVG] = IO_PVG_05;
    g_pin_capabilities[93].modes[PIN_MODE_VOUT] = IO_VOUT_05;
    g_pin_capabilities[93].modes[PIN_MODE_DO] = IO_DO_57;
    g_pin_capabilities[93].modes[PIN_MODE_ADC] = IO_ADC_57;
    g_pin_capabilities[93].modes[PIN_MODE_DI] = IO_DI_93;

    // Internal pin 94 (Connector Pin 194)
    g_pin_capabilities[94].connector_pin = IO_PIN_194;
    g_pin_capabilities[94].modes[PIN_MODE_PVG] = IO_PVG_06;
    g_pin_capabilities[94].modes[PIN_MODE_VOUT] = IO_VOUT_06;
    g_pin_capabilities[94].modes[PIN_MODE_DO] = IO_DO_58;
    g_pin_capabilities[94].modes[PIN_MODE_ADC] = IO_ADC_58;
    g_pin_capabilities[94].modes[PIN_MODE_DI] = IO_DI_94;

    // Internal pin 95 (Connector Pin 170)
    g_pin_capabilities[95].connector_pin = IO_PIN_170;
    g_pin_capabilities[95].modes[PIN_MODE_PVG] = IO_PVG_07;
    g_pin_capabilities[95].modes[PIN_MODE_VOUT] = IO_VOUT_07;
    g_pin_capabilities[95].modes[PIN_MODE_DO] = IO_DO_59;
    g_pin_capabilities[95].modes[PIN_MODE_ADC] = IO_ADC_59;
    g_pin_capabilities[95].modes[PIN_MODE_DI] = IO_DI_95;
}

/**
 * @brief Checks if the pin supports the specified mode
 * @param internal_pin Internal pin number (0..95)
 * @param mode Operation mode (PIN_MODE_DI, PIN_MODE_ADC, etc.)
 * @return TRUE if the mode is supported, FALSE if not
 */

inline ubyte1 Is_Pin_Capable(ubyte1 internal_pin, PinMode_t mode)
{
    if (internal_pin >= 96 || mode >= PIN_MODE_COUNT)
    {
        return FALSE;
    }
    if (g_pin_capabilities[internal_pin].modes[mode] != IO_PIN_NONE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief Get channel for given pin mode
 * @param internal_pin Internal pin number (0..95)
 * @param mode Mode of operation (PIN_MODE_DI, PIN_MODE_ADC etc.)
 * @return IO_DI_XX, IO_ADC_XX etc. or IO_PIN_NONE if not supported
 */

inline ubyte1 Get_Channel_ForMode(ubyte1 internal_pin, PinMode_t mode)
{
    if (internal_pin >= 96 || mode >= PIN_MODE_COUNT)
    {
        return IO_PIN_NONE;
    }

    return g_pin_capabilities[internal_pin].modes[mode];
}

/**
 * @brief Get the number of supported modes for a pin
 * @param internal_pin Internal pin number (0..95)
 * @return The number of supported modes (0..7)
 */

inline ubyte1 Get_SupportedModesCount(ubyte1 internal_pin)
{
    ubyte1 count = 0;
    ubyte1 i;

    if (internal_pin >= 96)
    {
        return 0;
    }

    // Iterate over all modes except PIN_MODE_NONE (start with 1)
    for (i = 1; i < PIN_MODE_COUNT; i++)
    {
        if (g_pin_capabilities[internal_pin].modes[i] != IO_PIN_NONE)
        {
            count++;
        }
    }

    return count;
}
