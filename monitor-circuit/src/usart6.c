#include "stm32f4xx.h"
#include "string.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void GenerateTempMax(void);
void GenerateSignal(void);
void SendMonitorData(void);

typedef struct {
	char MonitorTxBuffer[100];
	char DataGroup[4];
	
	} MonitorStructPrototype;

	

u16 CheckInteger;
	
	
	
u16 currentstateofdatas ;
u8 StartConditionValue = 123;
u8 monitorcount = 0;
u32 datagroup1;
u16	CC_FlagArray;
u16	DummyByte;
u16	BusCurrentArray;
u16	BusCurrentArray2;
	
u8 Signal_Status =0;

	
double testdouble;

//u16 DataGroup[4];

void USART6_Restruct(void)
{	
USART_InitTypeDef USART_InitStructure;
USART_InitStructure.USART_BaudRate						= 115200;		// this value influence with noise
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
USART_InitStructure.USART_Mode								= USART_Mode_Rx | USART_Mode_Tx;
USART_InitStructure.USART_Parity 							= USART_Parity_No; 	
USART_InitStructure.USART_StopBits						= USART_StopBits_1;
USART_InitStructure.USART_WordLength					= USART_WordLength_8b;  	
USART_Init(USART6, &USART_InitStructure);
	
USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);	
USART_Cmd(USART6, ENABLE); 	

}
 


void SendMonitorData(void){
	
		Regenative = 92;
		BusVoltage = 167;		
		GenerateTempMax();
		GenerateSignal();
		MonitorStructPrototype MonitorStruct;
		
		
		if(MotorTemp > 140){
		MotorTemp = MotorTemp/10;
		}
		MPPTGroup1Current = 278;
		MPPTGroup2Current = 712;
		
	 
		
		MonitorStruct.MonitorTxBuffer[0]  = CheckInteger;// value of regenative
		
		MonitorStruct.MonitorTxBuffer[1]  = Velocity ; // velocity of car  
		MonitorStruct.MonitorTxBuffer[2]  = Regenative; // value of regenative
		MonitorStruct.MonitorTxBuffer[3]  = Signal_Status; // status of right signal
	//MonitorStruct.MonitorTxBuffer[4]  = LeftSignal_Flag ; // status of left signal
		MonitorStruct.MonitorTxBuffer[5]  = Horn_Flag; // Horn status
		MonitorStruct.MonitorTxBuffer[6]  = CC_Flag; // Cruise control status
		MonitorStruct.MonitorTxBuffer[7]  = CC_Negative_Flag; // Cruise control negative status
		MonitorStruct.MonitorTxBuffer[8]  = CC_Positive_Flag; // Cruise control positive status
	  MonitorStruct.MonitorTxBuffer[9]  = Controller_Flag; // Controller status
		MonitorStruct.MonitorTxBuffer[10] = Controller_Negative_Flag; // Controller_Negative_status
		MonitorStruct.MonitorTxBuffer[11] = Controller_Positive_Flag; // Controller_Positive status
		MonitorStruct.MonitorTxBuffer[12] = Solar_Flag; // Solar System relay status
		MonitorStruct.MonitorTxBuffer[13] = Emergency_Flag; // Emergency status
		MonitorStruct.MonitorTxBuffer[14] = Screen_Button_Flag; // Screen_Button status
		MonitorStruct.MonitorTxBuffer[15] = EmusMaxVoltage; // Minimum cell voltage 
		MonitorStruct.MonitorTxBuffer[16] = EmusMinVoltage; // Maximum cell voltage
		MonitorStruct.MonitorTxBuffer[17] = EmusMinTemp-100; // Minimum temperature
		MonitorStruct.MonitorTxBuffer[18] = EmusMaxTemp-100; // Maximum temerature 
//	MonitorStruct.MonitorTxBuffer[15] = Max_Voltage; // Minimum cell voltage 
//	MonitorStruct.MonitorTxBuffer[16] = Min_Voltage; // Maximum cell voltage
//	MonitorStruct.MonitorTxBuffer[17] = Min_Temp; // Minimum temperature
//	MonitorStruct.MonitorTxBuffer[18] = Max_Temp; // Maximum temerature 
		MonitorStruct.MonitorTxBuffer[19] = Radio_Flag; // Radio status
		MonitorStruct.MonitorTxBuffer[20] = BusVoltage; // Bus Voltage
		MonitorStruct.MonitorTxBuffer[21] = Power; // Bus Current
		MonitorStruct.MonitorTxBuffer[22] = BusCurrent; // Radio status
		MonitorStruct.MonitorTxBuffer[23] = MotorTemp; //Motor Temp
		MonitorStruct.MonitorTxBuffer[24] = MPPTGroup1Current/3;
		MonitorStruct.MonitorTxBuffer[25] = MPPTGroup2Current/3;
		MonitorStruct.MonitorTxBuffer[26] = MPPTMaxTemp;
		MonitorStruct.MonitorTxBuffer[27] = Shift_Status;
		MonitorStruct.MonitorTxBuffer[28] = EmusEstimatedSOC;
		
		
				 
				
				
				currentstateofdatas	= MonitorStruct.MonitorTxBuffer[RcvdMonitor];//	MonitorStruct.DataGroup[RcvdMonitor];
				USART_SendData(USART6,MonitorStruct.MonitorTxBuffer[RcvdMonitor]);//MonitorStruct.DataGroup[RcvdMonitor]);
				
			
}


void GenerateTempMax(void){

	if((MPPTGroup1Temp >= MPPTGroup2Temp) && (MPPTGroup1Temp >= MPPTThirdTemp)){
		MPPTMaxTemp = MPPTGroup1Temp;
		}
	
	else if((MPPTGroup2Temp > MPPTGroup1Temp) && (MPPTGroup2Temp >= MPPTThirdTemp)){
		MPPTMaxTemp = MPPTGroup2Temp;
		}
	
	else if((MPPTThirdTemp > MPPTGroup1Temp) && (MPPTThirdTemp > MPPTGroup2Temp)){
		MPPTMaxTemp = MPPTThirdTemp;
		}
}


void GenerateSignal(void){

	if(RightSignal_Flag ==1 && LeftSignal_Flag ==0 && Emergency_Flag==0)
		{	
			Signal_Status = 1;
		}

	else if(RightSignal_Flag ==0 && LeftSignal_Flag ==1 && Emergency_Flag==0)
		{	
			Signal_Status = 2;
		}
		
	else if(RightSignal_Flag ==0 && LeftSignal_Flag ==0 && Emergency_Flag==1)
		{	
			Signal_Status = 3;
		}	

}


