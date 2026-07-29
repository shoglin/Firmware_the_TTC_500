/*

 */
#ifndef SWC_APP_ENUM_TYPES_h_
#define SWC_APP_ENUM_TYPES_h_


/* Type definition of Engine Mode Types. */
typedef enum {
		ENG_MODE_DOES_NOT_DEFINED = 0, /* Default value */
        ENG_STOP_MODE,
        ENG_IGNITION_MODE,
        ENG_STARTUP_MODE,
        ENG_IDLE_MODE,
        ENG_OPERATION_MODE,
        ENG_SHUTDOWN_MODE,
        ENG_EMERGENCY_MODE 
} EngineModeTypes;

/* Type definition of Powertrain Mode Types. */
typedef enum {
		PT_MODE_DOES_NOT_DEFINED = 0, /* Default value */
        PT_STOP_MODE,
        PT_IDLE_MODE,
        PT_TRACT_MODE,
        PT_EMERGENCY_MODE
} PowertrainModeTypes;

/* Type definition of Status Mode Types. */
typedef enum {
		OFF = 0, /* Default value */
		ON,
		RESERVED,
		NO_ACTION
} StatusModeTypes;

/* Type definition of Diag Fault Types. */
typedef enum {
		E_OK = 0, /* Default value */
		E_NOT_OK,
        SHORT_GND = 17,
        OPEN_LOAD_OR_SHORT_BAT = 19,
		//sensors' errors
		INTERNAL_ERROR = 254,
		NO_CONNECTION,

		//voltage measurment
		VOL_MES_ERROR = 65534,
		NOT_EVALUETED
} DiagFaultTypes;

/* Type definition of Digital Pin Status Types. */
typedef enum {
		DISABLE = 0, /* Default value */
		ENABLE,
		WARNING,
		ERROR
} DigitalPinStatusTypes;

/* Type definition of Error Value Types. */
typedef enum {
        UNKNOWN_ERROR = 0, /* Default value */
        VOLTAGE_ERROR_VALUE,
        CURRENT_ERROR_VALUE,
        RESISTANSE_ERROR_VALUE,
        PRESSURE_ERROR_VALUE,
        WEIGHT_ERROR_VALUE,
		FREQ_ERROR_VALUE,
        PEDAL_ERROR_VALUE,
        DUTY_CYCLE_ERROR_VALUE,
        TEMPERATURE_ERROR_VALUE,
		TORQUE_ERROR_VALUE,
        SPEED_ERROR_VALUE
} ErrorValueTypes;

/* Type definition of State Mode Types. */
typedef enum {
        STT_DISABLE = 0,  /* Default value */ 
        STT_ENABLE,
        STT_RESERVED,
        STT_DEFAULT,
        STT_ERROR
} StateModeTypes;

/* Type definition of State Mode Types. */
typedef enum {
       FLUID_STATE_IS_NOT_DEFINED = 0, /* Default value */ 
       FLUID_TEMP_IS_NORMAL,
       FLUID_TEMP_IS_OVERHEAT,
       
       FLUID_LEVEL_IS_CORRECT = 10,
       FLUID_LEVEL_IS_LOW,
                       
       FLUID_PRESS_IS_NORMAL = 20,
       FLUID_PRESS_IS_INCORRECT,
       FLUID_PRESS_IS_LOW,
       FLUID_PRESS_IS_HIGH        
} FluidStateTypes;

/* Type definition of State Mode Types. */
typedef enum {
       SENS_STT_IS_UNDEFINED = 0, /* Default value */
       SENS_ON,
       SENS_OFF,
       SENS_FLASHING,
       SENS_ERROR
} SensorsStateTypes;

/* Type definition of State Mode Types. */
typedef enum {
        VALVE_POS_DOES_NOT_DEFINED = 0, /* Default value */
        VALVE_OPEN,
        VALVE_CLOSED,
        VALVE_POS_ERROR
} ValvePosStateTypes;

/* Type definition of State Mode Types. */
typedef enum {
        LEVER_POS_DOES_NOT_DEFINED = 0, /* Default value */
        NEUTRAL,
        DRIVE,
        REVERSE,
        LEVER_POS_ERROR
} LeverPosTypes;

/* Type definition of State Mode Types. */
typedef enum { 
        BRK_PED_POS_NOT_DEFINED = 0, /* Default value */
        BRK_PED_RELEASED,
        BRK_PED_PRESSED,
        BRK_PED_ERROR
} BrkPedalTypes;

/* Type definition of State Mode Types. */
typedef enum { 
            START_NOT_AVAILIBLE = 0, /* Default value */
			START_NOT_REQ,
			STARTER_ACT_GEAR_NOT_ENG,
			STARTER_ACT_GEAR_ENG,
			START_FINISHED,
            STARTER_INH_ENG_RUN,
			STARTER_INH_ENG_NOT_READY,
            STARTER_INH_DRVL_ENG,
			STARTER_INH_ACT_IMMO,
            STARTER_INH_OVERHEAT,
            STARTER_INH_REASON_UNKNOWN,
            START_RESERVED,
			START_ERROR
} StarterModeTypes;

/* Type definition of EmergencyBrakeTypes. */
typedef enum {
       EMERGENCY_TYPE_DOES_NOT_DEFINED = 0,
       EMERGENCY_STOP,
       EMERGENCY_PARK,
       RECUPIRATION_HELP,
       BRAKE_INITIAL_MODE
} EmergencyBrakeTypes;

/* Type definition of Generator Mode Types. */
typedef enum {
       BRAKE_MODE_DOES_NOT_DEFINED = 0,
       BRAKE_OPERATION_MODE,
       BRAKE_PARKING_MODE,
       BRAKE_EMERGENCY_MODE
} BrakeModeTypes;

/* Type definition of Generator Mode Types. */
typedef enum {
        STG_DOES_NOT_DEFINED = 0,
        STG_INIT,
        STG_STANDBY,
        STG_PREPARE,
        STG_OPERATION,
        STG_COMPLETING,
        STG_COMPLETED,
        STG_EMERGENCY
} OperStageTypes;

/* Type definition of spool in axle slew drive. */
typedef enum {
      SPOOL_NOT_DEFINED = 0, 
      CLOSED_CENTER,
	  OPEN_CENTER
} SpoolTypes;

/* Type definition of cargo platform states. */
typedef enum {
      CARGO_PLATFORM_STATE_NOT_DEFINED = 0,
      LIFTING,
	  LOWERING,
      HOLDING,
      TRANSPORTABLE,
      UNKNOWN  
} CargoPlatformStateTypes;

/* Type definition of TransModeTypes. */
typedef enum {
      Mode_1_GM_spdveh_GP_joy = 0,
      Mode_2_GM_rev_GM_GP_rev_eng,
	  Mode_3_GM_rev_eng_GP_rev_eng 
} TransModeTypes;

/* Type definition of EngCtrlModeTypes. */
typedef enum {
      CANCELCONTROL = 0,
      SPEEDCONTR,
	  TRQCONTR, 
      TRQSPEEDCONTR 
} EngCtrlModeTypes;

/* Type definition of GearNumTypes. */
typedef enum {
       GEAR_NOT_AVAILABLE = 0,
       GEAR_2_WHEEL_HIGH,
       GEAR_4_WHEEL_HIGH,
       GEAR_NEUTRAL,
       GEAR_2_WHEEL_LOW,
       GEAR_4_WHEEL_LOW,
       GEAR_RESERVED,
       GEAR_ERROR 
} GearNumTypes; 

/* Type definition of SteeringModeTypes. */
typedef enum {
        STEERING_NOT_AVAILABLE = 0,
        STEERING_HOLD,
        STEERING_OPERATION,
        STEERING_LEFT,
        STEERING_RIGHT
} SteeringModeTypes;

/* Type definition of CabMovModeTypes. */
typedef enum {
        CAB_FIXED = 0,
        CAB_ROTATION,
	    CAB_ROTATION_RETURN,
        CAB_TILT,
		CAB_TILT_RETURN,
		CAB_TILT_STAB,
        CAB_AUTO,
		CAB_NOT_DEFINED
} CabMovModeTypes;

/* Type definition of CabPitchDirTypes. */
typedef enum {
        PITCH_NOT_DEFINED = 0,
        PITCH_STANDBY,
	    PITCH_FORWARD,
        PITCH_BACKWARD
} CabPitchDirTypes;

/* Type definition of CabRollDirTypes. */
typedef enum {
        ROLL_NOT_DEFINED = 0,
        ROLL_STANDBY,
        ROLL_LEFT,
        ROLL_RIGHT
} CabRollDirTypes;

/* Type definition of CabRotDirTypes. */
typedef enum {
        ROT_NOT_DEFINED = 0,
        ROT_STANDBY,
        ROT_LEFT,
        ROT_RIGHT
} CabRotDirTypes;

typedef enum {
        ROD_NOT_DEFINED = 0,
        ROD_STANDBY,
        ROD_UP,
        ROD_DOWN
} CylinderDirTypes;

typedef enum {
        ROTPOS_NOT_DEFINED = 0,
        ROTPOS_NEAR_ZERO,
        ROTPOS_LEFT,
        ROTPOS_LEFT_END,
        ROTPOS_RIGHT,
        ROTPOS_RIGHT_END,
        ROTPOS_ERROR
} CabRotPosTypes;

typedef enum {
       DOORS_POS_NOT_AVAILABLE = 0,
       DOORS_POS_AT_LEAST_1_DOOR_IS_OPEN,
       DOORS_POS_CLOSING_LAST_DOOR,
       DOORS_POS_ALL_DOORS_CLOSED,
       DOORS_POS_NOT_DEFINED,
       DOORS_POS_ERROR
} DoorsPositionTypes;

typedef enum {
       DRIVER_CLASS_NOT_AVAILABLE = 0,
       DRIVER_CLASS_EMPTY,
       DRIVER_CLASS_DRIVER_PRESENT,
       DRIVER_CLASS_RESERVED,
       DRIVER_CLASS_ERROR
} DriverOccClassSystemTypes;

typedef enum {
       LADDER_NOT_AVAILABLE = 0, 
       LADDER_UP,
       LADDER_DOWN,
       LADDER_RESERVED
} LadderStatusTypes;

typedef enum {
       H_ROT_NOT_DEFINED = 0,
	   H_ROT_CW,
       H_ROT_CCW
} HydroAgrRotDirTypes;

typedef enum {
       AUTOHOLD_DISABLE = 0,
	   AUTOHOLD_ENABLE,
       AUTOHOLD_ACTIVE
} AutoHoldModeTypes;

#endif                                 /* SWC_APP_ENUM_TYPES_h_ */

