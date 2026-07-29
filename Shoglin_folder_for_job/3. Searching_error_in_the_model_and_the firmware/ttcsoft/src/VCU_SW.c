/*
 * File: VCU_SW.c
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul 14 11:26:00 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VCU_SW.h"
#include "VCU_SW_private.h"
#include "IO_ADC.h"

const float8 VCU_SW_RGND = 0.0; /* float8 ground */

/* Block signals (default storage) */
B_VCU_SW_T VCU_SW_B;

/* Block states (default storage) */
DW_VCU_SW_T VCU_SW_DW;

/* Real-time model */
static RT_MODEL_VCU_SW_T VCU_SW_M_;
RT_MODEL_VCU_SW_T *const VCU_SW_M = &VCU_SW_M_;

// Deñlaration of CAN message frame and handler for TX
IO_CAN_DATA_FRAME transmit_message_vlvcmd_hyd1_msg_tx = { 0 };

ubyte2 transmit_message_vlvcmd_hyd1_handler_tx = 0;

// Deñlaration of CAN message frame and handler for RX
IO_CAN_DATA_FRAME read_message_Pin101_Pin104_CMD_msg_rx = { 0 };

ubyte2 read_message_Pin101_Pin104_CMD_handler_rx = 0;

static ubyte1 flag_first_run = 1;

// Deñlaration of CAN message frame and handler for TX
IO_CAN_DATA_FRAME transmit_message_vlvcmd_hyd1_k_msg_tx = { 0 };

ubyte2 transmit_message_vlvcmd_hyd1_k_handler_tx = 0;

/* Model step function */
void VCU_SW_step(void)
{
    /* local block i/o variables */
    ubyte2 rtb_error_tx_transmit_message_v;
    ubyte2 rtb_handler_err_419365114;
    ubyte2 rtb_error_tx_transmit_message_d;
    ubyte2 rtb_di_104_error;
    BOOL rtb_di_104_value;
    StateModeTypes rtb_FunctionCaller13;

    ubyte4 adc_value;
    ubyte2 adc_value_for_transmit;
    bool adc_fresh;
    IO_ErrorType rc;

    static ubyte1 old_CAN_config = 0xFF;
    static ubyte1 current_CAN_config = 0;

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  DataStoreWrite: '<S7>/Data Store Write13'
     */

    /* S-Function (scanpack): '<S7>/CANPack_VLVCMD_HYD1' */
    /* S-Function (scanpack): '<S7>/CANPack_VLVCMD_HYD1' */
    VCU_SW_B.CANPack_VLVCMD_HYD1.ID = 419385383U;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Length = 8U;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Extended = 1U;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Remote = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[0] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[1] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[2] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[3] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[4] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[5] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[6] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1.Data[7] = 0;

    {
        /* --------------- START Packing signal 0 ------------------
         *  startBit                = 0
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/

        /* --------------- START Packing signal 1 ------------------
         *  startBit                = 16
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/

        /* --------------- START Packing signal 2 ------------------
         *  startBit                = 32
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/

        /* --------------- START Packing signal 3 ------------------
         *  startBit                = 48
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/
        {
            ubyte4 packingValue = 0;

            {
                ubyte4 result = (ubyte4) (VCU_SW_B.di_104_error);

                /* no scaling required */
                packingValue = result;
            }

            {
                ubyte2 packedValue;
                packedValue = (ubyte2) (packingValue);

                {
                    {
                        VCU_SW_B.CANPack_VLVCMD_HYD1.Data[6] =
                                VCU_SW_B.CANPack_VLVCMD_HYD1.Data[6]
                                        | (ubyte1) ((ubyte2) (packedValue
                                                & (ubyte2) 0xFFU));
                        VCU_SW_B.CANPack_VLVCMD_HYD1.Data[7] =
                                VCU_SW_B.CANPack_VLVCMD_HYD1.Data[7]
                                        | (ubyte1) ((ubyte2) ((ubyte2) (packedValue
                                                & (ubyte2) 0xFF00U) >> 8));
                    }
                }
            }
        }
    }

    /* S-Function (canWrite_ttc500): '<S7>/transmit_message_vlvcmd_hyd1' */
    transmit_message_vlvcmd_hyd1_msg_tx.id_format =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Extended;
    transmit_message_vlvcmd_hyd1_msg_tx.length =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Length;
    transmit_message_vlvcmd_hyd1_msg_tx.id = VCU_SW_B.CANPack_VLVCMD_HYD1.ID;
    transmit_message_vlvcmd_hyd1_msg_tx.data[0] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[0];
    transmit_message_vlvcmd_hyd1_msg_tx.data[1] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[1];
    transmit_message_vlvcmd_hyd1_msg_tx.data[2] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[2];
    transmit_message_vlvcmd_hyd1_msg_tx.data[3] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[3];
    transmit_message_vlvcmd_hyd1_msg_tx.data[4] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[4];
    transmit_message_vlvcmd_hyd1_msg_tx.data[5] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[5];
    transmit_message_vlvcmd_hyd1_msg_tx.data[6] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[6];
    transmit_message_vlvcmd_hyd1_msg_tx.data[7] =
            VCU_SW_B.CANPack_VLVCMD_HYD1.Data[7];

    // Transmit transmit_message_vlvcmd_hyd1 CAN message with error check
    rtb_error_tx_transmit_message_v = IO_CAN_WriteMsg(
            transmit_message_vlvcmd_hyd1_handler_tx,
            &transmit_message_vlvcmd_hyd1_msg_tx);

    /* S-Function (canRead_ttc500): '<S5>/read_message_Pin101_Pin104_CMD' */

    // Receive read_message_Pin101_Pin104_CMD CAN message with error check
    rtb_handler_err_419365114 = IO_CAN_ReadMsg(
            read_message_Pin101_Pin104_CMD_handler_rx,
            &read_message_Pin101_Pin104_CMD_msg_rx);
    VCU_SW_B.msg_419365114.Extended =
            read_message_Pin101_Pin104_CMD_msg_rx.id_format;
    VCU_SW_B.msg_419365114.Length =
            read_message_Pin101_Pin104_CMD_msg_rx.length;
    VCU_SW_B.msg_419365114.ID = read_message_Pin101_Pin104_CMD_msg_rx.id;
    VCU_SW_B.msg_419365114.Data[0] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[0];
    VCU_SW_B.msg_419365114.Data[1] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[1];
    VCU_SW_B.msg_419365114.Data[2] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[2];
    VCU_SW_B.msg_419365114.Data[3] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[3];
    VCU_SW_B.msg_419365114.Data[4] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[4];
    VCU_SW_B.msg_419365114.Data[5] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[5];
    VCU_SW_B.msg_419365114.Data[6] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[6];
    VCU_SW_B.msg_419365114.Data[7] =
            read_message_Pin101_Pin104_CMD_msg_rx.data[7];

    /* S-Function (scanunpack): '<S5>/CANUnpack_Pin101_Pin104_CMD' */
    {
        /* S-Function (scanunpack): '<S5>/CANUnpack_Pin101_Pin104_CMD' */
        if ((8 == VCU_SW_B.msg_419365114.Length)
                && (VCU_SW_B.msg_419365114.ID !=
                INVALID_CAN_ID))
        {
            if ((419365114 == VCU_SW_B.msg_419365114.ID)
                    && (1U == VCU_SW_B.msg_419365114.Extended))
            {
                {
                    /* --------------- START Unpacking signal 0 ------------------
                     *  startBit                = 0
                     *  length                  = 3
                     *  desiredSignalByteLayout = LITTLEENDIAN
                     *  dataType                = UNSIGNED
                     *  factor                  = 1.0
                     *  offset                  = 0.0
                     * -----------------------------------------------------------------------*/
                    {
                        ubyte1 outValue = 0;

                        {
                            ubyte1 unpackedValue = 0;

                            {
                                ubyte1 tempValue = (ubyte1) (0);

                                {
                                    tempValue =
                                            tempValue
                                                    | (ubyte1) ((ubyte1) (VCU_SW_B.msg_419365114.Data[0])
                                                            & (ubyte1) (0x7U));
                                }

                                unpackedValue = tempValue;
                            }

                            outValue = (ubyte1) (unpackedValue);
                        }

                        {
                            ubyte1 result = (ubyte1) outValue;
                            VCU_SW_B.CANUnpack_Pin101_Pin104_CMD_o1 = result;
                        }
                    }

                    /* --------------- START Unpacking signal 1 ------------------
                     *  startBit                = 8
                     *  length                  = 8
                     *  desiredSignalByteLayout = LITTLEENDIAN
                     *  dataType                = UNSIGNED
                     *  factor                  = 1.0
                     *  offset                  = 0.0
                     * -----------------------------------------------------------------------*/
                    {
                        ubyte1 outValue = 0;

                        {
                            ubyte1 unpackedValue = 0;

                            {
                                ubyte1 tempValue = (ubyte1) (0);

                                {
                                    tempValue =
                                            tempValue
                                                    | (ubyte1) (VCU_SW_B.msg_419365114.Data[1]);
                                }

                                unpackedValue = tempValue;
                            }

                            outValue = (ubyte1) (unpackedValue);
                        }

                        {
                            ubyte1 result = (ubyte1) outValue;
                            VCU_SW_B.CANUnpack_Pin101_Pin104_CMD_o2 = result;
                        }
                    }
                }
            }
        }
    }

    /* DataStoreRead: '<S2>/Data Store Read' */
    VCU_SW_B.DataStoreRead =
            VCU_SW_DW.OutputNetworkData.Pin101_Pin104_FB.Pin3_feedback;

    /* S-Function (scanpack): '<S2>/CANPack_VLVCMD_HYD1' */
    /* S-Function (scanpack): '<S2>/CANPack_VLVCMD_HYD1' */
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.ID = 419364903U;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Length = 8U;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Extended = 1U;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Remote = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[0] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[1] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[2] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[3] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[4] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[5] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[6] = 0;
    VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[7] = 0;

    {
        /* --------------- START Packing signal 0 ------------------
         *  startBit                = 0
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/

        /* --------------- START Packing signal 1 ------------------
         *  startBit                = 16
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/

        /* --------------- START Packing signal 2 ------------------
         *  startBit                = 32
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/

        /* --------------- START Packing signal 3 ------------------
         *  startBit                = 48
         *  length                  = 16
         *  desiredSignalByteLayout = LITTLEENDIAN
         *  dataType                = UNSIGNED
         *  factor                  = 1.0
         *  offset                  = 0.0
         *  minimum                 = 0.0
         *  maximum                 = 0.0
         * -----------------------------------------------------------------------*/
        {
            ubyte4 packingValue = 0;

            {
                ubyte4 result = (ubyte4) (VCU_SW_B.DataStoreRead);

                /* no scaling required */
                packingValue = result;
            }

            {
                ubyte2 packedValue;
                packedValue = (ubyte2) (packingValue);

                {
                    {
                        VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[6] =
                                VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[6]
                                        | (ubyte1) ((ubyte2) (packedValue
                                                & (ubyte2) 0xFFU));
                        VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[7] =
                                VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[7]
                                        | (ubyte1) ((ubyte2) ((ubyte2) (packedValue
                                                & (ubyte2) 0xFF00U) >> 8));
                    }
                }
            }
        }
    }

    /* S-Function (canWrite_ttc500): '<S2>/transmit_message_vlvcmd_hyd1' */
    transmit_message_vlvcmd_hyd1_k_msg_tx.id_format =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Extended;
    transmit_message_vlvcmd_hyd1_k_msg_tx.length =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Length;
    transmit_message_vlvcmd_hyd1_k_msg_tx.id =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.ID;
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[0] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[0];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[1] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[1];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[2] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[2];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[3] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[3];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[4] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[4];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[5] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[5];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[6] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[6];
    transmit_message_vlvcmd_hyd1_k_msg_tx.data[7] =
            VCU_SW_B.CANPack_VLVCMD_HYD1_h.Data[7];

    // Transmit transmit_message_vlvcmd_hyd1_k CAN message with error check
    rtb_error_tx_transmit_message_d = IO_CAN_WriteMsg(
            transmit_message_vlvcmd_hyd1_k_handler_tx,
            &transmit_message_vlvcmd_hyd1_k_msg_tx);

    current_CAN_config = VCU_SW_B.CANUnpack_Pin101_Pin104_CMD_o1;

    if (old_CAN_config == current_CAN_config)
        switch (current_CAN_config)
        {
        case 1:
            /* S-Function (digitalInputGet_ttc500): '<S7>/EngineAirFilterClogSens' */

            // Get value of digital input IO_DI_50 with error check
            VCU_SW_B.di_104_error = IO_DI_Get(IO_DI_50, &rtb_di_104_value);

            /* FunctionCaller: '<S7>/Function Caller13' */
            convDIOSttToEnum(rtb_di_104_value, VCU_SW_B.di_104_error,
                             &rtb_FunctionCaller13);

            /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
             *  DataStoreWrite: '<S7>/Data Store Write13'
             */
            VCU_SW_DW.OutputNetworkData.Pin101_Pin104_FB.Pin3_feedback =
                    (ubyte2) rtb_FunctionCaller13;
            break;
        case 2:
            /* S-Function (analogInputGet_ttc500): '<S7>/EngineAirFilterClogSens' */

            // Get value of digital input IO_DI_50 with error check
            rc = IO_ADC_Get(IO_ADC_02, &adc_value, &adc_fresh);

            /* FunctionCaller: '<S7>/Function Caller13' */

            convAIVoltageData(adc_value, VCU_SW_B.adc_104_error,
                              &adc_value_for_transmit);

            /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
             *  DataStoreWrite: '<S7>/Data Store Write13'
             */
            VCU_SW_DW.OutputNetworkData.Pin101_Pin104_FB.Pin3_feedback =
                    adc_value_for_transmit;
            break;
        }
    else
    {
        switch (current_CAN_config)
        {
        case 1:
            IO_ADC_ChannelDeInit(IO_ADC_02);
            IO_DI_Init(IO_DI_50, IO_DI_PU_10K, NULL);
            /* S-Function (digitalInputGet_ttc500): '<S7>/EngineAirFilterClogSens' */

            // Get value of digital input IO_DI_50 with error check
            VCU_SW_B.di_104_error = IO_DI_Get(IO_DI_50, &rtb_di_104_value);

            /* FunctionCaller: '<S7>/Function Caller13' */
            convDIOSttToEnum(rtb_di_104_value, VCU_SW_B.di_104_error,
                             &rtb_FunctionCaller13);

            /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
             *  DataStoreWrite: '<S7>/Data Store Write13'
             */
            VCU_SW_DW.OutputNetworkData.Pin101_Pin104_FB.Pin3_feedback =
                    (ubyte2) rtb_FunctionCaller13;
            break;
        case 2:
            IO_DI_DeInit(IO_DI_50);
            IO_ADC_ChannelInit(IO_ADC_02, IO_ADC_ABSOLUTE,
            IO_ADC_NO_RANGE,
                               IO_ADC_NO_PULL,
                               IO_SENSOR_SUPPLY_0,
                               NULL);
            /* S-Function (analogInputGet_ttc500): '<S7>/EngineAirFilterClogSens' */

            // Get value of digital input IO_DI_50 with error check
            rc = IO_ADC_Get(IO_ADC_02, &adc_value, &adc_fresh);

            /* FunctionCaller: '<S7>/Function Caller13' */

            convAIVoltageData(adc_value, VCU_SW_B.adc_104_error,
                              &adc_value_for_transmit);

            /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
             *  DataStoreWrite: '<S7>/Data Store Write13'
             */
            VCU_SW_DW.OutputNetworkData.Pin101_Pin104_FB.Pin3_feedback =
                    adc_value_for_transmit;
            break;
        }
    }
    old_CAN_config = current_CAN_config;
}

/* Model initialize function */
void VCU_SW_initialize(void)
{
    /* Registration code */

    /* initialize error status */
    rtmSetErrorStatus(VCU_SW_M, (NULL));

    /* block I/O */
    (void) memset(((void*) &VCU_SW_B), 0, sizeof(B_VCU_SW_T));

    /* states (dwork) */
    (void) memset((void*) &VCU_SW_DW, 0, sizeof(DW_VCU_SW_T));

    /* Start for S-Function (digitalInputGet_ttc500): '<S7>/EngineAirFilterClogSens' */

    /* Turning the POWER_SUPPLY_0 */
    IO_POWER_Set(IO_SENSOR_SUPPLY_0, IO_POWER_ON);

    // Initialization of digital input IO_DI_50 channel
    IO_DI_Init(IO_DI_50, IO_DI_PU_10K, NULL);

    /* Start for S-Function (canWrite_ttc500): '<S7>/transmit_message_vlvcmd_hyd1' */

    // Initialization of CAN transmit_message_vlvcmd_hyd1 msg object for TX
    IO_CAN_ConfigMsg(&transmit_message_vlvcmd_hyd1_handler_tx,
    IO_CAN_CHANNEL_0,
                     IO_CAN_MSG_WRITE,
                     IO_CAN_EXT_FRAME,
                     0, 0);

    /* Start for S-Function (canRead_ttc500): '<S5>/read_message_Pin101_Pin104_CMD' */

    // Initialization of CAN read_message_Pin101_Pin104_CMD msg object for RX
    IO_CAN_ConfigMsg(&read_message_Pin101_Pin104_CMD_handler_rx,
    IO_CAN_CHANNEL_0,
                     IO_CAN_MSG_READ,
                     IO_CAN_EXT_FRAME,
                     419365114U, 536870911U);

    /* Start for S-Function (scanunpack): '<S5>/CANUnpack_Pin101_Pin104_CMD' */

    /*-----------S-Function Block: <S5>/CANUnpack_Pin101_Pin104_CMD -----------------*/

    /* Start for S-Function (canWrite_ttc500): '<S2>/transmit_message_vlvcmd_hyd1' */

    // Initialization of CAN transmit_message_vlvcmd_hyd1_k msg object for TX
    IO_CAN_ConfigMsg(&transmit_message_vlvcmd_hyd1_k_handler_tx,
    IO_CAN_CHANNEL_0,
                     IO_CAN_MSG_WRITE,
                     IO_CAN_EXT_FRAME,
                     0, 0);
}

/* Model terminate function */
void VCU_SW_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
