#ifndef ASSIGNPARAMS_H
#define ASSIGNPARAMS_H

/*#include "rtwtypes.h"
#include "ptypes_tms570.h"*/

// assign parameters group

//extern void assignParamsData(float4 value1, ubyte1 value2, ubyte2 value3);

// assign parameter by id

//extern void assignParamsDataById(ubyte1 id, float4 value);

//extern volatile ubyte4* pMinVehicleSpeedAddr;
//extern volatile ubyte4* pShiftInertiaTrqFactAddr;
//extern volatile ubyte4* pShiftDisengageTimeAddr;
//extern volatile ubyte4* pWheelRadiusAddr;
//extern volatile ubyte4* pMinVelocity_inverterAddr;
//extern volatile ubyte4* pInvDeltaForTrqDemandAddr;


/*
typedef struct {
		ubyte1  request;
		ubyte1	group;
		ubyte1  subgroup;
		ubyte1  id;
		ubyte1	flag;
		float4  value;
} ParamDataStruct;*/


//
//	extern void initParamsList(void);


//diag parameters
	//diag client

//input interface parameters
	//digital input
/*	extern void setDIParams(ubyte1 id, float4 value, ubyte1 manflag);
	//analog input
	extern void setAIParams(ubyte1 id, float4 value, ubyte1 manflag);
	//PWD input
	extern void setPWDParams(ubyte1 id, float4 value, ubyte1 manflag);
	//PWM current input
	//extern void assignPWMCurParams(ubyte1 id, float4 value, ubyte1 manflag);
	//digital output voltage input

	//electric CAN

	//torque CAN

	//cabine CAN

	//steering CAN

	//autonomous CAN

	//generator CAN

	//input interface client
	//extern void inIntrfcParClient(ubyte1 subgroup, ubyte1 id, float4 value);
//input functions parameters
	//pressures

	//pedals

	//positions

	//states

	//weights

	//currents

	//temperatures

	//speeds

	//input functions client

//application parameters
	//devices

	//steering

	//brake

	//engine

	//powertrain

	//generator

	//highvoltage
	void setBmsParams(ubyte1 id, float4 value, ubyte1 manflag);
	void setTmsParams(ubyte1 id, float4 value, ubyte1 manflag);
	void setBmsTmsCalibParams(ubyte1 id, float4 value, ubyte1 manflag);
	//app client
//output functions parameters
	//current

	//valves

	//output functions client

//output interface parameters
	//digital output
	extern void setDOParams(ubyte1 id, float4 value, ubyte1 manflag);
	//PWM
	extern void setPWMParams(ubyte1 id, float4 value, ubyte1 manflag);
	//HBridge

	//electric CAN
	extern void setECANParams(ubyte1 id, float4 value, ubyte1 manflag);
	//torque CAN
	extern void setTCANParams(ubyte1 id, float4 value, ubyte1 manflag);
	//cabine CAN
	extern void setCCANOutParams(ubyte1 id, float4 value, ubyte1 manflag);

	//steering CAN

	//autonomous CAN
	extern void setBrakeDiagOperParams(ubyte1 id, float4 value, ubyte1 manflag);
	//generator CAN

	//output interface client
	//extern void outIntrfcParClient(ubyte1 subgroup, ubyte1 id, float4 value);
//parameters main client
	extern void assignParData(ParamDataStruct parData);*/






#endif
