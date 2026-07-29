
#include "rtwtypes.h"
#include "ptypes_tms570.h"
#include "VCU_SW.h"
#include "assignCalParams.h"


	void assignCalData(ubyte1 connect) {

		IO_ErrorType status;
	//DO 10 msec and 100 msec
    if (connect == 1) {
		//status = IO_CAN_MsgStatus(manParamsDO10100_handler_rx); //MSG_NAME - ������ ���� ������ ���, ������� �� ���������� � ����� �� ���������� TTC ��� ������� ���������
		//if (status == IO_E_OK) {
			setDO10msecData();
		//}
	//DO 1000 msec
		//status = IO_CAN_MsgStatus(manParamsDO1000_handler_rx);
		//if (status == IO_E_OK) {
			setDO1000msecData();
		//}
	//GCAN Data Pack 1
		//status = IO_CAN_MsgStatus(manParamsGCAN1_handler_rx);
		//if (status == IO_E_OK) {
			setGCAN1Data();
		//}
	//GCAN Data Pack 2
		//status = IO_CAN_MsgStatus(manParamsGCAN2_handler_rx);
		//if (status == IO_E_OK) {
			setGCAN2Data();
		//}
	//GCAN Data Pack 3
		//status = IO_CAN_MsgStatus(manParamsGCAN3_handler_rx);
		//if (status == IO_E_OK) {
			setGCAN3Data();
		//}
	//GCAN Data Pack 4
		//status = IO_CAN_MsgStatus(manParamsGCAN4_handler_rx);
		//if (status == IO_E_OK) {
			setGCAN4Data();
		//}
	//GCAN Data Pack 5
		//status = IO_CAN_MsgStatus(manParamsGCAN5_handler_rx);
		//if (status == IO_E_OK) {
			setGCAN5Data();
		//}
	//GCAN Data Pack 6
		//status = IO_CAN_MsgStatus(manParamsGCANEng_handler_rx);
		//if (status == IO_E_OK) {
			setGCAN6Data();
		//}
	//TCAN Data Pack 1
		//status = IO_CAN_MsgStatus(manParams_TCAN1_handler_rx);
		//if (status == IO_E_OK) {
			setTCAN1Data();
		//}
	//TCAN Data Pack 2
		//status = IO_CAN_MsgStatus(manParams_TCAN2_handler_rx);
		//if (status == IO_E_OK) {
			setTCAN2Data();
		//}
	//TCAN Data Pack 3
		//status = IO_CAN_MsgStatus(manParams_TCAN3_handler_rx);
		//if (status == IO_E_OK) {
			setTCAN3Data();
		//}
	//TCAN Data Pack 4
		//status = IO_CAN_MsgStatus(manParams_TCAN4_handler_rx);
		//if (status == IO_E_OK) {
			setTCAN4Data();
		//}
	//TCAN Data Pack 5
		//status = IO_CAN_MsgStatus(manParams_TCAN5_handler_rx);
		//if (status == IO_E_OK) {
			setTCAN5Data();
		//}
	//Input Functions Data Pack 1
		//status = IO_CAN_MsgStatus(manParamsIFPedSpeed_handler_rx);
		//if (status == IO_E_OK) {
			setIF1Data();
		//}
	//Input Functions Data Pack 2
		//status = IO_CAN_MsgStatus(manParamsIFPress_handler_rx);
		//if (status == IO_E_OK) {
			setIF2Data();
		//}
	//Input Functions Data Pack 3
		//status = IO_CAN_MsgStatus(manParamsIFStt_Pos_handler_rx);
		//if (status == IO_E_OK) {
			setIF3Data();
		//}
	//Output Functions Data Pack 1
		//status = IO_CAN_MsgStatus(manParamsOF_DCV_handler_rx);
		//if (status == IO_E_OK) {
			setOF1Data();
		//}
	//Output Functions Data Pack 2
		//status = IO_CAN_MsgStatus(manParamsOF_DC_PID_handler_rx);
		//if (status == IO_E_OK) {
			setOF2Data();
		//}
	}
	}

	// Assign Data Functions
		//DO 10 msec and 100 msec
	void setDO10msecData(void) {
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOContACNeg <= (ubyte1)1) { // if parameter value in range
			pDOManual_ContactorACNeg = VCU_SW_DW.paramsData.ParDO10msec.manDOContACNeg;

			/*example enum
			if (VCU_SW_DW.paramsData.ParDO10msec.manDOContACNeg == (ubyte1)0) {
				pDOManual_ContactorACNeg = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO10msec.manDOContACNeg == (ubyte1)1) {
				pDOManual_ContactorACNeg = STT_ENABLE;
			} else {
				pDOManual_ContactorACNeg = STT_ERROR;
			}
			*/

			pDOManual_ContactorACNeg_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ContactorACNeg_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOContACPos <= (ubyte1)1) { // if parameter value in range
			pDOManual_ContactorACPos = VCU_SW_DW.paramsData.ParDO10msec.manDOContACPos;
			pDOManual_ContactorACPos_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ContactorACPos_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOContDCNeg <= (ubyte1)1) { // if parameter value in range
			pDOManual_ContactorDCNeg = VCU_SW_DW.paramsData.ParDO10msec.manDOContDCNeg;
			pDOManual_ContactorDCNeg_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ContactorDCNeg_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOContDCPos <= (ubyte1)1) { // if parameter value in range
			pDOManual_ContactorDCPos = VCU_SW_DW.paramsData.ParDO10msec.manDOContDCPos;
			pDOManual_ContactorDCPos_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ContactorDCPos_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOContGlob <= (ubyte1)1) { // if parameter value in range
			pDOManual_ContactorGlobal = VCU_SW_DW.paramsData.ParDO10msec.manDOContGlob;
			pDOManual_ContactorGlobal_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ContactorGlobal_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOContPrechrg <= (ubyte1)1) { // if parameter value in range
			pDOManual_ContactorPrechrg = VCU_SW_DW.paramsData.ParDO10msec.manDOContPrechrg;
			pDOManual_ContactorPrechrg_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ContactorPrechrg_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEngT15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_EngineT15 = VCU_SW_DW.paramsData.ParDO10msec.manDOEngT15;
			pDOManual_EngineT15_Flag = (ubyte1)1;

		}
		else {
			pDOManual_EngineT15 = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEngT50 <= (ubyte1)1) { // if parameter value in range
			pDOManual_EngineT50 = VCU_SW_DW.paramsData.ParDO10msec.manDOEngT50;
			pDOManual_EngineT50_Flag = (ubyte1)1;
		}
		else {
			pDOManual_EngineT50_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOFrontBrkSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_FrontBrakeHydSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOFrontBrkSup;
			pDOManual_FrontBrakeHydSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_FrontBrakeHydSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOIgnSwtAcc <= (ubyte1)1) { // if parameter value in range
			pDOManual_IgnitionSwtACC = VCU_SW_DW.paramsData.ParDO10msec.manDOIgnSwtAcc;
			pDOManual_IgnitionSwtACC_Flag = (ubyte1)1;
		}
		else {
			pDOManual_IgnitionSwtACC_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOIgnSwtT15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_IgnitionSwtT15 = VCU_SW_DW.paramsData.ParDO10msec.manDOIgnSwtT15;
			pDOManual_IgnitionSwtT15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_IgnitionSwtT15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOIgnSwtT30 <= (ubyte1)1) { // if parameter value in range
			pDOManual_IgnitionSwtT30 = VCU_SW_DW.paramsData.ParDO10msec.manDOIgnSwtT30;
			pDOManual_IgnitionSwtT30_Flag = (ubyte1)1;
		}
		else {
			pDOManual_IgnitionSwtT30_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOParkBrkSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_ParkBrakeHydSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOParkBrkSup;
			pDOManual_ParkBrakeHydSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ParkBrakeHydSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOParkBrkSwt <= (ubyte1)1) { // if parameter value in range
			pDOManual_ParkBrakeSwitch = VCU_SW_DW.paramsData.ParDO10msec.manDOParkBrkSwt;
			pDOManual_ParkBrakeSwitch_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ParkBrakeSwitch_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDORearBrkSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_RearBrakeHydSupply = VCU_SW_DW.paramsData.ParDO10msec.manDORearBrkSup;
			pDOManual_RearBrakeHydSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_RearBrakeHydSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDORemBrkSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_RemBrkCtrlSupply = VCU_SW_DW.paramsData.ParDO10msec.manDORemBrkSup;
			pDOManual_RemBrkCtrlSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_RemBrkCtrlSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOAlterT15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_AlternatorT15 = VCU_SW_DW.paramsData.ParDO10msec.manDOAlterT15;
			pDOManual_AlternatorT15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_AlternatorT15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOGenMastInvT15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_GenMasterInvT15 = VCU_SW_DW.paramsData.ParDO10msec.manDOGenMastInvT15;
			pDOManual_GenMasterInvT15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_GenMasterInvT15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOGenFollInvT15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_GenFollowInvT15 = VCU_SW_DW.paramsData.ParDO10msec.manDOGenFollInvT15;
			pDOManual_GenFollowInvT15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_GenFollowInvT15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEmotFollInv1T15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_EmotFollowInv1T15 = VCU_SW_DW.paramsData.ParDO10msec.manDOEmotFollInv1T15;
			pDOManual_EmotFollowInv1T15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_EmotFollowInv1T15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEmotMastInv2T15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_EmotMasterInv2T15 = VCU_SW_DW.paramsData.ParDO10msec.manDOEmotMastInv2T15;
			pDOManual_EmotMasterInv2T15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_EmotMasterInv2T15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEmotMastInv1T15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_EmotMasterInv1T15 = VCU_SW_DW.paramsData.ParDO10msec.manDOEmotMastInv1T15;
			pDOManual_EmotMasterInv1T15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_EmotMasterInv1T15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEmotFollInv2T15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_EmotFollowInv2T15 = VCU_SW_DW.paramsData.ParDO10msec.manDOEmotFollInv2T15;
			pDOManual_EmotFollowInv2T15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_EmotFollowInv2T15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOHVBox15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_HVBoxT15 = VCU_SW_DW.paramsData.ParDO10msec.manDOHVBox15;
			pDOManual_HVBoxT15_Flag = (ubyte1)1;
		}
		else {
			pDOManual_HVBoxT15_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOCapsSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_CapsSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOCapsSup;
			pDOManual_CapsSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_CapsSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOCoolSensSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_CoolingSensSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOCoolSensSup;
			pDOManual_CoolingSensSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_CoolingSensSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOOnBrdChrgTermSensSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_OnBoardChrgTermSttSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOOnBrdChrgTermSensSup;
			pDOManual_OnBoardChrgTermSttSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_OnBoardChrgTermSttSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOHVILSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_HVILSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOHVILSup;
			pDOManual_HVILSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_HVILSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOOnBrdChrgSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_OnBoardFastChrgSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOOnBrdChrgSup;
			pDOManual_OnBoardFastChrgSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_OnBoardFastChrgSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOPressSensSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_PressSensSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOPressSensSup;
			pDOManual_PressSensSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_PressSensSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOGearBoxSup <= (ubyte1)1) { // if parameter value in range
			pDOManual_GearboxSensSupply = VCU_SW_DW.paramsData.ParDO10msec.manDOGearBoxSup;
			pDOManual_GearboxSensSupply_Flag = (ubyte1)1;
		}
		else {
			pDOManual_GearboxSensSupply_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO10msec.manDOEproT15 <= (ubyte1)1) { // if parameter value in range
			pDOManual_ACDCChrgConvSwitch = VCU_SW_DW.paramsData.ParDO10msec.manDOEproT15;
			pDOManual_ACDCChrgConvSwitch_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ACDCChrgConvSwitch_Flag = (ubyte1)0;
		}


		}
	//DO 1000 msec
	void setDO1000msecData(void) {
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDOTMSFanSwt <= (ubyte1)1) { // if parameter value in range
			pDOManual_TMSFanSwitch = VCU_SW_DW.paramsData.ParDO1000msec.manDOTMSFanSwt;
			pDOManual_TMSFanSwitch_Flag = (ubyte1)1;
		}
		else {
			pDOManual_TMSFanSwitch_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDOCluVlv <= (ubyte1)1) { // if parameter value in range
			pDOManual_ClutchValve = VCU_SW_DW.paramsData.ParDO1000msec.manDOCluVlv;
			pDOManual_ClutchValve_Flag = (ubyte1)1;
		}
		else {
			pDOManual_ClutchValve_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDOTMSCompPerm <= (ubyte1)1) { // if parameter value in range
			pDOManual_TMSCompressorPermission = VCU_SW_DW.paramsData.ParDO1000msec.manDOTMSCompPerm;
			pDOManual_TMSCompressorPermission_Flag = (ubyte1)1;
		}
		else {
			pDOManual_TMSCompressorPermission_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIGlobSupTermStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIGlobSupTermStt == (ubyte1)0) {
				pDIManual_GlobalSupplyTermState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIGlobSupTermStt == (ubyte1)1) {
				pDIManual_GlobalSupplyTermState = ENABLE;
			} else {
				pDIManual_GlobalSupplyTermState = ERROR;
			}
			pDIManual_GlobalSupplyTermState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_GlobalSupplyTermState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIHVILStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIHVILStt == (ubyte1)0) {
				pDIManual_HVILState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIHVILStt == (ubyte1)1) {
				pDIManual_HVILState = ENABLE;
			} else {
				pDIManual_HVILState = ERROR;
			}
			pDIManual_HVILState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_HVILState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIPrechrgStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIPrechrgStt == (ubyte1)0) {
				pDIManual_PrechargeCtrlState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIPrechrgStt == (ubyte1)1) {
				pDIManual_PrechargeCtrlState = ENABLE;
			} else {
				pDIManual_PrechargeCtrlState = ERROR;
			}
			pDIManual_PrechargeCtrlState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_PrechargeCtrlState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIVoltConvStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIVoltConvStt == (ubyte1)0) {
				pDIManual_DCDCEmergencyGNDState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIVoltConvStt == (ubyte1)1) {
				pDIManual_DCDCEmergencyGNDState = ENABLE;
			} else {
				pDIManual_DCDCEmergencyGNDState = ERROR;
			}
			pDIManual_DCDCEmergencyGNDState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_DCDCEmergencyGNDState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIACChrgSupTermStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIACChrgSupTermStt == (ubyte1)0) {
				pDIManual_ACChrgSupplyTermState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIACChrgSupTermStt == (ubyte1)1) {
				pDIManual_ACChrgSupplyTermState = ENABLE;
			} else {
				pDIManual_ACChrgSupplyTermState = ERROR;
			}
			pDIManual_ACChrgSupplyTermState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_ACChrgSupplyTermState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIACChrgNegTermStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIACChrgNegTermStt == (ubyte1)0) {
				pDIManual_ACChrgGroundTermState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIACChrgNegTermStt == (ubyte1)1) {
				pDIManual_ACChrgGroundTermState = ENABLE;
			} else {
				pDIManual_ACChrgGroundTermState = ERROR;
			}
			pDIManual_ACChrgGroundTermState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_ACChrgGroundTermState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIDCChrgSupTermStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIDCChrgSupTermStt == (ubyte1)0) {
				pDIManual_DCChrgSupplyTermState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIDCChrgSupTermStt == (ubyte1)1) {
				pDIManual_DCChrgSupplyTermState = ENABLE;
			} else {
				pDIManual_DCChrgSupplyTermState = ERROR;
			}
			pDIManual_DCChrgSupplyTermState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_DCChrgSupplyTermState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIDCChrgNegTermStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIDCChrgNegTermStt == (ubyte1)0) {
				pDIManual_DCChrgGroundTermState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIDCChrgNegTermStt == (ubyte1)1) {
				pDIManual_DCChrgGroundTermState = ENABLE;
			} else {
				pDIManual_DCChrgGroundTermState = ERROR;
			}
			pDIManual_DCChrgGroundTermState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_DCChrgGroundTermState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnT15Stt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnT15Stt == (ubyte1)0) {
				pDIManual_Terminal15State = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnT15Stt == (ubyte1)1) {
				pDIManual_Terminal15State = ENABLE;
			} else {
				pDIManual_Terminal15State = ERROR;
			}
			pDIManual_Terminal15State_Flag = (ubyte1)1;
		}
		else {
			pDIManual_Terminal15State_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnAccStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnAccStt == (ubyte1)0) {
				pDIManual_TerminalACCState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnAccStt == (ubyte1)1) {
				pDIManual_TerminalACCState = ENABLE;
			} else {
				pDIManual_TerminalACCState = ERROR;
			}
			pDIManual_TerminalACCState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_TerminalACCState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnT50Stt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnT50Stt == (ubyte1)0) {
				pDIManual_Terminal50State = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIIgnT50Stt == (ubyte1)1) {
				pDIManual_Terminal50State = ENABLE;
			} else {
				pDIManual_Terminal50State = ERROR;
			}
			pDIManual_Terminal50State_Flag = (ubyte1)1;
		}
		else {
			pDIManual_Terminal50State_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIShutdnButStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIShutdnButStt == (ubyte1)0) {
				pDIManual_ShutdownButtonState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIShutdnButStt == (ubyte1)1) {
				pDIManual_ShutdownButtonState = ENABLE;
			} else {
				pDIManual_ShutdownButtonState = ERROR;
			}
			pDIManual_ShutdownButtonState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_ShutdownButtonState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDITMSCoolLvlStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDITMSCoolLvlStt == (ubyte1)0) {
				pDIManual_TMSCoolingLevelState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDITMSCoolLvlStt == (ubyte1)1) {
				pDIManual_TMSCoolingLevelState = ENABLE;
			} else {
				pDIManual_TMSCoolingLevelState = ERROR;
			}
			pDIManual_TMSCoolingLevelState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_TMSCoolingLevelState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIICECoolLvlStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIICECoolLvlStt == (ubyte1)0) {
				pDIManual_ICECoolingLevelState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIICECoolLvlStt == (ubyte1)1) {
				pDIManual_ICECoolingLevelState = ENABLE;
			} else {
				pDIManual_ICECoolingLevelState = ERROR;
			}
			pDIManual_ICECoolingLevelState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_ICECoolingLevelState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIFuseBoxCapStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIFuseBoxCapStt == (ubyte1)0) {
				pDIManual_FuseBoxCapState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIFuseBoxCapStt == (ubyte1)1) {
				pDIManual_FuseBoxCapState = ENABLE;
			} else {
				pDIManual_FuseBoxCapState = ERROR;
			}
			pDIManual_FuseBoxCapState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_FuseBoxCapState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIAirCondPerm <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIAirCondPerm == (ubyte1)0) {
				pDIManual_AirCondPermission = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIAirCondPerm == (ubyte1)1) {
				pDIManual_AirCondPermission = ENABLE;
			} else {
				pDIManual_AirCondPermission = ERROR;
			}
			pDIManual_AirCondPermission_Flag = (ubyte1)1;
		}
		else {
			pDIManual_AirCondPermission_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIOnBrdChrgCapStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIOnBrdChrgCapStt == (ubyte1)0) {
				pDIManual_OnBoardChrgStCapState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIOnBrdChrgCapStt == (ubyte1)1) {
				pDIManual_OnBoardChrgStCapState = ENABLE;
			} else {
				pDIManual_OnBoardChrgStCapState = ERROR;
			}
			pDIManual_OnBoardChrgStCapState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_OnBoardChrgStCapState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParDO1000msec.manDIVoltConvCapStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParDO1000msec.manDIVoltConvCapStt == (ubyte1)0) {
				pDIManual_DCDCCapState = DISABLE;
			} else if (VCU_SW_DW.paramsData.ParDO1000msec.manDIVoltConvCapStt == (ubyte1)1) {
				pDIManual_DCDCCapState = ENABLE;
			} else {
				pDIManual_DCDCCapState = ERROR;
			}
			pDIManual_DCDCCapState_Flag = (ubyte1)1;
		}
		else {
			pDIManual_DCDCCapState_Flag = (ubyte1)0;
		}
		//
		}
	//GCAN Data Pack 1
	void setGCAN1Data(void) {

		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvSpdRefRampTi < (float4)25 && VCU_SW_DW.paramsData.ParGCAN1.manGenInvSpdRefRampTi >= (float4)0) { // if parameter value in range
			pGenInv_cmd_mot_speed_ref_ramp_time = VCU_SW_DW.paramsData.ParGCAN1.manGenInvSpdRefRampTi;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvSpdCtrlKp < (float4)25 && VCU_SW_DW.paramsData.ParGCAN1.manGenInvSpdCtrlKp >= (float4)0) { // if parameter value in range
			pGenInv_cmd_mot_speed_control_kp = VCU_SW_DW.paramsData.ParGCAN1.manGenInvSpdCtrlKp;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotSpdCtrlTi < (float4)25 && VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotSpdCtrlTi >= (float4)0) { // if parameter value in range
			pGenInv_cmd_mot_speed_control_ti = VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotSpdCtrlTi;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotLimCurMin <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotLimCurMin >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_i_min = (float4)VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotLimCurMin;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotLimCurMax <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotLimCurMax >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_i_max = (float4)VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotLimCurMax;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdEna <= (ubyte1)1) { // if parameter value in range
			pGCANManual_CmdEnable = VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdEna;
			pGCANManual_CmdEnable_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdEnable_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotCtrlMod <= (ubyte1)10) { // if parameter value in range
			pGCANManual_CmdMotCtrlMode = VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotCtrlMod;
			pGCANManual_CmdMotCtrlMode_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotCtrlMode_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotRun <= (ubyte1)1) { // if parameter value in range
			pGCANManual_CmdMotRun = VCU_SW_DW.paramsData.ParGCAN1.manGenInvCmdMotRun;
			pGCANManual_CmdMotRun_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotRun_Flag = (ubyte1)0;
		}
		//
		}
	//GCAN Data Pack 2
	void setGCAN2Data(void) {

		if (VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMaxHi <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMaxHi >= (sbyte2)-32760) { // if parameter value in range
			pGCANManual_CmdMotLimUdcMaxHi = (float4)VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMaxHi;
			pGCANManual_CmdMotLimUdcMaxHi_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotLimUdcMaxHi_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMaxLo <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMaxLo >= (sbyte2)-32760) { // if parameter value in range
			pGCANManual_CmdMotLimUdcMaxLo = (float4)VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMaxLo;
			pGCANManual_CmdMotLimUdcMaxLo_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotLimUdcMaxLo_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMinHi <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMinHi >= (sbyte2)-32760) { // if parameter value in range
			pGCANManual_CmdMotLimUdcMinHi = (float4)VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMinHi;
			pGCANManual_CmdMotLimUdcMinHi_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotLimUdcMinHi_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMinLo <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMinHi >= (sbyte2)-32760) { // if parameter value in range
			pGCANManual_CmdMotLimUdcMinLo = (float4)VCU_SW_DW.paramsData.ParGCAN2.manGenInvCmdMotLimUdcMinLo;
			pGCANManual_CmdMotLimUdcMinLo_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotLimUdcMinLo_Flag = (ubyte1)0;
		}
		//
		}
	//GCAN Data Pack 3
	void setGCAN3Data(void) {

		if (VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimPMax <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimPMax >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_p_max = (float4)VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimPMax;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimPMin <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimPMin >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_p_min = (float4)VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimPMin;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimTMax <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimTMax >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_t_max = (float4)VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimTMax;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimTMin <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimTMin >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_t_min = (float4)VCU_SW_DW.paramsData.ParGCAN3.manGenInvCmdMotLimTMin;
		}
		//
	}
	//GCAN Data Pack 4
	void setGCAN4Data(void) {

		if (VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotLimNMax <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotLimNMax >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_n_max = (float4)VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotLimNMax;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotLimNMin <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotLimNMin >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_lim_n_min = (float4)VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotLimNMin;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotNRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotNRef >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_n_ref = (float4)VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotNRef;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotUdcRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotUdcRef >= (sbyte2)-32760) { // if parameter value in range
			pGCANManual_CmdMotUDcRef = (float4)VCU_SW_DW.paramsData.ParGCAN4.manGenInvCmdMotUdcRef;
			pGCANManual_CmdMotUDcRef_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_CmdMotUDcRef_Flag = (ubyte1)0;
		}
		//VCU_SW_DW.paramsData.ParGCAN4.manDOTMSFanSwt

		}
	//GCAN Data Pack 5
	void setGCAN5Data(void) {

		if (VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotFRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotFRef >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_f_ref = (float4)VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotFRef;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotPRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotPRef >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_p_ref = (float4)VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotPRef;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotQRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotQRef >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_q_ref = (float4)VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotQRef;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotTRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotTRef >= (sbyte2)-32760) { // if parameter value in range
			pGenInv_cmd_mot_t_ref = (float4)VCU_SW_DW.paramsData.ParGCAN5.manGenInvCmdMotTRef;
		}
		//
		}
	//GCAN Data Pack 6
	void setGCAN6Data(void) {
		if (VCU_SW_DW.paramsData.ParGCAN6.manEngOverCtrlModPr <= (ubyte1)250) { // if parameter value in range
			pGCANManual_OverContModPr = VCU_SW_DW.paramsData.ParGCAN6.manEngOverCtrlModPr;
			pGCANManual_OverContModPr_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_OverContModPr_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN6.manEngReqTrqLim <= (sbyte1)125 && VCU_SW_DW.paramsData.ParGCAN6.manEngReqTrqLim >= (sbyte1)-125) { // if parameter value in range
			pGCANManual_EngReqTrqTL = VCU_SW_DW.paramsData.ParGCAN6.manEngReqTrqLim;
			pGCANManual_EngReqTrqTL_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_EngReqTrqTL_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN6.manEngReqSpdContCond <= (ubyte1)250) { // if parameter value in range
			pGCANManual_EngReqSpContCond = VCU_SW_DW.paramsData.ParGCAN6.manEngReqSpdContCond;
			pGCANManual_EngReqSpContCond_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_EngReqSpContCond_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN6.manEngOverContMode <= (ubyte1)250) { // if parameter value in range
			pGCANManual_EngOverContMod = VCU_SW_DW.paramsData.ParGCAN6.manEngOverContMode;
			pGCANManual_EngOverContMod_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_EngOverContMod_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN6.manEngCtrlPurp <= (ubyte1)250) { // if parameter value in range
			pGCANManual_ContPurp = VCU_SW_DW.paramsData.ParGCAN6.manEngCtrlPurp;
			pGCANManual_ContPurp_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_ContPurp_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParGCAN6.manEngReqSpdLim <= (float4)8191 && VCU_SW_DW.paramsData.ParGCAN6.manEngReqSpdLim >= (float4)0) { // if parameter value in range
			pGCANManual_EngReqSpSL = VCU_SW_DW.paramsData.ParGCAN6.manEngReqSpdLim;
			pGCANManual_EngReqSpSL_Flag = (ubyte1)1;
		}
		else {
			pGCANManual_EngReqSpSL_Flag = (ubyte1)0;
		}
		//

		//VCU_SW_DW.paramsData.ParGCAN6.manDOTMSFanSwt
		}
	//TCAN Data Pack 1
	void setTCAN1Data(void) {
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdCtrlKp < (float4)25 && VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdCtrlKp >= (float4)0) { // if parameter value in range
			pInverterSpdCtrlKp1 = VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdCtrlKp;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdCtrlTi < (float4)25 && VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdCtrlTi >= (float4)0) { // if parameter value in range
			pInverterSpdCtrlTi1 = VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdCtrlTi;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdRefRampTi < (float4)25 && VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdRefRampTi >= (float4)0) { // if parameter value in range
			pInverterSpdRefRampTi1 = VCU_SW_DW.paramsData.ParTCAN1.manEmotSpdRefRampTi;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotCurMaxLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN1.manEmotCurMaxLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterCurMaxLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN1.manEmotCurMaxLim;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotCurMinLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN1.manEmotCurMinLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterCurMinLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN1.manEmotCurMinLim;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEMotCmdEna <= (ubyte1)1) { // if parameter value in range
			pTCANManual_cmd_enable_V_1 = VCU_SW_DW.paramsData.ParTCAN1.manEMotCmdEna;
			pTCANManual_cmd_enable_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_cmd_enable_F_1 = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotCmdMotCtrlMode <= (ubyte1)10) { // if parameter value in range
			pTCANManual_cmd_mot_ctrl_mode_V_1 = VCU_SW_DW.paramsData.ParTCAN1.manEmotCmdMotCtrlMode;
			pTCANManual_cmd_mot_ctrl_mode_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_cmd_mot_ctrl_mode_F_1 = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN1.manEmotCmdMotRun <= (ubyte1)1) { // if parameter value in range
			pTCANManual_cmd_mot_run_V_1 = VCU_SW_DW.paramsData.ParTCAN1.manEmotCmdMotRun;
			pTCANManual_cmd_mot_run_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_cmd_mot_run_F_1 = (ubyte1)0;
		}
		}
	//TCAN Data Pack 2
	void setTCAN2Data(void) {
		if (VCU_SW_DW.paramsData.ParTCAN2.manEmotPwrMaxLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN2.manEmotPwrMaxLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterPwrMaxLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN2.manEmotPwrMaxLim;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN2.manEmotPwrMinLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN2.manEmotPwrMinLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterPwrMinLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN2.manEmotPwrMinLim;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN2.manEmotTrqMaxLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN2.manEmotTrqMaxLim >= (sbyte2)-32760) { // if parameter value in range
			pTCANManual_Trq_max_Lim_V_1 = VCU_SW_DW.paramsData.ParTCAN2.manEmotTrqMaxLim;
			pTCANManual_Trq_max_Lim_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_Trq_max_Lim_F_1 = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN2.manEmotTrqMinLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN2.manEmotTrqMinLim >= (sbyte2)-32760) { // if parameter value in range
			pTCANManual_Trq_min_Lim_V_1 = VCU_SW_DW.paramsData.ParTCAN2.manEmotTrqMinLim;
			pTCANManual_Trq_min_Lim_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_Trq_min_Lim_F_1 = (ubyte1)0;
		}
	}
	//TCAN Data Pack 3
	void setTCAN3Data(void) {
		if (VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMaxHiLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMaxHiLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterDCVoltMaxHiLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMaxHiLim;
		}
		if (VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMaxLoLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMaxLoLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterDCVoltMaxLowLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMaxLoLim;
		}
		if (VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMinHiLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMinHiLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterDCVoltMinHiLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMinHiLim;
		}
		if (VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMinLoLim <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMinLoLim >= (sbyte2)-32760) { // if parameter value in range
			pInverterDCVoltMinLowLim1 = (float4)VCU_SW_DW.paramsData.ParTCAN3.manEmotDCVoltMinLoLim;
		}
		}
	//TCAN Data Pack 4
	void setTCAN4Data(void) {
		if (VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdLimNMin <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdLimNMin >= (sbyte2)-32760) { // if parameter value in range
			pTCANManual_cmd_mot_lim_n_min_V_1 = VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdLimNMin;
			pTCANManual_cmd_mot_lim_n_min_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_cmd_mot_lim_n_min_F_1 = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdLimNMax <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdLimNMax >= (sbyte2)-32760) { // if parameter value in range
			pTCANManual_cmd_mot_lim_n_max_V_1 = VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdLimNMax;
			pTCANManual_cmd_mot_lim_n_max_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_cmd_mot_lim_n_max_F_1 = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdMotSpdRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdMotSpdRef >= (sbyte2)-32760) { // if parameter value in range
			pInv1_cmd_mot_n_dc_ref = (float4)VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdMotSpdRef;
		}
		//
		if (VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdMotTrqRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdMotTrqRef >= (sbyte2)-32760) { // if parameter value in range
			pTCANManual_cmd_mot_t_ref_V_1 = VCU_SW_DW.paramsData.ParTCAN4.manEmotCmdMotTrqRef;
			pTCANManual_cmd_mot_t_ref_F_1 = (ubyte1)1;
		}
		else {
			pTCANManual_cmd_mot_t_ref_F_1 = (ubyte1)0;
		}
		//
		}
	//TCAN Data Pack 5
	void setTCAN5Data(void) {
		if (VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotFreqRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotFreqRef >= (sbyte2)-32760) { // if parameter value in range
			pInv1_cmd_mot_f_ref = (float4)VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotFreqRef;
		}
		if (VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotPwrRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotPwrRef >= (sbyte2)-32760) { // if parameter value in range
			pInv1_cmd_mot_p_dc_ref = (float4)VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotPwrRef;
		}
		if (VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotQRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotQRef >= (sbyte2)-32760) { // if parameter value in range
			pInv1_cmd_mot_q_ref = (float4)VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotQRef;
		}
		if (VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotUdcRef <= (sbyte2)32760 && VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotUdcRef >= (sbyte2)-32760) { // if parameter value in range
			pInv1_cmd_mot_u_dc_ref = (float4)VCU_SW_DW.paramsData.ParTCAN5.manEmotCmdMotUdcRef;
		}
		}
	//Input Functions Data Pack 1
	void setIF1Data(void) {
		if (VCU_SW_DW.paramsData.ParIF1.manIFAccPedPos <= (ubyte1)100) { // if parameter value in range
			pIFManual_accPedalPos = VCU_SW_DW.paramsData.ParIF1.manIFAccPedPos;
			pIFManual_accPedalPos_Flag = (ubyte1)1;
		}
		else {
			pIFManual_accPedalPos_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFBrkPedStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF1.manIFBrkPedStt == (ubyte1)0) {
				pIFManual_BrkPedalStt = BRK_PED_RELEASED;
			} else if (VCU_SW_DW.paramsData.ParIF1.manIFBrkPedStt == (ubyte1)1) {
				pIFManual_BrkPedalStt = BRK_PED_PRESSED;
			} else {
				pIFManual_BrkPedalStt = BRK_PED_ERROR;
			}
			pIFManual_BrkPedalStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_BrkPedalStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFVehSpd <= (ubyte1)100) { // if parameter value in range
			pIFManual_VehicleSpeed = VCU_SW_DW.paramsData.ParIF1.manIFVehSpd;
			pIFManual_VehicleSpeed_Flag = (ubyte1)1;
		}
		else {
			pIFManual_VehicleSpeed_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFRingShftSpd <= (ubyte2)65530) { // if parameter value in range
			pIFManual_RingShaftSpeed = VCU_SW_DW.paramsData.ParIF1.manIFRingShftSpd;
			pIFManual_RingShaftSpeed_Flag = (ubyte1)1;
		}
		else {
			pIFManual_RingShaftSpeed_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFOutShftSpd <= (ubyte2)30000) { // if parameter value in range
			pIFManual_OutputShaftSpeed = (sbyte2)VCU_SW_DW.paramsData.ParIF1.manIFOutShftSpd;
			pIFManual_OutputShaftSpeed_Flag = (ubyte1)1;
		}
		else {
			pIFManual_OutputShaftSpeed_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFTrCaseGear <= (ubyte1)4) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF1.manIFTrCaseGear == (ubyte1)0) {
				pIFManual_TransferCaseGear = LOW_GEAR;
			} else if (VCU_SW_DW.paramsData.ParIF1.manIFTrCaseGear == (ubyte1)1) {
				pIFManual_TransferCaseGear = HIGH_GEAR;
			} else if (VCU_SW_DW.paramsData.ParIF1.manIFTrCaseGear == (ubyte1)2) {
				pIFManual_TransferCaseGear = NEUTRAL_GEAR;
			} else {
				pIFManual_TransferCaseGear = GEAR_NUM_UNDEFINED;
			}
			pIFManual_TransferCaseGear_Flag = (ubyte1)1;
		}
		else {
			pIFManual_TransferCaseGear_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFTCOSpd <= (ubyte1)2540) { // if parameter value in range
			pIFManual_TCOSpeed = (sbyte2)VCU_SW_DW.paramsData.ParIF1.manIFTCOSpd;
			pIFManual_TCOSpeed_Flag = (ubyte1)1;
		}
		else {
			pIFManual_TCOSpeed_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF1.manIFParkBrkStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF1.manIFParkBrkStt == (ubyte1)0) {
				pIFManual_ParkBrakeState = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF1.manIFParkBrkStt == (ubyte1)1) {
				pIFManual_ParkBrakeState = STT_ENABLE;
			} else {
				pIFManual_ParkBrakeState = STT_ERROR;
			}
			pIFManual_ParkBrakeState_Flag = (ubyte1)1;
		}
		else {
			pIFManual_ParkBrakeState_Flag = (ubyte1)0;
		}
		//

		}
	//Input Functions Data Pack 2
	void setIF2Data(void) {
		if (VCU_SW_DW.paramsData.ParIF2.manIFRearBrkPress <= (ubyte4)254000) { // if parameter value in range
			pIFManual_rearBrakePressure = VCU_SW_DW.paramsData.ParIF2.manIFRearBrkPress;
			pIFManual_rearBrakePressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_rearBrakePressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFFrontBrkPress <= (ubyte4)254000) { // if parameter value in range
			pIFManual_frontBrakePressure = VCU_SW_DW.paramsData.ParIF2.manIFFrontBrkPress;
			pIFManual_frontBrakePressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_frontBrakePressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFParkBrkPress <= (ubyte4)254000) { // if parameter value in range
			pIFManual_parkBrakePressure = VCU_SW_DW.paramsData.ParIF2.manIFParkBrkPress;
			pIFManual_parkBrakePressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_parkBrakePressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFRemBrkPress <= (ubyte4)254000) { // if parameter value in range
			pIFManual_remBrakePressure = VCU_SW_DW.paramsData.ParIF2.manIFRemBrkPress;
			pIFManual_remBrakePressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_remBrakePressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFLeftTurnPress <= (ubyte4)25400) { // if parameter value in range
			pIFManual_leftTurnPressure = VCU_SW_DW.paramsData.ParIF2.manIFLeftTurnPress;
			pIFManual_leftTurnPressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_leftTurnPressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFRightTurnPress <= (ubyte4)25400) { // if parameter value in range
			pIFManual_rightTurnPressure = VCU_SW_DW.paramsData.ParIF2.manIFRightTurnPress;
			pIFManual_rightTurnPressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_rightTurnPressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFGBFirstCluPress <= (ubyte2)25400) { // if parameter value in range
			pIFManual_gearboxFstPressure = VCU_SW_DW.paramsData.ParIF2.manIFGBFirstCluPress;
			pIFManual_gearboxFstPressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_gearboxFstPressure_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF2.manIFGBSecCluPress <= (ubyte2)25400) { // if parameter value in range
			pIFManual_gearboxSecPressure = VCU_SW_DW.paramsData.ParIF2.manIFGBSecCluPress;
			pIFManual_gearboxSecPressure_Flag = (ubyte1)1;
		}
		else {
			pIFManual_gearboxSecPressure_Flag = (ubyte1)0;
		}
		//
		}
	//Input Functions Data Pack 3
	void setIF3Data(void) {
		if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode <= (ubyte1)12) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)0) {
				pIFManual_EnStrtM = START_NOT_AVAILIBLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)1) {
				pIFManual_EnStrtM = START_NOT_REQ;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)2) {
				pIFManual_EnStrtM = STARTER_ACT_GEAR_NOT_ENG;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)3) {
				pIFManual_EnStrtM = STARTER_ACT_GEAR_ENG;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)4) {
				pIFManual_EnStrtM = START_FINISHED;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)5) {
				pIFManual_EnStrtM = STARTER_INH_ENG_RUN;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)6) {
				pIFManual_EnStrtM = STARTER_INH_ENG_NOT_READY;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)7) {
				pIFManual_EnStrtM = STARTER_INH_DRVL_ENG;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)8) {
				pIFManual_EnStrtM = STARTER_INH_ACT_IMMO;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)9) {
				pIFManual_EnStrtM = STARTER_INH_OVERHEAT;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)10) {
				pIFManual_EnStrtM = STARTER_INH_REASON_UNKNOWN;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngStrtMode == (ubyte1)11) {
				pIFManual_EnStrtM = START_RESERVED;
			} else {
				pIFManual_EnStrtM = START_ERROR;
			}
			pIFManual_EnStrtM_Flag = (ubyte1)1;
		}
		else {
			pIFManual_EnStrtM_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFGBOilTempStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFGBOilTempStt == (ubyte1)0) {
				pIFManual_OilTempState = FLUID_TEMP_IS_NORMAL;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGBOilTempStt == (ubyte1)1) {
				pIFManual_OilTempState = FLUID_TEMP_IS_OVERHEAT;
			} else {
				pIFManual_OilTempState = FLUID_STATE_IS_NOT_DEFINED;
			}
			pIFManual_OilTempState_Flag = (ubyte1)1;
		}
		else {
			pIFManual_OilTempState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFGBOilLvlStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFGBOilLvlStt == (ubyte1)0) {
				pIFManual_OilLvlState = FLUID_LEVEL_IS_CORRECT;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGBOilLvlStt == (ubyte1)1) {
				pIFManual_OilLvlState = FLUID_LEVEL_IS_LOW;
			} else {
				pIFManual_OilLvlState = FLUID_STATE_IS_NOT_DEFINED;
			}
			pIFManual_OilLvlState_Flag = (ubyte1)1;
		}
		else {
			pIFManual_OilLvlState_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFEngCoolLvlStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFEngCoolLvlStt == (ubyte1)0) {
				pIFManual_EngCoolLvlStt = FLUID_LEVEL_IS_CORRECT;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngCoolLvlStt == (ubyte1)1) {
				pIFManual_EngCoolLvlStt = FLUID_LEVEL_IS_LOW;
			} else {
				pIFManual_EngCoolLvlStt = FLUID_STATE_IS_NOT_DEFINED;
			}
			pIFManual_EngCoolLvlStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_EngCoolLvlStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos <= (ubyte1)5) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos == (ubyte1)0) {
				pIFManual_LeverPos = DRIVE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos == (ubyte1)1) {
				pIFManual_LeverPos = REVERSE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos == (ubyte1)2) {
				pIFManual_LeverPos = NEUTRAL;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos == (ubyte1)3) {
				pIFManual_LeverPos = LEVER_POS_ERROR;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos == (ubyte1)4) {
				pIFManual_LeverPos = DRIVE_1;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFLeverPos == (ubyte1)5) {
				pIFManual_LeverPos = DRIVE_2;
			} else {
				pIFManual_LeverPos = LEVER_POS_DOES_NOT_DEFINED;
			}
			pIFManual_LeverPos_Flag = (ubyte1)1;
		}
		else {
			pIFManual_LeverPos_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFHVILStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFHVILStt == (ubyte1)0) {
				pIFManual_HVILStt = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFHVILStt == (ubyte1)1) {
				pIFManual_HVILStt = STT_ENABLE;
			} else {
				pIFManual_HVILStt = STT_ERROR;
			}
			pIFManual_HVILStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_HVILStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFShutdnButStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFShutdnButStt == (ubyte1)0) {
				pIFManual_ShutdownButStt = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFShutdnButStt == (ubyte1)1) {
				pIFManual_ShutdownButStt = STT_ENABLE;
			} else {
				pIFManual_ShutdownButStt = STT_ERROR;
			}
			pIFManual_ShutdownButStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_ShutdownButStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFOnBrdChrgCtrlCapStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFOnBrdChrgCtrlCapStt == (ubyte1)0) {
				pIFManual_OnBrdChrgCtrlCapStt = CAP_OPENED;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFOnBrdChrgCtrlCapStt == (ubyte1)1) {
				pIFManual_OnBrdChrgCtrlCapStt = CAP_CLOSED;
			} else {
				pIFManual_OnBrdChrgCtrlCapStt = CAP_POS_NOT_AVAILIBLE;
			}
			pIFManual_OnBrdChrgCtrlCapStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_OnBrdChrgCtrlCapStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFVoltConvCapStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFVoltConvCapStt == (ubyte1)0) {
				pIFManual_DCDCCapStt = CAP_OPENED;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFVoltConvCapStt == (ubyte1)1) {
				pIFManual_DCDCCapStt = CAP_CLOSED;
			} else {
				pIFManual_DCDCCapStt = CAP_POS_NOT_AVAILIBLE;
			}
			pIFManual_DCDCCapStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_DCDCCapStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFFuseBoxCapStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFFuseBoxCapStt == (ubyte1)0) {
				pIFManual_FuseBoxCapStt = CAP_OPENED;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFFuseBoxCapStt == (ubyte1)1) {
				pIFManual_FuseBoxCapStt = CAP_CLOSED;
			} else {
				pIFManual_FuseBoxCapStt = CAP_POS_NOT_AVAILIBLE;
			}
			pIFManual_FuseBoxCapStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_FuseBoxCapStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFGenSts <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFGenSts == (ubyte1)0) {
				pIFManual_GeneratorStatus = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGenSts == (ubyte1)1) {
				pIFManual_GeneratorStatus = STT_ENABLE;
			} else {
				pIFManual_GeneratorStatus = STT_ERROR;
			}
			pIFManual_GeneratorStatus_Flag = (ubyte1)1;
		}
		else {
			pIFManual_GeneratorStatus_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFGenMode <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFGenMode == (ubyte1)0) {
				pIFManual_GeneratorMode = EMOT_RUN;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGenMode == (ubyte1)1) {
				pIFManual_GeneratorMode = EMOT_STOP;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGenMode == (ubyte1)2) {
				pIFManual_GeneratorMode = EMOT_INITIALIZING;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGenMode == (ubyte1)3) {
				pIFManual_GeneratorMode = EMOT_STARTING;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFGenMode == (ubyte1)4) {
				pIFManual_GeneratorMode = EMOT_TRIPPED;
			} else {
				pIFManual_GeneratorMode = EMOT_ERROR;
			}
			pIFManual_GeneratorMode_Flag = (ubyte1)1;
		}
		else {
			pIFManual_GeneratorMode_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFPlugLockStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFPlugLockStt == (ubyte1)0) {
				pIFManual_PlugLockStt = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFPlugLockStt == (ubyte1)1) {
				pIFManual_PlugLockStt = STT_ENABLE;
			} else {
				pIFManual_PlugLockStt = STT_ERROR;
			}
			pIFManual_PlugLockStt_Flag = (ubyte1)1;
		}
		else {
			pIFManual_PlugLockStt_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFVoltConvEna <= (ubyte1)1) { // if parameter value in range
			pECANManual_BPNEnable = VCU_SW_DW.paramsData.ParIF3.manIFVoltConvEna;
			pECANManual_BPNEnabler_Flag = (ubyte1)1;
		}
		else {
			pECANManual_BPNEnabler_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFGenCmdFaultRes <= (ubyte1)1) { // if parameter value in range
			pGenInv_cmd_fault_reset_manual = VCU_SW_DW.paramsData.ParIF3.manIFGenCmdFaultRes;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFEmotCmdFaultRes <= (ubyte1)1) { // if parameter value in range
			pInv1_cmd_fault_reset_manual = VCU_SW_DW.paramsData.ParIF3.manIFEmotCmdFaultRes;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFBMSNegRelayStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFBMSNegRelayStt == (ubyte1)0) {
				pIFManual_BMSNegRel = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFBMSNegRelayStt == (ubyte1)1) {
				pIFManual_BMSNegRel = STT_ENABLE;
			} else {
				pIFManual_BMSNegRel = STT_ERROR;
			}
			pIFManual_BMSNegRel_Flag = (ubyte1)1;
		}
		else {
			pIFManual_BMSNegRel_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFBMSPosRelayStt <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFBMSPosRelayStt == (ubyte1)0) {
				pIFManual_BMSPosRel = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFBMSPosRelayStt == (ubyte1)1) {
				pIFManual_BMSPosRel = STT_ENABLE;
			} else {
				pIFManual_BMSPosRel = STT_ERROR;
			}
			pIFManual_BMSPosRel_Flag = (ubyte1)1;
		}
		else {
			pIFManual_BMSPosRel_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFEngWaitSttLamp <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFEngWaitSttLamp == (ubyte1)0) {
				pIFManual_WaitStLam = STT_DISABLE;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFEngWaitSttLamp == (ubyte1)1) {
				pIFManual_WaitStLam = STT_ENABLE;
			} else {
				pIFManual_WaitStLam = STT_ERROR;
			}
			pIFManual_WaitStLam_Flag = (ubyte1)1;
		}
		else {
			pIFManual_WaitStLam_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFTMSValvePos <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFTMSValvePos == (ubyte1)0) {
				pIFManual_TMSValvePos = VALVE_CONNECT_TO_PORT_A;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFTMSValvePos == (ubyte1)1) {
				pIFManual_TMSValvePos = VALVE_CONNECT_TO_PORT_B;
			} else {
				pIFManual_TMSValvePos = VALVE_POS_ERROR;
			}
			pIFManual_TMSValvePos_Flag = (ubyte1)1;
		}
		else {
			pIFManual_TMSValvePos_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFTMSValveCtrlCmd <= (ubyte1)1) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFTMSValveCtrlCmd == (ubyte1)0) {
				pOFManual_TMSValveCtrlComand = VALVE_CONNECT_TO_PORT_A;
			} else if (VCU_SW_DW.paramsData.ParIF3.manIFTMSValveCtrlCmd == (ubyte1)1) {
				pOFManual_TMSValveCtrlComand = VALVE_CONNECT_TO_PORT_B;
			} else {
				pOFManual_TMSValveCtrlComand = VALVE_POS_ERROR;
			}
			pOFManual_TMSValveCtrlComand_Flag = (ubyte1)1;
		}
		else {
			pOFManual_TMSValveCtrlComand_Flag = (ubyte1)0;
		}
		//
	/*	if (VCU_SW_DW.paramsData.ParIF3.manIFTMSCircPumpCtrl <= (ubyte1)250) { // if parameter value in range
			pOFManual_TMSCircPumpCtrl = VCU_SW_DW.paramsData.ParIF3.manIFTMSCircPumpCtrl;
			pOFManual_TMSCircPumpCtrl_Flag = (ubyte1)1;
		}
		else {
			pOFManual_TMSCircPumpCtrl_Flag = (ubyte1)0;
		}
		*/
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFDiagProhib_BMS <= (ubyte1)3) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFDiagProhib_BMS == (ubyte1)0) {
				pMan_DiagProhib_BMS = STT_DISABLE;
			} else {
				pMan_DiagProhib_BMS = STT_ENABLE;
			}
			//pMan_DiagProhib_BMS_Flag = (ubyte1)1;
		}
		else {
			//pMan_DiagProhib_BMS_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manIFDiagProhib_TMS <= (ubyte1)3) { // if parameter value in range
			if (VCU_SW_DW.paramsData.ParIF3.manIFDiagProhib_TMS == (ubyte1)0) {
				pMan_DiagProhib_TMS = STT_DISABLE;
			} else {
				pMan_DiagProhib_TMS = STT_ENABLE;
			}
			//pMan_DiagProhib_TMS_Flag = (ubyte1)1;
		}
		else {
			//pMan_DiagProhib_TMS_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParIF3.manDOVoltageConvT15 <= (ubyte1)1) { // if parameter value in range
			//pDOManual_VoltageConverterT15 = VCU_SW_DW.paramsData.ParIF3.manDOVoltageConvT15;
			//pDOManual_VoltageConverterT15_Flag = (ubyte1)1;
		}
		else {
			//pDOManual_VoltageConverterT15_Flag = (ubyte1)0;
		}
		//
		}
	//Output Functions Data Pack 1
	void setOF1Data(void) {
		if (VCU_SW_DW.paramsData.ParOF1.manOFClu1CurReq <= (ubyte2)2540) { // if parameter value in range
			//pOFManual_FirstGearPICtrl_CurrentReq = VCU_SW_DW.paramsData.ParOF1.manOFClu1CurReq;
			//pOFManual_FirstGearPICtrl_CurrentReq_Flag = (ubyte1)1;
		}
		else {
			//pOFManual_FirstGearPICtrl_CurrentReq_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFClu2CurReq <= (ubyte2)2540) { // if parameter value in range
			//pOFManual_SecGearPICtrl_CurrentReq = VCU_SW_DW.paramsData.ParOF1.manOFClu2CurReq;
			//pOFManual_SecGearPICtrl_CurrentReq_Flag = (ubyte1)1;
		}
		else {
			//pOFManual_SecGearPICtrl_CurrentReq_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFCircPumpPWMReq <= (ubyte1)250) { // if parameter value in range
			pOFManual_TMSCircPumpCtrl = VCU_SW_DW.paramsData.ParOF1.manOFCircPumpPWMReq;
			pOFManual_TMSCircPumpCtrl_Flag = (ubyte1)1;
		}
		else {
			pOFManual_TMSCircPumpCtrl_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFClu1PWMReq <= (ubyte1)250) { // if parameter value in range
			pOFManual_FirstGearCtrlValve = VCU_SW_DW.paramsData.ParOF1.manOFClu1PWMReq;
			pOFManual_FirstGearCtrlValve_Flag = (ubyte1)1;
		}
		else {
			pOFManual_FirstGearCtrlValve_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFClu2PWMReq <= (ubyte1)250) { // if parameter value in range
			pOFManual_SecGearCtrlValve = VCU_SW_DW.paramsData.ParOF1.manOFClu2PWMReq;
			pOFManual_SecGearCtrlValve_Flag = (ubyte1)1;
		}
		else {
			pOFManual_SecGearCtrlValve_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFRemBrkPWMReq <= (ubyte1)250) { // if parameter value in range
			pOFManual_RemBrkCtrlValve = VCU_SW_DW.paramsData.ParOF1.manOFRemBrkPWMReq;
			pOFManual_RemBrkCtrlValve_Flag = (ubyte1)1;
		}
		else {
			pOFManual_RemBrkCtrlValve_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFPumpFlowPWMReq <= (ubyte1)250) { // if parameter value in range
			pOFManual_PumpFlowControl = VCU_SW_DW.paramsData.ParOF1.manOFPumpFlowPWMReq;
			pOFManual_PumpFlowControl_Flag = (ubyte1)1;
		}
		else {
			pOFManual_PumpFlowControl_Flag = (ubyte1)0;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF1.manOFTMSComprPWMReq <= (ubyte1)250) { // if parameter value in range
			pOFManual_TMSCompressprCtrl = VCU_SW_DW.paramsData.ParOF1.manOFTMSComprPWMReq;
			pOFManual_TMSCompressprCtrl_Flag = (ubyte1)1;
		}
		else {
			pOFManual_TMSCompressprCtrl_Flag = (ubyte1)0;
		}
		//

		}
	//Output Functions Data Pack 2
	void setOF2Data(void) {
		if (VCU_SW_DW.paramsData.ParOF2.manOFSecGearVlvMaxCur <= (ubyte2)65535) { // if parameter value in range
			//pSecGearVlvMaxCur = VCU_SW_DW.paramsData.ParOF2.manOFSecGearVlvMaxCur;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvMaxCur <= (ubyte2)65535) { // if parameter value in range
			//pFstGearVlvMaxCur = VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvMaxCur;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF2.manOFSecGearVlvPI_P <= (float4)25.5 && VCU_SW_DW.paramsData.ParOF2.manOFSecGearVlvPI_P >= (float4)0) { // if parameter value in range
			//pSecGearVlvPI_P = VCU_SW_DW.paramsData.ParOF2.manOFSecGearVlvPI_P;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvMaxCur <= (float4)25.5 && VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvMaxCur >= (float4)0) { // if parameter value in range
			//pSecGearVlvPI_I = VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvMaxCur;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvPI_P <= (float4)25.5 && VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvPI_P >= (float4)0) { // if parameter value in range
			//pFstGearVlvPI_P = VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvPI_P;
		}
		//
		if (VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvPI_I <= (float4)25.5 && VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvPI_I >= (float4)0) { // if parameter value in range
			//pFstGearVlvPI_I = VCU_SW_DW.paramsData.ParOF2.manOFFstGearVlvPI_I;
		}
		//
	}
