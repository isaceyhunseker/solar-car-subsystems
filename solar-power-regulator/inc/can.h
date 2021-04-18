// Motor controller CAN base address and packet offsets
#define	MC_CAN_BASE						0x0400
#define MC_ID									0x00
#define MC_STATUS							0x01
#define	MC_BUS								0x02
#define MC_VELOCITY						0x03
#define MC_PHASE							0x04
#define MC_V_VECTOR						0x05
#define MC_I_VECTOR						0x06
#define MC_BEMF								0x07
#define MC_RAIL_1							0x08
#define MC_RAIL_2							0x09
#define MC_FAN								0x0A
#define MC_TEMP1							0x0B
#define MC_TEMP2							0x0C
#define MC_TEMP3							0x0D
#define MC_CUMULATIVE					0x0E

#define MC_CONF_REQUEST					18
#define MC_CONF_REPLY					  19
#define MC_CONF_DATA_OUT				20
#define MC_CONF_DATA_IN					21

#define MC2_CAN_BASE				  0x430
#define MC2_ID			          0x00
#define MC2_STATUS				    0x01
#define MC2_BJS				        0x02
#define MC2_VELOCITY				  0x03
#define MC2_PHASE			        0x04
#define MC2_V_VECTOR		      0x05
#define MC2_I_VECTOR		      0x06
#define MC2_BEMF							0x07
#define MC2_RAIL_1						0x08
#define MC2_RAIL_2						0x09
#define MC2_FAN					  		0x0A
#define MC2_TEMP1      			  0x0B
#define MC2_TEMP2						  0x0C
#define MC2_TEMP3							0x0D
#define MC2_CUMULATIVE				0x0E

// Driver controls CAN base address and packet offsets
#define DC_CAN_BASE						0x0500
#define DC_DRIVE					  	0x01
#define DC_POWER						  0x02
#define DC_RESET						  0x03
#define DC_SWITCH						  0x04



typedef enum
{
Req_None=0,
LOCK_DATAFLASH,
UNLOCK_DATAFLASH,
RELOAD_CONF,
WRITESTREAM_TO_DATAFLASH,
Reserved
}eMotorControllerConfigRequests;

typedef struct
{
uint8_t OutputVoltagePWM:1;
uint8_t MotorCurrentLimitFlag:1;
uint8_t VelocityLimitFlag:1;
uint8_t BusCurrentLimitFlag:1;
uint8_t BusVoltageUpperLimitFlag:1;
uint8_t BusVoltageLowerLimitFlag:1;
uint8_t IPMorMotorTemperatureLimitFlag:1;
uint8_t Reserved:1;		    
}sMC_LimitFlags;

typedef struct
{
u8 HardwareOverCurrentFlag:1;
u8 SoftwareOverCurrentFlag:1;
u8 DC_BusOverVoltageFlag:1;
u8 BadMotorPositionFlag:1;
u8 WatchdogResetFlag:1;
u8 ConfigReadErrorFlag:1;
u8 UnderVoltageLockOutFlag:1;
u8 DesaturationFaultFlag:1;
}sMC_ErrorFlags;


typedef struct
{
float Img;
float Real;
}
fComplexNum;

typedef struct
{
u32 SerialNumber;
u8 TritiumID[4];
sMC_ErrorFlags Errors;
sMC_LimitFlags Limits;
float BusCurrent;				//A
float BusVoltage;				//volts
float VehicleVelocity;			//m/s
float MotorVelocity;			//rpm
float PhaseACurrent;			//A
float PhaseBCurrent;			//A
fComplexNum MotorVoltageVector;	//volts
fComplexNum MotorCurrentVector;	//A
fComplexNum MotorBackEMF;		//volts
float VoltageRail15V;			//volts
float VoltageRail1V65;			//volts
float FanSpeed;					//rpm
float FanDrive;					//percent
float HeatSinkTemp;				//celcius
float MotorTemp;				//celcius
float AirInletTemp;				//celcius
float ProcessorTemp;			//celcius
float AirOutletTemp;			//celcius
float CapacitorTemp;			//celcius
float DCBusAmpsHour;			//Ah
float Odometer;					//m
float WheelRadius;              //m
}sMotorController;


typedef union _group_64 {
	float data_fp[2];
	u8 data_u8[8];
	u16 data_u16[4];
	u32 data_u32[2];
	double data_d64;
} group_64;

typedef union _group_32 {
	float data_fp;
	u8 data_u8[4];
	u16 data_u16[2];
	u32 data_u32;
} group_32;		  

typedef union _group_16 {
	u8 data_u8[2];
	u16 data_u16;
} group_16;
