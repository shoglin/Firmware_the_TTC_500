#include "Pin_Capabilities.h"

void Init_Pin(ubyte1 group_idx, ubyte1 pin_idx, ubyte1 pin_value)
{
    // Calculate internal numb pin (0..95)

    ubyte1 internal_numb_pin = (group_idx * 4U) + pin_idx; // Counted between 0 and 95

    ubyte1 current_config = Get_Pin_current_config(
            &g_groups[group_idx].current_cmd, pin_idx);

    ubyte2 PVG_pin_value = pin_value * 100U;

    ubyte2 PWD_pin_value = (ubyte2) (((ubyte4) pin_value * 65535U) / 100U);

    switch (internal_numb_pin)
    {

    // Initial group 1 (pins step-by-step)

    case 0: // Pin 103
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_48:
             pupd and limits ignored;
             The input IO_DI_48 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_48 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_48, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_00:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_00 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_00 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_00
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_00, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 1: // Pin 127
        switch (current_config)
        {
        case 0:
            break;
        case 1:
            /* IO_DI_49:
             pupd and limits ignored;
             The input IO_DI_49 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_49 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_49, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_01:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_01 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_01 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_01
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_01, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 2: // Pin 104
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_50:
             pupd and limits ignored;
             The input IO_DI_50 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_50 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_50, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_02:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_02 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_02 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_02
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_02, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 3: // Pin 128
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_51:
             pupd and limits ignored;
             The input IO_DI_51 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_51 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_51, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_03:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_03 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_03 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_03
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_03, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 4: // Pin 105
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_52:
             pupd and limits ignored;
             The input IO_DI_52 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_52 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_52, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_04:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_04 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_04 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_04.
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_04, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 5: // Pin 129
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_53:
             pupd and limits ignored;
             The input IO_DI_53 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_53 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_53, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_05:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_06 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_06 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_05.
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_05, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 6: // Pin 130
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_54:
             pupd and limits ignored;
             The input IO_DI_54 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_54 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_54, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_06:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_06 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_06 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement(IO_ADC_06.
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_06, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 7: // Pin 130
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /* IO_DI_55:
             pupd and limits ignored;
             The input IO_DI_55 have a fixed switching threshold of 2.5V.
             Attention:
             IO_DI_55 have a fixed pull up and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_55, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_07:
             type: IO_ADC_RATIOMETRIC,
             IO_ADC_CURRENT, IO_ADC_RESISTIVE or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL)
             following restrictions additionally apply:

             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             For IO_ADC_RATIOMETRIC mode the following configuration options are recommended:
             3 mode ADC: IO_ADC_07 with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             3 mode ADC: IO_ADC_07 with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V).

             Note:
             If a channel is configured as safety critical and a sensor supply
             was configured, also the sensor supply voltage will be checked
             by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)

             3 mode ADC:
             5V ADC inputs.
             Up to 8 ADC inputs for 0-5V measurement IO_ADC_07.
             Can be configured as resistive, current, absolute or ratiometric input.
             An additional reference channel or a sensor supply measurement (for the ratiometric case) will be configured and serves to correct the ADC signal.
             Range: 0-5V.

             The precision of the remaining configuration options
             in IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V,
             therefore the precision of those inputs is only slightly improved by selecting the ratiometric mode.
             he configuration options not listed above are NOT recommended.

             Ratiometric configuration
             use this configuration if the connected sensor is supplied by one of the sensor supplies
             (IO_SENSOR_SUPPLY_0 or IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2) and delivers a voltage signal.
             Task function returns voltage in [mV]
             */

            IO_ADC_ChannelInit(IO_ADC_07, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 8: // Pin 107
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_56
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_56 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_56, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_08:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.


             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_RESISTIVE: 0..100000 (0Ohm..100000Ohm)
             IO_ADC_ABSOLUTE: 0..5000 (0V..5.000V)


             2 mode 10V ADC: IO_ADC_08 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_08 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_08 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_08, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 9: // Pin 131
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_57
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_57 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_57, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_09:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_09 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_09 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_09 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_09, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 10: // Pin 108
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_58
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_58 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_58, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_10:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_10 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_10 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_10 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_10, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 11: // Pin 132
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_59
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_59 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_59, IO_DI_PD_10K, NULL);
            break;

        case 2:

            /* IO_ADC_11:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_11 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_11 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_11 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_11, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 12: // Pin 109
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_60
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_60 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_60, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_12:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_12 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_12 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_12 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_12, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 13: // Pin 133
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_61
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_61 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_61, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_13:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_13 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_13 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_13 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_13, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 14: // Pin 110
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_62
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_62 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_62, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_14:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_14 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_14 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_14 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_14, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 15: // Pin 134
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*IO_DI_63
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_63 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_63, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_15:
             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_10V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..10200 (0V..10.200V)

             2 mode 10V ADC: IO_ADC_15 configured in
             IO_ADC_RANGE_5V with IO_ADC_SENSOR_SUPPLY_0 or IO_ADC_SENSOR_SUPPLY_1.
             2 mode 10V ADC: IO_ADC_15 configured in
             IO_ADC_RANGE_5V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 5V ... 10V)

             2 mode 10V ADC: IO_ADC_15 configured in
             IO_ADC_RANGE_10V range with IO_ADC_SENSOR_SUPPLY_2 (sensor supply voltage setting 6V ... 10V).
             The precision of the remaining configuration options in
             IO_ADC_RATIOMETRIC mode for reading a ratiometric sensor connected to one of the sensor supplies
             is mainly limited by the fact that the related stages are designed for input voltages up to 32V or 55V, therefore the precision
             of those inputs is only slightly improved by selecting the ratiometric mode. The configuration options not listed above are NOT recommended.
             */

            IO_ADC_ChannelInit(IO_ADC_15, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 16: // Pin 111
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_64:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_64 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_64, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_16:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_16, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 17: // Pin 135
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_65:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_65 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_65, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_17:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_17, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 18: // Pin 112
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_66:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_66 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_66, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_18:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_18, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 19: // Pin 136
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_67:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_67 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_67, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_19:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_19, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 20: // Pin 113
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_68:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_68 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_68, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_20:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_20, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 21: // Pin 137
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_69:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_69 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_69, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_21:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_21, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 22: // Pin 114
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_70:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_70 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_70, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_22:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE (Range 32V): 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_22, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_32V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 23: // Pin 138
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_71:
             limits: Voltage limits for low/high-levels
             Attention:
             The input IO_DI_71 is only suitable for switches to BAT.
             */

            IO_DI_Init(IO_DI_71, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_23:

             type: IO_ADC_RATIOMETRIC, IO_ADC_CURRENT or IO_ADC_ABSOLUTE
             range: IO_ADC_RANGE_5V or IO_ADC_RANGE_32V (supported for type IO_ADC_ABSOLUTE and IO_ADC_RATIOMETRIC)
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2
             safety_conf: Safety configuration

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_23, IO_ADC_ABSOLUTE,
            IO_ADC_RANGE_5V,
                                           IO_ADC_NO_PULL, IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 24: // Pin 115
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_36:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_36 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_36, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_24:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_24,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_00:
             * Setup single timer channel that measures frequency and pulse-width at the same time.
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      IO_PWD_PD_90:   Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf    - Relevant safety configurations for the checker modules
             *
             * Supported features for IO_PWD_00:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration supported
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_00 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_00,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL);

            /*
             * INCREMENTAL MODE (Inactive)
             * Setup a single incremental interface.
             *
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_00
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *                      count on IO_PWD_00 for 1st incremental interface
             *                      count on IO_PWD_02 for 2nd incremental interface
             *                      count on IO_PWD_04 for 3rd incremental interface
             *                      count on IO_PWD_06 for 4th incremental interface
             *                      count on IO_PWD_08 for 5th incremental interface
             *                      count on IO_PWD_10 for 6th incremental interface
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00.
             *
             *   A channel that is initialized with this function can retrieve the counter value: IO_PWD_IncGet()
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     IO_PWD_00 and IO_PWD_01 define the 1st incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface,
             *   independently if the function gets called with the 1st or 2nd channel belonging
             *   to an incremental interface.
             *
             *   The incremental interface will decrement when the 1st channel is leading
             *   and increment when the 2nd channel is leading.

             IO_PWD_IncInit(IO_PWD_00,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Counter Mode (Inactive)
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_05
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00 .. IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_00,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Setup a single universal timer channel.
             *
             * Parameters:
             *   timer_channel - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   cplx_conf     - Complex configuration
             *   cnt_conf      - Edge counter configuration
             *   inc_conf      - Incremental counter configuration
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *                     IO_PWD_PD_90:  Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *   Note that this setting is invalid if the input is also configured for edge and/or
             *   incremental counter mode.
             *
             *   If a channel is configured for incremental mode, both the primary and secondary channel
             *   are redundantly configured using the provided complex, edge counter and safety configuration.
             *   Thus, the application must periodically call IO_PWD_UniversalGet() for both channels
             *   if either the complex or edge counter mode is configured for safety.
             *
             * Supported features for IO_PWD_00 .. IO_PWD_05:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration
             *
             * Remarks:
             *   Parameter safety_conf can be set to NULL in order to initialize the input as non-safety-critical.
             *   To configure the input as safety-critical, parameter safety_conf must provide exactly one valid
             *   (i.e., not NULL) safety configuration. Providing zero or multiple safety configurations or a
             *   safety configuration for a mode that is not configured will fail with return code
             *   IO_E_INVALID_SAFETY_CONFIG.
             *
             *   A channel that is initialized with this function can retrieve its measurement results
             *   by calling the function: IO_PWD_UniversalGet()
             *
             *   The timing measurement for channels IO_PWD_00 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             *   The maximum frequency that can be measured with IO_PWD_00 is 20kHz.
             *
             * Note:
             *   For complex mode, the driver doesn't return a value as long as not all configured samples are captured.

             IO_PWD_UniversalInit(IO_PWD_00,
             NULL,
             NULL,
             NULL,
             IO_PWD_PU_10K,
             NULL);
             */
            break;
        }
        break;

    case 25: // Pin 139
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_37:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_37 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_37, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_25:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_25,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_01:
             * Setup single timer channel that measures frequency and pulse-width at the same time.
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      IO_PWD_PD_90:   Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf    - Relevant safety configurations for the checker modules
             *
             * Supported features for IO_PWD_01:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration supported
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_00 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_01,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL);

            /*
             * INCREMENTAL MODE (Inactive)
             * Setup a single incremental interface.
             *
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_01
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *                      count on IO_PWD_00 for 1st incremental interface
             *                      count on IO_PWD_02 for 2nd incremental interface
             *                      count on IO_PWD_04 for 3rd incremental interface
             *                      count on IO_PWD_06 for 4th incremental interface
             *                      count on IO_PWD_08 for 5th incremental interface
             *                      count on IO_PWD_10 for 6th incremental interface
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00.
             *
             *   A channel that is initialized with this function can retrieve the counter value: IO_PWD_IncGet()
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     IO_PWD_00 and IO_PWD_01 define the 1st incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface,
             *   independently if the function gets called with the 1st or 2nd channel belonging
             *   to an incremental interface.
             *
             *   The incremental interface will decrement when the 1st channel is leading
             *   and increment when the 2nd channel is leading.

             IO_PWD_IncInit(IO_PWD_01,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Counter Mode (Inactive)
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_05
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00 .. IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_01,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Setup a single universal timer channel.
             *
             * Parameters:
             *   timer_channel - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   cplx_conf     - Complex configuration
             *   cnt_conf      - Edge counter configuration
             *   inc_conf      - Incremental counter configuration
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *                     IO_PWD_PD_90:  Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *   Note that this setting is invalid if the input is also configured for edge and/or
             *   incremental counter mode.
             *
             *   If a channel is configured for incremental mode, both the primary and secondary channel
             *   are redundantly configured using the provided complex, edge counter and safety configuration.
             *   Thus, the application must periodically call IO_PWD_UniversalGet() for both channels
             *   if either the complex or edge counter mode is configured for safety.
             *
             * Supported features for IO_PWD_00 .. IO_PWD_05:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration
             *
             * Remarks:
             *   Parameter safety_conf can be set to NULL in order to initialize the input as non-safety-critical.
             *   To configure the input as safety-critical, parameter safety_conf must provide exactly one valid
             *   (i.e., not NULL) safety configuration. Providing zero or multiple safety configurations or a
             *   safety configuration for a mode that is not configured will fail with return code
             *   IO_E_INVALID_SAFETY_CONFIG.
             *
             *   A channel that is initialized with this function can retrieve its measurement results
             *   by calling the function: IO_PWD_UniversalGet()
             *
             *   The timing measurement for channels IO_PWD_00 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             *   The maximum frequency that can be measured with IO_PWD_00 is 20kHz.
             *
             * Note:
             *   For complex mode, the driver doesn't return a value as long as not all configured samples are captured.

             IO_PWD_UniversalInit(IO_PWD_01,
             NULL,
             NULL,
             NULL,
             IO_PWD_PU_10K,
             NULL);
             */
            break;
        }
        break;

    case 26: // Pin 116
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_38:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_37 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_38, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_26:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..5000 (0V..5.000V)
             IO_ADC_CURRENT: 0..25000 (0mA..25.000mA)
             IO_ADC_ABSOLUTE: 0..32.000 (0V..32.000V)
             */

            IO_ADC_ChannelInit(IO_ADC_26,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_PIN_NONE,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_02:
             * Complex Mode
             * Setup single timer channel that measures frequency and pulse-width at the same time.
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      IO_PWD_PD_90:   Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf    - Relevant safety configurations for the checker modules
             *
             * Supported features for IO_PWD_02:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration supported
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_00..IO_PWD_05 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_02,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL);

            /* Incremental Mode Mode
             * Setup a single incremental interface.
             *
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_02
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *                      count on IO_PWD_00 for 1st incremental interface
             *                      count on IO_PWD_02 for 2nd incremental interface
             *                      count on IO_PWD_04 for 3rd incremental interface
             *                      count on IO_PWD_06 for 4th incremental interface
             *                      count on IO_PWD_08 for 5th incremental interface
             *                      count on IO_PWD_10 for 6th incremental interface
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   A channel that is initialized with this function can retrieve the counter value: IO_PWD_IncGet()
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     IO_PWD_00 and IO_PWD_01 define the 1st incremental interface.
             *     IO_PWD_02 and IO_PWD_03 define the 2nd incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface,
             *   independently if the function gets called with the 1st or 2nd channel belonging
             *   to an incremental interface.
             *
             *   The incremental interface will decrement when the 1st channel is leading
             *   and increment when the 2nd channel is leading.

             IO_PWD_IncInit(IO_PWD_02,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             /* Count Mode
             * Setup a single counter channel.
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_05
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_02,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             /* Universal Mdde
             * Setup a single universal timer channel.
             *
             * Parameters:
             *   timer_channel - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   cplx_conf     - Complex configuration
             *   cnt_conf      - Edge counter configuration
             *   inc_conf      - Incremental counter configuration
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *                     IO_PWD_PD_90:  Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *   Note that this setting is invalid if the input is also configured for edge and/or
             *   incremental counter mode.
             *
             *   If a channel is configured for incremental mode, both the primary and secondary channel
             *   are redundantly configured using the provided complex, edge counter and safety configuration.
             *   Thus, the application must periodically call IO_PWD_UniversalGet() for both channels
             *   if either the complex or edge counter mode is configured for safety.
             *
             * Supported features for IO_PWD_00..IO_PWD_05:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration
             *
             * Remarks:
             *   Parameter safety_conf can be set to NULL in order to initialize the input as non-safety-critical.
             *   To configure the input as safety-critical, parameter safety_conf must provide exactly one valid
             *   (i.e., not NULL) safety configuration. Providing zero or multiple safety configurations or a
             *   safety configuration for a mode that is not configured will fail with return code
             *   IO_E_INVALID_SAFETY_CONFIG.
             *
             *   A channel that is initialized with this function can retrieve its measurement results
             *   by calling the function: IO_PWD_UniversalGet()
             *
             *   The timing measurement for channels IO_PWD_00..IO_PWD_05 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             *   The maximum frequency that can be measured with IO_PWD_00..IO_PWD_05 is 20kHz.
             *
             * Note:
             *   For complex mode, the driver doesn't return a value as long as not all configured samples are captured.

             IO_PWD_UniversalInit(IO_PWD_02,
             NULL,
             NULL,
             NULL,
             IO_PWD_PU_10K,
             NULL);
             */
            break;
        }
        break;

    case 27: // Pin 140
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_39:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_39 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_39, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_27:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_27,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_03:
             * Complex Mode
             * Setup single timer channel that measures frequency and pulse-width at the same time.
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      IO_PWD_PD_90:   Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf    - Relevant safety configurations for the checker modules
             *
             * Supported features for IO_PWD_03:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration supported
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_00..IO_PWD_05 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_03,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL);

            /* Incremental Mode Mode
             * Setup a single incremental interface.
             *
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_03
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *                      count on IO_PWD_00 for 1st incremental interface
             *                      count on IO_PWD_02 for 2nd incremental interface
             *                      count on IO_PWD_04 for 3rd incremental interface
             *                      count on IO_PWD_06 for 4th incremental interface
             *                      count on IO_PWD_08 for 5th incremental interface
             *                      count on IO_PWD_10 for 6th incremental interface
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05
             *
             *   A channel that is initialized with this function can retrieve the counter value: IO_PWD_IncGet()
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     IO_PWD_00 and IO_PWD_01 define the 1st incremental interface.
             *     IO_PWD_02 and IO_PWD_03 define the 2nd incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface,
             *   independently if the function gets called with the 1st or 2nd channel belonging
             *   to an incremental interface.
             *
             *   The incremental interface will decrement when the 1st channel is leading
             *   and increment when the 2nd channel is leading.

             IO_PWD_IncInit(IO_PWD_03,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             /* Count Mode
             * Setup a single counter channel.
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_05
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_03,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             /* Universal Mdde
             * Setup a single universal timer channel.
             *
             * Parameters:
             *   timer_channel - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   cplx_conf     - Complex configuration
             *   cnt_conf      - Edge counter configuration
             *   inc_conf      - Incremental counter configuration
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *                     IO_PWD_PD_90:  Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *   Note that this setting is invalid if the input is also configured for edge and/or
             *   incremental counter mode.
             *
             *   If a channel is configured for incremental mode, both the primary and secondary channel
             *   are redundantly configured using the provided complex, edge counter and safety configuration.
             *   Thus, the application must periodically call IO_PWD_UniversalGet() for both channels
             *   if either the complex or edge counter mode is configured for safety.
             *
             * Supported features for IO_PWD_00..IO_PWD_05:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration
             *
             * Remarks:
             *   Parameter safety_conf can be set to NULL in order to initialize the input as non-safety-critical.
             *   To configure the input as safety-critical, parameter safety_conf must provide exactly one valid
             *   (i.e., not NULL) safety configuration. Providing zero or multiple safety configurations or a
             *   safety configuration for a mode that is not configured will fail with return code
             *   IO_E_INVALID_SAFETY_CONFIG.
             *
             *   A channel that is initialized with this function can retrieve its measurement results
             *   by calling the function: IO_PWD_UniversalGet()
             *
             *   The timing measurement for channels IO_PWD_00..IO_PWD_05 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             *   The maximum frequency that can be measured with IO_PWD_00..IO_PWD_05 is 20kHz.
             *
             * Note:
             *   For complex mode, the driver doesn't return a value as long as not all configured samples are captured.

             IO_PWD_UniversalInit(IO_PWD_03,
             NULL,
             NULL,
             NULL,
             IO_PWD_PU_10K,
             NULL);
             */
            break;
        }
        break;

    case 28: // Pin 117
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_40:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_40 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_40, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_28:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_28,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        }
        break;

    case 29: // Pin 141
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_41:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_41 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_41, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_29:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_29,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_05:
             * Complex Mode
             * Setup single timer channel that measures frequency and pulse-width at the same time.
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      IO_PWD_PD_90:   Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf    - Relevant safety configurations for the checker modules
             *
             * Supported features for IO_PWD_05:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration supported
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_00..IO_PWD_05 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_05,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL);

            /* Incremental Mode Mode
             * Setup a single incremental interface.
             *
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_05
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *                      count on IO_PWD_00 for 1st incremental interface
             *                      count on IO_PWD_02 for 2nd incremental interface
             *                      count on IO_PWD_04 for 3rd incremental interface
             *                      count on IO_PWD_06 for 4th incremental interface
             *                      count on IO_PWD_08 for 5th incremental interface
             *                      count on IO_PWD_10 for 6th incremental interface
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05
             *
             *   A channel that is initialized with this function can retrieve the counter value: IO_PWD_IncGet()
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     IO_PWD_00 and IO_PWD_01 define the 1st incremental interface.
             *     IO_PWD_02 and IO_PWD_03 define the 2nd incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface,
             *   independently if the function gets called with the 1st or 2nd channel belonging
             *   to an incremental interface.
             *
             *   The incremental interface will decrement when the 1st channel is leading
             *   and increment when the 2nd channel is leading.

             IO_PWD_IncInit(IO_PWD_05,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             /* Count Mode
             * Setup a single counter channel.
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_05
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_05,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);

             /* Universal Mdde
             * Setup a single universal timer channel.
             *
             * Parameters:
             *   timer_channel - Timer channel: IO_PWD_00 .. IO_PWD_05
             *   cplx_conf     - Complex configuration
             *   cnt_conf      - Edge counter configuration
             *   inc_conf      - Incremental counter configuration
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *                     IO_PWD_PD_90:  Pull down 90 Ohm (for 7mA/14mA sensors)
             *   safety_conf   - Relevant safety configurations for the checker modules
             *
             * Attention:
             *   Passing IO_PWD_PD_90 as pupd parameter configures the input for a current sensor (7mA/14mA).
             *   In this case an additional range check on the current signal will be performed.
             *   Note that this setting is invalid if the input is also configured for edge and/or
             *   incremental counter mode.
             *
             *   If a channel is configured for incremental mode, both the primary and secondary channel
             *   are redundantly configured using the provided complex, edge counter and safety configuration.
             *   Thus, the application must periodically call IO_PWD_UniversalGet() for both channels
             *   if either the complex or edge counter mode is configured for safety.
             *
             * Supported features for IO_PWD_00..IO_PWD_05:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K, IO_PWD_PD_10K or IO_PWD_PD_90
             *   safety_conf:   Safety configuration
             *
             * Remarks:
             *   Parameter safety_conf can be set to NULL in order to initialize the input as non-safety-critical.
             *   To configure the input as safety-critical, parameter safety_conf must provide exactly one valid
             *   (i.e., not NULL) safety configuration. Providing zero or multiple safety configurations or a
             *   safety configuration for a mode that is not configured will fail with return code
             *   IO_E_INVALID_SAFETY_CONFIG.
             *
             *   A channel that is initialized with this function can retrieve its measurement results
             *   by calling the function: IO_PWD_UniversalGet()
             *
             *   The timing measurement for channels IO_PWD_00..IO_PWD_05 is based on a 27bit timer with a resolution
             *   of 0.5 us, therefore the period that shall be measured must be smaller than 67.108.863 us (~ 67 s).
             *
             *   The maximum frequency that can be measured with IO_PWD_00..IO_PWD_05 is 20kHz.
             *
             * Note:
             *   For complex mode, the driver doesn't return a value as long as not all configured samples are captured.

             IO_PWD_UniversalInit(IO_PWD_05,
             NULL,
             NULL,
             NULL,
             IO_PWD_PU_10K,
             NULL);
             */
            break;
        }
        break;

    case 30: // Pin 122
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_42:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_42 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_42, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_30:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_30,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_06:
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_06 .. IO_PWD_11
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      (NOTE: IO_PWD_PD_90 is NOT supported for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported for this group, must be NULL)
             *
             * Supported features for IO_PWD_06:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K or IO_PWD_PD_10K
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_06 .. IO_PWD_11 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 0.5 us.
             *   Because those timers work in an accumulating fashion
             *   the product of the measured period and the capture_count must be below this time.
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_06,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL); // Safety NOT supported here

            /* Incremental Mode
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_06
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     ...
             *     IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface.

             IO_PWD_IncInit(IO_PWD_06,  // <-- Fixed: was IO_PWD_05
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);       // Safety NOT supported here

             * Count Mode
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_11
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_06,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);

             // Universal mode is only available for IO_PWD_00..IO_PWD_05.
             // Do not attempt to initialize it for this group.
             */
            break;
        }
        break;

    case 31: // Pin 146
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_43:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_43 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_43, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_31:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_31,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_07:
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_06 .. IO_PWD_11
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      (NOTE: IO_PWD_PD_90 is NOT supported for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported for this group, must be NULL)
             *
             * Supported features for IO_PWD_07:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K or IO_PWD_PD_10K
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_06 .. IO_PWD_11 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 0.5 us.
             *   Because those timers work in an accumulating fashion
             *   the product of the measured period and the capture_count must be below this time.
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_07,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL); // Safety NOT supported here

            /* Incremental Mode
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_07
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     ...
             *     IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface.

             IO_PWD_IncInit(IO_PWD_07,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Count Mode
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_11
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_07,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);       // Safety NOT supported here

             // Universal mode is only available for IO_PWD_00..IO_PWD_05.
             // Do not attempt to initialize it for this group.
             */
            break;
        }
        break;

    case 32: // Pin 123
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_44:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_43 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_44, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_32:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_32,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_08:
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_06 .. IO_PWD_11
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      (NOTE: IO_PWD_PD_90 is NOT supported for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported for this group, must be NULL)
             *
             * Supported features for IO_PWD_08:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K or IO_PWD_PD_10K
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_06 .. IO_PWD_11 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 0.5 us.
             *   Because those timers work in an accumulating fashion
             *   the product of the measured period and the capture_count must be below this time.
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_08,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL); // Safety NOT supported here

            /* Incremental Mode
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_08
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     ...
             *     IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface.

             IO_PWD_IncInit(IO_PWD_08,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Count Mode
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_11
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_08,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);       // Safety NOT supported here

             // Universal mode is only available for IO_PWD_00..IO_PWD_05.
             // Do not attempt to initialize it for this group.
             */
            break;
        }
        break;

    case 33: // Pin 147
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_45:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_45 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_45, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_33:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_33,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_09:
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_06 .. IO_PWD_11
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      (NOTE: IO_PWD_PD_90 is NOT supported for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported for this group, must be NULL)
             *
             * Supported features for IO_PWD_09:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K or IO_PWD_PD_10K
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_06 .. IO_PWD_11 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 0.5 us.
             *   Because those timers work in an accumulating fashion
             *   the product of the measured period and the capture_count must be below this time.
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_09,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL); // Safety NOT supported here

            /* Incremental Mode
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_09
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     ...
             *     IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface.

             IO_PWD_IncInit(IO_PWD_09,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Count Mode
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_11
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_09,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);       // Safety NOT supported here

             // Universal mode is only available for IO_PWD_00..IO_PWD_05.
             // Do not attempt to initialize it for this group.
             */
            break;
        }
        break;

    case 34: // Pin 124
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_46:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_46 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_46, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_34:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_34,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_10:
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_06 .. IO_PWD_11
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      (NOTE: IO_PWD_PD_90 is NOT supported for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported for this group, must be NULL)
             *
             * Supported features for IO_PWD_10:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K or IO_PWD_PD_10K
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_06 .. IO_PWD_11 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 0.5 us.
             *   Because those timers work in an accumulating fashion
             *   the product of the measured period and the capture_count must be below this time.
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_10,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL); // Safety NOT supported here

            /* Incremental Mode
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_10
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     ...
             *     IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface.

             IO_PWD_IncInit(IO_PWD_10,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Count Mode
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_11
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_10,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);       // Safety NOT supported here

             // Universal mode is only available for IO_PWD_00..IO_PWD_05.
             // Do not attempt to initialize it for this group.
             */
            break;
        }
        break;

    case 35: // Pin 148
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_47:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             The input IO_DI_47 have a fixed switching threshold of 2.5V.
             */

            IO_DI_Init(IO_DI_47, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_35:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_35,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 3:

            /* IO_PWD_11:
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_06 .. IO_PWD_11
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of frequency/pulse-width measurements that will be accumulated (1..8)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_PU_10K:  Pull up 10 kOhm
             *                      IO_PWD_PD_10K:  Pull down 10 kOhm
             *                      (NOTE: IO_PWD_PD_90 is NOT supported for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported for this group, must be NULL)
             *
             * Supported features for IO_PWD_11:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1..8
             *   pupd:          IO_PWD_PU_10K or IO_PWD_PD_10K
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_06 .. IO_PWD_11 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 0.5 us.
             *   Because those timers work in an accumulating fashion
             *   the product of the measured period and the capture_count must be below this time.
             *
             * Note:
             *   Until not all configured samples are captured, the driver doesn't return a value.
             */

            IO_PWD_ComplexInit(IO_PWD_11,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 8,
                                           IO_PWD_PU_10K,
                                           NULL); // Safety NOT supported here

            /* Incremental Mode
             * Parameters:
             *   inc_channel  - Channel of the incremental interface: IO_PWD_11
             *   mode         - Defines the counter behavior:
             *                    IO_PWD_INC_2_COUNT: Counts up/down on any edge of the two input channels
             *                    IO_PWD_INC_1_COUNT: Counts up/down on any edge of the 1st input channel only
             *   count_init   - Init value of the incremental counter (0..65535)
             *   pupd         - Pull up/down interface:
             *                    IO_PWD_PU_10K: Pull up 10 kOhm
             *                    IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf  - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.
             *
             *   Two PWD channels are used (needed) for one incremental interface.
             *   The pairs are defined in the following order:
             *     ...
             *     IO_PWD_06 and IO_PWD_07 define the 4th incremental interface.
             *
             * Note:
             *   The function initializes both PWD channels of the incremental interface.

             IO_PWD_IncInit(IO_PWD_11,
             IO_PWD_INC_1_COUNT,
             PWD_pin_value,
             IO_PWD_PU_10K,
             NULL);

             * Count Mode
             *
             * Parameters:
             *   count_channel - Counter channel: IO_PWD_00 .. IO_PWD_11
             *   mode          - Specify on which edge shall be count:
             *                     IO_PWD_RISING_COUNT:  count on a rising edge
             *                     IO_PWD_FALLING_COUNT: count on a falling edge
             *                     IO_PWD_BOTH_COUNT:    count on both edges
             *   direction     - Specify the counting direction:
             *                     IO_PWD_UP_COUNT:   counts up
             *                     IO_PWD_DOWN_COUNT: counts down
             *   count_init    - Init value of the counter (0..65535)
             *   pupd          - Pull up/down interface:
             *                     IO_PWD_PU_10K: Pull up 10 kOhm
             *                     IO_PWD_PD_10K: Pull down 10 kOhm
             *   safety_conf   - NOT supported for this group, must be NULL
             *
             * Remarks:
             *   The parameter safety_conf is only supported for the PWD channels IO_PWD_00..IO_PWD_05.

             IO_PWD_CountInit(IO_PWD_11,
             IO_PWD_RISING_COUNT,
             IO_PWD_UP_COUNT,
             0,
             IO_PWD_PU_10K,
             NULL);       // Safety NOT supported here

             // Universal mode is only available for IO_PWD_00..IO_PWD_05.
             // Do not attempt to initialize it for this group.
             */
            break;
        }
        break;

    case 36: // Pin 149
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_72:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_72, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_35:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_36,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_00:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_00
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_00 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_00, TRUE, NULL);
            break;
        }
        break;

    case 37: // Pin 173
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_73:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_73, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_37:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_37,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_01:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_01
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_01 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_01, TRUE, NULL);
            break;
        }
        break;

    case 38: // Pin 152
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_74:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_74, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_38:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_38,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_02:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_02
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_02 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_02, TRUE, NULL);
            break;
        }
        break;

    case 39: // Pin 176
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_75:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_75, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_38:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_39,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_03:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_03
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_02 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_03, TRUE, NULL);
            break;
        }
        break;

    case 40: // Pin 155
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_76:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_76, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_40:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_40,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_04:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_04
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_03 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_04, TRUE, NULL);
            break;
        }
        break;

    case 41: // Pin 179
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_77:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_77, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_41:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_41,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_05:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_05
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_04 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_05, TRUE, NULL);
            break;
        }
        break;

    case 42: // Pin 158
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_78:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_78, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_42:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_42,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_06:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_06
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_05 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_06, TRUE, NULL);
            break;
        }
        break;

    case 43: // Pin 182
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_79:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_79, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_43:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_43,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_07:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_07
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *   safety_conf - Relevant safety configurations for the checker modules.
             *                 Supported for: IO_DO_00..IO_DO_07.
             *                 Passing NULL initializes it as non-safety-critical.
             *
             * Remarks:
             *   - IO_DO_00..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_05 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             */

            IO_DO_Init(IO_DO_07, TRUE, NULL);
            break;
        }
        break;

    case 44: // Pin 251
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_80:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_80 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_80, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_44:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_44,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_08:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_08
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_08, FALSE, NULL);
            break;
        }
        break;

    case 45: // Pin 238
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_81:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_81 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_81, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_45:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_45,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_09:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_09
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_09, FALSE, NULL);
            break;
        }
        break;

    case 46: // Pin 252
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_82:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_82 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_82, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_46:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_46,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_10:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_10
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_10, FALSE, NULL);
            break;
        }
        break;

    case 47: // Pin 239
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_83:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_83 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_83, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_47:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_47,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_11:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_11
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_11, FALSE, NULL);
            break;
        }
        break;

    case 48: // Pin 253
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_84:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_84 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_84, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_48:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_48,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_12:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_12
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_12, FALSE, NULL);
            break;
        }
        break;

    case 49: // Pin 240
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_85:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_85 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_85, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_49:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_49,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_13:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_13
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_13, FALSE, NULL);
            break;
        }
        break;

    case 50: // Pin 254
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_86:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_86 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_86, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_50:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_50,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_14:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_14
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_14, FALSE, NULL);
            break;
        }
        break;

    case 51: // Pin 241
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_87:
             limits: Voltage limits for low/high-levels
             Depending on the parameter limits switches to ground or BAT can be read.

             The input IO_DI_87 have a fixed pull up.
             */

            IO_DI_Init(IO_DI_87, IO_DI_NO_PULL, NULL);
            break;
        case 2:

            /* IO_ADC_51:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_51,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 5:
            /* IO_DO_15:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_15
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_08..IO_DO_15!
             *                               Diagnostic (open load/short circuit) NO supported.
             *   safety_conf - Relevant safety configurations:
             *                  NO supported for IO_DO_08..IO_DO_15. Only NULL.
             *
             * Remarks:
             *   - IO_DO_08..IO_DO_15 are controlled over SPI shift registers (updated every 1ms).
             *   - Protection reset wait time for IO_DO_08 is 1 second.
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             */

            IO_DO_Init(IO_DO_15, FALSE, NULL);
            break;
        }
        break;

    case 52: // Pin 153
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_00:
             pupd and limits ignored

             The input IO_DI_00 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_00 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_00, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_16:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_16
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_16, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_00: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_00, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 53: // Pin 177
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_01:
             pupd and limits ignored

             The input IO_DI_01 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_01 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_01, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_17:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_17
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_17, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_00: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_01, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 54: // Pin 156
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_02:
             pupd and limits ignored

             The input IO_DI_01 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_02 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_02, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_18:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_18
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_18, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_02: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_02, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 55: // Pin 180
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_03:
             pupd and limits ignored

             The input IO_DI_01 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_01 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_03, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_19:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_19
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_19, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_03: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_03, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 56: // Pin 159
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_04:
             pupd and limits ignored

             The input IO_DI_04 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_04 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_04, IO_DI_NO_PULL, NULL);
            break;
            ;
        case 5:
            /* IO_DO_20:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_20
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_20, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_04: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_04, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 57: // Pin 183
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_05:
             pupd and limits ignored

             The input IO_DI_05 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_05 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_05, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_21:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_21
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_21, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_05: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_05, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 58: // Pin 186
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_06:
             pupd and limits ignored

             The input IO_DI_06 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_06 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_06, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_22:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_22
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_22, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_06: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_06, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 59: // Pin 162
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_07:
             pupd and limits ignored

             The input IO_DI_07 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_07 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_07, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_23:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_23
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_23, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_07: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_07, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 60: // Pin 189
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_08:
             pupd and limits ignored

             The input IO_DI_08 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_08 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_08, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_24:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_24
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_24, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_08: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_08, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 61: // Pin 165
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_09:
             pupd and limits ignored

             The input IO_DI_09 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_09 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_09, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_25:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_25
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_25, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_09: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_09, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 62: // Pin 192
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_10:
             pupd and limits ignored

             The input IO_DI_10 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_10 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_10, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_26:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_26
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_26, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_10: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_10, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 63: // Pin 168
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_11:
             pupd and limits ignored

             The input IO_DI_11 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_10 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_11, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_27:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_27
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_27, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_11: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_11, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 64: // Pin 195
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_12:
             pupd and limits ignored

             The input IO_DI_12 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_12 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_12, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_28:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_28
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_28, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_12: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_12, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 65: // Pin 171
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_13:
             pupd and limits ignored

             The input IO_DI_13 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_13 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_13, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_29:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_29
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_29, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_13: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_13, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 66: // Pin 154
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_14:
             pupd and limits ignored

             The input IO_DI_14 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_14 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_14, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_30:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_30
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_30, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_13: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_13, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 67: // Pin 178
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_15:
             pupd and limits ignored

             The input IO_DI_15 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_15 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_13, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_31:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_31
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_31, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_15: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_15, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 68: // Pin 157
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_16:
             pupd and limits ignored

             The input IO_DI_16 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_16 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_16, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_32:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_32
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_32, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_16: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_16, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 69: // Pin 181
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_17:
             pupd and limits ignored

             The input IO_DI_17 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_17 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_17, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_33:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_33
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_33, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_17: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_17, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 70: // Pin 160
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_18:
             pupd and limits ignored

             The input IO_DI_18 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_18 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_18, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_34:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_34
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_34, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_17: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_17, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 71: // Pin 184
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_19:
             pupd and limits ignored

             The input IO_DI_19 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_19 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_19, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_35:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_35
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_35, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_19: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_19, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 72: // Pin 187
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_20:
             pupd and limits ignored

             The input IO_DI_20 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_20 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_20, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_36:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_36
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_36, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_20: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_20, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 73: // Pin 163
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_21:
             pupd and limits ignored

             The input IO_DI_21 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_21 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_21, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_37:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_37
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_37, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_21: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_21, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 74: // Pin 190
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_22:
             pupd and limits ignored

             The input IO_DI_22 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_22 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_22, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_38:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_38
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_38, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_22: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_22, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 75: // Pin 166
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_23:
             pupd and limits ignored

             The input IO_DI_23 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_23 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_23, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_39:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_39
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_39, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_23: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_23, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 76: // Pin 193
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_24:
             pupd and limits ignored

             The input IO_DI_24 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_24 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_24, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_40:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_40
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_40, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_24: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_24, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 77: // Pin 169
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_25:
             pupd and limits ignored

             The input IO_DI_25 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_25 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_25, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_41:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_41
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_41, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_25: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_25, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 78: // Pin 196
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_26:
             pupd and limits ignored

             The input IO_DI_26 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_26 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_26, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_42:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_42
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_42, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_26: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_26, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 79: // Pin 172
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_27:
             pupd and limits ignored

             The input IO_DI_27 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_27 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_27, IO_DI_NO_PULL, NULL);
            break;
        case 5:
            /* IO_DO_43:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_43
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_43, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_27: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_27, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 80: // Pin 101
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_28:
             pupd and limits ignored

             The input IO_DI_28 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_28 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_28, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_12
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_12,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_44:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_44
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_44, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_28: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_28, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 81: // Pin 125
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_29:
             pupd and limits ignored

             The input IO_DI_29 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_29 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_29, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_13
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_13,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_45:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_45
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_45, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_29: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_29, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 82: // Pin 150
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_30:
             pupd and limits ignored

             The input IO_DI_30 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_30 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_30, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_14
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_14,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_46:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_46
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_46, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_30: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_30, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 83: // Pin 174
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_31:
             pupd and limits ignored

             The input IO_DI_31 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_31 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_31, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_15
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_15,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_47:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_47
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_47, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_31: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_31, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 84: // Pin 102
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_32:
             pupd and limits ignored

             The input IO_DI_32 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_32 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_32, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_16
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_16,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_48:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_48
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_48, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_32: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_32, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 85: // Pin 126
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_33:
             pupd and limits ignored

             The input IO_DI_33 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_33 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_33, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_17
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_17,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_49:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_49
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_49, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_33: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_33, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 86: // Pin 151
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_34:
             pupd and limits ignored

             The input IO_DI_34 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_34 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_34, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_18
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_18,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_50:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_50
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_50, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_34: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_34, 100, TRUE, FALSE, NULL);
            break;
        default:
            IO_E_INVALID_PARAMETER;
            break;
        }
        break;

    case 87: // Pin 175
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_35:
             pupd and limits ignored

             The input IO_DI_35 have a fixed switching threshold of 2.5V.

             The inputs IO_DI_35 have a fixed pull up
             and are only suitable for switches to ground.
             */

            IO_DI_Init(IO_DI_35, IO_DI_NO_PULL, NULL);
            break;
        case 3:
            /* IO_PWD_19
             *
             * Complex Mode
             *
             * Parameters:
             *   timer_channel  - Timer channel: IO_PWD_12 .. IO_PWD_19
             *   pulse_mode     - Specifies the pulse mode:
             *                      IO_PWD_HIGH_TIME:   measure pulse-high-time
             *                      IO_PWD_LOW_TIME:    measure pulse-low-time
             *                      IO_PWD_PERIOD_TIME: measure pulse-high and low-time (Period)
             *   freq_mode      - Specifies the variable edge:
             *                      IO_PWD_RISING_VAR:  rising edge is variable (frequency measured on falling edges)
             *                      IO_PWD_FALLING_VAR: falling edge is variable (frequency measured on rising edges)
             *   capture_count  - Number of measurements (STRICTLY 1 for this group!)
             *   pupd           - Pull up/down interface:
             *                      IO_PWD_NO_PULL: fixed pull resistor (STRICTLY REQUIRED for this group!)
             *   safety_conf    - Relevant safety configurations (NOTE: NOT supported, must be NULL)
             *
             * Supported features for IO_PWD_12 .. IO_PWD_19:
             *   pulse_mode:    IO_PWD_HIGH_TIME, IO_PWD_LOW_TIME or IO_PWD_PERIOD_TIME
             *   freq_mode:     IO_PWD_RISING_VAR or IO_PWD_FALLING_VAR
             *   capture_count: 1 (Driver ignores other values and handles every pulse sample directly)
             *   pupd:          IO_PWD_NO_PULL
             *   safety_conf:   NOT supported
             *
             * Remarks:
             *   A channel that is initialized with this function can retrieve frequency and duty cycle
             *   by calling the function: IO_PWD_ComplexGet()
             *
             *   The timing measurement for channels IO_PWD_12 .. IO_PWD_19 is hardware limited
             *   to 10.000.000 us (= 10 s) with a resolution of 1 us (NOT 0.5 us!).
             *   The maximum frequency that can be measured with IO_PWD_12 .. IO_PWD_19 is 10 kHz.
             *
             * Note:
             *   The driver returns a value after every single sample (capture_count is forced to 1).
             */

            IO_PWD_ComplexInit(IO_PWD_19,
            IO_PWD_HIGH_TIME,
                                           IO_PWD_FALLING_VAR, 1,
                                           IO_PWD_NO_PULL,
                                           NULL);   // Safety NOT supported here

            /* Incremental, count, AND universal modes
             // NOT SUPPORTED for IO_PWD_12 .. IO_PWD_19.
             // Do not attempt to initialize IO_PWD_IncInit, IO_PWD_CountInit,
             // or IO_PWD_UniversalInit for this group.
             */
            break;
        case 5:
            /* IO_DO_51:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_51
             *   diagnostic  - Output configuration:
             *                   TRUE/FALSE: ignored driver for group channel IO_DO_16..IO_DO_51!
             *                               Diagnostic (open load/short circuit) N0 supported.
             *   safety_conf - Relevant safety configurations:
             *                   N0 supported для IO_DO_16..IO_DO_51. Only NULL.
             *
             * Remarks:
             *   - IO_DO_16..IO_DO_51 are an alternative function to IO_PWM_00..IO_PWM_35.
             *   - Protection reset wait time for IO_DO_16 is 10 seconds (NOT 1 second!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - diagnostic parameter is IGNORED for this channel group.
             *   - IO_E_CM_CALIBRATION error can only occur for IO_DO_16..IO_DO_51.
             */

            IO_DO_Init(IO_DO_51, FALSE, NULL);
            break;
        case 6:
            /* IO_PWM_35: setup of a single PWM output.
             *
             * Available functions:
             *   IO_PWM_Init(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *   IO_PWM_InitWithLowside(pwm_channel, frequency, polarity, diag_margin, safety_conf)
             *
             * Parameters:
             *
             * pwm_channel   PWM channel, one of: IO_PWM_00 .. IO_PWM_35
             *
             * frequency     PWM frequency (50 Hz .. 1000 Hz); only predefined
             *               frequencies with a period of an integral multiple
             *               of 1 ms, 0.5 ms or 0.25 ms are possible
             *
             * polarity      Polarity of output signal:
             *                 FALSE - low output signal is variable
             *                 TRUE  - high output signal is variable
             *
             * diag_margin   Indicate if a margin should be applied or not:
             *                 TRUE  - margin is on
             *                 FALSE - no margin will be applied
             *               If a PWM channel is configured safety relevant,
             *               this parameter has to be set to TRUE.
             *
             * safety_conf   [in] Safety configuration of the PWM channel.
             *               The low_side_channel field is evaluated only by
             *               IO_PWM_InitWithLowside(). If a safety configuration
             *               is passed, diag_margin will be forced to TRUE.
             *               NULL - no safety configuration
             */

            IO_PWM_Init(IO_PWM_35, 100, TRUE, FALSE, NULL);
            break;
        }
        break;

    case 88: // Pin 161
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_88:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_88, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_52:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_52,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_00:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_00, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_52:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_52
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_52, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_00:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_00);
            break;
        }
        break;

    case 89: // Pin 185
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_89:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_89, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_53:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_53,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_01:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_01, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_53:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_53
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_53, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_01:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_01);
            break;
        }
        break;

    case 90: // Pin 188
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_90:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_90, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_54:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_54,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_02:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_02, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_54:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_54
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_54, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_02:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_02);
            break;
        }
        break;

    case 91: // Pin 164
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_91:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_91, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_55:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_55,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_03:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_03, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_55:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_54
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_55, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_03:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_03);
            break;
        }
        break;

    case 92: // Pin 191
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_92:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_92, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_56:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_56,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_04:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_04, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_56:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_56
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_56, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_04:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_04);
            break;
        }
        break;

    case 93: // Pin 167
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_93:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_93, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_57:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_57,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_05:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_05, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_57:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_57
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_57, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_05:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_05);
            break;
        }
        break;

    case 94: // Pin 194
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_94:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_94, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_58:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_58,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_06:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_06, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_58:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_58
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_58, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_06:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_06);
            break;
        }
        break;

    case 95: // Pin 170
        switch (current_config)
        {
        case 0:
            break;
        case 1:

            /*
             IO_DI_95:
             pupd: IO_DI_PU_10K or IO_DI_PD_10K
             limits: Voltage limits for low/high-levels
             */

            IO_DI_Init(IO_DI_95, IO_DI_PD_10K, NULL);
            break;
        case 2:

            /* IO_ADC_59:

             type: IO_ADC_RATIOMETRIC or IO_ADC_ABSOLUTE
             sensor_supply: IO_SENSOR_SUPPLY_0, IO_SENSOR_SUPPLY_1 or IO_SENSOR_SUPPLY_2 (supported for type IO_ADC_RATIOMETRIC)
             pupd: IO_ADC_PU_10K or IO_ADC_PD_10K

             If a channel does not support a function,
             the value of the associated parameter will be ignored.

             Attention:
             For safety critical configuration (safety_conf != NULL) following restrictions additionally apply:
             Resistive measurement type IO_ADC_RESISTIVE is not valid
             Variable sensor supply IO_SENSOR_SUPPLY_2 is not valid

             Note:
             If a channel is configured as safety critical and a sensor supply was configured,
             also the sensor supply voltage will be checked by the diagnostic modules.

             IO_ADC_RATIOMETRIC: 0..32000 (0V..32.000V)
             IO_ADC_ABSOLUTE: 0..32000 (0V..32.000V)

             */

            IO_ADC_ChannelInit(IO_ADC_59,
            IO_ADC_ABSOLUTE,
                                           IO_ADC_RANGE_32V,
                                           IO_ADC_PD_10K,
                                           IO_SENSOR_SUPPLY_0,
                                           NULL);
            break;
        case 4:

            /*
             IO_PVG_07:

             Setup one PVG channel.

             Parameters:

             pvg_channel: PVG channel (IO_PVG_00 .. IO_PVG_07)

             output_value: Output value with which the PVG-channel will be initialized in percent * 100 ( 1000..9000 )
             */

            IO_PVG_Init(IO_PVG_07, PVG_pin_value);
            break;
        case 5:
            /* IO_DO_59:
             * Setup a digital output.
             *
             * Parameters:
             *   do_channel  - Digital output: IO_DO_59
             *   diagnostic  - Output configuration:
             *                   TRUE:  diagnostic pull-up enabled (detects open load/short circuit)
             *                   FALSE: diagnostic pull-up disabled (use for low current loads like LEDs)
             *                   (NOTE: Diagnostic IS supported for this group, unlike IO_DO_16..51!)
             *   safety_conf - Relevant safety configurations:
             *                   NOT supported for IO_DO_52..IO_DO_59. Strictly NULL.
             *
             * Remarks:
             *   - IO_DO_52..IO_DO_59 are an alternative function to IO_PVG_00..IO_PVG_07.
             *   - Protection reset wait time for IO_DO_52 is 1 second (NOT 10 seconds!).
             *   - After protection reset, output must be explicitly set high via IO_DO_Set().
             *   - IO_E_CM_CALIBRATION error does NOT occur for this group (only for IO_DO_16..51).
             */

            IO_DO_Init(IO_DO_59, TRUE, NULL);
            break;
        case 7:
            /* IO_VOUT_07:
             * Setup a voltage output.
             */

            IO_VOUT_Init(IO_VOUT_07);
            break;
        }
        break;
    }
}
