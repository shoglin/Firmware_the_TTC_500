#ifndef PIN_SETTINGS_h_
#define PIN_SETTINGS_h_

#include "IO_DIO.h"
#include "IO_ADC.h"
#include "IO_PWD.h"
#include "IO_PVG.h"
#include "IO_PWM.h"
#include "IO_VOUT.h"

#define PINS 96U

/**
 *
 * @brief Структура параметров инициализации цифрового входа (DI)
 *
 * Повторяет сигнатуру функции IO_DI_Init() и содержит все необходимые
 * параметры для настройки канала.
 */

typedef struct
{
    /**
     * @brief Канал цифрового входа (Digital input channel)
     *
     * Допустимые значения (алиасы пинов):
     * - IO_DI_00.. IO_DI_35
     * - IO_DI_36.. IO_DI_47
     * - IO_DI_48.. IO_DI_55
     * - IO_DI_56.. IO_DI_63
     * - IO_DI_64.. IO_DI_71
     * - IO_DI_72.. IO_DI_79
     * - IO_DI_80.. IO_DI_87
     * - IO_DI_88.. IO_DI_95
     */
    ubyte1 pin_channel;

    /**
     * @brief Конфигурация подтягивающего резистора (Pull up/down configuration)
     *
     * Допустимые значения:
     * - IO_DI_NO_PULL (0x00U): fixed pull resistor (фиксированный резистор)
     * - IO_DI_PU_10K  (0x01U): Pull up 10 kOhm (подтяжка к питанию)
     * - IO_DI_PD_10K  (0x02U): Pull down 10 kOhm (подтяжка к земле)
     *
     * @attention Поддержка параметра зависит от группы каналов:
     * - IO_DI_00.. IO_DI_35: параметр игнорируется (fixed pull)
     * - IO_DI_36.. IO_DI_47: поддерживаются IO_DI_PU_10K или IO_DI_PD_10K
     * - IO_DI_48.. IO_DI_55: параметр игнорируется (fixed pull)
     * - IO_DI_56.. IO_DI_63: параметр игнорируется
     * - IO_DI_64.. IO_DI_71: параметр игнорируется
     * - IO_DI_72.. IO_DI_79: поддерживаются IO_DI_PU_10K или IO_DI_PD_10K
     * - IO_DI_80.. IO_DI_87: параметр игнорируется (fixed pull up)
     * - IO_DI_88.. IO_DI_95: поддерживаются IO_DI_PU_10K или IO_DI_PD_10K
     */
    ubyte1 pull_resistor;

    /**
     * @brief Пределы напряжения для уровней low/high (Voltage limits)
     *
     * Указатель на структуру IO_DIO_LIMITS.
     * Если передать NULL, будут использованы пределы по умолчанию (default limits).
     *
     * @attention Поддержка параметра зависит от группы каналов:
     * - IO_DI_00.. IO_DI_35: игнорируется
     * - IO_DI_36.. IO_DI_47: игнорируется
     * - IO_DI_48.. IO_DI_55: игнорируется
     * - IO_DI_56.. IO_DI_63: поддерживается (Voltage limits for low/high-levels)
     * - IO_DI_64.. IO_DI_71: поддерживается (Voltage limits for low/high-levels)
     * - IO_DI_72.. IO_DI_79: поддерживается (Voltage limits for low/high-levels)
     * - IO_DI_80.. IO_DI_87: поддерживается (Voltage limits for low/high-levels)
     * - IO_DI_88.. IO_DI_95: поддерживается (Voltage limits for low/high-levels)
     */
    const IO_DIO_LIMITS *voltage_limits;

} DI_Config_t;

/**
 * @brief Структура параметров инициализации аналогового входа (ADC)
 *
 * Повторяет сигнатуру функции IO_ADC_ChannelInit() и содержит все необходимые
 * параметры для настройки канала.
 */

typedef struct
{
    /**
     * @brief Канал аналогового входа (ADC channel)
     *
     * Допустимые значения (алиасы пинов):
     * - IO_ADC_00.. IO_ADC_07   (3 mode ADC: 0-5V, ток, сопротивление)
     * - IO_ADC_08.. IO_ADC_15   (2 mode 10V ADC: 0-5V/0-10V, ток)
     * - IO_ADC_16.. IO_ADC_23   (2 mode 32V ADC: 0-5V/0-32V, ток)
     * - IO_ADC_24.. IO_ADC_35   (Normal ADC: альтернативная функция PWD)
     * - IO_ADC_36.. IO_ADC_43   (Normal ADC: альтернативная функция DO)
     * - IO_ADC_44.. IO_ADC_51   (Normal ADC: альтернативная функция DO)
     * - IO_ADC_52.. IO_ADC_59   (Normal ADC: альтернативная функция PVG/VOUT)
     * - IO_ADC_SENSOR_SUPPLY_0  (мониторинг питания датчиков 5V)
     * - IO_ADC_SENSOR_SUPPLY_1  (мониторинг питания датчиков 5V)
     * - IO_ADC_SENSOR_SUPPLY_2  (мониторинг питания датчиков переменного)
     * - IO_ADC_K15              (Terminal 15)
     * - IO_ADC_WAKE_UP          (Wake-Up)
     * - IO_ADC_UBAT             (BAT+ CPU)
     * - IO_ADC_SAFETY_SW_0      (Safety Switch 0)
     * - IO_ADC_SAFETY_SW_1      (Safety Switch 1)
     * - IO_ADC_SAFETY_SW_2      (Safety Switch 2)
     * - IO_ADC_BOARD_TEMP       (температура платы)
     */
    ubyte1 pin_channel;

    /**
     * @brief Тип входа (Type of input)
     *
     * Допустимые значения:
     * - IO_ADC_RATIOMETRIC (0x00U): ратиометрический вход на питании датчика
     *   Возвращает напряжение в [mV]
     * - IO_ADC_CURRENT (0x01U): токовая петля 0-25mA
     *   Возвращает ток в [uA]
     * - IO_ADC_RESISTIVE (0x02U): резистивный вход 0-100000 Ohm
     *   Возвращает сопротивление в [Ohm]
     * - IO_ADC_ABSOLUTE (0x03U): абсолютное измерение напряжения
     *   Возвращает напряжение в [mV]
     *
     * @attention Поддержка типа зависит от группы каналов:
     * - IO_ADC_00.. IO_ADC_07: все 4 типа поддерживаются
     * - IO_ADC_08.. IO_ADC_15: RATIOMETRIC, CURRENT, ABSOLUTE (RESISTIVE не поддерживается)
     * - IO_ADC_16.. IO_ADC_23: RATIOMETRIC, CURRENT, ABSOLUTE (RESISTIVE не поддерживается)
     * - IO_ADC_24.. IO_ADC_35: только RATIOMETRIC или ABSOLUTE
     * - IO_ADC_36.. IO_ADC_43: только RATIOMETRIC или ABSOLUTE
     * - IO_ADC_44.. IO_ADC_51: только RATIOMETRIC или ABSOLUTE
     * - IO_ADC_52.. IO_ADC_59: только RATIOMETRIC или ABSOLUTE
     * - Все остальные каналы: только ABSOLUTE
     *
     * @attention Для safety-critical конфигурации (safety_conf != NULL):
     * - Резистивный тип IO_ADC_RESISTIVE НЕ допустим
     */
    ubyte1 input_type;

    /**
     * @brief Диапазон входа (Range of input)
     *
     * Допустимые значения:
     * - IO_ADC_NO_RANGE (0x00U): диапазон не настраивается (фиксированный)
     * - IO_ADC_RANGE_5V (0x01U): диапазон 0V..5000mV
     * - IO_ADC_RANGE_10V (0x02U): диапазон 0V..10200mV
     * - IO_ADC_RANGE_32V (0x03U): диапазон 0V..32000mV
     *
     * @attention Поддержка диапазона зависит от группы каналов:
     * - IO_ADC_00.. IO_ADC_07: только NO_RANGE (фиксированный диапазон 0-5V)
     * - IO_ADC_08.. IO_ADC_15: RANGE_5V или RANGE_10V (для ABSOLUTE и RATIOMETRIC)
     * - IO_ADC_16.. IO_ADC_23: RANGE_5V или RANGE_32V (для ABSOLUTE и RATIOMETRIC)
     * - Все остальные каналы: только NO_RANGE
     *
     * @attention Если канал не поддерживает настройку диапазона, значение параметра игнорируется
     */
    ubyte1 voltage_range;

    /**
     * @brief Конфигурация подтягивающего резистора (Pull up/down configuration)
     *
     * Допустимые значения:
     * - IO_ADC_NO_PULL (0x00U): фиксированный резистор
     * - IO_ADC_PU_10K (0x02U): подтяжка к питанию 10 kOhm
     * - IO_ADC_PD_10K (0x01U): подтяжка к земле 10 kOhm
     *
     * @attention Поддержка подтяжки зависит от группы каналов:
     * - IO_ADC_00.. IO_ADC_07: параметр игнорируется
     * - IO_ADC_08.. IO_ADC_15: параметр игнорируется
     * - IO_ADC_16.. IO_ADC_23: параметр игнорируется
     * - IO_ADC_24.. IO_ADC_35: поддерживается PU_10K или PD_10K
     * - IO_ADC_36.. IO_ADC_43: поддерживается PU_10K или PD_10K
     * - IO_ADC_44.. IO_ADC_51: параметр игнорируется
     * - IO_ADC_52.. IO_ADC_59: поддерживается PU_10K или PD_10K
     * - Все остальные каналы: параметр игнорируется
     *
     * @attention Если канал не поддерживает настройку подтяжки, значение параметра игнорируется
     */
    ubyte1 pull_resistor;

    /**
     * @brief Источник питания датчика (Sensor supply)
     *
     * Допустимые значения:
     * - IO_SENSOR_SUPPLY_0: питание датчиков 5V (фиксированное)
     * - IO_SENSOR_SUPPLY_1: питание датчиков 5V (фиксированное)
     * - IO_SENSOR_SUPPLY_2: питание датчиков переменное (5V-10V)
     * - IO_PIN_NONE: источник питания не используется
     *
     * @attention Поддержка источника питания зависит от типа и группы каналов:
     * - Для типа IO_ADC_RATIOMETRIC:
     *   - IO_ADC_00.. IO_ADC_07: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     *   - IO_ADC_08.. IO_ADC_15: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     *   - IO_ADC_16.. IO_ADC_23: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     *   - IO_ADC_24.. IO_ADC_35: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     *   - IO_ADC_36.. IO_ADC_43: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     *   - IO_ADC_44.. IO_ADC_51: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     *   - IO_ADC_52.. IO_ADC_59: поддерживаются SENSOR_SUPPLY_0, SENSOR_SUPPLY_1, SENSOR_SUPPLY_2
     * - Для типов IO_ADC_CURRENT, IO_ADC_RESISTIVE, IO_ADC_ABSOLUTE:
     *   - Все каналы: только IO_PIN_NONE (источник питания не используется)
     *
     * @attention Для safety-critical конфигурации (safety_conf != NULL):
     * - Переменный источник питания IO_SENSOR_SUPPLY_2 НЕ допустим
     *
     * @attention Если канал не поддерживает настройку источника питания, значение параметра игнорируется
     */
    ubyte1 supply_source;

    /**
     * @brief Конфигурация безопасности (Safety configuration)
     *
     * Указатель на структуру IO_ADC_SAFETY_CONF.
     * Если передать NULL, канал будет настроен как не safety-critical.
     *
     * @attention Safety-critical конфигурация поддерживается только для каналов:
     * - IO_ADC_00.. IO_ADC_07
     * - IO_ADC_08.. IO_ADC_15
     * - IO_ADC_16.. IO_ADC_23
     *
     * @attention Для safety-critical конфигурации:
     * - Резистивный тип IO_ADC_RESISTIVE не допустим
     * - Переменный источник питания IO_SENSOR_SUPPLY_2 не допустим
     * - Если настроен источник питания датчика, напряжение питания также будет контролироваться
     *   диагностическими модулями
     */
    const IO_ADC_SAFETY_CONF *safety_settings;

} ADC_Config_t;

/**************************************************************************************************
 * Конфигурационные структуры для PWD (Timer Input) драйвера HY-TTC 500
 *
 * Разделены на 4 независимые структуры в соответствии с 4 режимами инициализации,
 * поддерживаемыми API драйвера. Это обеспечивает строгую типизацию и предотвращает
 * передачу невалидных параметров в функции инициализации.
 *************************************************************************************************/

/* ================================================================================
 * 1. КОМПЛЕКСНЫЙ РЕЖИМ (Complex Mode)
 * Инициализация: IO_PWD_ComplexInit()
 * Назначение: Одновременное измерение частоты и ширины импульса.
 * ================================================================================ */
typedef struct
{
    /**
     * @brief Канал таймера (например, IO_PWD_00)
     * @note Поддерживаемые каналы: IO_PWD_00 .. IO_PWD_19
     */
    ubyte1 pin_channel;

    /**
     * @brief Режим измерения импульса
     * Допустимые значения:
     * - IO_PWD_HIGH_TIME   (1U): Измерять длительность высокого уровня
     * - IO_PWD_LOW_TIME    (0U): Измерять длительность низкого уровня
     * - IO_PWD_PERIOD_TIME (2U): Измерять полный период (высокий + низкий уровень)
     */
    ubyte1 pulse_duration_mode;

    /**
     * @brief Переменный фронт для измерения частоты
     * Частота всегда измеряется между окружающими противоположными фронтами.
     * Допустимые значения:
     * - IO_PWD_RISING_VAR  (2U): Переменным является нарастающий фронт.
     *   (Частота измеряется по времени между спадающими фронтами).
     * - IO_PWD_FALLING_VAR (3U): Переменным является спадающий фронт.
     *   (Частота измеряется по времени между нарастающими фронтами).
     */
    ubyte1 frequency_edge_mode;

    /**
     * @brief Количество накопленных измерений для усреднения (1..8)
     * @attention ВАЖНО: Для каналов IO_PWD_12..IO_PWD_19 этот параметр игнорируется
     * аппаратно, так как эти каналы не имеют буфера накопления и возвращают каждый
     * сэмпл отдельно. Драйвер не вернет новое значение (IO_E_PWD_NOT_FINISHED),
     * пока не будет захвачено указанное количество фронтов.
     */
    ubyte1 sample_accumulation_count;

    /**
     * @brief Конфигурация подтягивающего резистора
     * Допустимые значения:
     * - IO_PWD_NO_PULL  (0x03U): Фиксированный резистор (по умолчанию)
     * - IO_PWD_PU_10K   (0x01U): Подтяжка к питанию 10 кОм
     * - IO_PWD_PD_10K   (0x00U): Подтяжка к земле 10 кОм
     * - IO_PWD_PD_90    (0x02U): Подтяжка к земле 90 Ом
     *
     * @attention КРИТИЧЕСКИ ВАЖНО: Использование IO_PWD_PD_90 автоматически
     * конфигурирует вход для работы с токовым датчиком скорости (7мА/14мА, ABS-сенсор).
     * В этом режиме драйвер аппаратно выполняет дополнительную проверку диапазона тока
     * (защита от обрыва или КЗ). Для обычных цифровых переключателей используйте 10K.
     */
    ubyte1 pull_resistor;

    /**
     * @brief Конфигурация безопасности для Complex режима
     * @attention Поддерживается ТОЛЬКО для каналов IO_PWD_00..IO_PWD_05.
     * Для каналов IO_PWD_06..IO_PWD_19 передавайте строго NULL, иначе будет
     * возвращена ошибка IO_E_INVALID_SAFETY_CONFIG.
     */
    const IO_PWD_CPLX_SAFETY_CONF *complex_safety_settings;

} PWD_Complex_Config_t;

/* ================================================================================
 * 2. РЕЖИМ ПОДСЧЕТА ФРОНТОВ (Count Mode)
 * Инициализация: IO_PWD_CountInit()
 * Назначение: Простой подсчет нарастающих, спадающих или обоих типов фронтов.
 * ================================================================================ */
typedef struct
{
    /**
     * @brief Канал таймера (например, IO_PWD_00)
     * @note Поддерживаемые каналы: IO_PWD_00 .. IO_PWD_11
     */
    ubyte1 pin_channel;

    /**
     * @brief Режим подсчета фронтов
     * Допустимые значения:
     * - IO_PWD_RISING_COUNT  (1U): Считать только нарастающие фронты
     * - IO_PWD_FALLING_COUNT (2U): Считать только спадающие фронты
     * - IO_PWD_BOTH_COUNT    (3U): Считать оба типа фронтов
     */
    ubyte1 edge_counting_mode;

    /**
     * @brief Направление счета
     * Допустимые значения:
     * - IO_PWD_UP_COUNT   (0U): Счетчик инкрементируется (считает вверх)
     * - IO_PWD_DOWN_COUNT (1U): Счетчик декрементируется (считает вниз)
     */
    ubyte1 counter_direction;

    /**
     * @brief Начальное значение счетчика (0..65535)
     * Позволяет задать стартовое значение перед началом подсчета.
     */
    ubyte2 counter_start_value;

    /**
     * @brief Конфигурация подтягивающего резистора
     * Допустимые значения:
     * - IO_PWD_NO_PULL  (0x03U): Фиксированный резистор
     * - IO_PWD_PU_10K   (0x01U): Подтяжка к питанию 10 кОм
     * - IO_PWD_PD_10K   (0x00U): Подтяжка к земле 10 кОм
     *
     * @attention ВАЖНО: В режиме Count параметр IO_PWD_PD_90 (90 Ом) НЕ ПОДДЕРЖИВАЕТСЯ.
     * Используйте только 10K варианты или NO_PULL.
     */
    ubyte1 pull_resistor;

    /**
     * @brief Конфигурация безопасности для Count режима
     * @attention Поддерживается ТОЛЬКО для каналов IO_PWD_00..IO_PWD_05.
     */
    const IO_PWD_INC_SAFETY_CONF *count_safety_settings;

} PWD_Count_Config_t;

/* ================================================================================
 * 3. ИНКРЕМЕНТАЛЬНЫЙ РЕЖИМ (Incremental Mode)
 * Инициализация: IO_PWD_IncInit()
 * Назначение: Чтение инкрементальных (относительных) энкодеров.
 * ================================================================================ */
typedef struct
{
    /**
     * @brief Канал таймера (например, IO_PWD_00)
     * @note Поддерживаемые каналы: IO_PWD_00 .. IO_PWD_11
     *
     * @attention КРИТИЧЕСКИ ВАЖНО: Для инкрементального режима ВСЕГДА резервируются
     * ДВА физических канала. Пары жестко заданы аппаратно: (00,01), (02,03), (04,05),
     * (06,07), (08,09), (10,11). Инициализация первого канала пары автоматически
     * настраивает и второй канал. Интерфейс будет декрементировать счетчик, если
     * 1-й канал опережает 2-й, и инкрементировать, если 2-й канал опережает 1-й.
     */
    ubyte1 pin_channel;

    /**
     * @brief Режим счетчика энкодера
     * Допустимые значения:
     * - IO_PWD_INC_1_COUNT (0x01U): Считать фронты только 1-го канала пары.
     * - IO_PWD_INC_2_COUNT (0x03U): Считать фронты по обоим каналам пары (квадратурный режим).
     */
    ubyte1 encoder_counting_mode;

    /**
     * @brief Начальное значение счетчика энкодера (0..65535)
     */
    ubyte2 encoder_start_value;

    /**
     * @brief Конфигурация подтягивающего резистора
     * Допустимые значения:
     * - IO_PWD_NO_PULL  (0x03U): Фиксированный резистор
     * - IO_PWD_PU_10K   (0x01U): Подтяжка к питанию 10 кОм
     * - IO_PWD_PD_10K   (0x00U): Подтяжка к земле 10 кОм
     *
     * @attention ВАЖНО: В режиме Incremental параметр IO_PWD_PD_90 (90 Ом) НЕ ПОДДЕРЖИВАЕТСЯ.
     */
    ubyte1 pull_resistor;

    /**
     * @brief Конфигурация безопасности для Incremental режима
     * @attention Поддерживается ТОЛЬКО для каналов IO_PWD_00..IO_PWD_05.
     */
    const IO_PWD_INC_SAFETY_CONF *encoder_safety_settings;

} PWD_Incremental_Config_t;

/* ================================================================================
 * 4. УНИВЕРСАЛЬНЫЙ РЕЖИМ (Universal Mode)
 * Инициализация: IO_PWD_UniversalInit()
 * Назначение: Позволяет комбинировать Complex, Count и Incremental на одном канале.
 * ================================================================================ */
typedef struct
{
    /**
     * @brief Канал таймера (например, IO_PWD_00)
     * @attention Поддерживается ТОЛЬКО для каналов IO_PWD_00..IO_PWD_05.
     */
    ubyte1 pin_channel;

    /**
     * @brief Указатель на структуру конфигурации Complex части
     * @note Передайте NULL, если этот под-режим не нужен.
     */
    const IO_PWD_CPLX_CONF *universal_complex_settings;

    /**
     * @brief Указатель на структуру конфигурации Counter части
     * @note Передайте NULL, если этот под-режим не нужен.
     */
    const IO_PWD_CNT_CONF *universal_count_settings;

    /**
     * @brief Указатель на структуру конфигурации Incremental части
     * @note Передайте NULL, если этот под-режим не нужен.
     */
    const IO_PWD_INC_CONF *universal_encoder_settings;

    /**
     * @brief Конфигурация подтягивающего резистора
     * Допустимые значения:
     * - IO_PWD_NO_PULL  (0x03U): Фиксированный резистор
     * - IO_PWD_PU_10K   (0x01U): Подтяжка к питанию 10 кОм
     * - IO_PWD_PD_10K   (0x00U): Подтяжка к земле 10 кОм
     * - IO_PWD_PD_90    (0x02U): Подтяжка к земле 90 Ом (для токовых датчиков)
     */
    ubyte1 pull_resistor;

    /**
     * @brief Конфигурация безопасности для Universal режима
     *
     * @attention ПРАВИЛО "РОВНО ОДНА": Должна быть предоставлена ровно ОДНА валидная
     * (не NULL) конфигурация безопасности, соответствующая одному из АКТИВНЫХ под-режимов
     * (complex, count или incremental).
     * Передача NULL (если режим safety-critical), передача нескольких конфигураций
     * или передача конфигурации для режима, который не был активирован (указатель на его
     * конфиг равен NULL), вернет ошибку IO_E_INVALID_SAFETY_CONFIG.
     * Поддерживается ТОЛЬКО для каналов IO_PWD_00..IO_PWD_05.
     */
    const IO_PWD_UNIVERSAL_SAFETY_CONF *universal_safety_settings;

} PWD_Universal_Config_t;

/**************************************************************************************************
 * Конфигурационная структура для PVG (Proportional Valve Group) драйвера HY-TTC 500
 *
 * Основана на функции IO_PVG_Init().
 *************************************************************************************************/

/**
 * @brief Структура параметров инициализации выхода PVG
 *
 * Повторяет сигнатуру функции IO_PVG_Init() и содержит все необходимые
 * параметры для настройки канала пропорционального клапана.
 */
typedef struct
{
    /**
     * @brief Канал PVG (PVG channel)
     *
     * Допустимые значения (алиасы пинов):
     * - IO_PVG_00 .. IO_PVG_07
     *
     * @attention Аппаратные особенности:
     * - Выходной каскад PVG представляет собой push/pull PWM выход с фиксированным
     *   выходным сопротивлением 2.58 кОм. Это сопротивление необходимо для работы,
     *   низкочастотной фильтрации и защиты от перегрузки.
     * - Коррекция импеданса выполняется непосредственно внутри модуля. Поэтому для
     *   корректной работы этих выходов **обязательно** требуется подключение реального
     *   клапана типа PVG (с интегрированной электроникой).
     * - При конфигурировании выхода PVG автоматически настраивается и связанный
     *   с ним канал обратной связи по напряжению (voltage feedback).
     */
    ubyte1 pin_channel;

    /**
     * @brief Начальное выходное значение (Output value)
     *
     * Значение, с которым будет инициализирован канал PVG, выраженное в процентах * 100.
     *
     * Допустимый диапазон: 1000 .. 9000 (что соответствует 10.00% .. 90.00%).
     *
     * @attention Механизм защиты выхода (PVG output protection):
     * Каждый выход PVG индивидуально защищен от неисправностей.
     * Если разница между измеренным выходным напряжением (U_feedback) и расчетным
     *configured output (U_diff = (output_value / 100) * U_BAT - U_feedback) превышает
     * abs(+/- 18V) в течение как минимум 100 мс, защита выхода активируется (не позднее чем через 12 мс).
     *
     * При переходе в состояние защиты выход PVG должен оставаться в этом состоянии
     * минимум 1 секунду. После этого времени выход может быть повторно включен с помощью
     * функции IO_PVG_ResetProtection(). Количество попыток повторного включения для одного
     * канала PVG ограничено 10 разами.
     */
    ubyte2 initial_percentage_value;

} PVG_Config_t;

/**************************************************************************************************
 * Конфигурационная структура для DO (Digital Output) драйвера HY-TTC 500
 *
 * Основана на функции IO_DO_Init().
 *************************************************************************************************/

/**
 * @brief Структура параметров инициализации цифрового выхода (DO)
 *
 * Повторяет сигнатуру функции IO_DO_Init() и содержит все необходимые
 * параметры для настройки канала.
 */
typedef struct
{
    /**
     * @brief Канал цифрового выхода (Digital output channel)
     *
     * Допустимые значения (алиасы пинов):
     * - IO_DO_00 .. IO_DO_07  (High-side, поддерживают Safety и расширенную диагностику)
     * - IO_DO_08 .. IO_DO_15  (High-side, управляются через SPI с обновлением 1 мс)
     * - IO_DO_16 .. IO_DO_51  (High-side, альтернативная функция для IO_PWM_00..IO_PWM_35)
     * - IO_DO_52 .. IO_DO_59  (High-side, альтернативная функция для IO_PVG_00..IO_PVG_07)
     *
     * @attention Физические ограничения групп:
     * - Пины IO_DO_00..IO_DO_15 и IO_DO_52..IO_DO_59 имеют встроенную защиту от перегрузки
     *   с временем ожидания 1 сек перед сбросом.
     * - Пины IO_DO_16..IO_DO_51 имеют время ожидания защиты 10 сек перед сбросом.
     */
    ubyte1 pin_channel;

    /**
     * @brief Конфигурация диагностики (Diagnostic pull-up)
     *
     * Допустимые значения:
     * - TRUE:  Диагностика включена. Выход может обнаруживать обрыв нагрузки (Open Load)
     *          и короткое замыкание.
     * - FALSE: Диагностика выключена. Внутренняя подтяжка (pull-up) отключена.
     *          Используйте это для нагрузок с малым током потребления (например, светодиоды),
     *          чтобы избежать ложных срабатываний диагностики.
     *
     * @attention КРИТИЧЕСКИ ВАЖНЫЕ ОГРАНИЧЕНИЯ:
     * 1. Параметр применяется ТОЛЬКО к каналам IO_DO_00..IO_DO_07 и IO_DO_52..IO_DO_59.
     *    Для остальных каналов он игнорируется.
     * 2. Если передана валидная структура safety_conf (safety_conf != NULL),
     *    драйвер ПРИНУДИТЕЛЬНО установит diagnostic = TRUE, независимо от того,
     *    что вы передали в этом поле.
     */
    bool enable_diagnostics;

    /**
     * @brief Конфигурация безопасности (Safety configuration)
     *
     * Указатель на структуру IO_DO_SAFETY_CONF.
     * Если передать NULL, канал будет настроен как не safety-critical.
     *
     * @attention Если safety_conf != NULL:
     * - Внутренние checker модули проверяют каналы против параметров в safety_conf
     * - Параметр diagnostic принудительно устанавливается в TRUE
     */
    const IO_DO_SAFETY_CONF *safety_settings;

} DO_Config_t;

/**************************************************************************************************
 * Конфигурационная структура для PWM (Pulse Width Modulation) драйвера HY-TTC 500
 *
 * Универсальная структура, покрывающая обе функции инициализации:
 * - IO_PWM_Init() - стандартная инициализация
 * - IO_PWM_InitWithLowside() - инициализация с подключением к low-side каналу
 *   (отличается только тем, что использует поле low_side_channel из safety_conf)
 *************************************************************************************************/

/**
 * @brief Структура параметров инициализации PWM выхода
 *
 * Повторяет сигнатуры функций IO_PWM_Init() и IO_PWM_InitWithLowside()
 * и содержит все необходимые параметры для настройки канала.
 * Пользователь заполняет только те поля, которые необходимы.
 */
typedef struct
{
    /**
     * @brief Канал PWM выхода (PWM channel)
     *
     * Допустимые значения (алиасы пинов):
     * - IO_PWM_00 .. IO_PWM_35
     *
     * @attention Физические ограничения:
     * - Все PWM выходы имеют timer feedback (обратная связь по таймеру)
     * - Все PWM выходы имеют измерение тока (current measurement)
     * - PWM выходы будут немедленно отключены, если непрерывный ток превысит 4A
     * - Каналы IO_PWM_00..IO_PWM_13 принадлежат к shut-off group A
     * - Каналы IO_PWM_14..IO_PWM_27 принадлежат к shut-off group B
     * - Каналы IO_PWM_28..IO_PWM_35 принадлежат к shut-off group C
     */
    ubyte1 pin_channel;

    /**
     * @brief Частота PWM (PWM frequency)
     *
     * Допустимый диапазон: 50 Hz .. 1000 Hz
     *
     * @attention ВАЖНО: Поддерживаются ТОЛЬКО предопределенные частоты,
     * у которых период является целым кратным 1ms, 0.5ms или 0.25ms.
     *
     * Таблица поддерживаемых частот (период [ms] -> частота [Hz] -> период выборки тока [ms]):
     * - 1.00 ms  -> 1000 Hz  -> 1 ms
     * - 1.25 ms  -> 800 Hz   -> 5 ms
     * - 1.50 ms  -> 666 Hz   -> 3 ms
     * - 1.75 ms  -> 571 Hz   -> 7 ms
     * - 2.00 ms  -> 500 Hz   -> 2 ms
     * - 2.25 ms  -> 444 Hz   -> 9 ms
     * - 2.50 ms  -> 400 Hz   -> 5 ms
     * - 2.75 ms  -> 363 Hz   -> 11 ms
     * - 3.00 ms  -> 333 Hz   -> 3 ms
     * - 3.25 ms  -> 307 Hz   -> 13 ms
     * - 3.50 ms  -> 285 Hz   -> 7 ms
     * - 3.75 ms  -> 266 Hz   -> 15 ms
     * - 4.00 ms  -> 250 Hz   -> 4 ms
     * - 4.25 ms  -> 235 Hz   -> 17 ms
     * - 4.50 ms  -> 222 Hz   -> 9 ms
     * - 4.75 ms  -> 210 Hz   -> 19 ms
     * - 5.00 ms  -> 200 Hz   -> 5 ms
     * - 5.50 ms  -> 181 Hz   -> 11 ms
     * - 6.00 ms  -> 166 Hz   -> 6 ms
     * - 6.50 ms  -> 153 Hz   -> 13 ms
     * - 7.00 ms  -> 142 Hz   -> 7 ms
     * - 7.50 ms  -> 133 Hz   -> 15 ms
     * - 8.00 ms  -> 125 Hz   -> 8 ms
     * - 8.50 ms  -> 117 Hz   -> 17 ms
     * - 9.00 ms  -> 111 Hz   -> 9 ms
     * - 9.50 ms  -> 105 Hz   -> 19 ms
     * - 10.0 ms  -> 100 Hz   -> 10 ms
     * - 11.0 ms  -> 90 Hz    -> 11 ms
     * - 12.0 ms  -> 83 Hz    -> 12 ms
     * - 13.0 ms  -> 76 Hz    -> 13 ms
     * - 14.0 ms  -> 71 Hz    -> 14 ms
     * - 15.0 ms  -> 66 Hz    -> 15 ms
     * - 16.0 ms  -> 62 Hz    -> 16 ms
     * - 17.0 ms  -> 58 Hz    -> 17 ms
     * - 18.0 ms  -> 55 Hz    -> 18 ms
     * - 19.0 ms  -> 52 Hz    -> 19 ms
     * - 20.0 ms  -> 50 Hz    -> 20 ms
     *
     * @note Если указана недоступная частота в допустимом диапазоне,
     * будет использована следующая более высокая доступная частота.
     * Например, если указано 180 Hz, будет использовано 181.8 Hz.
     *
     * @note Для гидравлических клапанов типичный диапазон частот 90..160 Hz
     * для борьбы со статическим трением (stiction). Правильная настройка
     * частоты PWM согласно резонансной частоте актуатора позволяет создать
     * небольшую вибрацию, которая постоянно разрушает статическое трение.
     */
    ubyte2 target_frequency;

    /**
     * @brief Полярность выходного сигнала (Polarity of output signal)
     *
     * Допустимые значения:
     * - TRUE:  Высокий уровень выходного сигнала является переменным
     *          (High output signal is variable)
     * - FALSE: Низкий уровень выходного сигнала является переменным
     *          (Low output signal is variable)
     */
    bool signal_polarity;

    /**
     * @brief Флаг использования диагностической маржи (Diagnostic margin)
     *
     * Допустимые значения:
     * - TRUE:  Маржа включена. Duty cycle не может выходить за пределы
     *          маржи 100us (нижняя граница) и 200us (верхняя граница).
     *          Этот режим важен для гидравлических клапанов.
     * - FALSE: Маржа не применяется.
     *
     * @attention КРИТИЧЕСКИ ВАЖНО:
     * Если передана валидная структура safety_conf (safety_conf != NULL),
     * драйвер ПРИНУДИТЕЛЬНО установит diag_margin = TRUE, независимо от
     * того, что вы передали в этом поле. Это необходимо для диагностики.
     *
     * @note Если diag_margin = FALSE, ограничение диапазона duty cycle
     * не применяется.
     */
    bool enable_diagnostic_margin;

    /**
     * @brief Флаг использования инициализации с low-side каналом
     *
     * Допустимые значения:
     * - TRUE:  Использовать IO_PWM_InitWithLowside() - инициализация
     *          с подключением к low-side каналу. В этом случае поле
     *          low_side_channel структуры safety_conf будет оценено драйвером.
     * - FALSE: Использовать IO_PWM_Init() - стандартная инициализация.
     *
     * @note Отличие IO_PWM_InitWithLowside() от IO_PWM_Init():
     * - low_side_channel поле safety_conf оценивается только в InitWithLowside
     * - Если настроен low-side канал, он включается и выключается вместе
     *   с high-side safety switch канала
     */
    bool enable_lowside_pairing;

    /**
     * @brief Конфигурация безопасности (Safety configuration)
     *
     * Указатель на структуру IO_PWM_SAFETY_CONF.
     * Если передать NULL, канал будет настроен как не safety-critical.
     *
     * @attention Если safety_conf != NULL:
     * - Внутренние checker модули проверяют каналы против параметра
     *   current в safety_conf
     * - Проверяется обратная связь по периоду и duty cycle против выхода
     * - Параметр diag_margin принудительно устанавливается в TRUE
     * - Для IO_PWM_InitWithLowside() оценивается поле low_side_channel
     *
     * @note Детали проверки тока смотрите в определении IO_PWM_SAFETY_CONF
     */
    const IO_PWM_SAFETY_CONF *safety_settings;

} PWM_Config_t;

/**************************************************************************************************
 * Конфигурационная структура для VOUT (Voltage Output) драйвера HY-TTC 500
 *
 * Основана на функции IO_VOUT_Init() и IO_VOUT_SetVoltage().
 *************************************************************************************************/

/**
 * @brief Структура параметров инициализации и настройки выхода VOUT
 *
 * Повторяет сигнатуру функции IO_VOUT_Init() и содержит дополнительные поля
 * для унифицированного задания стартового напряжения.
 */
typedef struct
{
    /**
     * @brief Канал выхода напряжения (VOUT channel)
     *
     * Допустимые значения (алиасы пинов):
     * - IO_VOUT_00 .. IO_VOUT_07
     *
     * @attention Физические ограничения и особенности (из документации):
     * - Выходной каскад VOUT представляет собой push/pull PWM выход с
     *   четко определенным выходным сопротивлением 2.58 кОм.
     *   Это сопротивление необходимо для работы, фильтрации нижних частот
     *   и защиты от перегрузки.
     * - Выход напряжения ограничен ТОЛЬКО резистивными нагрузками на массу
     *   с сопротивлением 10 кОм или выше.
     * - При конфигурировании выхода VOUT автоматически настраивается и связанный
     *   с ним канал обратной связи по напряжению (voltage feedback).
     * - Отклонения напряжения питания автоматически корректируются модулем.
     * - Для корректной работы требуется подключение реальной нагрузки.
     */
    ubyte1 pin_channel;

    /**
     * @brief Начальное выходное напряжение (Initial output voltage)
     *
     * Хотя функция IO_VOUT_Init не принимает напряжение (оно задается отдельно
     * через IO_VOUT_SetVoltage), в универсальной структуре конфигурации удобно
     * хранить стартовое значение для применения сразу после инициализации.
     *
     * Допустимый диапазон: 0 .. 32000 (0 мВ .. 32 000 мВ).
     *
     * @note Если стартовое напряжение не требуется, установите значение 0.
     */
    ubyte2 startup_voltage_mv;

} VOUT_Config_t;

typedef struct
{
    DI_Config_t di_cfg;

    ADC_Config_t adc_cfg;

    PWD_Complex_Config_t pwd_complex_cfg;

    PWD_Count_Config_t pwd_count_cfg;

    PWD_Incremental_Config_t pwd_incremental_cfg;

    PWD_Universal_Config_t pwd_universal_cfg;

    PVG_Config_t pvg_cfg;

    DO_Config_t do_cfg;

    PWM_Config_t pwm_cfg;

    VOUT_Config_t vout_cfg;

} PinConfigUnion_t;

// Глобальный массив конфигураций для всех 96 пинов
extern PinConfigUnion_t g_pin_configs[PINS];

// Функция с настройками всех пинов для последующей инициализации
extern void Pin_Properties(void);

// Лимиты для DI (согласно IO_DIO_LIMITS из DIO.pdf)
static const IO_DIO_LIMITS s_di_limits_default = { 0U, // Нижняя граница LOW
        3000U,   // Верхняя граница LOW (до 3В = 0)
        7000U,   // Нижняя граница HIGH (от 7В = 1)
        32000U   // Верхняя граница HIGH
        };

// Safety конфигурация для ADC 0-5V (согласно IO_ADC_SAFETY_CONF из ADC.pdf)
// Поля: adc_val_lower (%), adc_val_upper (%), redundant_channel
static const IO_ADC_SAFETY_CONF s_adc_safety_5v = { 10U, // 10%
        90U,          // 90%
        IO_PIN_NONE   // Без резервирования
        };

// Safety конфигурация для ADC 0-10V
static const IO_ADC_SAFETY_CONF s_adc_safety_10v = { 10U, 90U,
IO_PIN_NONE };

// Safety конфигурация для ADC 0-32V
static const IO_ADC_SAFETY_CONF s_adc_safety_32v = { 10U, 90U,
IO_PIN_NONE };

// Safety configuration for Complex PWD inputs
static const IO_PWD_CPLX_SAFETY_CONF pwd_complex_safety_conf = { 100U, 100, 20U,
                                                                 20U };

// Safety configuration for Incremental PWD inputs
static const IO_PWD_INC_SAFETY_CONF pwd_inc_safety_conf = { 65534U, 65534U };

// Safety configuration for Counter PWD inputs
static const IO_PWD_INC_SAFETY_CONF pwd_cnt_safety_conf = { 65534U, 65534U };

// Safety configuration for Universal PWD inputs
static const IO_PWD_UNIVERSAL_SAFETY_CONF pwd_universal_safety_conf = {
        &pwd_inc_safety_conf, &pwd_cnt_safety_conf, &pwd_complex_safety_conf };

// Safety configuration for DO inputs
static const IO_DO_SAFETY_CONF do_safety_conf = { IO_DO_08 };

// Safety configuration for PWM inputs
static const IO_PWM_SAFETY_CONF pwm_safety_conf = { TRUE, 7500, IO_PIN_NONE };

#endif /* PIN_SETTINGS_h_ */
