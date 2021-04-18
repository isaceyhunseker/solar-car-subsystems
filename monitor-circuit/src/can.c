#include "stm32f4xx.h"                  // Device header
#include "can.h"
#include "common.h"



CanRxMsg CanTempMess;


group_64 canTempMess64;
group_32 canTempMess32;


u16 deneme2;
u16 deneme4;
u16 deneme5;



u16 CC_Flag = 0;
u8 CC_Negative_Flag = 0;
u8 CC_Positive_Flag = 0;
u8 Controller_Flag = 0;
u8 Controller_Negative_Flag = 0;
u8 Controller_Positive_Flag = 0;
u8 Solar_Flag = 0;
u8 RightSignal_Flag = 0;
u8 LeftSignal_Flag = 0;
u8 Radio_Flag = 0;
u8 Emergency_Flag = 0;
u8 Horn_Flag = 0;
u8 Screen_Button_Flag = 0;
u8 Drive_Flag=0;		
u8 Neutral_Flag=0;	 
u8 Reverse_Flag = 0; 
u8 Shift_Status =0;
u16 ContactorFlag= 1;

u16 Min_Voltage;
u16 Max_Voltage;
u16 Min_Temp;
u16 Max_Temp;

u16 EmusEventNumber;
u16 MotorTemp;
u16 HeatSinkTemp;

float Regenative_Float;
float Velocity_Float;
float BusCurrent_Float;
float BusVoltage_Float;
float MotorTemp_Float;
float HeatSinkTemp_Float;
float MaxVoltageFloat;
float MinVoltageFloat;
u16	EmusMinVoltage; 		
u16	EmusMaxVoltage;
u16	EmusAverageVoltage; 
u16 EmusMaxTemp;
u16 EmusMinTemp;
u16 EmusAverageTemp;
u16 EmusEstimatedSOC;

		

// RightSignalCircuit
double MPPTGroup1Voltage_Double;
double MPPTGroup1Current_Double;
double MPPTGroup1Temp_Double;
u16 MPPTGroup1Voltage;
u16 MPPTGroup1Current;
u16 MPPTGroup1Temp;

// LeftSignalCircuit
double MPPTGroup2Voltage_Double;
double MPPTGroup2Current_Double;
double MPPTGroup2Temp_Double;
u16 MPPTGroup2Voltage;
u16 MPPTGroup2Current;
u16 MPPTGroup2Temp;


//STOPCircuit
double MPPTThirdTemp_Double;
u16 MPPTThirdTemp;

u16 MPPTMaxTemp;

u16 Regenative;
u8 Velocity;


u16 BusVoltage;
float BusVoltage_Float;
u16 BusCurrent;
float BusCurrent_Float;
u32 Power;




void ContactorControl(void);
void BrakeStatusSend(void);
void ParseTestMessage(void);
void SignalControl(void);


void  CAN_Restruct(void)
{
    
    CAN_InitTypeDef        CAN_InitStructure;
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;

    /* CAN register init */
    CAN_DeInit(CAN2);
    CAN_StructInit(&CAN_InitStructure);

    /* CAN cell init */
    CAN_InitStructure.CAN_TTCM=DISABLE;
    CAN_InitStructure.CAN_ABOM=ENABLE; // it may be disable
    CAN_InitStructure.CAN_AWUM=DISABLE;
    CAN_InitStructure.CAN_NART=DISABLE;
    CAN_InitStructure.CAN_RFLM=DISABLE;
    CAN_InitStructure.CAN_TXFP=ENABLE;// it may be disable
    CAN_InitStructure.CAN_Mode=CAN_Mode_Normal;
    CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;  //1
    CAN_InitStructure.CAN_BS1=CAN_BS1_5tq;	//8
    CAN_InitStructure.CAN_BS2=CAN_BS2_3tq;	//7
    CAN_InitStructure.CAN_Prescaler=2; //1MHZ
    CAN_Init(CAN2, &CAN_InitStructure);

    
	/* CAN filter init */
    CAN_FilterInitStructure.CAN_FilterNumber=14;
    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;	   
    CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;
    CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FIFO0;
    CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);

    /* CAN FIFO0 message pending interrupt enable */ 
    CAN_ITConfig(CAN2, CAN_IT_FMP0, ENABLE);
   

}


/* Parse Can Message Source    **********************************************

Author : Alper Dedeoglu
File: cancomroutines.c
Date: 16.06.2015
Caution: 
Input Parameter: void
Return Value: void 
Description: Decides the source of the CAN message and calls the individual 
parser function. 

ITU SOLAR CAR TEAM         ******************************************************/



void ParseCanMessage(void)
{

		CanRxMsg CanRcvdMsg;
	  CanRcvdMsg =  CanTempMess;
  


	if(CanRcvdMsg.StdId == SW_CAN_BASE + SW_DRIVE_MEAS) 
	{
			canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
			canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
			canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
			canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
			canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
			canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
			canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
			canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];

			Velocity_Float   = canTempMess64.data_u32[0];
			Velocity = (u8)Velocity_Float;
			Regenative_Float = canTempMess64.data_u32[1];
			Regenative = (u16)Regenative_Float;
	}
			
		if(CanRcvdMsg.StdId == MC_CAN_BASE + MC_BUS) 
	{
		
			
		
		
			canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
			canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
			canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
			canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
			canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
			canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
			canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
			canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];

			BusVoltage_Float = canTempMess64.data_fp[0];
			BusVoltage = (u8)BusVoltage_Float;
			BusCurrent_Float = canTempMess64.data_fp[1];
			BusCurrent =	(u8)BusCurrent_Float;
			Power = BusVoltage*BusCurrent;
		
	}

	else if(CanRcvdMsg.StdId == MC_CAN_BASE + MC_TEMP1)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MotorTemp_Float =  canTempMess64.data_fp[0];   	// celcius
		MotorTemp = (u8)MotorTemp_Float;	
		HeatSinkTemp_Float = canTempMess64.data_fp[1];
		HeatSinkTemp = (u8)HeatSinkTemp_Float;
		
		
		
	}
	else if(CanRcvdMsg.StdId == SW_CAN_BASE + SW_DRIVE_FLAGS)
	{
		CC_Flag=CanRcvdMsg.Data[0];
		CC_Negative_Flag=CanRcvdMsg.Data[1];
		CC_Positive_Flag=CanRcvdMsg.Data[2];
		Drive_Flag=CanRcvdMsg.Data[3];		
		Neutral_Flag=CanRcvdMsg.Data[4];	 
		Reverse_Flag = CanRcvdMsg.Data[5]; 
		RightSignal_Flag=CanRcvdMsg.Data[6];
		LeftSignal_Flag=CanRcvdMsg.Data[7];
		
		
		
		if (Neutral_Flag == 1 && Reverse_Flag == 0 && Drive_Flag == 0){
			Shift_Status = 0;	
		}
		
		if (Neutral_Flag == 0 && Reverse_Flag == 1 && Drive_Flag == 0){
			Shift_Status = 1;	
		}
		
		if (Neutral_Flag == 0 && Reverse_Flag == 0 && Drive_Flag == 1){
			Shift_Status = 2;	
		}
		
	}
	
	else if(CanRcvdMsg.StdId == SW_CAN_BASE + SW_OTHER_FLAGS)
	{
		Solar_Flag=CanRcvdMsg.Data[0];
		Radio_Flag=CanRcvdMsg.Data[1];
		Emergency_Flag=CanRcvdMsg.Data[2];
		Horn_Flag=CanRcvdMsg.Data[3];
		Screen_Button_Flag=CanRcvdMsg.Data[4];
		Controller_Flag=CanRcvdMsg.Data[5];
		Controller_Negative_Flag=CanRcvdMsg.Data[6];
		Controller_Positive_Flag=CanRcvdMsg.Data[7];
		
		
			

			
	}
	
else if(CanRcvdMsg.StdId==0x151)
{
	
					canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
					canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
					canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
					canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
					canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
					canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
					canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
					canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
	
				
				  MaxVoltageFloat	=		canTempMess64.data_u16[1];
					Max_Voltage  	= 	(u16)MaxVoltageFloat / 30;
					Max_Voltage = (Max_Voltage-50);
				  MinVoltageFloat	=		canTempMess64.data_u16[0];
					Min_Voltage  =    (u16)MinVoltageFloat / 30;
					Min_Voltage = (Min_Voltage-50);
//				Min_temp		=				canTempMess64.data_u16[2];
//				Max_Temp		=				canTempMess64.data_u16[3];


}



else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_GROUP1_VOUT)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTGroup1Voltage_Double =  canTempMess64.data_d64;   	
		MPPTGroup1Voltage = (u8)MPPTGroup1Voltage_Double;			
		
		
		
	}
	
	
	else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_GROUP1_CURRENT)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTGroup1Current_Double =  canTempMess64.data_d64;   	
		MPPTGroup1Current = (u8)MPPTGroup1Current_Double;			
		
		
		
	}
	
	
	else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_GROUP1_TEMP)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTGroup1Temp_Double =  canTempMess64.data_d64;   	
		MPPTGroup1Temp = (u8)MPPTGroup1Temp_Double;			
		
		
		
	}

	
	else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_GROUP2_VOUT)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTGroup2Voltage_Double =  canTempMess64.data_d64;   	
		MPPTGroup2Voltage = (u8)MPPTGroup2Voltage_Double;			
		
		
		
	}
	
	
	else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_GROUP2_CURRENT)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTGroup2Current_Double =  canTempMess64.data_d64;   	
		MPPTGroup2Current = (u8)MPPTGroup2Current_Double;			
		
		
		
	}
	
	
	else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_GROUP2_TEMP)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTGroup2Temp_Double =  canTempMess64.data_d64;   	
		MPPTGroup2Temp = (u8)MPPTGroup2Temp_Double;			
		
		
		
	}
	
	
	else if(CanRcvdMsg.StdId == MPPT_CAN_BASE + MPPT_THIRD_TEMP)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		MPPTThirdTemp_Double =  canTempMess64.data_d64;   	
		MPPTThirdTemp = (u8)MPPTThirdTemp_Double;			
		
		
		
	}
	
	
	else if(CanRcvdMsg.StdId == BMS_CAN_BASE + BMS_CAN_CELL)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		
		EmusMinVoltage 		=  (u16)canTempMess64.data_u8[0];
		EmusMaxVoltage 		=  (u16)canTempMess64.data_u8[1];
		EmusAverageVoltage =  (u16)canTempMess64.data_u8[2];		
		
	
		
	}
	
	else if(CanRcvdMsg.StdId == BMS_CAN_BASE + BMS_CAN_TEMP_MODULE)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		
		EmusMinTemp 				=  (u16)canTempMess64.data_u8[0];
		EmusMaxTemp 				=  (u16)canTempMess64.data_u8[1];
		EmusAverageTemp		  =  (u16)canTempMess64.data_u8[2];		
		
	
		
	}
	
		else if(CanRcvdMsg.StdId == BMS_CAN_BASE + BMS_SOC)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		
		EmusEstimatedSOC 	= (u16)canTempMess64.data_u8[6];
			
	}
	
			else if(CanRcvdMsg.StdId == BMS_CAN_BASE + 0x45)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
		
		//Most significant byte of the event data. If data type is 0 (Event info), this byte contains the event ID. List of event IDs: 
	//0 – No event;
	//1 – BMS Started;
	//2 – Lost communication to cells;
	//3 – Established communication to cells; 
	//4 – Cells voltage critically low;
	//5 – Critical low voltage recovered;
	//6 – Cells voltage critically high; 
	//7 – Critical high voltage recovered;
	//8 – Discharge current critically high;
	//9 – Discharge critical high current recovered;
	//10 – Charge current critically high;
	//11 – Charge critical high current recovered; 
	//12 – Cell module temperature critically high;
	//13 – Critical high cell module temperature recovered; 
	//14 – Leakage detected; 
	//15 – Leakage recovered;
	//16– Warning: Low voltage - reducing power;
	//17 – Power reduction due to low voltage recovered;
	//18– Warning: High current - reducing power;
	//19 – Power reduction due to high current recovered;
	//20 – Warning: High cell module temperature - reducing power;
	//21 – Power reduction due to high cell module temperature recovered;
	//22 – Charger connected;
	//23 – Charger disconnected;
	//24 – Started pre-heating stage;
	//25 – Started pre-charging stage;
	//26 – Started main charging stage;
	//27 – Started balancing stage;
	//28 – Charging finished; 
	//29 – Charging error occurred;
	//30 – Retrying charging;
	//31 – Restarting charging;
	//42 – Cell temperature critically high;
	//43 – Critically high cell temperature recovered; 
	//44 – Warning: High cell temperature – reducing power; 
	//45 – Power reduction due to high cell temperature recovered;
	
		
		EmusEventNumber 	= (u16)canTempMess64.data_u8[2];
			
	}


	else if(CanRcvdMsg.StdId == 0x41)
	{
		
		canTempMess64.data_u8[0] = CanRcvdMsg.Data[0];
		canTempMess64.data_u8[1] = CanRcvdMsg.Data[1];
		canTempMess64.data_u8[2] = CanRcvdMsg.Data[2];
		canTempMess64.data_u8[3] = CanRcvdMsg.Data[3];
		canTempMess64.data_u8[4] = CanRcvdMsg.Data[4];
		canTempMess64.data_u8[5] = CanRcvdMsg.Data[5];
		canTempMess64.data_u8[6] = CanRcvdMsg.Data[6];
		canTempMess64.data_u8[7] = CanRcvdMsg.Data[7];
	
		
		EmusEstimatedSOC 	= (u16)canTempMess64.data_u8[0];
		deneme2						= (u16)canTempMess64.data_u8[1];
		deneme4						= (u16)canTempMess64.data_u8[2];
		deneme5						= (u16)canTempMess64.data_u8[3];
			
	}
	

}

void BrakeStatusSend(void)
{
		CanTxMsg	 BrakeStatus_CanTxMsg;
	
		BrakeStatus_CanTxMsg.StdId		= MOC_CAN_BASE + MOC_BUTTON_STATUS;
    BrakeStatus_CanTxMsg.IDE			= CAN_ID_STD; 
    BrakeStatus_CanTxMsg.RTR			= CAN_RTR_DATA;
    BrakeStatus_CanTxMsg.DLC			= 4;
		
    BrakeStatus_CanTxMsg.Data[0] = Brake_Flag;
		BrakeStatus_CanTxMsg.Data[1] = 0;
		BrakeStatus_CanTxMsg.Data[2] = 0;
		BrakeStatus_CanTxMsg.Data[3] = 0;

    CAN_Transmit(CAN2, &BrakeStatus_CanTxMsg);
}


void ContactorControl(void)
{
		CanTxMsg	ContactorControl_CanTxMsg;
	
		ContactorControl_CanTxMsg.StdId		= 0x00;
		ContactorControl_CanTxMsg.ExtId		= 0x00;
    ContactorControl_CanTxMsg.IDE			= CAN_ID_STD; 
    ContactorControl_CanTxMsg.RTR			= CAN_RTR_DATA;
    ContactorControl_CanTxMsg.DLC			= 8;
		
    ContactorControl_CanTxMsg.Data[0] = 0x31 ;
		ContactorControl_CanTxMsg.Data[1] = 0 ;
		ContactorControl_CanTxMsg.Data[2] = 0 ;
		ContactorControl_CanTxMsg.Data[3] = 0 ;
		ContactorControl_CanTxMsg.Data[4] = 0 ;
		ContactorControl_CanTxMsg.Data[5] = 0 ;
		ContactorControl_CanTxMsg.Data[6] = 0 ;
		ContactorControl_CanTxMsg.Data[7] = 0 ;
		
    CAN_Transmit(CAN2, &ContactorControl_CanTxMsg);
}



