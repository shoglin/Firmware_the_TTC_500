/*
 * File: VCU_SW.c
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.437
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Jul  6 11:47:51 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VCU_SW.h"
#include "VCU_SW_private.h"

const DIAG_ERRORCODE VCU_SW_rtZDIAG_ERRORCODE = {
  0U,                                  /* error_code */
  0U,                                  /* device_num */
  0U                                   /* faulty_value */
} ;                                    /* DIAG_ERRORCODE ground */

/* Block signals (default storage) */
B_VCU_SW_T VCU_SW_B;

/* Block states (default storage) */
DW_VCU_SW_T VCU_SW_DW;

/* Real-time model */
static RT_MODEL_VCU_SW_T VCU_SW_M_;
RT_MODEL_VCU_SW_T *const VCU_SW_M = &VCU_SW_M_;

// Deñlaration of CAN message frame and handler for RX
IO_CAN_DATA_FRAME read_message_PLC_StateM_msg_rx = { 0 };

ubyte2 read_message_PLC_StateM_handler_rx = 0;

// Deñlaration of CAN message frame and handler for TX
IO_CAN_DATA_FRAME transmit_message_hyd_fluid_temp_msg_tx = { 0 };

ubyte2 transmit_message_hyd_fluid_temp_handler_tx = 0;

/* System initialize for function-call system: '<S9>/GetDI10msec' */
void VCU_SW_GetDI10msec_Init(void)
{
  /* Start for S-Function (digitalInputGet_ttc500): '<S10>/EngineAirFilterClogSens' */

  // Initialization of digital input IO_DI_28 channel
  IO_DI_Init(IO_DI_28, IO_DI_PU_10K, NULL);
}

/* Output and update for function-call system: '<S9>/GetDI10msec' */
void VCU_SW_GetDI10msec(void)
{
  /* local block i/o variables */
  ubyte2 rtb_di_101_error;
  BOOL rtb_di_101_value;
  StateModeTypes rtb_FunctionCaller13;

  /* S-Function (digitalInputGet_ttc500): '<S10>/EngineAirFilterClogSens' */

  // Get value of digital input IO_DI_28 with error check
  rtb_di_101_error = IO_DI_Get(IO_DI_28, &rtb_di_101_value);

  /* FunctionCaller: '<S10>/Function Caller13' */
  convDIOSttToEnum(rtb_di_101_value, rtb_di_101_error, &rtb_FunctionCaller13);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S10>/Data Store Write'
   */
  VCU_SW_DW.CANOutput.Pin101_Pin104_FB.Pin0_feedback = (ubyte2)
    rtb_FunctionCaller13;
}

/* System initialize for atomic system: '<S7>/DigitalInput' */
void VCU_SW_DigitalInput_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S9>/10msec' incorporates:
   *  SubSystem: '<S9>/GetDI10msec'
   */
  VCU_SW_GetDI10msec_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S9>/10msec' */
}

/* Output and update for atomic system: '<S7>/DigitalInput' */
void VCU_SW_DigitalInput(void)
{
  /* S-Function (fcgen): '<S9>/10msec' incorporates:
   *  SubSystem: '<S9>/GetDI10msec'
   */
  VCU_SW_GetDI10msec();

  /* End of Outputs for S-Function (fcgen): '<S9>/10msec' */
}

/* System initialize for atomic system: '<S1>/InputInterfaces1' */
void VCU_SW_InputInterfaces1_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S7>/DigitalInput' */
  VCU_SW_DigitalInput_Init();

  /* End of SystemInitialize for SubSystem: '<S7>/DigitalInput' */
}

/* Output and update for atomic system: '<S1>/InputInterfaces1' */
void VCU_SW_InputInterfaces1(void)
{
  /* Outputs for Atomic SubSystem: '<S7>/DigitalInput' */
  VCU_SW_DigitalInput();

  /* End of Outputs for SubSystem: '<S7>/DigitalInput' */
}

/* System initialize for atomic system: '<S1>/InputNetwork' */
void VCU_SW_InputNetwork_Init(void)
{
  /* Start for S-Function (canRead_ttc500): '<S8>/read_message_PLC_StateM' */

  // Initialization of CAN read_message_PLC_StateM msg object for RX
  IO_CAN_ConfigMsg(&read_message_PLC_StateM_handler_rx,
                   IO_CAN_CHANNEL_0,
                   IO_CAN_MSG_READ,
                   IO_CAN_EXT_FRAME,
                   419365114U,
                   536870911U);

  /* Start for S-Function (scanunpack): '<S8>/CAN_Unpack_PLC_StateM' */

  /*-----------S-Function Block: <S8>/CAN_Unpack_PLC_StateM -----------------*/
}

/* Output and update for atomic system: '<S1>/InputNetwork' */
void VCU_SW_InputNetwork(void)
{
  /* local block i/o variables */
  ubyte2 rtb_handler_err_419365114;

  /* S-Function (canRead_ttc500): '<S8>/read_message_PLC_StateM' */

  // Receive read_message_PLC_StateM CAN message with error check
  rtb_handler_err_419365114 = IO_CAN_ReadMsg(read_message_PLC_StateM_handler_rx,
    &read_message_PLC_StateM_msg_rx);
  VCU_SW_B.msg_419365114.Extended = read_message_PLC_StateM_msg_rx.id_format;
  VCU_SW_B.msg_419365114.Length = read_message_PLC_StateM_msg_rx.length;
  VCU_SW_B.msg_419365114.ID = read_message_PLC_StateM_msg_rx.id;
  VCU_SW_B.msg_419365114.Data[0] = read_message_PLC_StateM_msg_rx.data[0];
  VCU_SW_B.msg_419365114.Data[1] = read_message_PLC_StateM_msg_rx.data[1];
  VCU_SW_B.msg_419365114.Data[2] = read_message_PLC_StateM_msg_rx.data[2];
  VCU_SW_B.msg_419365114.Data[3] = read_message_PLC_StateM_msg_rx.data[3];
  VCU_SW_B.msg_419365114.Data[4] = read_message_PLC_StateM_msg_rx.data[4];
  VCU_SW_B.msg_419365114.Data[5] = read_message_PLC_StateM_msg_rx.data[5];
  VCU_SW_B.msg_419365114.Data[6] = read_message_PLC_StateM_msg_rx.data[6];
  VCU_SW_B.msg_419365114.Data[7] = read_message_PLC_StateM_msg_rx.data[7];

  /* S-Function (scanunpack): '<S8>/CAN_Unpack_PLC_StateM' */
  {
    /* S-Function (scanunpack): '<S8>/CAN_Unpack_PLC_StateM' */
    if ((8 == VCU_SW_B.msg_419365114.Length) && (VCU_SW_B.msg_419365114.ID !=
         INVALID_CAN_ID) ) {
      if ((419365114 == VCU_SW_B.msg_419365114.ID) && (1U ==
           VCU_SW_B.msg_419365114.Extended) ) {
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
                  tempValue = tempValue | (ubyte1)((ubyte1)
                    (VCU_SW_B.msg_419365114.Data[0]) & (ubyte1)(0x7U));
                }

                unpackedValue = tempValue;
              }

              outValue = (ubyte1) (unpackedValue);
            }

            {
              ubyte1 result = (ubyte1) outValue;
              VCU_SW_B.CAN_Unpack_PLC_StateM_o1 = result;
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
                  tempValue = tempValue | (ubyte1)(VCU_SW_B.msg_419365114.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (ubyte1) (unpackedValue);
            }

            {
              ubyte1 result = (ubyte1) outValue;
              VCU_SW_B.CAN_Unpack_PLC_StateM_o2 = result;
            }
          }
        }
      }
    }
  }
}

/* System initialize for atomic system: '<Root>/InputLayer' */
void VCU_SW_InputLayer_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/InputInterfaces1' */
  VCU_SW_InputInterfaces1_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/InputInterfaces1' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/InputNetwork' */
  VCU_SW_InputNetwork_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/InputNetwork' */
}

/* Output and update for atomic system: '<Root>/InputLayer' */
void VCU_SW_InputLayer(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/InputInterfaces1' */
  VCU_SW_InputInterfaces1();

  /* End of Outputs for SubSystem: '<S1>/InputInterfaces1' */

  /* Outputs for Atomic SubSystem: '<S1>/InputNetwork' */
  VCU_SW_InputNetwork();

  /* End of Outputs for SubSystem: '<S1>/InputNetwork' */
}

/* System initialize for atomic system: '<S2>/OutputNetwork' */
void VCU_SW_OutputNetwork_Init(void)
{
  /* Start for S-Function (canWrite_ttc500): '<S11>/transmit_message_hyd_fluid_temp' */

  // Initialization of CAN transmit_message_hyd_fluid_temp msg object for TX
  IO_CAN_ConfigMsg(&transmit_message_hyd_fluid_temp_handler_tx,
                   IO_CAN_CHANNEL_0,
                   IO_CAN_MSG_WRITE,
                   IO_CAN_EXT_FRAME,
                   0,
                   0);
}

/* Output and update for atomic system: '<S2>/OutputNetwork' */
void VCU_SW_OutputNetwork(void)
{
  /* local block i/o variables */
  ubyte2 rtb_error_tx_transmit_message_h;

  /* DataStoreRead: '<S11>/Data Store Read' */
  VCU_SW_B.DataStoreRead = VCU_SW_DW.CANOutput.Pin101_Pin104_FB.Pin0_feedback;

  /* S-Function (scanpack): '<S11>/CANPack_hyd_Fluid_temp' */
  /* S-Function (scanpack): '<S11>/CANPack_hyd_Fluid_temp' */
  VCU_SW_B.CANPack_hyd_Fluid_temp.ID = 419364903U;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Length = 8U;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Extended = 1U;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Remote = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[0] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[1] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[2] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[3] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[4] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[5] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[6] = 0;
  VCU_SW_B.CANPack_hyd_Fluid_temp.Data[7] = 0;

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
            VCU_SW_B.CANPack_hyd_Fluid_temp.Data[0] =
              VCU_SW_B.CANPack_hyd_Fluid_temp.Data[0] | (ubyte1)((ubyte2)
              (packedValue & (ubyte2)0xFFU));
            VCU_SW_B.CANPack_hyd_Fluid_temp.Data[1] =
              VCU_SW_B.CANPack_hyd_Fluid_temp.Data[1] | (ubyte1)((ubyte2)
              ((ubyte2)(packedValue & (ubyte2)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* S-Function (canWrite_ttc500): '<S11>/transmit_message_hyd_fluid_temp' */
  transmit_message_hyd_fluid_temp_msg_tx.id_format =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Extended;
  transmit_message_hyd_fluid_temp_msg_tx.length =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Length;
  transmit_message_hyd_fluid_temp_msg_tx.id = VCU_SW_B.CANPack_hyd_Fluid_temp.ID;
  transmit_message_hyd_fluid_temp_msg_tx.data[0] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[0];
  transmit_message_hyd_fluid_temp_msg_tx.data[1] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[1];
  transmit_message_hyd_fluid_temp_msg_tx.data[2] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[2];
  transmit_message_hyd_fluid_temp_msg_tx.data[3] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[3];
  transmit_message_hyd_fluid_temp_msg_tx.data[4] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[4];
  transmit_message_hyd_fluid_temp_msg_tx.data[5] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[5];
  transmit_message_hyd_fluid_temp_msg_tx.data[6] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[6];
  transmit_message_hyd_fluid_temp_msg_tx.data[7] =
    VCU_SW_B.CANPack_hyd_Fluid_temp.Data[7];

  // Transmit transmit_message_hyd_fluid_temp CAN message with error check
  rtb_error_tx_transmit_message_h = IO_CAN_WriteMsg
    (transmit_message_hyd_fluid_temp_handler_tx,
     &transmit_message_hyd_fluid_temp_msg_tx);
}

/* System initialize for atomic system: '<Root>/OutputLayer' */
void VCU_SW_OutputLayer_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S2>/OutputNetwork' */
  VCU_SW_OutputNetwork_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/OutputNetwork' */
}

/* Output and update for atomic system: '<Root>/OutputLayer' */
void VCU_SW_OutputLayer(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/OutputNetwork' */
  VCU_SW_OutputNetwork();

  /* End of Outputs for SubSystem: '<S2>/OutputNetwork' */
}

/* Model step function */
void VCU_SW_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/InputLayer' */
  VCU_SW_InputLayer();

  /* End of Outputs for SubSystem: '<Root>/InputLayer' */

  /* Outputs for Atomic SubSystem: '<Root>/OutputLayer' */
  VCU_SW_OutputLayer();

  /* End of Outputs for SubSystem: '<Root>/OutputLayer' */
}

/* Model initialize function */
void VCU_SW_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(VCU_SW_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &VCU_SW_B), 0,
                sizeof(B_VCU_SW_T));

  /* states (dwork) */
  (void) memset((void *)&VCU_SW_DW, 0,
                sizeof(DW_VCU_SW_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/InputLayer' */
  VCU_SW_InputLayer_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/InputLayer' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/OutputLayer' */
  VCU_SW_OutputLayer_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/OutputLayer' */
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
