/**************************************************************************************************
 * \file PinCapabilities.h
 * \brief Configuration structures for initializing pins by internal number (0-95)
 *************************************************************************************************/

#ifndef PIN_CAPABILITIES_H_
#define PIN_CAPABILITIES_H_

#include "IO_Pin.h"
#include "IO_DIO.h"
#include "IO_ADC.h"
#include "IO_PWM.h"
#include "IO_PVG.h"
#include "IO_PWD.h"
#include "IO_VOUT.h"

#define PIN_MODE_COUNT    8U    // Total number of modes (including NONE)

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

// Mode numbers (for use in code and CAN commands)

typedef enum
{
    PIN_MODE_NONE = 0U,   // Mode not assigned/not supported
    PIN_MODE_DI = 1U,   // DI
    PIN_MODE_ADC = 2U,   // ADC
    PIN_MODE_PWD = 3U,   // PWD
    PIN_MODE_PVG = 4U,   // PVG
    PIN_MODE_DO = 5U,   // DO
    PIN_MODE_PWM = 6U,   // PWM
    PIN_MODE_VOUT = 7U    // VOUT
} PinMode_t;

// Single Pin capabilities

typedef struct
{
    ubyte1 connector_pin;     // Physical number on the connector (IO_PIN_103, etc.)
    ubyte1 internal_pin;            // Internal number (0-95) - array index
    ubyte1 modes[PIN_MODE_COUNT];   // Channel array for each mode
                                    // modes[PIN_MODE_DI] = IO_DI_50
                                    // modes[PIN_MODE_ADC] = IO_ADC_02
                                    // modes[PIN_MODE_NONE] = IO_PIN_NONE
} PinCapabilities_t;

// Global array

extern PinCapabilities_t g_pin_capabilities[96];

// Functions

/**
 * @brief Initialization of the pin capabilities array
 */

extern void Init_PinCapabilities(void);

/**
 * @brief Checks if the pin supports the specified mode
 * @param internal_pin Internal pin number (0..95)
 * @param mode Operation mode (PIN_MODE_DI, PIN_MODE_ADC, etc.)
 * @return TRUE if the mode is supported, FALSE if not
 */

extern inline ubyte1 Is_Pin_Capable(ubyte1 internal_pin, PinMode_t mode);

/**
 * @brief Get channel for given pin mode
 * @param internal_pin Internal pin number (0..95)
 * @param mode Mode of operation (PIN_MODE_DI, PIN_MODE_ADC etc.)
 * @return IO_DI_XX, IO_ADC_XX etc. or IO_PIN_NONE if not supported
 */

extern inline ubyte1 Get_Channel_ForMode(ubyte1 internal_pin, PinMode_t mode);

/**
 * @brief Get the number of supported modes for a pin
 * @param internal_pin Internal pin number (0..95)
 * @return The number of supported modes (0..7)
 */

extern inline ubyte1 Get_SupportedModesCount(ubyte1 internal_pin);

#endif /* PIN_CAPABILITIES_H_ */
