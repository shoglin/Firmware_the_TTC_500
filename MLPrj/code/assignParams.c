
#include "rtwtypes.h"
#include "ptypes_tms570.h"
#include "VCU_SW.h"
#include "assignParams.h"


//init
//input interfaces
	//digital input
	void setDIParams(ubyte1 id, float4 value, ubyte1 manflag) {

	    /*if (id == 1) {
			pDIManual_GlobalSupplyTermState_Flag = manflag;
			pDIManual_GlobalSupplyTermState = (ubyte1)value;
		}
		else if (id == 2) {
			pDIManual_HVILState_Flag = manflag;
			pDIManual_HVILState = (ubyte1)value;
		}
		else if (id == 3) {
			pDIManual_PrechargeCtrlState_Flag = manflag;
			pDIManual_PrechargeCtrlState = (ubyte1)value;
		}
		else if (id == 4) {
			pDIManual_DCDCEmergencyGNDState_Flag = manflag;
			pDIManual_DCDCEmergencyGNDState = (ubyte1)value;
		}
		else if (id == 5) {
			pDIManual_ACChrgSupplyTermState_Flag = manflag;
			pDIManual_ACChrgSupplyTermState = (ubyte1)value;
		}
		else if (id == 6) {
			pDIManual_ACChrgGroundTermState_Flag = manflag;
			pDIManual_ACChrgGroundTermState = (ubyte1)value;
		}
		else if (id == 7) {
			pDIManual_DCChrgSupplyTermState_Flag = manflag;
			pDIManual_DCChrgSupplyTermState = (ubyte1)value;
		}
		else if (id == 8) {
			pDIManual_DCChrgGroundTermState_Flag = manflag;
			pDIManual_DCChrgGroundTermState = (ubyte1)value;
		}*/


	}



    //input functions
	void setInFcnsParams(ubyte1 id, float4 value, ubyte1 manflag) {

		// pressure
		//gearboxFstPressure
		if (id == 0) {
			pIFManual_gearboxFstPressure_Flag = manflag;
			pIFManual_gearboxFstPressure = (ubyte2)value;
			pMaxGearPressValue = (ubyte2)value;
			pMinGearPressValue = (ubyte2)value;
		}
		//gearboxSecPressure
		else if (id == 1) {
			pIFManual_gearboxSecPressure_Flag = manflag;
			pIFManual_gearboxSecPressure = (ubyte2)value;
			pMaxGearPressValue = (ubyte2)value;
			pMinGearPressValue = (ubyte2)value;
		}
		//gearboxOilTempStt
		else if (id == 2) {
			pIFManual_OilTempState_Flag = manflag;
			pIFManual_OilTempState = (ubyte1)value;
			pOilSensVoltageThres = (ubyte2)value;
			pOilSensTimeThres = (ubyte2)value;
			pMaxOilSensVoltage = (ubyte2)value;
		}
		//gearboxOilLvlStt
		else if (id == 3) {
			pIFManual_OilLvlState_Flag = manflag;
			pIFManual_OilLvlState = (ubyte1)value;
			pOilSensVoltageThres = (ubyte2)value;
			pOilSensTimeThres = (ubyte2)value;
			pMaxOilSensVoltage = (ubyte2)value;
		}
		//ringShaftSpeed
        else if (id == 4) {
			pIFManual_RingShaftSpeed_Flag = manflag;
			pIFManual_RingShaftSpeed = (ubyte2)value;
			pRingShftTeethNum = (ubyte2)value;
		}
		//OutputShaftSpeed
        else if (id == 5) {
			pIFManual_OutputShaftSpeed_Flag = manflag;
			pIFManual_OutputShaftSpeed = (ubyte2)value;
			pOutShftTeethNum = (ubyte2)value;
		}
	}


		// weight


		// speed


		//oil sens








	//}
	//analog input
	void setAIParams(ubyte1 id, float4 value, ubyte1 manflag) {


		if (id == 1) {
			pAIManual_FuseBoxTempSens1 = (ubyte4)value;
			pAIManual_FuseBoxTempSens1_Flag = manflag;
		}
		else if (id == 2) {
			pAIManual_FuseBoxTempSens2 = (ubyte4)value;
			pAIManual_FuseBoxTempSens2_Flag = manflag;
		}
		else if (id == 3) {
			pAIManual_FrontCargoWeightSens = (ubyte4)value;
			pAIManual_FrontCargoWeightSens_Flag = manflag;
		}
		else if (id == 4) {
			pAIManual_RearCargoWeightSens = (ubyte4)value;
			pAIManual_RearCargoWeightSens_Flag = manflag;
		}
		/*else if (id == 5) {
			pAIManual_TMSTempInput = (ubyte4)value;
			pAIManual_TMSTempInput_Flag = manflag;
		}
		else if (id == 6) {
			pAIManual_TMSTempOutput = (ubyte4)value;
			pAIManual_TMSTempOutput_Flag = manflag;
		}*/
		else if (id == 7) {
			pAIManual_GearboxOilState = (ubyte4)value;
			pAIManual_GearboxOilState_Flag = manflag;
		}

	}
	//PWD input
	void setPWDParams(ubyte1 id, float4 value, ubyte1 manflag) {

		if (id == 1) {
			pAIManual_GearboxOutShiftSensFreq = (ubyte4)value;
			pAIManual_GearboxOutShiftSensFreq_Flag = manflag;
		}
		else if (id == 2) {
			pAIManual_GearboxOutRingSensFreq = (ubyte4)value;
			pAIManual_GearboxOutRingSensFreq_Flag = manflag;
		}

	}
	//PWM current input
	/*void assignPWMCurParams(ubyte1 id, ubyte1 flag, float4 value) {


	}
	*/
	//Client

//output interfaces
	//digital output
	void setDOParams(ubyte1 id, float4 value, ubyte1 manflag) {

		/*if (id == 0) {
			pDOManual_CapsSupply = (ubyte1)value;
			pDOManual_CapsSupply_Flag = manflag;
		}
		else if (id == 1) {
			pDOManual_CoolingSensSupply = (ubyte1)value;
			pDOManual_CoolingSensSupply_Flag = manflag;
		}
		else if (id == 2) {
			pDOManual_OnBoardChrgTermSttSupply = (ubyte1)value;
			pDOManual_OnBoardChrgTermSttSupply_Flag = manflag;
		}
		else if (id == 3) {
			pDOManual_HVILSupply = (ubyte1)value;
			pDOManual_HVILSupply_Flag = manflag;
		}
		else if (id == 4) {
			pDOManual_OnBoardFastChrgSupply = (ubyte1)value;
			pDOManual_OnBoardFastChrgSupply_Flag = manflag;
		}
		else if (id == 5) {
			pDOManual_PressSensSupply = (ubyte1)value;
			pDOManual_PressSensSupply_Flag = manflag;
		}
		else if (id == 6) {
			pDOManual_GearboxSensSupply = (ubyte1)value;
			pDOManual_GearboxSensSupply_Flag = manflag;
		}
		else if (id == 7) {
			pDOManual_ACDCChrgConvSwitch = (ubyte1)value;
			pDOManual_ACDCChrgConvSwitch_Flag = manflag;
		}*/
	}
	//PWM
	void setPWMParams(ubyte1 id, float4 value, ubyte1 manflag) {


		if (id == 0) {
			pPWMManual_PumpFlowControl = (ubyte2)value;
			pPWMManual_PumpFlowControl_Flag = manflag;
		}
		else if (id == 1) {
			pPWMManual_FirstGearCtrlValve = (ubyte2)value;
			pPWMManual_FirstGearCtrlValve_Flag = manflag;
		}
		else if (id == 2) {
			pPWMManual_SecondGearCtrlValve = (ubyte2)value;
			pPWMManual_SecondGearCtrlValve_Flag = manflag;
		}
		else if (id == 3) {
			pPWMManual_RemBrkCtrlValve = (ubyte2)value;
			pPWMManual_RemBrkCtrlValve_Flag = manflag;
		}
		else if (id == 4) {
			pPWMManual_TMSCompressorCtrl = (ubyte2)value;
			pPWMManual_TMSCompressorCtrl_Flag = manflag;
		}
		else if (id == 5) {
			pPWMManual_TMSCircPumpCtrl = (ubyte2)value;
			pPWMManual_TMSCircPumpCtrl_Flag = manflag;
		}

	}
	//cabine CAN
	void setCCANOutParams(ubyte1 id, float4 value, ubyte1 manflag) {
		//BMS_sts1
		if (id == 0) {
			pCCANManual_TMSState = (ubyte1)value;
			pCCANManual_TMSState_Flag = manflag;
		}
		else if (id == 1) {
			pCCANManual_TMSOutlet = (sbyte2)value;
			pCCANManual_TMSOutlet_Flag = manflag;
		}
		else if (id == 2) {
			pCCANManual_TMSInlet = (sbyte2)value;
			pCCANManual_TMSInlet_Flag = manflag;
		}
		else if (id == 3) {
			pCCANManual_AverageTempBattery = (sbyte2)value;
			pCCANManual_AverageTempBattery_Flag = manflag;
		}
		else if (id == 4) {
			pCCANManual_CurrentLoad = (sbyte2)value;
			pCCANManual_CurrentLoad_Flag = manflag;
		}
		else if (id == 5) {
			pCCANManual_PresentVoltage = (ubyte2)value;
			pCCANManual_PresentVoltage_Flag = manflag;
		}
		else if (id == 6) {
			pCCANManual_SOC = (float4)value;
			pCCANManual_SOC_Flag = manflag;
		}
		else if (id == 7) {
			pCCANManual_ThermCondTractionBatt = (ubyte1)value;
			pCCANManual_ThermCondTractionBatt_Flag = manflag;
		}

		//CCVS1
		else if (id == 8) {
			pCCANManual_BrakeSwitch = (ubyte1)value;
			pCCANManual_BrakeSwitch_Flag = manflag;
		}
		else if (id == 9) {
			pCCANManual_PTOGovernorState = (ubyte1)value;
			pCCANManual_PTOGovernorState_Flag = manflag;
		}
		else if (id == 10) {
			pCCANManual_ClutchSwitch = (ubyte1)value;
			pCCANManual_ClutchSwitch_Flag = manflag;
		}
		else if (id == 11) {
			pCCANManual_WheelBasedVehicleSpeed = (ubyte2)value;
			pCCANManual_WheelBasedVehicleSpeed_Flag = manflag;
		}
		else if (id == 12) {
			pCCANManual_ParkBrakeReleaseInhReq = (ubyte1)value;
			pCCANManual_ParkBrakeReleaseInhReq_Flag = manflag;
		}
		else if (id == 13) {
			pCCANManual_ParkingBrakeSwitch = (ubyte1)value;
			pCCANManual_ParkingBrakeSwitch_Flag = manflag;
		}

		//CCVS1
		else if (id == 14) {
			pCCANManual_DCDCInputVoltage = (ubyte2)value;
			pCCANManual_DCDCInputVoltage_Flag = manflag;
		}
		else if (id == 15) {
			pCCANManual_DCDCTempRadiator = (sbyte2)value;
			pCCANManual_DCDCTempRadiator_Flag = manflag;
		}
		else if (id == 16) {
			pCCANManual_DCDCOutputCurrent = (ubyte1)value;
			pCCANManual_DCDCOutputCurrent_Flag = manflag;
		}
		else if (id == 17) {
			pCCANManual_DCDCOutputVoltage = (float4)value;
			pCCANManual_DCDCOutputVoltage_Flag = manflag;
		}
		else if (id == 18) {
			pCCANManual_DCDCStatus = (ubyte1)value;
			pCCANManual_DCDCStatus_Flag = manflag;
		}
		else if (id == 19) {
			pCCANManual_VoltageIndicator = (ubyte1)value;
			pCCANManual_VoltageIndicator_Flag = manflag;
		}
		else if (id == 20) {
			pCCANManual_OverheatIndicator = (ubyte1)value;
			pCCANManual_OverheatIndicator_Flag = manflag;
		}

		//ACDC_sts
		else if (id == 21) {
			pCCANManual_ACDCOutputVoltage = (float4)value;
			pCCANManual_ACDCOutputVoltage_Flag = manflag;
		}
		else if (id == 22) {
			pCCANManual_ACDCInputCurrent = (float4)value;
			pCCANManual_ACDCInputCurrent_Flag = manflag;
		}
		else if (id == 23) {
			pCCANManual_IGBITemp = (float4)value;
			pCCANManual_IGBITemp_Flag = manflag;
		}
		else if (id == 24) {
			pCCANManual_ACDCStatus = (ubyte1)value;
			pCCANManual_ACDCStatus_Flag = manflag;
		}

		//BMS_sts2
		else if (id == 25) {
			pCCANManual_MaxTempCel = (float4)value;
			pCCANManual_MaxTempCel_Flag = manflag;
		}
		else if (id == 26) {
			pCCANManual_MinTempCell = (float4)value;
			pCCANManual_MinTempCell_Flag = manflag;
		}
		else if (id == 27) {
			pCCANManual_MinCellVoltage = (float4)value;
			pCCANManual_MinCellVoltage_Flag = manflag;
		}
		else if (id == 28) {
			pCCANManual_MaxCellVoltage = (float4)value;
			pCCANManual_MaxCellVoltage_Flag = manflag;
		}

		//DLCC2
		else if (id == 29) {
			pCCANManual_VehicleBattChargLampCom = (ubyte1)value;
			pCCANManual_VehicleBattChargLampCom_Flag = manflag;
		}
		else if (id == 30) {
			pCCANManual_VehicleBattVoltLowLampCom = (ubyte1)value;
			pCCANManual_VehicleBattVoltLowLampCom_Flag = manflag;
		}

		//ST_GEN
		else if (id == 31) {
			pCCANManual_ActPowerGen = (float4)value;
			pCCANManual_ActPowerGen_Flag = manflag;
		}
		else if (id == 32) {
			pCCANManual_ActVoltageGen = (float4)value;
			pCCANManual_ActVoltageGen_Flag = manflag;
		}
		else if (id == 33) {
			pCCANManual_ActTorqueGen = (sbyte2)value;
			pCCANManual_ActTorqueGen_Flag = manflag;
		}
		else if (id == 34) {
			pCCANManual_ActSpeedGen = (float4)value;
			pCCANManual_ActSpeedGen_Flag = manflag;
		}

		//ETC_2
		else if (id == 35) {
			pCCANManual_TransmReqRange = (ubyte2)value;
			pCCANManual_TransmReqRange_Flag = manflag;
		}
		else if (id == 36) {
			pCCANManual_TransmCurrRange = (ubyte2)value;
			pCCANManual_TransmCurrRange_Flag = manflag;
		}
		else if (id == 37) {
			pCCANManual_TransmCurrGear = (sbyte1)value;
			pCCANManual_TransmCurrGear_Flag = manflag;
		}
		else if (id == 38) {
			pCCANManual_TransmActGearRatio = (float4)value;
			pCCANManual_TransmActGearRatio_Flag = manflag;
		}
		else if (id == 39) {
			pCCANManual_TransmSelectedGear = (sbyte1)value;
			pCCANManual_TransmSelectedGear_Flag = manflag;
		}

		//EBC1
		else if (id == 40) {
			pCCANManual_ABS_EBSAmberWarningSig = (ubyte1)value;
			pCCANManual_ABS_EBSAmberWarningSig_Flag = manflag;
		}
		else if (id == 41) {
			pCCANManual_EBSRedWarningSig = (ubyte1)value;
			pCCANManual_EBSRedWarningSig_Flag = manflag;
		}
		else if (id == 42) {
			pCCANManual_BrakePedalPosition = (float4)value;
			pCCANManual_BrakePedalPosition_Flag = manflag;
		}

		//EFL_P1
		else if (id == 43) {
			pCCANManual_EngineCoolantLevel = (float4)value;
			pCCANManual_EngineCoolantLevel_Flag = manflag;
		}
		else if (id == 44) {
			pCCANManual_EngineOilPressure = (ubyte2)value;
			pCCANManual_EngineOilPressure_Flag = manflag;
		}

		//SEN_INFO_3
		else if (id == 45) {
			pCCANManual_CurrentSensor1 = (float4)value;
			pCCANManual_CurrentSensor1_Flag = manflag;
		}
		else if (id == 46) {
			pCCANManual_CurrentSensor2 = (float4)value;
			pCCANManual_CurrentSensor2_Flag = manflag;
		}
		else if (id == 47) {
			pCCANManual_CurrentSensor3 = (float4)value;
			pCCANManual_CurrentSensor3_Flag = manflag;
		}
		else if (id == 48) {
			pCCANManual_CurrentSensor4 = (float4)value;
			pCCANManual_CurrentSensor4_Flag = manflag;
		}
		else if (id == 49) {
			pCCANManual_CurrentSensor5 = (float4)value;
			pCCANManual_CurrentSensor5_Flag = manflag;
		}
		else if (id == 50) {
			pCCANManual_CurrentSensor6 = (float4)value;
			pCCANManual_CurrentSensor6_Flag = manflag;
		}
		else if (id == 51) {
			pCCANManual_CurrentSensor7 = (float4)value;
			pCCANManual_CurrentSensor7_Flag = manflag;
		}

		//ETC_1
		else if (id == 52) {
			pCCANManual_TransmInputShaftSpeed = (float4)value;
			pCCANManual_TransmInputShaftSpeed_Flag = manflag;
		}
		else if (id == 53) {
			pCCANManual_TransmOutputShaftSpeed = (float4)value;
			pCCANManual_TransmOutputShaftSpeed_Flag = manflag;
		}
		else if (id == 54) {
			pCCANManual_TransmShiftInProcess = (ubyte1)value;
			pCCANManual_TransmShiftInProcess_Flag = manflag;
		}

		//SEN_INFO_1
		else if (id == 55) {
			pCCANManual_RearCargoLoad = (float4)value;
			pCCANManual_RearCargoLoad_Flag = manflag;
		}
		else if (id == 56) {
			pCCANManual_FrontCargoLoad = (float4)value;
			pCCANManual_FrontCargoLoad_Flag = manflag;
		}
		else if (id == 57) {
			pCCANManual_ArticulatedFrameStrAngle = (ubyte1)value;
			pCCANManual_ArticulatedFrameStrAngle_Flag = manflag;
		}
		else if (id == 58) {
			pCCANManual_LeftTurnFlag = (ubyte1)value;
			pCCANManual_LeftTurnFlag_Flag = manflag;
		}
		else if (id == 59) {
			pCCANManual_RightTurnFlag = (ubyte1)value;
			pCCANManual_RightTurnFlag_Flag = manflag;
		}

		//SHUTDN
		else if (id == 60) {
			pCCANManual_EngWaittoStartLamp = (ubyte1)value;
			pCCANManual_EngWaittoStartLamp_Flag = manflag;
		}

		//ST_MOT_INV1
		else if (id == 61) {
			pCCANManual_ActMotDC = (float4)value;
			pCCANManual_ActMotDC_Flag = manflag;
		}
		else if (id == 62) {
			pCCANManual_RMSPhaseCurrMot = (float4)value;
			pCCANManual_RMSPhaseCurrMot_Flag = manflag;
		}
		else if (id == 63) {
			pCCANManual_InvMotStatus = (ubyte1)value;
			pCCANManual_InvMotStatus_Flag = manflag;
		}
		else if (id == 64) {
			pCCANManual_MaxWindTempMot = (sbyte2)value;
			pCCANManual_MaxWindTempMot_Flag = manflag;
		}
		else if (id == 65) {
			pCCANManual_MinWindTempMot = (sbyte2)value;
			pCCANManual_MinWindTempMot_Flag = manflag;
		}

		//DLCC1
		else if (id == 66) {
			pCCANManual_EngCoolTempHighLampComm = (ubyte1)value;
			pCCANManual_EngCoolTempHighLampComm_Flag = manflag;
		}
		else if (id == 67) {
			pCCANManual_EngOilPressLowLampComm = (ubyte1)value;
			pCCANManual_EngOilPressLowLampComm_Flag = manflag;
		}
		else if (id == 68) {
			pCCANManual_EngRedStopLampComm = (ubyte1)value;
			pCCANManual_EngRedStopLampComm_Flag = manflag;
		}
		else if (id == 69) {
			pCCANManual_EngAmberWarningLampComm = (ubyte1)value;
			pCCANManual_EngAmberWarningLampComm_Flag = manflag;
		}

		//MVS
		else if (id == 70) {
			pCCANManual_AppliedVehicleSpeedLim = (ubyte1)value;
			pCCANManual_AppliedVehicleSpeedLim_Flag = manflag;
		}

		//MVS
		else if (id == 71) {
			pCCANManual_EngCoolTemp = (sbyte2)value;
			pCCANManual_EngCoolTemp_Flag = manflag;
		}
		else if (id == 72) {
			pCCANManual_EngFuelTemp = (sbyte2)value;
			pCCANManual_EngFuelTemp_Flag = manflag;
		}

		//ST_GEN_INV
		else if (id == 73) {
			pCCANManual_ActGenDC = (float4)value;
			pCCANManual_ActGenDC_Flag = manflag;
		}
		else if (id == 74) {
			pCCANManual_RMSPhaseCurrGen = (float4)value;
			pCCANManual_RMSPhaseCurrGen_Flag = manflag;
		}
		else if (id == 75) {
			pCCANManual_MinWindingTemp = (sbyte2)value;
			pCCANManual_MinWindingTemp_Flag = manflag;
		}
		else if (id == 76) {
			pCCANManual_MaxWindingTemp = (sbyte2)value;
			pCCANManual_MaxWindingTemp_Flag = manflag;
		}

		//ST_MOT_INV2
		else if (id == 77) {
			pCCANManual_ActMotDC2 = (float4)value;
			pCCANManual_ActMotDC2_Flag = manflag;
		}
		else if (id == 78) {
			pCCANManual_RMSPhaseCurrMot2 = (float4)value;
			pCCANManual_RMSPhaseCurrMot2_Flag = manflag;
		}
		else if (id == 79) {
			pCCANManual_InvMotStatus2 = (ubyte1)value;
			pCCANManual_InvMotStatus2_Flag = manflag;
		}
		else if (id == 80) {
			pCCANManual_MaxWindTempMot2 = (sbyte2)value;
			pCCANManual_MaxWindTempMot2_Flag = manflag;
		}
		else if (id == 81) {
			pCCANManual_MinWindTempMot2 = (sbyte2)value;
			pCCANManual_MinWindTempMot2_Flag = manflag;
		}

		//TCI_VCU
		else if (id == 82) {
			pCCANManual_TransferCaseStatus = (ubyte1)value;
			pCCANManual_TransferCaseStatus_Flag = manflag;
		}

		//SEN_INFO_2
		else if (id == 83) {
			pCCANManual_RearBrakePress = (float4)value;
			pCCANManual_RearBrakePress_Flag = manflag;
		}
		else if (id == 84) {
			pCCANManual_RightTurnLoopPress = (float4)value;
			pCCANManual_RightTurnLoopPress_Flag = manflag;
		}
		else if (id == 85) {
			pCCANManual_LeftTurnLoopPress = (float4)value;
			pCCANManual_LeftTurnLoopPress_Flag = manflag;
		}
		else if (id == 86) {
			pCCANManual_ParkBrakePress = (float4)value;
			pCCANManual_ParkBrakePress_Flag = manflag;
		}
		else if (id == 87) {
			pCCANManual_RemBrakePress = (float4)value;
			pCCANManual_RemBrakePress_Flag = manflag;
		}
		else if (id == 88) {
			pCCANManual_FrontBrakePress = (float4)value;
			pCCANManual_FrontBrakePress_Flag = manflag;
		}

		//ETC_7
		else if (id == 89) {
			pCCANManual_TransmWarningIndicator = (ubyte1)value;
			pCCANManual_TransmWarningIndicator_Flag = manflag;
		}
		else if (id == 90) {
			pCCANManual_TransmServiceIndicator = (ubyte1)value;
			pCCANManual_TransmServiceIndicator_Flag = manflag;
		}

		//PEDAL_SENS
		else if (id == 91) {
			pCCANManual_PosRecoveryPedal = (float4)value;
			pCCANManual_PosRecoveryPedal_Flag = manflag;
		}
		else if (id == 92) {
			pCCANManual_PosAcceleratorPedal = (float4)value;
			pCCANManual_PosAcceleratorPedal_Flag = manflag;
		}

		//TRF1
		else if (id == 93) {
			pCCANManual_TransmOilTemp = (float4)value;
			pCCANManual_TransmOilTemp_Flag = manflag;
		}

		//TRF2
		else if (id == 94) {
			pCCANManual_TransmOverheatIndicator = (ubyte1)value;
			pCCANManual_TransmOverheatIndicator_Flag = manflag;
		}
		else if (id == 95) {
			pCCANManual_TransmOilLvlSwitch = (ubyte1)value;
			pCCANManual_TransmOilLvlSwitch_Flag = manflag;
		}

		//HV_INFO
		else if (id == 96) {
			pCCANManual_FuseBoxTempSens2 = (sbyte2)value;
			pCCANManual_FuseBoxTempSens2_Flag = manflag;
		}
		else if (id == 97) {
			pCCANManual_FuseBoxTempSens1 = (sbyte2)value;
			pCCANManual_FuseBoxTempSens1_Flag = manflag;
		}
		else if (id == 98) {
			pCCANManual_BrdChrgStCap = (ubyte1)value;
			pCCANManual_BrdChrgStCap_Flag = manflag;
		}
		else if (id == 99) {
			pCCANManual_FuseBoxCapSt = (ubyte1)value;
			pCCANManual_FuseBoxCapSt_Flag = manflag;
		}
		else if (id == 100) {
			pCCANManual_HVILState = (ubyte1)value;
			pCCANManual_HVILState_Flag = manflag;
		}
		else if (id == 122) {
			pCCANManual_OnBrdSupDisProhib = (ubyte1)value;
			pCCANManual_OnBrdSupDisProhib_Flag = manflag;
		}

		//ST_MOT
		else if (id == 101) {
			pCCANManual_ActPowerMot = (float4)value;
			pCCANManual_ActPowerMot_Flag = manflag;
		}
		else if (id == 102) {
			pCCANManual_ActVoltageMot = (float4)value;
			pCCANManual_ActVoltageMot_Flag = manflag;
		}
		else if (id == 103) {
			pCCANManual_ActTorqueMot = (ubyte2)value;
			pCCANManual_ActTorqueMot_Flag = manflag;
		}
		else if (id == 104) {
			pCCANManual_ActSpeedMot = (float4)value;
			pCCANManual_ActSpeedMot_Flag = manflag;
		}

		//TIRE
		else if (id == 105) {
			pCCANManual_TirePressThresholdDetec = (ubyte1)value;
			pCCANManual_TirePressThresholdDetec_Flag = manflag;
		}
		else if (id == 106) {
			pCCANManual_TirePressure = (ubyte2)value;
			pCCANManual_TirePressure_Flag = manflag;
		}
		else if (id == 107) {
			pCCANManual_TireLocation = (ubyte1)value;
			pCCANManual_TireLocation_Flag = manflag;
		}

		//VDHR
		else if (id == 108) {
			pCCANManual_HighResolutionTripDist = (ubyte4)value;
			pCCANManual_HighResolutionTripDist_Flag = manflag;
		}
		else if (id == 109) {
			pCCANManual_HighResolTotalVehicleDist = (ubyte4)value;
			pCCANManual_HighResolTotalVehicleDist_Flag = manflag;
		}

		//VD
		else if (id == 110) {
			pCCANManual_TotalVehicleDistance = (float4)value;
			pCCANManual_TotalVehicleDistance_Flag = manflag;
		}
		else if (id == 111) {
			pCCANManual_TripDistance = (float4)value;
			pCCANManual_TripDistance_Flag = manflag;
		}

		//AT1_FC1
		else if (id == 112) {
			pCCANManual_AftertreatmentIgn = (ubyte1)value;
			pCCANManual_AftertreatmentIgn_Flag = manflag;
		}

		//PTCD
		else if (id == 113) {
			pCCANManual_ChrgContactorVoltage = (ubyte2)value;
			pCCANManual_ChrgContactorVoltage_Flag = manflag;
		}
		else if (id == 114) {
			pCCANManual_ChrgStationSt = (ubyte1)value;
			pCCANManual_ChrgStationSt_Flag = manflag;
		}
		else if (id == 115) {
			pCCANManual_ChrgType = (ubyte1)value;
			pCCANManual_ChrgType_Flag = manflag;
		}
		else if (id == 116) {
			pCCANManual_ChrgConnectionSt = (ubyte1)value;
			pCCANManual_ChrgConnectionSt_Flag = manflag;
		}
		else if (id == 117) {
			pCCANManual_ChrgInletMotSt = (ubyte1)value;
			pCCANManual_ChrgInletMotSt_Flag = manflag;
		}
		else if (id == 118) {
			pCCANManual_ChrglineCPState = (ubyte1)value;
			pCCANManual_ChrglineCPState_Flag = manflag;
		}
		else if (id == 119) {
			pCCANManual_ChrgLinePPState = (ubyte1)value;
			pCCANManual_ChrgLinePPState_Flag = manflag;
		}
		else if (id == 120) {
			pCCANManual_ChrgActCurrent = (ubyte2)value;
			pCCANManual_ChrgActCurrent_Flag = manflag;
		}
		else if (id == 121) {
			pCCANManual_ChrgDCContactTemp = (float4)value;
			pCCANManual_ChrgDCContactTemp_Flag = manflag;
		}
		else if (id == 122) {
			pCCANManual_Transmission_Mode_1_Ind = (ubyte1)value;
			pCCANManual_Transmission_Mode_1_Ind_Flag = manflag;
		}
		else if (id == 123) {
			pCCANManual_Transmission_Mode_2_Ind = (ubyte1)value;
			pCCANManual_Transmission_Mode_2_Ind_Flag = manflag;
		}
		else if (id == 124) {
			pCCANManual_State_Rec_Switch = (ubyte1)value;
			pCCANManual_State_Rec_Switch_Flag = manflag;
		}
		else if (id == 125) {
			pCCANManual_Pos_Acc_Pedal = (float4)value;
			pCCANManual_Pos_Acc_Pedal_Flag = manflag;
		}
		else if (id == 126) {
			pCCANManual_Eng_Cool_LevLowLampComm = (ubyte1)value;
			pCCANManual_Eng_Cool_LevLowLampComm_Flag = manflag;
		}
		else if (id == 127) {
			pCCANManual_Eng_Protect_Lamp_Comm= (ubyte1)value;
			pCCANManual_Eng_Protect_Lamp_Comm_Flag = manflag;
		}
	}


	void setTCANParams(ubyte1 id, float4 value, ubyte1 manflag) {

		if (id == 1) {
			pTCANManual_cmd_enable_F_1= manflag;
			pTCANManual_cmd_enable_V_1 = (ubyte1)value;
		}
		else if (id == 2) {
			//pTCANManual_cmd_enable_F_2 = manflag;
			//pTCANManual_cmd_enable_V_2 = (ubyte1)value;
		}
		else if (id == 3) {
			pTCANManual_cmd_mot_ctrl_mode_F_1 = manflag;
			pTCANManual_cmd_mot_ctrl_mode_V_1 = (ubyte1)value;
		}
		else if (id == 4) {
			//pTCANManual_cmd_mot_ctrl_mode_F_2 = manflag;
			//pTCANManual_cmd_mot_ctrl_mode_V_2 = (ubyte1)value;
		}
		else if (id == 5) {
			pTCANManual_cmd_mot_run_F_1 = manflag;
			pTCANManual_cmd_mot_run_V_1 = (ubyte1)value;
		}
		else if (id == 6) {
			//pTCANManual_cmd_mot_run_F_2 = manflag;
			//pTCANManual_cmd_mot_run_V_2 = (ubyte1)value;
		}
		else if (id == 7) {

			pInv1_cmd_mot_n_dc_ref = (float4)value;
		}
		else if (id == 8) {

			//pInv2_cmd_mot_n_dc_ref = (float4)value;
		}
		else if (id == 9) {
			pTCANManual_cmd_mot_t_ref_F_1 = manflag;
			pTCANManual_cmd_mot_t_ref_V_1 = (sbyte2)value;
		}
		else if (id == 10) {
			pTCANManual_cmd_mot_t_ref_F_1 = manflag;
			//pTCANManual_cmd_mot_t_ref_V_2 = (sbyte2)value;
		}
		else if (id == 11) {

			pInv1_cmd_mot_u_dc_ref= (float4)value;
		}
		else if (id == 12) {

			//pInv2_cmd_mot_u_dc_ref = (float4)value;
		}
		else if (id == 13) {

			pInv1_cmd_mot_p_dc_ref = (float4)value;
		}
		else if (id == 14) {

			//pInv2_cmd_mot_p_dc_ref= (float4)value;
		}
		else if (id == 15) {

			pInv1_cmd_mot_f_ref = (float4)value;
		}
		else if (id == 16) {

			//pInv2_cmd_mot_f_ref = (float4)value;
		}
		else if (id == 17) {

			pInv1_cmd_mot_q_ref = (float4)value;
		}
		else if (id == 18) {

			//pInv2_cmd_mot_q_ref = (float4)value;
		}
		else if (id == 19) {
			pTCANManual_cmd_mot_lim_n_max_F_1 = manflag;
			pTCANManual_cmd_mot_lim_n_max_V_1 = (sbyte2)value;
		}
		else if (id == 20) {
			//pTCANManual_cmd_mot_lim_n_max_F_2 = manflag;
			//pTCANManual_cmd_mot_lim_n_max_V_2 = (sbyte2)value;
		}
		else if (id == 21) {
			pTCANManual_cmd_mot_lim_n_min_F_1 = manflag;
			pTCANManual_cmd_mot_lim_n_min_V_1 = (sbyte2)value;
		}
		else if (id == 22) {
			//pTCANManual_cmd_mot_lim_n_min_F_2 = manflag;
			//pTCANManual_cmd_mot_lim_n_min_V_2 = (sbyte2)value;
		}
		else if (id == 23) {

			pInverterPwrMaxLim1 = (float4)value;
		}
		else if (id == 24) {

			//pInverterPwrMaxLim2 = (float4)value;
		}
		else if (id == 25) {

			pInverterPwrMinLim1 = (float4)value;
		}
		else if (id == 26) {

			//pInverterPwrMinLim2 = (float4)value;
		}
		else if (id == 27) {

			pInverterDCVoltMaxHiLim1 = (sbyte2)value;
		}
		else if (id == 28) {

			pInverterDCVoltMaxLowLim1 = (sbyte2)value;
		}
		else if (id == 29) {

			pInverterDCVoltMinHiLim1 = (sbyte2)value;
		}
		else if (id == 30) {

			pInverterDCVoltMinLowLim1 = (sbyte2)value;
		}
		else if (id == 31) {

			pInverterPwrMaxLim1 = (float4)value;
		}
		else if (id == 32) {

			//pInverterPwrMaxLim2 = (float4)value;
		}
		else if (id == 33) {

			pInverterPwrMinLim1 = (float4)value;
		}
		else if (id == 34) {

			//pInverterPwrMinLim2 = (float4)value;
		}
		else if (id == 35) {

			pInverterSpdCtrlKp1 = (float4)value;
		}
		else if (id == 36) {

			//pInverterSpdCtrlKp2 = (float4)value;
		}
		else if (id == 37) {

			pInverterSpdCtrlTi1 = (float4)value;
		}
		else if (id == 38) {

			//pInverterSpdCtrlTi2 = (float4)value;
		}
		else if (id == 39) {

			pInverterSpdRefRampTi1 = (float4)value;
		}
		else if (id == 40) {

			//pInverterSpdRefRampTi2 = (float4)value;
		}
		else if (id == 41) {
			//pTCANManual_cmd_contactor_F_1 = manflag;
			//pTCANManual_cmd_contactor_V_1 = (ubyte1)value;
		}
		else if (id == 42) {
			//pTCANManual_cmd_contactor_F_2 = manflag;
			//pTCANManual_cmd_contactor_V_2 = (ubyte1)value;
		}
		else if (id == 43) {

			pInverterCurMinLim1 = (float4)value;
		}
		else if (id == 44) {

			//pInverterCurMinLim2 = (float4)value;
		}
		else if (id == 45) {

			pInverterCurMaxLim1 = (float4)value;
		}
		else if (id == 46) {

			//pInverterCurMaxLim2 = (float4)value;
		}
		else if (id == 47) {

			pInv1_cmd_fault_reset_manual = (ubyte1)value;
		}
		else if (id == 48) {

			//pInv2_cmd_fault_reset_manual = (ubyte1)value;
		}
		else if (id == 49) {
			pTCANManual_Trq_min_Lim_F_1 = manflag;
			pTCANManual_Trq_min_Lim_V_1 = (sbyte2)value;
		}
		else if (id == 50) {
			pTCANManual_Trq_max_Lim_F_1 = manflag;
			pTCANManual_Trq_max_Lim_V_1 = (sbyte2)value;
		}
	}

 void setGCANParams(ubyte1 id, float4 value, ubyte1 manflag) {
//EMS VCU_ECU_TSC1
		if (id == 0) {
			pGCANManual_OverContModPr_Flag= manflag;
			pGCANManual_OverContModPr = (ubyte1)value;
		}
		else if (id == 1) {
			pGCANManual_EngReqTrqTL_Flag = manflag;
			pGCANManual_EngReqTrqTL = (ubyte1)value;
		}
		else if (id == 2) {
			pGCANManual_EngReqSpContCond_Flag = manflag;
			pGCANManual_EngReqSpContCond = (ubyte1)value;
		}
		else if (id == 3) {
			pGCANManual_EngReqSpSL_Flag = manflag;
			pGCANManual_EngReqSpSL = (float4)value;
		}
		else if (id == 4) {
			pGCANManual_EngOverContMod_Flag = manflag;
			pGCANManual_EngOverContMod = (ubyte1)value;
		}
		else if (id == 5) {
			pGCANManual_ContPurp_Flag = manflag;
			pGCANManual_ContPurp = (ubyte1)value;
		}


		if (id == 6) {
			pGenInv_cmd_mot_speed_ref_ramp_time = (float4)value;
		}
		else if (id == 7) {
			pGenInv_cmd_mot_speed_control_ti = (float4)value;
		}
		else if (id == 8) {
			pGenInv_cmd_mot_speed_control_kp = (float4)value;
		}
		else if (id == 9) {
			pGenInv_cmd_mot_lim_i_min = (float4)value;
		}
		else if (id == 10) {
			pGenInv_cmd_mot_lim_i_max = (float4)value;
		}
		else if (id == 11) {
			pGenInv_cmd_mot_lim_p_min = (float4)value;
		}
		else if (id == 12) {
			pGenInv_cmd_mot_lim_p_max = (float4)value;
		}



		else if (id == 13) {
			pGCANManual_CmdMotLimUdcMinLo_Flag = manflag;
			pGCANManual_CmdMotLimUdcMinLo = (float4)value;
		}
		else if (id == 14) {
			pGCANManual_CmdMotLimUdcMinHi_Flag = manflag;
			pGCANManual_CmdMotLimUdcMinHi = (float4)value;
		}
		else if (id == 15) {
			pGCANManual_CmdMotLimUdcMaxLo_Flag = manflag;
			pGCANManual_CmdMotLimUdcMaxLo = (float4)value;
		}
		else if (id == 16) {
			pGCANManual_CmdMotLimUdcMaxHi_Flag = manflag;
			pGCANManual_CmdMotLimUdcMaxHi = (float4)value;
		}


		else if (id == 17) {
			pGenInv_cmd_mot_lim_t_min = (float4)value;
		}
		else if (id == 18) {
			pGenInv_cmd_mot_lim_t_max = (float4)value;
		}
		else if (id == 19) {
			pGenInv_cmd_mot_lim_n_min = (float4)value;
		}
		else if (id == 20) {
			pGenInv_cmd_mot_lim_n_max = (float4)value;
		}


		else if (id == 21) {
			pGCANManual_CmdContactor_Flag = manflag;
			pGCANManual_CmdContactor = (ubyte1)value;
		}


		else if (id == 22) {
			pGenInv_cmd_fault_reset_manual = (ubyte1)value;
		}



		else if (id == 23) {
			pGCANManual_CmdEnable_Flag = manflag;
			pGCANManual_CmdEnable = (ubyte1)value;
		}
		else if (id == 24) {
			pGCANManual_CmdMotRun_Flag = manflag;
			pGCANManual_CmdMotRun = (ubyte1)value;
		}
		else if (id == 25) {
			pGCANManual_CmdMotCtrlMode_Flag = manflag;
			pGCANManual_CmdMotCtrlMode = (ubyte1)value;
		}


		else if (id == 26) {
			pGenInv_cmd_mot_q_ref = (float4)value;
		}
		else if (id == 27) {
			pGenInv_cmd_mot_f_ref = (float4)value;
		}


		else if (id == 28) {
			pGCANManual_CmdMotUDcRef_Flag = manflag;
			pGCANManual_CmdMotUDcRef = (float4)value;
		}


		else if (id == 29) {
			pGenInv_cmd_mot_t_ref = (float4)value;
		}
		else if (id == 30) {
			pGenInv_cmd_mot_p_ref = (float4)value;
		}
		else if (id == 31) {
			pGenInv_cmd_mot_n_ref = (float4)value;
		}

    }

		void setECANParams(ubyte1 id, float4 value, ubyte1 manflag) {
	 //EMS VCU_ECU_TSC1
	 		if (id == 0) {
	 			pECANManual_LatchClose_Flag= manflag;
	 			pECANManual_LatchClose = (ubyte1)value;
	 		}
			else if (id == 1) {
				pECANManual_ContactorStatus_Flag = manflag;
				pECANManual_ContactorStatus = (float4)value;
			}
			else if (id == 2) {
				pECANManual_PlugLockPerm_Flag = manflag;
				pECANManual_PlugLockPerm = (float4)value;
			}
			else if (id == 3) {
				pECANManual_PlugUnlockPerm_Flag = manflag;
				pECANManual_PlugUnlockPerm = (float4)value;
			}
      else if (id == 4) {
				pChargeManToShutdown_Flag = manflag;
				pChargeManToShutdown = (float4)value;
			}
      else if (id == 5) {
				pIFManual_ChrgPortReleaseReq_Flag = manflag;
				pIFManual_ChrgPortReleaseReq = (float4)value;
			}
		}

    //BrakeDiagOper
	void setBrakeDiagOperParams(ubyte1 id, float4 value, ubyte1 manflag) {
		if (id == 0) {
			pOperBrakeManual_BrakeDiagFrontSysFailure_Flag = (ubyte1)value;
		}
		else if (id == 1) {
			pOperBrakeManual_BrakeDiagRearSysFailure_Flag = (ubyte1)value;
		}
		else if (id == 2) {
			pOperBrakeManual_BrakeDiagFrontSysCrtclFailSupp_Flag = (ubyte1)value;
		}
		else if (id == 3) {
			pOperBrakeManual_BrakeDiagRearSysCrtclFailSupp_Flag = (ubyte1)value;
		}
		else if (id == 4) {
			pOperBrakeManual_BrakeDiagRemSysFailSupp_Flag = (ubyte1)value;
		}
		else if (id == 5) {
			pOperBrakeManual_BrakeDiagRemSysSupValveFail_Flag = (ubyte1)value;
		}
		else if (id == 6) {
			pOperBrakeManual_BrakeDiagParkSysFailSupp_Flag = (ubyte1)value;
		}
		else if (id == 7) {
			pOperBrakeManual_BrakeDiagParkSysSupValveFail_Flag = (ubyte1)value;
		}
		else if (id == 8) {
			pOperBrakeManual_BrakeDiagRemValveFail_Flag = (ubyte1)value;
		}
		else if (id == 9) {
			pOperBrakeManual_BrakeDiagRearSysSupValveFail_Flag = (ubyte1)value;
		}
		else if (id == 10) {
			pOperBrakeManual_BrakeDiagFrontSysSupValveFail_Flag = (ubyte1)value;
		}
		else if (id == 11) {
			pOperBrakeManual_BrakeDiagParkValveFailure_Flag = (ubyte1)value;
		}

	}




	void setBmsParams(ubyte1 id, float4 value, ubyte1 manflag) {

		if (id == 1) {
			pBMSmanToPowerOn_Flag = manflag;
			pBMSmanToPowerOn = (ubyte1)value;
		}
		else if (id == 2) {
			pBMSmanToDischarge_Flag = manflag;
			pBMSmanToDischarge = (ubyte1)value;
		}
		else if (id == 3) {
			pBMSmanToPreOff_Flag = manflag;
			pBMSmanToPreOff = (ubyte1)value;
		}
		else if (id == 4) {
			pBMSmanToPowerOff_Flag = manflag;
			pBMSmanToPowerOff = (ubyte1)value;
		}
		else if (id == 5) {
			pBMSmanToCharge_Flag = manflag;
			pBMSmanToCharge = (ubyte1)value;
		}
		else if (id == 6) {
			pBMSmanToErrorHandler_Flag = manflag;
			pBMSmanToErrorHandler = (ubyte1)value;
		}
		else if (id == 7) {
			//pEproManualMes1Flag = (ubyte1)value;
		}
		else if (id == 8) {
			//pEproManualMes2Flag = (ubyte1)value;
		}
		else if (id == 9) {
			//pEproManualMes3Flag = (ubyte1)value;
		}
	}

	void setTmsParams(ubyte1 id, float4 value, ubyte1 manflag) {

		if (id == 1) {
			pTMSmanToLaunch_Flag = manflag;
			pTMSmanToLaunch = (ubyte1)value;
		}
		else if (id == 2) {
			pTMSmanToShutdown_Flag = manflag;
			pTMSmanToShutdown = (ubyte1)value;
		}
		else if (id == 3) {
			pTMSmanToStop_Flag = manflag;
			pTMSmanToStop = (ubyte1)value;
		}
		else if (id == 4) {
			pTMSmanToStandby_Flag = manflag;
			pTMSmanToStandby = (ubyte1)value;
		}
		else if (id == 5) {
			pTMSmanToCooling_Flag = manflag;
			pTMSmanToCooling = (ubyte1)value;
		}
		else if (id == 6) {
			pTMSmanToHeating_Flag = manflag;
			pTMSmanToHeating = (ubyte1)value;
		}
		else if (id == 7) {
			pTMSmanToSelf_Flag = manflag;
			pTMSmanToSelf = (ubyte1)value;
		}
	}

	void setBmsTmsCalibParams(ubyte1 id, float4 value, ubyte1 manflag) {

		if (id == 1) {
			pPumpCriticalValue = (ubyte1)value;
		}
		else if (id == 2) {
			pCompressorCriticalValue = (ubyte1)value;
		}
		else if (id == 3) {
			pHeaterCriticalValue = (ubyte1)value;
		}
		else if (id == 4) {
			pCellTempHighLimit = (ubyte1)value;
		}
		else if (id == 5) {
			pCellTempLowLimit = (ubyte1)value;
		}
		else if (id == 6) {
			pBatAverageLowerTempLimit = (ubyte1)value;
		}
		else if (id == 7) {
			pBatAverageUpperTempLimit = (ubyte1)value;
		}
		else if (id == 8) {
			pCellsTempNormDiff = (ubyte1)value;
		}
		else if (id == 10) {
			pMaxOutletWaterTemp = (ubyte1)value;
		}
		else if (id == 11) {
			pMinOutletWaterTemp = (ubyte1)value;
		}
		else if (id == 12) {
			pCompressorPoweroffValue = (ubyte1)value;
		}
		else if (id == 13) {
			pPumpPoweroffValue = (ubyte1)value;
		}
		else if (id == 14) {
			pHeaterPoweroffValue = (ubyte1)value;
		}
		else if (id == 15) {
			//pPumpMaxPowerValue = (ubyte1)value;
		}
		else if (id == 16) {
			pNormalAverageBatTemp = (ubyte1)value;
		}
		else if (id == 17) {
		//pNormalInletOutletDiff = (ubyte1)value;
		}
		else if (id == 18) {
			pHeaterPowerLimit = (ubyte1)value;
		}
		else if (id == 19) {
			tms_time_to_disconnect = (ubyte1)value;
		}
		else if (id == 20) {
			pPumpP1 = (ubyte1)value;
		}
		else if (id == 21) {
			pPumpP2 = (ubyte1)value;
		}
		else if (id == 22) {
			pCompressorP1 = (ubyte1)value;
		}
		else if (id == 23) {
			pCompressorP2 = (ubyte1)value;
		}
		else if (id == 24) {
			pHeaterPowerP1 = (ubyte1)value;
		}
		else if (id == 25) {
			pHeaterPowerP2 = (ubyte1)value;
		}
	}

//main
	void assignParData(ParamDataStruct parData) {
		if (parData.group == 1) { //input interfaces
			if (parData.subgroup == 1) {
				setDIParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 2) {
				setAIParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 3) {
				setPWDParams(parData.id, parData.value, parData.flag);
			}
		}
		else if (parData.group == 2) { // input functions
			//TO DO
			if (parData.subgroup == 1) {
				setInFcnsParams(parData.id, parData.value, parData.flag);
			}
		}
		else if (parData.group == 3) { // application
			if (parData.subgroup == 1) {
				setBmsParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 2) {
				setTmsParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 3) {
				setBmsTmsCalibParams(parData.id, parData.value, parData.flag);
			}
		}
		else if (parData.group == 4) { // output functions
			if (parData.subgroup == 1) {
				setCCANOutParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 2) {
				setTCANParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 3) {
				setGCANParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 4) {
				setECANParams(parData.id, parData.value, parData.flag);
			}
		}
		else if (parData.group == 5) { // output interface client
			if (parData.subgroup == 1) {
				//setDOParams(parData.id, parData.value, parData.flag);
			}
			else if (parData.subgroup == 2) {
				//setPWMParams(parData.id, parData.value, parData.flag);
			}
		}
		else if (parData.group == 6) { // BrakeDiagOper
			if (parData.subgroup == 1) {
				setBrakeDiagOperParams(parData.id, parData.value, parData.flag);
			}

		}


	}
