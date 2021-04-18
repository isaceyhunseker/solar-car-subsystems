#include "stm32f4xx.h"
#include "string.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SendWifiData(void);

typedef struct {
	char WifiStruct[24];
	} WifiStructPrototype;

u8 currentstateofdatawifi = 0;
//u8 StartConditionValue = 123;
u8 wificount = 0;



void USART1_Restruct(void)
{	
USART_InitTypeDef USART_InitStructure;

USART_InitStructure.USART_BaudRate						= 9600;		// this value influence with noise
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
USART_InitStructure.USART_Mode								= USART_Mode_Rx | USART_Mode_Tx;
USART_InitStructure.USART_Parity 							= USART_Parity_No; 	
USART_InitStructure.USART_StopBits						= USART_StopBits_1;
USART_InitStructure.USART_WordLength					= USART_WordLength_8b;  	
USART_Init(USART1, &USART_InitStructure);
	
USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
USART_Cmd(USART1, ENABLE); 	
	
}



void SendWifiData(void){

		WifiStructPrototype WifiStruct;
	
		WifiStruct.WifiStruct[0]  = 11; // value of regenative
		WifiStruct.WifiStruct[1]  = Velocity ; // velocity of car  
		WifiStruct.WifiStruct[2]  = Regenative; // value of regenative
		WifiStruct.WifiStruct[3]  = RightSignal_Flag; // status of right signal
		WifiStruct.WifiStruct[4]  = LeftSignal_Flag ; // status of left signal
		WifiStruct.WifiStruct[5]  = Horn_Flag; // Horn status
		WifiStruct.WifiStruct[6]  = CC_Flag; // Cruise control status
		WifiStruct.WifiStruct[7]  = CC_Negative_Flag; // Cruise control negative status
		WifiStruct.WifiStruct[8]  = CC_Positive_Flag; // Cruise control positive status
	  WifiStruct.WifiStruct[9]  = Controller_Flag; // Controller status
		WifiStruct.WifiStruct[10]  = Controller_Negative_Flag; // Controller_Negative_status
		WifiStruct.WifiStruct[11] = Controller_Positive_Flag; // Controller_Positive status
		WifiStruct.WifiStruct[12] = Solar_Flag; // Solar System relay status
		WifiStruct.WifiStruct[13] = Emergency_Flag; // Emergency status
		WifiStruct.WifiStruct[14] = Screen_Button_Flag; // Screen_Button status
		WifiStruct.WifiStruct[15] = Min_Voltage; // Minimum cell voltage 
		WifiStruct.WifiStruct[16] = Max_Voltage; // Maximum cell voltage
		WifiStruct.WifiStruct[17] = Min_Temp; // Minimum temperature
		WifiStruct.WifiStruct[18] = Max_Temp; // Maximum temerature 
		WifiStruct.WifiStruct[19] = Radio_Flag; // Radio status
		WifiStruct.WifiStruct[20] = BusVoltage; // Bus Voltage
		WifiStruct.WifiStruct[21] = 4; // Bus Current
		WifiStruct.WifiStruct[22] = Power; // Radio status
		WifiStruct.WifiStruct[23] = MotorTemp; //Motor Temp
		
		 
		 
			 
			 
				 
				currentstateofdatawifi	=	WifiStruct.WifiStruct[21];
				USART_SendData(USART1,(u8)WifiStruct.WifiStruct[21]);
				
			
		 
		//USART_SendData(USART6,(u8)MonitorStruct.MonitorTxBuffer[RcvdMonitor]);//MonitorStruct.MonitorTxBuffer[RcvdMonitor]);
}




