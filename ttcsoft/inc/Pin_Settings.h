#ifndef PIN_SETTINGS_h_
#define PIN_SETTINGS_h_

#include "IO_DIO.h"
#include "IO_ADC.h"
#include "IO_PWD.h"
#include "IO_PVG.h"
#include "IO_PWM.h"
#include "IO_VOUT.h"

#define PINS 96U

/*
 * @brief Setup a digital input.
 *
 * Repeats the signature of the IO_DI_Init() function and contains all necessary
 * options to customize the channel.
 *
 * @attention The inputs IO_DI_00.. IO_DI_35 and IO_DI_48.. IO_DI_55 have a fixed pull up and
 * are only suitable for switches to ground.
 * The inputs IO_DI_56.. IO_DI_63 and IO_DI_64.. IO_DI_71 are only suitable for
 * switches to BAT.
 * The inputs IO_DI_80.. IO_DI_87 have a fixed pull up. Depending on the
 * parameter limits switches to ground or BAT can be read.
 */
typedef struct
{
    /**
     * @brief Digital input channel
     *
     * Allowed values (pin aliases):
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
     * @brief Pull up/down configuration
     *
     * Allowed values:
     * - IO_DI_NO_PULL (0x00U): fixed pull resistor
     * - IO_DI_PU_10K (0x01U): Pull up 10 kOhm
     * - IO_DI_PD_10K (0x02U): Pull down 10 kOhm
     *
     * @attention The supported features depend on the selected channel:
     * - IO_DI_00.. IO_DI_35: pupd ignored
     * - IO_DI_36.. IO_DI_47: pupd: IO_DI_PU_10K or IO_DI_PD_10K
     * - IO_DI_48.. IO_DI_55: pupd ignored
     * - IO_DI_56.. IO_DI_63: pupd ignored
     * - IO_DI_64.. IO_DI_71: pupd ignored
     * - IO_DI_72.. IO_DI_79: pupd: IO_DI_PU_10K or IO_DI_PD_10K
     * - IO_DI_80.. IO_DI_87: pupd ignored
     * - IO_DI_88.. IO_DI_95: pupd: IO_DI_PU_10K or IO_DI_PD_10K
     *
     * @attention If the channel does not support pull configuration, the parameter value is ignored.
     */
    ubyte1 pupd;

    /**
     * @brief Voltage limits for low/high-levels
     *
     * Pointer to IO_DIO_LIMITS structure.
     * If NULL, default limits will be used. See IO_DIO_LIMITS for details.
     *
     * @attention The supported features depend on the selected channel:
     * - IO_DI_00.. IO_DI_35: limits ignored
     * - IO_DI_36.. IO_DI_47: limits ignored
     * - IO_DI_48.. IO_DI_55: limits ignored
     * - IO_DI_56.. IO_DI_63: limits: Voltage limits for low/high-levels
     * - IO_DI_64.. IO_DI_71: limits: Voltage limits for low/high-levels
     * - IO_DI_72.. IO_DI_79: limits: Voltage limits for low/high-levels
     * - IO_DI_80.. IO_DI_87: limits: Voltage limits for low/high-levels
     * - IO_DI_88.. IO_DI_95: limits: Voltage limits for low/high-levels
     *
     * @attention The inputs IO_DI_00.. IO_DI_35, IO_DI_36.. IO_DI_47 and IO_DI_48.. IO_DI_55
     * have a fixed switching threshold of 2.5V.
     *
     * @attention If the channel does not support limit configuration, the parameter value is ignored.
     */
    const IO_DIO_LIMITS *limits;

} DI_Config_t;

/*
 * @brief Setup one ADC channel.
 *
 * Repeats the signature of the IO_ADC_ChannelInit() function and contains all necessary
 * options to customize the channel.
 */
typedef struct
{
    /**
     * @brief ADC channel
     *
     * Allowed values (pin aliases):
     * - IO_ADC_00.. IO_ADC_07   (3 mode ADC: 0-5V)
     * - IO_ADC_08.. IO_ADC_15   (2 mode 10V ADC: 0-5V/0-10V)
     * - IO_ADC_16.. IO_ADC_23   (2 mode 32V ADC: 0-5V/0-32V)
     * - IO_ADC_24.. IO_ADC_35   (Normal ADC: alternative function PWD)
     * - IO_ADC_36.. IO_ADC_43   (Normal ADC: alternative function DO)
     * - IO_ADC_44.. IO_ADC_51   (Normal ADC: alternative function DO)
     * - IO_ADC_52.. IO_ADC_59   (Normal ADC: alternative function PVG/VOUT)
     * - IO_ADC_SENSOR_SUPPLY_0..2, IO_ADC_K15, IO_ADC_WAKE_UP, IO_ADC_UBAT,
     *   IO_ADC_SAFETY_SW_0..2, IO_ADC_BOARD_TEMP (Internal channels)
     */
    ubyte1 pin_channel;

    /**
     * @brief Type of input
     *
     * Allowed values:
     * - IO_ADC_RATIOMETRIC (0x00U): voltage input on sensor supply. Returns voltage in [mV].
     * - IO_ADC_CURRENT (0x01U): 0-25mA input. Returns current in [uA].
     * - IO_ADC_RESISTIVE (0x02U): 0-100000Ohm input. Returns resistance in [Ohm].
     * - IO_ADC_ABSOLUTE (0x03U): normal voltage input. Returns voltage in [mV].
     *
     * @attention The supported features depend on the selected channel:
     * - IO_ADC_00.. IO_ADC_07: all 4 types supported
     * - IO_ADC_08.. IO_ADC_15: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT, IO_ADC_ABSOLUTE
     * - IO_ADC_16.. IO_ADC_23: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT, IO_ADC_ABSOLUTE
     * - IO_ADC_24.. IO_ADC_35, IO_ADC_36.. IO_ADC_43, IO_ADC_44.. IO_ADC_51,
     *   IO_ADC_52.. IO_ADC_59: only IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
     * - All other channels: only IO_ADC_ABSOLUTE
     *
     * @attention For safety-critical configuration (safety_conf != NULL):
     * - Resistive measurement type IO_ADC_RESISTIVE is not valid
     */
    ubyte1 input_type;

    /**
     * @brief Range of input
     *
     * Allowed values:
     * - IO_ADC_NO_RANGE (0x00U): ADC range not configurable (fixed)
     * - IO_ADC_RANGE_5V (0x01U): voltage input 0-5000mV
     * - IO_ADC_RANGE_10V (0x02U): voltage input 0-10200mV
     * - IO_ADC_RANGE_32V (0x03U): voltage input 0-32000mV
     *
     * @attention The supported features depend on the selected channel:
     * - IO_ADC_00.. IO_ADC_07: only IO_ADC_NO_RANGE (fixed range 0-5V)
     * - IO_ADC_08.. IO_ADC_15: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (for ABSOLUTE and RATIOMETRIC)
     * - IO_ADC_16.. IO_ADC_23: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (for ABSOLUTE and RATIOMETRIC)
     * - All other channels: only IO_ADC_NO_RANGE
     *
     * @attention If the channel does not support range configuration, the parameter value is ignored.
     */
    ubyte1 voltage_range;

    /**
     * @brief Pull up/down configuration
     *
     * Allowed values:
     * - IO_ADC_NO_PULL (0x00U): fixed pull resistor
     * - IO_ADC_PU_10K (0x02U): pull up 10 kOhm
     * - IO_ADC_PD_10K (0x01U): pull down 10 kOhm
     *
     * @attention The supported features depend on the selected channel:
     * - IO_ADC_00.. IO_ADC_07: parameter ignored
     * - IO_ADC_08.. IO_ADC_15: parameter ignored
     * - IO_ADC_16.. IO_ADC_23: parameter ignored
     * - IO_ADC_24.. IO_ADC_35: IO_ADC_PU_10K or IO_ADC_PD_10K
     * - IO_ADC_36.. IO_ADC_43: IO_ADC_PU_10K or IO_ADC_PD_10K
     * - IO_ADC_44.. IO_ADC_51: parameter ignored
     * - IO_ADC_52.. IO_ADC_59: IO_ADC_PU_10K or IO_ADC_PD_10K
     * - All other channels: parameter ignored
     *
     * @attention If the channel does not support pull configuration, the parameter value is ignored.
     */

    ubyte1 pupd;

    /*
     * @brief Sensor supply
     *
     * Allowed values:
     * - IO_SENSOR_SUPPLY_0: 5V sensor supply
     * - IO_SENSOR_SUPPLY_1: 5V sensor supply
     * - IO_SENSOR_SUPPLY_2: variable sensor supply (5V-10V)
     * - IO_PIN_NONE: no sensor supply is used
     *
     * @attention The supported features depend on the input type and selected channel:
     * - For IO_ADC_RATIOMETRIC type:
     *   - IO_ADC_00.. IO_ADC_59: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1, or IO_SENSOR_SUPPLY_2
     * - For IO_ADC_CURRENT, IO_ADC_RESISTIVE, IO_ADC_ABSOLUTE types:
     *   - All channels: only IO_PIN_NONE
     *
     * @attention For safety-critical configuration (safety_conf != NULL):
     * - Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid
     *
     * @attention If the channel does not support sensor supply configuration, the parameter value is ignored.
     */
    ubyte1 supply_source;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_ADC_SAFETY_CONF structure.
     * If NULL, the channel will be configured as non-safety-critical.
     *
     * @attention Safety-critical configuration is supported only for channels:
     * - IO_ADC_00.. IO_ADC_07
     * - IO_ADC_08.. IO_ADC_15
     * - IO_ADC_16.. IO_ADC_23
     *
     * @attention For safety-critical configuration:
     * - Resistive measurement type IO_ADC_RESISTIVE is not valid
     * - Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid
     * - If a sensor supply is configured, the sensor supply voltage will also be
     *   checked by the diagnostic modules
     */
    const IO_ADC_SAFETY_CONF *safety_settings;

} ADC_Config_t;

/*
 * Configuration structures for the PWD (Timer Input) driver
 *
 * Divided into 4 independent structures according to the 4 initialization modes
 * supported by the driver API. This ensures strict typing and prevents passing
 * invalid parameters to the initialization functions.
 *
 * 1. COMPLEX MODE
 * Initialization: IO_PWD_ComplexInit()
 * Purpose: Measures frequency and pulse-width at the same time.
 */

typedef struct
{
    /**
     * @brief Timer channel
     *
     * Allowed values:
     * - IO_PWD_00.. IO_PWD_05
     * - IO_PWD_06.. IO_PWD_11
     * - IO_PWD_12.. IO_PWD_19
     */
    ubyte1 pin_channel;

    /**
     * @brief Pulse mode
     *
     * Specifies the pulse mode:
     * - IO_PWD_HIGH_TIME (1U): configuration to measure pulse-high-time
     * - IO_PWD_LOW_TIME (0U): configuration to measure pulse-low-time
     * - IO_PWD_PERIOD_TIME (2U): configuration to measure pulse-high and low-time (Period)
     */
    ubyte1 pulse_duration_mode;

    /**
     * @brief Frequency mode (Variable edge)
     *
     * Specifies the variable edge. If the rising edge is variable, the frequency
     * is measured between the surrounding falling edges.
     * - IO_PWD_RISING_VAR (2U): rising edge is variable
     * - IO_PWD_FALLING_VAR (3U): falling edge is variable
     */
    ubyte1 frequency_edge_mode;

    /**
     * @brief Capture count
     *
     * Number of frequency/pulse-width measurements that will be accumulated (1..8).
     *
     * @attention The supported features depend on the selected channel:
     * - IO_PWD_00.. IO_PWD_11: Accumulates up to 8 pulse samples.
     * - IO_PWD_12.. IO_PWD_19: These inputs do not accumulate a number of samples.
     *   Instead, every pulse sample has to be handled directly. The driver captures
     *   exactly as many measurements as given in this parameter. Note: Until not all
     *   configured samples are captured, the driver doesn't return a value.
     */
    ubyte1 sample_accumulation_count;

    /**
     * @brief Pull up/down configuration
     *
     * Allowed values:
     * - IO_PWD_NO_PULL (0x03U): fixed pull resistor
     * - IO_PWD_PU_10K (0x01U): Pull up 10 kOhm
     * - IO_PWD_PD_10K (0x00U): Pull down 10 kOhm
     * - IO_PWD_PD_90 (0x02U): Pull down 90 Ohm (for 7mA/14mA sensors)
     *
     * @attention Passing IO_PWD_PD_90 as pupd parameter configures the input for
     * a current sensor (7mA/14mA). In this case an additional range check on the
     * current signal will be performed.
     *
     * @attention The supported features depend on the selected channel:
     * - IO_PWD_00.. IO_PWD_05: IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
     * - IO_PWD_06.. IO_PWD_11: IO_PWD_PU_10K or IO_PWD_PD_10K
     * - IO_PWD_12.. IO_PWD_19: Parameter ignored (voltage signals only)
     */
    ubyte1 pupd;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_PWD_CPLX_SAFETY_CONF structure.
     *
     * @attention Safety configuration is only supported for the PWD channels
     * IO_PWD_00.. IO_PWD_05. For other channels, pass NULL.
     */
    const IO_PWD_CPLX_SAFETY_CONF *complex_safety_settings;

} PWD_Complex_Config_t;

/*
 * 2. COUNT MODE
 * Initialization: IO_PWD_CountInit()
 * Purpose: Counts rising, falling or both edges.
 */

typedef struct
{
    /**
     * @brief Counter channel
     *
     * Allowed values:
     * - IO_PWD_00.. IO_PWD_05
     * - IO_PWD_06.. IO_PWD_11
     */
    ubyte1 pin_channel;

    /**
     * @brief Edge count mode
     *
     * Specify on which edge shall be counted:
     * - IO_PWD_RISING_COUNT (1U): count on a rising edge
     * - IO_PWD_FALLING_COUNT (2U): count on a falling edge
     * - IO_PWD_BOTH_COUNT (3U): count on both edges
     */
    ubyte1 edge_counting_mode;

    /**
     * @brief Count direction
     *
     * Specify the counting direction:
     * - IO_PWD_UP_COUNT (0U): counts up
     * - IO_PWD_DOWN_COUNT (1U): counts down
     */
    ubyte1 counter_direction;

    /**
     * @brief Init value of the counter
     *
     * Allowed values: 0..65535
     */
    ubyte2 counter_start_value;

    /**
     * @brief Pull up/down configuration
     *
     * Allowed values:
     * - IO_PWD_PU_10K (0x01U): Pull up 10 kOhm
     * - IO_PWD_PD_10K (0x00U): Pull down 10 kOhm
     *
     * @attention Note that IO_PWD_NO_PULL and IO_PWD_PD_90 are NOT supported
     * for the Count mode initialization.
     */
    ubyte1 pupd;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_PWD_INC_SAFETY_CONF structure.
     *
     * @attention Safety configuration is only supported for the PWD channels
     * IO_PWD_00.. IO_PWD_05. For other channels, pass NULL.
     */
    const IO_PWD_INC_SAFETY_CONF *count_safety_settings;

} PWD_Count_Config_t;

/*
 * 3. INCREMENTAL MODE
 * Initialization: IO_PWD_IncInit()
 * Purpose: Reads incremental (relative) encoders. Two inputs are reserved for
 * one incremental encoder (clock and direction) interface.
 */

typedef struct
{
    /**
     * @brief Channel of the incremental interface
     *
     * Allowed values:
     * - IO_PWD_00.. IO_PWD_05
     * - IO_PWD_06.. IO_PWD_11
     *
     * @attention Two PWD channels are used (needed) for one incremental interface.
     * The pairs are defined in the following order:
     * - IO_PWD_00 and IO_PWD_01 define the 1st incremental interface.
     * - IO_PWD_02 and IO_PWD_03 define the 2nd incremental interface.
     * - IO_PWD_04 and IO_PWD_05 define the 3rd incremental interface.
     * - IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
     * - IO_PWD_08 and IO_PWD_09 define the 5th incremental interface.
     * - IO_PWD_10 and IO_PWD_11 define the 6th incremental interface.
     *
     * @note The function initializes both PWD channels of the incremental interface,
     * independently if the function gets called with the 1st or 2nd channel belonging
     * to an incremental interface. The incremental interface will decrement when the
     * 1st channel is leading and increment when the 2nd channel is leading.
     */
    ubyte1 pin_channel;

    /**
     * @brief Counting mode
     *
     * Defines the counter behavior:
     * - IO_PWD_INC_2_COUNT (0x03U): Counts up/down on any edge of the two input channels
     * - IO_PWD_INC_1_COUNT (0x01U): Counts up/down on any edge of the 1st input channel only
     */
    ubyte1 encoder_counting_mode;

    /**
     * @brief Init value of the incremental counter
     *
     * Allowed values: 0..65535
     */
    ubyte2 encoder_start_value;

    /**
     * @brief Pull up/down configuration
     *
     * Allowed values:
     * - IO_PWD_PU_10K (0x01U): Pull up 10 kOhm
     * - IO_PWD_PD_10K (0x00U): Pull down 10 kOhm
     *
     * @attention Note that IO_PWD_NO_PULL and IO_PWD_PD_90 are NOT supported
     * for the Incremental mode initialization.
     */
    ubyte1 pupd;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_PWD_INC_SAFETY_CONF structure.
     *
     * @attention Safety configuration is only supported for the PWD channels
     * IO_PWD_00.. IO_PWD_05. For other channels, pass NULL.
     */
    const IO_PWD_INC_SAFETY_CONF *encoder_safety_settings;

} PWD_Incremental_Config_t;

/*
 * 4. UNIVERSAL MODE
 * Initialization: IO_PWD_UniversalInit()
 * Purpose: Combination of complex, incremental and count mode.
 */

typedef struct
{
    /**
     * @brief Timer channel
     *
     * Allowed values:
     * - IO_PWD_00.. IO_PWD_05 (ONLY)
     */
    ubyte1 pin_channel;

    /**
     * @brief Complex configuration
     *
     * Pointer to IO_PWD_CPLX_CONF structure.
     * Can be set to NULL if complex mode is not needed.
     */
    const IO_PWD_CPLX_CONF *universal_complex_settings;

    /**
     * @brief Edge counter configuration
     *
     * Pointer to IO_PWD_CNT_CONF structure.
     * Can be set to NULL if edge counter mode is not needed.
     */
    const IO_PWD_CNT_CONF *universal_count_settings;

    /**
     * @brief Incremental counter configuration
     *
     * Pointer to IO_PWD_INC_CONF structure.
     * Can be set to NULL if incremental mode is not needed.
     *
     * @attention If a channel is configured for incremental mode, both the primary
     * and secondary channel are redundantly configured using the provided complex,
     * edge counter and safety configuration.
     */
    const IO_PWD_INC_CONF *universal_encoder_settings;

    /**
     * @brief Pull up/down configuration
     *
     * Allowed values:
     * - IO_PWD_PU_10K (0x01U): Pull up 10 kOhm
     * - IO_PWD_PD_10K (0x00U): Pull down 10 kOhm
     * - IO_PWD_PD_90 (0x02U): Pull down 90 Ohm (for 7mA/14mA sensors)
     *
     * @attention Passing IO_PWD_PD_90 as pupd parameter configures the input for
     * a current sensor (7mA/14mA). Note that this setting is INVALID if the input
     * is also configured for edge and/or incremental counter mode.
     */
    ubyte1 pupd;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_PWD_UNIVERSAL_SAFETY_CONF structure.
     *
     * @attention Parameter safety_conf can be set to NULL in order to initialize
     * the input as non-safety-critical. To configure the input as safety-critical,
     * parameter safety_conf must provide exactly one valid (i.e., not NULL) safety
     * configuration. Providing zero or multiple safety configurations or a safety
     * configuration for a mode that is not configured will fail with return code
     * IO_E_INVALID_SAFETY_CONFIG.
     */
    const IO_PWD_UNIVERSAL_SAFETY_CONF *universal_safety_settings;

} PWD_Universal_Config_t;

/*
 * Configuration structure for the PVG (Proportional Valve Group) driver
 *
 * Based on the IO_PVG_Init() function.
 *
 * @brief Setup one PVG channel.
 *
 * Repeats the signature of the IO_PVG_Init() function and contains all necessary
 * parameters to configure the proportional valve channel.
 */

typedef struct
{
    /**
     * @brief PVG channel
     *
     * Allowed values:
     * - IO_PVG_00.. IO_PVG_07
     *
     * @attention Hardware specifics:
     * - The PVG output stage is a push/pull PWM output with a well defined output
     *   resistance of 2.58kOhm. This resistance is necessary for operation, low pass
     *   filtering and over load protection.
     * - The correction of the PVG impedance is directly performed inside the module.
     *   Therefore a PVG valve is needed for correct operation of this outputs.
     * - When configuring a PVG output, the associated voltage feedback channel will
     *   also be configured.
     */

    ubyte1 pin_channel;

    /**
     * @brief Initial output value
     *
     * Output value with which the PVG-channel will be initialized in percent*100
     * (1000..9000).
     *
     * @attention PVG output protection:
     * Each PVG output is individually protected against malfunction. Whenever the
     * difference between the measured output (U_feedback) and the configured output
     * calculated by U_diff = (output_value / 100) * U_BAT - U_feedback is greater
     * than abs(+/-18V) for at least 100ms, the output protection is enabled latest
     * within 12ms.
     *
     * When entering the protection state, the PVG output has to remain in this state
     * for at least 1s. After this wait time the PVG output can be reenabled via
     * function IO_PVG_ResetProtection(). Note that the number of reenabling operations
     * for a single PVG output is limited to 10.
     */

    ubyte2 initial_percentage_value;

} PVG_Config_t;

/*
 * @brief Setup a digital output.
 *
 * Repeats the signature of the IO_DO_Init() function and contains all necessary
 * parameters to configure the channel.
 */

typedef struct
{
    /**
     * @brief Digital output channel
     *
     * Allowed values:
     * - IO_DO_00.. IO_DO_07
     * - IO_DO_08.. IO_DO_15
     * - IO_DO_16.. IO_DO_51
     * - IO_DO_52.. IO_DO_59
     *
     * @attention The digital output channels IO_DO_00.. IO_DO_15 are controlled over SPI shift
     * registers. Therefore the outputs will be periodically updated with a cycle of 1ms.
     * The digital output channels IO_DO_16.. IO_DO_51 are an alternative function to
     * IO_PWM_00.. IO_PWM_35.
     * The digital output channels IO_DO_52.. IO_DO_59 are an alternative function to
     * IO_PVG_00.. IO_PVG_07.
     *
     * @attention Digital output protection wait times:
     * - IO_DO_00.. IO_DO_15, IO_DO_52.. IO_DO_59: 1s wait time before protection can be reset.
     * - IO_DO_16.. IO_DO_51: 10s wait time before protection can be reset.
     */

    ubyte1 pin_channel;

    /**
     * @brief Output configuration (Diagnostic pull-up)
     *
     * Allowed values:
     * - TRUE: diagnostic pull-up enabled. The output can detect open load and short circuit.
     * - FALSE: diagnostic pull-up disabled. The output can not detect open load or short circuit.
     *   Select FALSE for loads with low current consumption like LEDs. With diagnostic== FALSE
     *   the pull up will be switched off.
     *
     * @attention The parameter diagnostic is only applied to the channels IO_DO_00.. IO_DO_07
     * and IO_DO_52.. IO_DO_59. For other channels, it is ignored.
     *
     * @attention If safety_conf != NULL, the parameter diagnostic is forced to TRUE to allow
     * diagnostics.
     */

    bool enable_diagnostics;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_DO_SAFETY_CONF structure.
     * Relevant safety configurations for the checker modules.
     *
     * @attention Safety configuration is only supported for the DO channels:
     * - IO_DO_00.. IO_DO_07
     *
     * @attention If safety_conf != NULL:
     * - A low side and high side channel have to be connected together. The internal checker
     *   modules check the given channels against the parameter in safety_conf.
     * - The parameter diagnostic is forced to TRUE to allow diagnostics.
     */

    const IO_DO_SAFETY_CONF *safety_settings;

} DO_Config_t;

/*
 * Configuration structure for the PWM (Pulse Width Modulation) driver
 *
 * Universal structure covering both initialization functions:
 * - IO_PWM_Init() - standard initialization
 * - IO_PWM_InitWithLowside() - initialization with connection to a low-side channel
 *   (differs only in that it evaluates the low_side_channel field from safety_conf)
 */

/*
 * @brief Setup a single PWM output.
 *
 * Repeats the signatures of the IO_PWM_Init() and IO_PWM_InitWithLowside() functions
 * and contains all necessary parameters to configure the channel.
 */

typedef struct
{
    /**
     * @brief PWM channel
     *
     * Allowed values:
     * - IO_PWM_00.. IO_PWM_35
     *
     * @attention Hardware specifics:
     * - All PWM outputs have timer feedback.
     * - All PWM outputs have current measurement.
     * - The PWM outputs will be switched off immediately if the continuous current is above 4A.
     */
    ubyte1 pin_channel;

    /**
     * @brief PWM frequency
     *
     * Allowed range: 50Hz.. 1000Hz.
     * Only predefined frequencies with a period of an integral multiple of 1ms, 0.5ms or 0.25ms are possible.
     *
     * @attention Available frequencies (Period [ms] -> Frequency [Hz] -> Current sample period [ms]):
     * - 1.00 ms -> 1000 Hz -> 1 ms
     * - 1.25 ms -> 800 Hz -> 5 ms
     * - 1.50 ms -> 666 Hz -> 3 ms
     * - 1.75 ms -> 571 Hz -> 7 ms
     * - 2.00 ms -> 500 Hz -> 2 ms
     * - 2.25 ms -> 444 Hz -> 9 ms
     * - 2.50 ms -> 400 Hz -> 5 ms
     * - 2.75 ms -> 363 Hz -> 11 ms
     * - 3.00 ms -> 333 Hz -> 3 ms
     * - 3.25 ms -> 307 Hz -> 13 ms
     * - 3.50 ms -> 285 Hz -> 7 ms
     * - 3.75 ms -> 266 Hz -> 15 ms
     * - 4.00 ms -> 250 Hz -> 4 ms
     * - 4.25 ms -> 235 Hz -> 17 ms
     * - 4.50 ms -> 222 Hz -> 9 ms
     * - 4.75 ms -> 210 Hz -> 19 ms
     * - 5.00 ms -> 200 Hz -> 5 ms
     * - 5.50 ms -> 181 Hz -> 11 ms
     * - 6.00 ms -> 166 Hz -> 6 ms
     * - 6.50 ms -> 153 Hz -> 13 ms
     * - 7.00 ms -> 142 Hz -> 7 ms
     * - 7.50 ms -> 133 Hz -> 15 ms
     * - 8.00 ms -> 125 Hz -> 8 ms
     * - 8.50 ms -> 117 Hz -> 17 ms
     * - 9.00 ms -> 111 Hz -> 9 ms
     * - 9.50 ms -> 105 Hz -> 19 ms
     * - 10.0 ms -> 100 Hz -> 10 ms
     * - 11.0 ms -> 90 Hz -> 11 ms
     * - 12.0 ms -> 83 Hz -> 12 ms
     * - 13.0 ms -> 76 Hz -> 13 ms
     * - 14.0 ms -> 71 Hz -> 14 ms
     * - 15.0 ms -> 66 Hz -> 15 ms
     * - 16.0 ms -> 62 Hz -> 16 ms
     * - 17.0 ms -> 58 Hz -> 17 ms
     * - 18.0 ms -> 55 Hz -> 18 ms
     * - 19.0 ms -> 52 Hz -> 19 ms
     * - 20.0 ms -> 50 Hz -> 20 ms
     *
     * @note If you select an unavailable frequency within the allowed range, the next higher
     * available frequency will be used. For example, if 180 Hz is specified, 181.8 Hz will be used.
     *
     * @note For hydraulic valves, a typical range to operate without friction is 90..160Hz.
     * A proper setting of PWM frequency according to the resonance frequency of the actuator
     * allows to adjust small vibrations to break static friction and stiction.
     */
    ubyte2 target_frequency;

    /**
     * @brief Polarity of output signal
     *
     * Allowed values:
     * - TRUE: High output signal is variable
     * - FALSE: Low output signal is variable
     */
    bool signal_polarity;

    /**
     * @brief Diagnostic margin
     *
     * Indicate if a margin should be applied or not.
     * - TRUE: margin is on. The duty cycle cannot exceed the margin of 100us (lower boundary)
     *   and 200us (upper boundary) used for diagnostic. This mode is important for hydraulic coils.
     * - FALSE: no margin will be applied.
     *
     * @attention If a PWM channel is configured safety relevant (safety_conf != NULL),
     * this parameter is forced to TRUE to allow diagnostics.
     */
    bool enable_diagnostic_margin;

    /**
     * @brief Low-side pairing flag
     *
     * Indicates whether to use IO_PWM_InitWithLowside() instead of IO_PWM_Init().
     * - TRUE: Initialize with low-side channel connection. The low_side_channel field
     *   of the safety configuration will be evaluated. If configured, the low side switch
     *   of a PWM channel is switched on and off together with the high side safety switch.
     * - FALSE: Standard initialization using IO_PWM_Init(). The low_side_channel field is ignored.
     */
    bool enable_lowside_pairing;

    /**
     * @brief Safety configuration
     *
     * Pointer to IO_PWM_SAFETY_CONF structure.
     * Relevant safety configuration of the PWM channel.
     *
     * @attention If safety_conf != NULL:
     * - The internal checker modules check the given channels against the current parameter
     *   in safety_conf, and the period and duty cycle feedback against the output.
     * - The parameter diag_margin is forced to TRUE to allow diagnostics.
     * - For IO_PWM_InitWithLowside(), the low_side_channel field is evaluated.
     *
     * @note If NULL, the channel is configured as non-safety-critical.
     */
    const IO_PWM_SAFETY_CONF *safety_settings;

} PWM_Config_t;

/*
 * Configuration structure for the VOUT (Voltage Output) driver
 *
 * Based on the IO_VOUT_Init() and IO_VOUT_SetVoltage() functions.
 */

/*
 * @brief Setup one voltage output channel.
 *
 * Repeats the signature of the IO_VOUT_Init() function and contains an additional field
 * for unified setting of the initial output voltage.
 */

typedef struct
{
    /**
     * @brief VOUT channel
     *
     * Allowed values:
     * - IO_VOUT_00.. IO_VOUT_07
     *
     * @attention Hardware specifics:
     * - The voltage output stage is a push/pull PWM output with a well defined output
     *   resistance of 2.58kOhm. This resistance is necessary for operation, low pass
     *   filtering and over load protection.
     * - The voltage output is limited to resistive loads to ground with 10kOhm or higher.
     * - When configuring a voltage output, the associated voltage feedback channel will
     *   also be configured.
     * - Deviations on the power supply are automatically corrected by the module.
     * - The outputs will be activated after setting them via IO_VOUT_SetVoltage().
     */

    ubyte1 pin_channel;

    /**
     * @brief Initial output voltage
     *
     * Although the IO_VOUT_Init() function does not take a voltage parameter
     * (it is set separately via IO_VOUT_SetVoltage()), it is convenient to store
     * the initial value in a universal configuration structure to apply it
     * immediately after initialization.
     *
     * Allowed range: 0..32000 (0mV.. 32.000V).
     *
     * @note If the initial voltage is not required, set this value to 0.
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

// Global array confs
extern PinConfigUnion_t g_pin_configs[PINS];

// Function with settings all pins for next init

extern void Pin_Properties(void);

// DI Limits

static const IO_DIO_LIMITS s_di_limits_default = { 0U, // Нижняя граница LOW
        3000U,   // Верхняя граница LOW (до 3В = 0)
        7000U,   // Нижняя граница HIGH (от 7В = 1)
        32000U   // Верхняя граница HIGH
        };

// Safety configuration for ADC 0-5V
// Fields: adc_val_lower (%), adc_val_upper (%), redundant_channel

static const IO_ADC_SAFETY_CONF s_adc_safety_5v = { 10U, // 10%
        90U,          // 90%
        IO_PIN_NONE
        };

// Safety configuration for ADC 0-10V

static const IO_ADC_SAFETY_CONF s_adc_safety_10v = { 10U, 90U,
IO_PIN_NONE };

// Safety configuration for ADC 0-32V

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
