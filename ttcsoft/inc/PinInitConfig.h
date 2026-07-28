/**************************************************************************************************
 * \file PinInitConfig.h
 * \brief Структуры конфигурации для инициализации пинов по внутреннему номеру (0-95)
 *************************************************************************************************/

#ifndef PIN_INIT_CONFIG_H_
#define PIN_INIT_CONFIG_H_

#include "IO_Driver.h"
#include "IO_DIO.h"
#include "IO_ADC.h"
#include "IO_PWM.h"
#include "IO_PWD.h"
#include "IO_PVG.h"
#include "IO_VOUT.h"
#include <stdbool.h>

// ==========================================
// 1. ОПРЕДЕЛЕНИЕ ОСНОВНЫХ РЕЖИМОВ РАБОТЫ (1-7)
// ==========================================
typedef enum {
    PIN_MODE_DI    = 1,  ///< Digital Input
    PIN_MODE_ADC   = 2,  ///< Analog-to-Digital Converter
    PIN_MODE_PWD   = 3,  ///< Pulse Width Demodulation (Timer Input)
    PIN_MODE_PVG   = 4,  ///< Proportional Valve Group
    PIN_MODE_DO    = 5,  ///< Digital Output
    PIN_MODE_PWM   = 6,  ///< Pulse Width Modulation
    PIN_MODE_VOUT  = 7   ///< Voltage Output
} PinMode_e;

// ==========================================
// 2. СТРУКТУРЫ НАСТРОЕК ДЛЯ КАЖДОГО РЕЖИМА
// ==========================================

/**
 * \brief Настройки для Digital Input (IO_DI_Init)
 *
 * \attention АППАРАТНЫЕ ОГРАНИЧЕНИЯ ПО ГРУППАМ КАНАЛОВ:
 * - IO_DI_00..35  : Параметры \c pupd и \c limits ИГНОРИРУЮТСЯ. Фиксированный порог 2.5V.
 *                   Подходит ТОЛЬКО для ключей на землю (GND).
 * - IO_DI_36..47  : Поддерживает \c pupd: IO_DI_PU_10K или IO_DI_PD_10K. \c limits ИГНОРИРУЕТСЯ.
 * - IO_DI_48..55  : Параметры \c pupd и \c limits ИГНОРИРУЮТСЯ. Фиксированный порог 2.5V.
 *                   Подходит ТОЛЬКО для ключей на землю (GND).
 * - IO_DI_56..63  : Поддерживает \c limits. \c pupd ИГНОРИРУЕТСЯ. Подходит ТОЛЬКО для ключей на питание (BAT).
 * - IO_DI_64..71  : Поддерживает \c limits. \c pupd ИГНОРИРУЕТСЯ. Подходит ТОЛЬКО для ключей на питание (BAT).
 * - IO_DI_72..79  : Поддерживает \c pupd (PU_10K/PD_10K) и \c limits.
 * - IO_DI_80..87  : Поддерживает \c limits. \c pupd ИГНОРИРУЕТСЯ (имеет фиксированную внутреннюю подтяжку).
 * - IO_DI_88..95  : Поддерживает \c pupd (PU_10K/PD_10K) и \c limits.
 *
 * \note Если указатель \c limits равен NULL, применяются значения по умолчанию: {0, 2500, 2500, 32000} мВ.
 * \note Правило для limits: low_thresh1 < low_thresh2 < high_thresh1 < high_thresh2.
 */
typedef struct {
    ubyte1 pupd;                          // IO_DI_NO_PULL (0x00), IO_DI_PU_10K (0x01), IO_DI_PD_10K (0x02)
    const IO_DIO_LIMITS* limits;          // Указатель на лимиты напряжений (или NULL для дефолтных)
} PinConfigDI_t;

/**
 * \brief Настройки для Digital Output (IO_DO_Init)
 *
 * \attention АППАРАТНЫЕ ОГРАНИЧЕНИЯ:
 * - Параметр \c diagnostic=true работает ТОЛЬКО для каналов IO_DO_00..07 и IO_DO_52..59.
 *   Для остальных каналов он игнорируется, а внутренняя подтяжка диагностики отключается
 *   (используйте FALSE для нагрузок с низким потреблением, например, светодиодов).
 * - Конфигурация безопасности (\c safety_conf) поддерживается СТРОГО ТОЛЬКО для каналов IO_DO_00..07.
 * - \warning Если \c safety_conf != NULL, параметр \c diagnostic автоматически форсируется в TRUE.
 * - \warning Для корректной диагностики на каналах IO_DO_00..15 требуется задержка не менее 20 мс
 *   между переключениями состояния выхода.
 *
 * \note Время ожидания (Wait time) для сброса защиты (IO_DO_ResetProtection):
 *   - 1 секунда для IO_DO_00..15 и IO_DO_52..59.
 *   - 10 секунд для IO_DO_16..51.
 * \note Количество попыток сброса защиты ограничено 10 разами. Функция сброса НЕ возвращает
 *       выход в состояние HIGH; после сброса необходимо явно вызвать IO_DO_Set().
 */
typedef struct {
    bool diagnostic;                      // true = включить диагностическую подтяжку
    const IO_DO_SAFETY_CONF* safety_conf; // Указатель на safety конфиг (или NULL)
} PinConfigDO_t;

/**
 * \brief Настройки для ADC (IO_ADC_ChannelInit)
 *
 * \attention АППАРАТНЫЕ ОГРАНИЧЕНИЯ ПО ГРУППАМ КАНАЛОВ:
 * - IO_ADC_00..07  : type=RATIOMETRIC, CURRENT, RESISTIVE, ABSOLUTE. range=5V (NO_RANGE).
 *                    sensor_supply=0,1,2. safety_conf=ПОДДЕРЖИВАЕТСЯ.
 * - IO_ADC_08..15  : type=RATIOMETRIC, CURRENT, ABSOLUTE. range=5V, 10V.
 *                    sensor_supply=0,1,2. safety_conf=ПОДДЕРЖИВАЕТСЯ.
 * - IO_ADC_16..23  : type=RATIOMETRIC, CURRENT, ABSOLUTE. range=5V, 32V.
 *                    sensor_supply=0,1,2. safety_conf=ПОДДЕРЖИВАЕТСЯ.
 * - IO_ADC_24..59  : type=RATIOMETRIC, ABSOLUTE. range=32V. pupd=PU_10K, PD_10K.
 *                    sensor_supply=0,1,2 (только для RATIOMETRIC).
 *                    safety_conf=НЕ ПОДДЕРЖИВАЕТСЯ.
 *
 * \warning Для safety critical конфигурации (safety_conf != NULL) ЗАПРЕЩЕНО использовать:
 *          - Тип измерения IO_ADC_RESISTIVE
 *          - Sensor supply IO_SENSOR_SUPPLY_2
 *
 * \note Защита от перегрузки по току (IO_ADC_ResetProtection) доступна ТОЛЬКО для каналов 00..23
 *       и ТОЛЬКО если type == IO_ADC_CURRENT. Время ожидания сброса: 1с. Максимум 10 сбросов.
 */
typedef struct {
    ubyte1 type;                          // IO_ADC_RATIOMETRIC, IO_ADC_CURRENT, IO_ADC_RESISTIVE, IO_ADC_ABSOLUTE
    ubyte1 range;                         // IO_ADC_NO_RANGE, IO_ADC_RANGE_5V, IO_ADC_RANGE_10V, IO_ADC_RANGE_32V
    ubyte1 pupd;                          // IO_ADC_NO_PULL, IO_ADC_PU_10K, IO_ADC_PD_10K
    ubyte1 sensor_supply;                 // IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1, IO_SENSOR_SUPPLY_2 или IO_PIN_NONE
    const IO_ADC_SAFETY_CONF* safety_conf;// Указатель на safety конфиг (или NULL)
} PinConfigADC_t;

/**
 * \brief Настройки для PWM (IO_PWM_Init / IO_PWM_InitWithLowside)
 *
 * \attention АППАРАТНЫЕ ОГРАНИЧЕНИЯ:
 * - Частота должна быть в диапазоне 50..1000 Гц. Поддерживаются только частоты, кратные 1мс, 0.5мс или 0.25мс.
 *   Если указана неподдерживаемая частота, драйвер автоматически округлит её до ближайшей более высокой.
 * - Все 36 каналов (IO_PWM_00..35) поддерживают измерение тока, timer feedback и защиту.
 * - \warning Если safety_conf != NULL, параметр diag_margin автоматически форсируется в TRUE.
 * - \warning При использовании use_lowside_init=true, в safety_conf ОБЯЗАТЕЛЬНО должен быть задан low_side_channel.
 *
 * \note Время ожидания сброса защиты (FET protection) для ВСЕХ каналов PWM составляет 10 секунд. Максимум 10 сбросов.
 * \attention ВАЖНО: В момент инициализации PWM актуатор должен быть полностью разряжен, иначе калибровка
 *          измерения тока (IO_E_CM_CALIBRATION) завершится ошибкой.
 */
typedef struct {
    ubyte2 frequency;                     // Частота в Гц (50..1000)
    bool polarity;                        // true = High output signal is variable, false = Low is variable
    bool diag_margin;                     // true = включить диагностический зазор (100us нижний, 200us верхний). Критично для гидравлики.
    bool use_lowside_init;                // true = вызвать IO_PWM_InitWithLowside вместо IO_PWM_Init
    const IO_PWM_SAFETY_CONF* safety_conf;// Конфиг безопасности (или NULL)
} PinConfigPWM_t;

/* ==========================================================================
 * НАСТРОЙКИ ДЛЯ PWD (4 разных режима инициализации)
 * ========================================================================== */

typedef enum {
    PWD_SUBMODE_COMPLEX   = 0,  ///< Измерение частоты и ширины импульса (IO_PWD_ComplexInit)
    PWD_SUBMODE_INC       = 1,  ///< Инкрементальный энкодер (IO_PWD_IncInit)
    PWD_SUBMODE_COUNT     = 2,  ///< Подсчет фронтов (IO_PWD_CountInit)
    PWD_SUBMODE_UNIVERSAL = 3   ///< Комбинация режимов, ТОЛЬКО для PWD 00-05 (IO_PWD_UniversalInit)
} PwdSubMode_e;

/**
 * \brief Настройки для PWD Complex mode
 * \attention ОГРАНИЧЕНИЯ ПО ГРУППАМ:
 * - IO_PWD_00..05: pupd=PU_10K, PD_10K, PD_90. capture_count=1..8. safety_conf=ПОДДЕРЖИВАЕТСЯ. Макс. частота=20 кГц.
 * - IO_PWD_06..11: pupd=PU_10K, PD_10K (PD_90 НЕДОПУСТИМ). capture_count=1..8. safety_conf=НЕ ПОДДЕРЖИВАЕТСЯ. Макс. частота=20 кГц.
 * - IO_PWD_12..19: pupd=ТОЛЬКО NO_PULL. capture_count=СТРОГО 1. safety_conf=НЕ ПОДДЕРЖИВАЕТСЯ. Макс. частота=10 кГц.
 *
 * \note Передача IO_PWD_PD_90 конфигурирует вход для токового датчика (7mA/14mA) с дополнительной проверкой диапазона.
 * \note Для каналов 00..05 таймер 27-бит (макс. период ~67с). Для 06..19 аппаратное ограничение 10 секунд.
 */
typedef struct {
    ubyte1 pulse_mode;                    // IO_PWD_LOW_TIME, IO_PWD_HIGH_TIME, IO_PWD_PERIOD_TIME
    ubyte1 freq_mode;                     // IO_PWD_RISING_VAR, IO_PWD_FALLING_VAR
    ubyte1 capture_count;                 // 1..8 (ВНИМАНИЕ: для PWD 12-19 драйвер игнорирует это и всегда использует 1!)
    ubyte1 pupd;                          // IO_PWD_NO_PULL, IO_PWD_PU_10K, IO_PWD_PD_10K, IO_PWD_PD_90
    const IO_PWD_CPLX_SAFETY_CONF* safety_conf;
} PinConfigPWD_Complex_t;

/**
 * \brief Настройки для PWD Incremental mode
 * \attention Поддерживается ТОЛЬКО для IO_PWD_00..11.
 * \note Два канала PWD резервируются под один энкодер: (00+01), (02+03), (04+05), (06+07), (08+09), (10+11).
 * \note pupd=ТОЛЬКО PU_10K или PD_10K. safety_conf поддерживается ТОЛЬКО для 00..05.
 */
typedef struct {
    ubyte1 mode;                          // IO_PWD_INC_1_COUNT или IO_PWD_INC_2_COUNT
    ubyte2 count_init;                    // Начальное значение счетчика (0..65535)
    ubyte1 pupd;                          // IO_PWD_PU_10K или IO_PWD_PD_10K
    const IO_PWD_INC_SAFETY_CONF* safety_conf;
} PinConfigPWD_Inc_t;

/**
 * \brief Настройки для PWD Count mode
 * \attention Поддерживается ТОЛЬКО для IO_PWD_00..11.
 * \note pupd=ТОЛЬКО PU_10K или PD_10K. safety_conf поддерживается ТОЛЬКО для 00..05.
 */
typedef struct {
    ubyte1 mode;                          // IO_PWD_RISING_COUNT, IO_PWD_FALLING_COUNT, IO_PWD_BOTH_COUNT
    ubyte1 direction;                     // IO_PWD_UP_COUNT или IO_PWD_DOWN_COUNT
    ubyte2 count_init;                    // Начальное значение счетчика (0..65535)
    ubyte1 pupd;                          // IO_PWD_PU_10K или IO_PWD_PD_10K
    const IO_PWD_INC_SAFETY_CONF* safety_conf;
} PinConfigPWD_Count_t;

/**
 * \brief Настройки для PWD Universal mode
 * \attention Поддерживается СТРОГО ТОЛЬКО для IO_PWD_00..05.
 * \warning Если настроен incremental mode, оба канала настраиваются избыточно. Приложение должно периодически
 *          вызывать IO_PWD_UniversalGet() для ОБОИХ каналов, если complex или edge counter mode настроены как safety.
 */
typedef struct {
    const IO_PWD_CPLX_CONF* cplx_conf;    // Конфигурация Complex режима
    const IO_PWD_CNT_CONF* cnt_conf;      // Конфигурация счетчика
    const IO_PWD_INC_CONF* inc_conf;      // Конфигурация инкрементального режима
    ubyte1 pupd;                          // IO_PWD_PU_10K, IO_PWD_PD_10K, IO_PWD_PD_90
    const IO_PWD_UNIVERSAL_SAFETY_CONF* safety_conf;
} PinConfigPWD_Universal_t;

/** \brief Главная структура PWD с указанием подрежима (экономит RAM через union) */
typedef struct {
    PwdSubMode_e submode;                 // Указывает, какое поле union ниже активно
    union {
        PinConfigPWD_Complex_t complex;
        PinConfigPWD_Inc_t inc;
        PinConfigPWD_Count_t count;
        PinConfigPWD_Universal_t universal;
    } cfg;
} PinConfigPWD_t;

/**
 * \brief Настройки для PVG (IO_PVG_Init)
 *
 * \attention АППАРАТНЫЕ ОГРАНИЧЕНИЯ:
 * - Значение output_value ДОЛЖНО быть строго в диапазоне 1000..9000 (что соответствует 10.00% .. 90.00%).
 *   Значения вне этого диапазона вернут IO_E_INVALID_PARAMETER.
 * - Выходной каскад имеет фиксированное сопротивление 2.58 кОм. Для корректной работы ОБЯЗАТЕЛЬНО
 *   подключение реального PVG-клапана (входное сопротивление клапана ~12 кОм к 50% Ubat).
 *
 * \note Время ожидания сброса защиты (FET protection) составляет 1 секунду. Лимит сбросов: 10 раз.
 * \warning После сброса защиты выход НЕ восстанавливает последнее заданное значение. Необходимо явно
 *          вызвать IO_PVG_SetOutput() для установки нужного уровня.
 */
typedef struct {
    ubyte2 output_value;                  // 1000..9000 (10.00% .. 90.00%)
} PinConfigPVG_t;

/**
 * \brief Настройки для VOUT (IO_VOUT_Init)
 *
 * \attention АППАРАТНЫЕ ОГРАНИЧЕНИЯ:
 * - Выход ограничен резистивной нагрузкой на землю с сопротивлением 10 кОм и выше.
 * - initial_voltage_mv должен быть в диапазоне 0..32000 мВ (0В .. 32В).
 *
 * \note Время ожидания сброса защиты (FET protection) составляет 1 секунду. Лимит сбросов: 10 раз.
 * \note Если initial_voltage_mv > 0, система автоматически вызовет IO_VOUT_SetVoltage после инициализации.
 * \warning После сброса защиты выход НЕ восстанавливает последнее заданное напряжение. Необходимо явно
 *          вызвать IO_VOUT_SetVoltage() для установки нужного уровня.
 */
typedef struct {
    ubyte2 initial_voltage_mv;            // 0..32000 мВ (0В .. 32В)
} PinConfigVOUT_t;

// ==========================================
// 3. ГЛАВНАЯ СТРУКТУРА ИНИЦИАЛИЗАЦИИ ПИНА
// ==========================================

/**
 * \brief Полная структура параметров для инициализации одного пина
 *
 * Использует union для экономии RAM. Размер структуры фиксирован (~24-28 байт)
 * и не зависит от выбранного режима, что позволяет создавать компактные массивы конфигураций.
 */
typedef struct {
    ubyte1 internal_pin;    // Внутренний номер пина (0..95)
    PinMode_e mode;         // Выбранный режим работы (1..7)

    // Union хранит только параметры активного режима, экономя память
    union {
        PinConfigDI_t   di;
        PinConfigDO_t   do_; // do_ вместо do, так как 'do' - ключевое слово в C
        PinConfigADC_t  adc;
        PinConfigPWM_t  pwm;
        PinConfigPWD_t  pwd; // Содержит submode и union конкретных настроек
        PinConfigPVG_t  pvg;
        PinConfigVOUT_t vout;
    } cfg;
} PinInitParams_t;

#endif /* PIN_INIT_CONFIG_H_ */
