/**************************************************************************************************
 * \file PinCapabilities.h
 * \brief Configuration structures for initializing pins by internal number (0-95)
 *************************************************************************************************/

#ifndef PIN_CAPABILITIES_H_
#define PIN_CAPABILITIES_H_

#include "CAN_Properties.h"
#include "IO_Driver.h"
#include "IO_ADC.h"
#include "IO_DIO.h"
#include "IO_PWM.h"
#include "IO_PWD.h"
#include "IO_PVG.h"
#include "IO_VOUT.h"

/****************************************************************************************************************
 * \verbatim[table]
 * ========================= ===================== =========== ============ =============== =========== =========
 * Connector\n pin           Internal\n pin number \n .        \n .         Pin aliases\n . \n .        \n .
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_103 "Pin 103"           0           #IO_ADC_00  #IO_DI_48
 * \ref IO_PIN_127 "Pin 127"           1           #IO_ADC_01  #IO_DI_49
 * \ref IO_PIN_104 "Pin 104"           2           #IO_ADC_02  #IO_DI_50
 * \ref IO_PIN_128 "Pin 128"           3           #IO_ADC_03  #IO_DI_51
 * \ref IO_PIN_105 "Pin 105"           4           #IO_ADC_04  #IO_DI_52
 * \ref IO_PIN_129 "Pin 129"           5           #IO_ADC_05  #IO_DI_53
 * \ref IO_PIN_106 "Pin 106"           6           #IO_ADC_06  #IO_DI_54
 * \ref IO_PIN_130 "Pin 130"           7           #IO_ADC_07  #IO_DI_55
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_107 "Pin 107"           8           #IO_ADC_08  #IO_DI_56
 * \ref IO_PIN_131 "Pin 131"           9           #IO_ADC_09  #IO_DI_57
 * \ref IO_PIN_108 "Pin 108"           10          #IO_ADC_10  #IO_DI_58
 * \ref IO_PIN_132 "Pin 132"           11          #IO_ADC_11  #IO_DI_59
 * \ref IO_PIN_109 "Pin 109"           12          #IO_ADC_12  #IO_DI_60
 * \ref IO_PIN_133 "Pin 133"           13          #IO_ADC_13  #IO_DI_61
 * \ref IO_PIN_110 "Pin 110"           14          #IO_ADC_14  #IO_DI_62
 * \ref IO_PIN_134 "Pin 134"           15          #IO_ADC_15  #IO_DI_63
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_111 "Pin 111"           16          #IO_ADC_16  #IO_DI_64
 * \ref IO_PIN_135 "Pin 135"           17          #IO_ADC_17  #IO_DI_65
 * \ref IO_PIN_112 "Pin 112"           18          #IO_ADC_18  #IO_DI_66
 * \ref IO_PIN_136 "Pin 136"           19          #IO_ADC_19  #IO_DI_67
 * \ref IO_PIN_113 "Pin 113"           20          #IO_ADC_20  #IO_DI_68
 * \ref IO_PIN_137 "Pin 137"           21          #IO_ADC_21  #IO_DI_69
 * \ref IO_PIN_114 "Pin 114"           22          #IO_ADC_22  #IO_DI_70
 * \ref IO_PIN_138 "Pin 138"           23          #IO_ADC_23  #IO_DI_71
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_115 "Pin 115"           24          #IO_PWD_00  #IO_ADC_24   #IO_DI_36
 * \ref IO_PIN_139 "Pin 139"           25          #IO_PWD_01  #IO_ADC_25   #IO_DI_37
 * \ref IO_PIN_116 "Pin 116"           26          #IO_PWD_02  #IO_ADC_26   #IO_DI_38
 * \ref IO_PIN_140 "Pin 140"           27          #IO_PWD_03  #IO_ADC_27   #IO_DI_39
 * \ref IO_PIN_117 "Pin 117"           28          #IO_PWD_04  #IO_ADC_28   #IO_DI_40
 * \ref IO_PIN_141 "Pin 141"           29          #IO_PWD_05  #IO_ADC_29   #IO_DI_41
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_122 "Pin 122"           30          #IO_PWD_06  #IO_ADC_30   #IO_DI_42
 * \ref IO_PIN_146 "Pin 146"           31          #IO_PWD_07  #IO_ADC_31   #IO_DI_43
 * \ref IO_PIN_123 "Pin 123"           32          #IO_PWD_08  #IO_ADC_32   #IO_DI_44
 * \ref IO_PIN_147 "Pin 147"           33          #IO_PWD_09  #IO_ADC_33   #IO_DI_45
 * \ref IO_PIN_124 "Pin 124"           34          #IO_PWD_10  #IO_ADC_34   #IO_DI_46
 * \ref IO_PIN_148 "Pin 148"           35          #IO_PWD_11  #IO_ADC_35   #IO_DI_47
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_149 "Pin 149"           36          #IO_DO_00   #IO_ADC_36   #IO_DI_72
 * \ref IO_PIN_173 "Pin 173"           37          #IO_DO_01   #IO_ADC_37   #IO_DI_73
 * \ref IO_PIN_152 "Pin 152"           38          #IO_DO_02   #IO_ADC_38   #IO_DI_74
 * \ref IO_PIN_176 "Pin 176"           39          #IO_DO_03   #IO_ADC_39   #IO_DI_75
 * \ref IO_PIN_155 "Pin 155"           40          #IO_DO_04   #IO_ADC_40   #IO_DI_76
 * \ref IO_PIN_179 "Pin 179"           41          #IO_DO_05   #IO_ADC_41   #IO_DI_77
 * \ref IO_PIN_158 "Pin 158"           42          #IO_DO_06   #IO_ADC_42   #IO_DI_78
 * \ref IO_PIN_182 "Pin 182"           43          #IO_DO_07   #IO_ADC_43   #IO_DI_79
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_251 "Pin 251"           44          #IO_DO_08   #IO_ADC_44   #IO_DI_80
 * \ref IO_PIN_238 "Pin 238"           45          #IO_DO_09   #IO_ADC_45   #IO_DI_81
 * \ref IO_PIN_252 "Pin 252"           46          #IO_DO_10   #IO_ADC_46   #IO_DI_82
 * \ref IO_PIN_239 "Pin 239"           47          #IO_DO_11   #IO_ADC_47   #IO_DI_83
 * \ref IO_PIN_253 "Pin 253"           48          #IO_DO_12   #IO_ADC_48   #IO_DI_84
 * \ref IO_PIN_240 "Pin 240"           49          #IO_DO_13   #IO_ADC_49   #IO_DI_85
 * \ref IO_PIN_254 "Pin 254"           50          #IO_DO_14   #IO_ADC_50   #IO_DI_86
 * \ref IO_PIN_241 "Pin 241"           51          #IO_DO_15   #IO_ADC_51   #IO_DI_87
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_153 "Pin 153"           52          #IO_PWM_00  #IO_DO_16    #IO_DI_00
 * \ref IO_PIN_177 "Pin 177"           53          #IO_PWM_01  #IO_DO_17    #IO_DI_01
 * \ref IO_PIN_156 "Pin 156"           54          #IO_PWM_02  #IO_DO_18    #IO_DI_02
 * \ref IO_PIN_180 "Pin 180"           55          #IO_PWM_03  #IO_DO_19    #IO_DI_03
 * \ref IO_PIN_159 "Pin 159"           56          #IO_PWM_04  #IO_DO_20    #IO_DI_04
 * \ref IO_PIN_183 "Pin 183"           57          #IO_PWM_05  #IO_DO_21    #IO_DI_05
 * \ref IO_PIN_186 "Pin 186"           58          #IO_PWM_06  #IO_DO_22    #IO_DI_06
 * \ref IO_PIN_162 "Pin 162"           59          #IO_PWM_07  #IO_DO_23    #IO_DI_07
 * \ref IO_PIN_189 "Pin 189"           60          #IO_PWM_08  #IO_DO_24    #IO_DI_08
 * \ref IO_PIN_165 "Pin 165"           61          #IO_PWM_09  #IO_DO_25    #IO_DI_09
 * \ref IO_PIN_192 "Pin 192"           62          #IO_PWM_10  #IO_DO_26    #IO_DI_10
 * \ref IO_PIN_168 "Pin 168"           63          #IO_PWM_11  #IO_DO_27    #IO_DI_11
 * \ref IO_PIN_195 "Pin 195"           64          #IO_PWM_12  #IO_DO_28    #IO_DI_12
 * \ref IO_PIN_171 "Pin 171"           65          #IO_PWM_13  #IO_DO_29    #IO_DI_13
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_154 "Pin 154"           66          #IO_PWM_14  #IO_DO_30    #IO_DI_14
 * \ref IO_PIN_178 "Pin 178"           67          #IO_PWM_15  #IO_DO_31    #IO_DI_15
 * \ref IO_PIN_157 "Pin 157"           68          #IO_PWM_16  #IO_DO_32    #IO_DI_16
 * \ref IO_PIN_181 "Pin 181"           69          #IO_PWM_17  #IO_DO_33    #IO_DI_17
 * \ref IO_PIN_160 "Pin 160"           70          #IO_PWM_18  #IO_DO_34    #IO_DI_18
 * \ref IO_PIN_184 "Pin 184"           71          #IO_PWM_19  #IO_DO_35    #IO_DI_19
 * \ref IO_PIN_187 "Pin 187"           72          #IO_PWM_20  #IO_DO_36    #IO_DI_20
 * \ref IO_PIN_163 "Pin 163"           73          #IO_PWM_21  #IO_DO_37    #IO_DI_21
 * \ref IO_PIN_190 "Pin 190"           74          #IO_PWM_22  #IO_DO_38    #IO_DI_22
 * \ref IO_PIN_166 "Pin 166"           75          #IO_PWM_23  #IO_DO_39    #IO_DI_23
 * \ref IO_PIN_193 "Pin 193"           76          #IO_PWM_24  #IO_DO_40    #IO_DI_24
 * \ref IO_PIN_169 "Pin 169"           77          #IO_PWM_25  #IO_DO_41    #IO_DI_25
 * \ref IO_PIN_196 "Pin 196"           78          #IO_PWM_26  #IO_DO_42    #IO_DI_26
 * \ref IO_PIN_172 "Pin 172"           79          #IO_PWM_27  #IO_DO_43    #IO_DI_27
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_101 "Pin 101"           80          #IO_PWM_28  #IO_DO_44    #IO_DI_28       #IO_PWD_12
 * \ref IO_PIN_125 "Pin 125"           81          #IO_PWM_29  #IO_DO_45    #IO_DI_29       #IO_PWD_13
 * \ref IO_PIN_150 "Pin 150"           82          #IO_PWM_30  #IO_DO_46    #IO_DI_30       #IO_PWD_14
 * \ref IO_PIN_174 "Pin 174"           83          #IO_PWM_31  #IO_DO_47    #IO_DI_31       #IO_PWD_15
 * \ref IO_PIN_102 "Pin 102"           84          #IO_PWM_32  #IO_DO_48    #IO_DI_32       #IO_PWD_16
 * \ref IO_PIN_126 "Pin 126"           85          #IO_PWM_33  #IO_DO_49    #IO_DI_33       #IO_PWD_17
 * \ref IO_PIN_151 "Pin 151"           86          #IO_PWM_34  #IO_DO_50    #IO_DI_34       #IO_PWD_18
 * \ref IO_PIN_175 "Pin 175"           87          #IO_PWM_35  #IO_DO_51    #IO_DI_35       #IO_PWD_19
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 *
 * ------------------------- --------------------- ----------- ------------ --------------- ----------- ---------
 * \ref IO_PIN_161 "Pin 161"           88          #IO_PVG_00  #IO_VOUT_00  #IO_DO_52       #IO_ADC_52  #IO_DI_88
 * \ref IO_PIN_185 "Pin 185"           89          #IO_PVG_01  #IO_VOUT_01  #IO_DO_53       #IO_ADC_53  #IO_DI_89
 * \ref IO_PIN_188 "Pin 188"           90          #IO_PVG_02  #IO_VOUT_02  #IO_DO_54       #IO_ADC_54  #IO_DI_90
 * \ref IO_PIN_164 "Pin 164"           91          #IO_PVG_03  #IO_VOUT_03  #IO_DO_55       #IO_ADC_55  #IO_DI_91
 * \ref IO_PIN_191 "Pin 191"           92          #IO_PVG_04  #IO_VOUT_04  #IO_DO_56       #IO_ADC_56  #IO_DI_92
 * \ref IO_PIN_167 "Pin 167"           93          #IO_PVG_05  #IO_VOUT_05  #IO_DO_57       #IO_ADC_57  #IO_DI_93
 * \ref IO_PIN_194 "Pin 194"           94          #IO_PVG_06  #IO_VOUT_06  #IO_DO_58       #IO_ADC_58  #IO_DI_94
 * \ref IO_PIN_170 "Pin 170"           95          #IO_PVG_07  #IO_VOUT_07  #IO_DO_59       #IO_ADC_59  #IO_DI_95
 * ========================= ===================== =========== ============ =============== =========== =========
 ***************************************************************************************************************/

 // For DI mode

    /*
     Setup a digital input.
     Parameters
     di_channel Digital input:•IO_DI_00 .. IO_DI_35
     IO_DI_36 .. IO_DI_47
     IO_DI_48 .. IO_DI_55
     IO_DI_56 .. IO_DI_63
     IO_DI_64 .. IO_DI_71
     IO_DI_72 .. IO_DI_79
     IO_DI_80 .. IO_DI_87
     IO_DI_88 .. IO_DI_95

     pupd Pull up/down configuration:•IO_DI_NO_PULL: fixed pull resistor
     IO_DI_PU_10K: Pull up 10 kOhm
     IO_DI_PD_10K: Pull down 10 kOhm

     [in] limits Voltage limits for low/high-levels. If NULL, default limits will be used. See IO_DIO_LIMITS for details.
     */

    IO_DIO_LIMITS limits = { 0 };

    // For ADC mode

    /*
     Attention:
     For the safety configuration of a 2 mode ADC channel, the following rules need to be fulfilled
     The primary channel needs to specify a redundant channel (IO_ADC_08 .. IO_ADC_23) at the redundant_channel field.

     The redundant channel must not reference a redundant channel by itself. Thus IO_PIN_NONE shall be used for the redundant channel.
     Every redundant channel can only be used once as redundant channel.
     It's not allowed to have a redundant channel which is not used by a primary channel.
     If the ratiometric measurement mode is used, the primary and the redundant channel must use different sensor supplies (but not IO_SENSOR_SUPPLY_2).
     For the safety configuration of a 3 mode ADC channel, the following rules need to be fulfilled:•The channel must have IO_PIN_NONE in the redundant_channel field.
     If the ratiometric measurement mode is used, the channel must not use IO_SENSOR_SUPPLY_2.

     Setup one ADC channel.
     Parameters
     adc_channel ADC channel, one of:•IO_ADC_00 .. IO_ADC_07
     IO_ADC_08 .. IO_ADC_15
     IO_ADC_16 .. IO_ADC_23
     IO_ADC_24 .. IO_ADC_35
     IO_ADC_36 .. IO_ADC_43
     IO_ADC_44 .. IO_ADC_51
     IO_ADC_52 .. IO_ADC_59
     IO_ADC_SENSOR_SUPPLY_0
     IO_ADC_SENSOR_SUPPLY_1
     IO_ADC_SENSOR_SUPPLY_2
     IO_ADC_K15
     IO_ADC_WAKE_UP
     IO_ADC_UBAT
     IO_ADC_SAFETY_SW_0
     IO_ADC_SAFETY_SW_1
     IO_ADC_SAFETY_SW_2
     IO_ADC_BOARD_TEMP

     type Type of input:•IO_ADC_RATIOMETRIC: voltage input on sensor supply
     IO_ADC_CURRENT: 0-25mA input
     IO_ADC_RESISTIVE: 0-100000Ohm input
     IO_ADC_ABSOLUTE: normal voltage input

     range Range of input:•IO_ADC_NO_RANGE: voltage input with fixed range
     IO_ADC_RANGE_5V: voltage input 0-5000mV
     IO_ADC_RANGE_10V: voltage input 0-10200mV
     IO_ADC_RANGE_32V: voltage input 0-32000mV

     pupd Pull up/down configuration:•IO_ADC_NO_PULL: fixed pull resistor
     IO_ADC_PU_10K: pull up 10 kOhm
     IO_ADC_PD_10K: pull down 10 kOhm

     sensor_supply Sensor supply:•IO_SENSOR_SUPPLY_0: 5V
     IO_SENSOR_SUPPLY_1: 5V
     IO_SENSOR_SUPPLY_2: variable
     IO_PIN_NONE: no sensor supply is used

     [in] safety_conf Relevant safety configurations for the checker modules.
     The following ADC channels can be configured safety relevant:
     IO_ADC_00 .. IO_ADC_07
     IO_ADC_08 .. IO_ADC_15
     IO_ADC_16 .. IO_ADC_23
     */

    // Example 1: Safety config for 3-mode ADC (channels 00-07)
    // redundant_channel MUST be IO_PIN_NONE
    IO_ADC_SAFETY_CONF adc_safety_conf_3mode = { 10, // 1. adc_val_lower: Lower limit of 10% (minimum of 4%)
            90,         // 2. adc_val_upper: Upper limit of 90% (maximum of 96%)
            IO_PIN_NONE    // 3. redundant_channel: Required for channels 00-07
            };

    // Example 2: Safety config for 2-mode ADC (channels 08-23) WITHOUT redundancy
    IO_ADC_SAFETY_CONF adc_safety_conf_2mode_no_redundancy = { 5, // 1. adc_val_lower
            95,              // 2. adc_val_upper
            IO_PIN_NONE      // 3. redundant_channel
            };

    // Example 3: Safety config for 2-mode ADC (channels 08-23) with redundancy
    IO_ADC_SAFETY_CONF adc_safety_conf_2mode_with_redundancy_primary = { 10, // 1. adc_val_lower
            90,              // 2. adc_val_upper
            IO_ADC_09 // 3. redundant_channel: Redundant channel for primary channel 08
            };

    // The redundant channel (09) must be initialized separately with IO_PIN_NONE
    IO_ADC_SAFETY_CONF adc_safety_conf_2mode_redundant = { 10, // 1. adc_val_lower: The same limits as the primary channel
            90,              // 2. adc_val_upper
            IO_PIN_NONE // 3. redundant_channel: The redundant channel does NOT reference another channel
            };

    // For PWD mode

    /*
     Contains all service functions for the PWD (Pulse Width Demodulation).
     There are three groups of timer inputs available:

     IO_PWD_00..IO_PWD_05:
     Complex mode: Can be configured to measure frequency and pulse-width at the same time.
     Additionally, a pull up/down interface can be configured. These inputs can accumulate up to 8 pulse samples. An average value is calculated automatically, but all samples are available on demand. These inputs support voltage and current signals (7mA/14mA). For current signals an additional range check is done.

     Incremental mode:

     Can be configured to read incremental (relative) encoders. In this case two inputs are reserved for one incremental encoder (clock and direction) interface. Additionally, a pull up/down interface can be configured. The incremental interface will decrement when the 1st channel is leading and increment when the 2nd channel is leading. These inputs support voltage signals only.

     Count mode:

     Can be configured to count rising, falling or both edges.
     Additionally, a pull up/down interface can be configured. These inputs support voltage signals only.
     Universal mode: Can be configured as a combination of complex, incremental and count mode.

     IO_PWD_06..IO_PWD_11:
     Complex mode: Can be configured to measure frequency and pulse-width at the same time.
     Additionally, a pull up/down interface can be configured. These inputs can accumulate up to 8 pulse samples.
     An average value is calculated automatically. The different pulse samples cannot be gathered. These inputs support voltage signals only.

     Incremental mode:

     Can be configured to read incremental (relative) encoders.
     In this case two inputs are reserved for one incremental encoder (clock and direction) interface.
     Additionally, a pull up/down interface can be configured.
     The incremental interface will decrement when the 1st channel is leading and increment when the 2nd channel is leading. These inputs support voltage signals only.

     Count mode:

     Can be configured to count rising, falling or both edges.
     Additionally, a pull up/down interface can be configured.
     These inputs support voltage signals only.

     IO_PWD_12..IO_PWD_19:

     Complex mode:

     Can be configured to measure frequency and pulse-width at the same time.
     However, these inputs do not accumulate a number of samples.
     Instead every pulse sample has to be handled directly. These inputs support voltage signals only.

     Setup single timer channel that measures frequency and pulse-width at the same time.
     Parameters
     timer_channel Timer channel:
     IO_PWD_00 .. IO_PWD_05
     IO_PWD_06 .. IO_PWD_11
     IO_PWD_12 .. IO_PWD_19

     pulse_mode Specifies the pulse mode•IO_PWD_HIGH_TIME:
     configuration to measure pulse-high-time
     IO_PWD_LOW_TIME: configuration to measure pulse-low-time
     IO_PWD_PERIOD_TIME: configuration to measure pulse-high and low-time (Period)

     freq_mode Specifies the variable edge•IO_PWD_RISING_VAR:
     rising edge is variable this means, frequency is measured on falling edges
     IO_PWD_FALLING_VAR: falling edge is variable this means, frequency is measured on rising edges

     capture_count Number of frequency/pulse-width measurements that will be accumulated (1..8)
     pupd Pull up/down interface:
     IO_PWD_NO_PULL: fixed pull resistor
     IO_PWD_PU_10K: Pull up 10 kOhm
     IO_PWD_PD_10K: Pull down 10 kOhm
     IO_PWD_PD_90: Pull down 90 Ohm (for 7mA/14mA sensors)

     [in] safety_conf Relevant safety configurations for the checker modules
     */


    // PWD SAFETY CONFIGURATIONS

    // 1. Complex Mode Safety Config (supported only for channels 00-05)
    static const IO_PWD_CPLX_SAFETY_CONF pwd_cplx_safety_conf = { 1000, // 1. frequency_min
            20000000,   // 2. frequency_max
            100,        // 3. pulse_width_min
            1000000     // 4. pulse_width_max:
            };

    // 2. Incremental/Count Mode Safety Config (supported only for channels 00-05)
    static const IO_PWD_INC_SAFETY_CONF pwd_inc_safety_conf = { 0, // 1. count_min
            65535       // 2. count_max
            };

    // 3. Universal Mode Safety Config (supported only for channels 00-05)

    //   1. pwd_inc_safety_conf
    //   2. pwd_cnt_safety_conf
    //   3. pwd_cplx_safety_conf
    static const IO_PWD_UNIVERSAL_SAFETY_CONF pwd_universal_safety_conf = {
    NULL,                   // 1. pwd_inc_safety_conf: no used
            NULL,                   // 2. pwd_cnt_safety_conf: no used
            &pwd_cplx_safety_conf   // 3. pwd_cplx_safety_conf:
            };


    /* For PVG mode:

     IO Driver functions for PVG channels.

     Contains all service functions for the PVG (Proportional Valve Group) outputs. Up to 8 channels can be configured: IO_PVG_00 .. IO_PVG_07

     PVG valves are active valves with integrated electronic control. The input impedance is defined with 12kOhm to 50% Ubat (2 * 24kOhm to Ubat and GND).

     The PVG output stage is a push/pull PWM output with a well defined output resistance of 2.58kOhm. This resistance is necessary for operation, low pass filtering and over load protection.
     NoteThe correction of the PVG impedance is directly performed inside the module. Therefore a PVG valve is needed for correct operation of this outputs.
     When configuring a PVG output, the associated voltage feedback channel will also be configured.

     PVG-API Usage:

     */


    // For DO mode:

    /* Contains all service functions for the digital in/outputs.

     NoteThe digital inputs reflect the current status of the input at the point in time where the function is called.
     The digital outputs IO_DO_00 .. IO_DO_15 are controlled over SPI shift registers,
     therefore the outputs will be periodically updated with a cycle of 1ms.

     Note:
     The error code IO_E_CM_CALIBRATION is only returned for IO_DO_16 .. IO_DO_51

     Remarks:
     The digital output channels IO_DO_00 .. IO_DO_15 are controlled over SPI shift registers.
     Therefore the outputs will be periodically updated with a cycle of 1ms.

     The digital output channels IO_DO_16 .. IO_DO_51 are an alternative function to IO_PWM_00 .. IO_PWM_35.
     The digital output channels IO_DO_52 .. IO_DO_59 are an alternative function to IO_PVG_00 .. IO_PVG_07.
     The parameter diagnostic is only applied to the channels IO_DO_00 .. IO_DO_07 and IO_DO_52 .. IO_DO_59.

     If diagnostic is TRUE, the output can detect open load and short circuit.
     If it is FALSE, the output can not detect open load or short circuit.
     Select FALSE for loads with low current consumption like LEDs. With diagnostic == FALSE the pull up will be switched off.

     If safety_conf != NULL, a low side and high side channel have to be connected together.
     The internal checker modules check the given channels against the parameter in safety_conf.
     For more detail about each parameter look on the definition of IO_DO_SAFETY_CONF

     If safety_conf != NULL, the parameter diagnostic is forced to TRUE to allow diagnostics

     */
    // For channels the IO_DO_00..IO_DO_07 (with safety):
    IO_DO_SAFETY_CONF do_safety_conf_IO_DO_00___07 = { 0 };

    // For channels the IO_DO_08..IO_DO_15 (with safety):
    IO_DO_SAFETY_CONF do_safety_conf_IO_DO_08__15 = { IO_DO_08 }; // low side channel

    // For PWM mode:

    /*
     * For the equidistant current measurement to work properly
     * only certain frequencies are supported:
     * ============================================================================
     * Available frequencies:
     * ============================================================================
     * Period[ms] | Frequency[Hz]    | Current sample period[ms]
     * -----------+------------------+---------------------------
     * 1          | 1000             | 1
     * 1.25       | 800              | 5
     * 1.5        | 666 (666.6666)   | 3
     * 1.75       | 571 (571.4285)   | 7
     * 2          | 500              | 2
     * 2.25       | 444 (444.4444)   | 9
     * 2.5        | 400              | 5
     * 2.75       | 363 (363.6363)   | 11
     * 3          | 333 (333.3333)   | 3
     * 3.25       | 307 (307.6923)   | 13
     * 3.5        | 285 (285.7142)   | 7
     * 3.75       | 266 (266.6666)   | 15
     * 4          | 250              | 4
     * 4.25       | 235 (235.2941)   | 17
     * 4.5        | 222 (222.2222)   | 9
     * 4.75       | 210 (210.5263)   | 19
     * 5          | 200              | 5
     * 5.5        | 181 (181.8181)   | 11
     * 6          | 166 (166.6666)   | 6
     * 6.5        | 153 (153.8461)   | 13
     * 7          | 142 (142.8571)   | 7
     * 7.5        | 133 (133.3333)   | 15
     * 8          | 125              | 8
     * 8.5        | 117 (117.6470)   | 17
     * 9          | 111 (111.1111)   | 9
     * 9.5        | 105 (105.2631)   | 19
     * 10         | 100              | 10
     * 11         | 90 (90.9090)     | 11
     * 12         | 83 (83.3333)     | 12
     * 13         | 76 (76.9230)     | 13
     * 14         | 71 (71.4285)     | 14
     * 15         | 66 (66.6666)     | 15
     * 16         | 62 (62.5)        | 16
     * 17         | 58 (58.8235)     | 17
     * 18         | 55 (55.5555)     | 18
     * 19         | 52 (52.6315)     | 19
     * 20         | 50               | 20
     * ============================================================================

     If you select an unavailable frequency within the allowed range, the next higher available
     frequency will be used. For example, if 180 Hz is specified, 181.8 Hz will be used.

     The associated timer loopback channel will also be configured for open load and short circuit detection.

     The associated current measurement will also be configured.

     The duty cycle cannot exceed the margin of 100us(lower boundary)
     and 200us(upper boundary) used for diagnostic if the parameter
     diag_margin is TRUE. This mode is important for hydraulic coils.
     If the parameter diag_margin is FALSE, no duty cycle range margin will be applied.

     All PWM channels have their own frequency time base.

     If safety_conf != NULL, the internal checker modules check the given channels

     against the current parameter in safety_conf, and the period and duty cycle
     feedback against the output. For more details about the current checking refer to the definition of IO_PWM_SAFETY_CONF.

     If safety_conf != NULL, the parameter diag_margin is forced to TRUE to allow diagnostics

     Static friction and stiction can cause a hysteresis and make
     the control of a hydraulic valve erratic and unpredictable. In order to counteract these hysteresis effects,
     small vibrations about the desired position shall be created in the valve.

     This constantly breaks the static friction ensuring that
     it will move even with small input changes, and the effects of hysteresis
     are average out. A proper setting of PWM frequency according to the resonance frequency of the actuator
     allows to adjust this desired small vibration, low enough in amplitude to
     prevent noticeable oscillations on the hydraulic output but sufficient high to prevent friction.

     The PWM frequency can be set in the range of 50 .. 1000Hz,
     a typical range for hydraulic valves to operate without friction is 90 .. 160Hz.

     Unlike with IO_PWM_Init(), the low_side_channel
     field of the safety configuration is evaluated with this function.

     If configured, the low side switch of a PWM channel is
     switched on and off together with the high side safety switch of the channel.

     The remarks for IO_PWM_Init() also apply here.
     */

    static const IO_PWM_SAFETY_CONF safety_conf = { 1000, TRUE,
    IO_PIN_NONE };

    /*
     Field Documentation:

     ubyte2 IO_PWM_SAFETY_CONF::current_limit

     Current limit in mA [0 .. 7500].
     The diagnostic component of the I/O driver will check
     if the electric current through the load does not exceed the specified limit

     bool IO_PWM_SAFETY_CONF::enable_current_check

     If set to TRUE the diagnostic component of the I/O driver will check
     if the electric current through the load is within the specified limits

     ubyte1 IO_PWM_SAFETY_CONF::low_side_channel

     Low side channel which is connected to the load on the configured PWM channel as a tertiary
     shut-off path. This channel is switched on and off together
     with the PWM channel's secondary shut-off path, the safety switch.
     Only one safety-critical PWM channel or HS digital output can be connected to a low-side channel.

     IO_PIN_NONE if the load is connected to the ground
     IO_DO_08 .. IO_DO_15 if the load is connected to a low side switch
     */

    // For VOUT mode:
    /*Detailed Description

     IO Driver functions for voltage outputs.

     Contains all service functions for the voltage outputs.
     Up to 8 channels can be configured: IO_VOUT_00 .. IO_VOUT_07

     The voltage output stage is a push/pull PWM output with
     a well defined output resistance of 2.58kOhm.
     This resistance is necessary for operation, low pass filtering and over load protection.
     NoteThe voltage output is limited to resistive loads to ground with 10kOhm or higher.
     The outputs will be activated after setting them via IO_VOUT_SetVoltage().

     When configuring a voltage output,
     the associated voltage feedback channel will also be configured.
     NoteDeviations on the power supply are automatically corrected by the module.
     */

    // PinInit function

    extern void Init_Pin(ubyte1 group_idx, ubyte1 pin_idx, ubyte1 pin_value);

#endif /* PIN_CAPABILITIES_H_ */
