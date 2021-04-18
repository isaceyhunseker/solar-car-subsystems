#include "stm32f4xx.h"
#include "string.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SendUSBData(void);

typedef struct {
	u8 USBTxBuffer[8];
	} USBStructPrototype;

u8 usbcount = 0;	


void USART3_Restruct(void)
{	
USART_InitTypeDef USART_InitStructure;

USART_InitStructure.USART_BaudRate						= 9600;		// this value influence with noise
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
USART_InitStructure.USART_Mode								= USART_Mode_Rx | USART_Mode_Tx;
USART_InitStructure.USART_Parity 							= USART_Parity_No; 	
USART_InitStructure.USART_StopBits						= USART_StopBits_1;
USART_InitStructure.USART_WordLength					= USART_WordLength_8b;  	
USART_Init(USART3, &USART_InitStructure);
	
USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
USART_Cmd(USART3, ENABLE); 	
		
}


	




	void SendUSBData(void){

		USBStructPrototype USBStruct;
	
		USBStruct.USBTxBuffer[0] = RightSignal_Flag;
		USBStruct.USBTxBuffer[1] = LeftSignal_Flag;
		USBStruct.USBTxBuffer[2] = Velocity;
		USBStruct.USBTxBuffer[3] = Regenative;
		USBStruct.USBTxBuffer[4] = Horn_Flag;
		USBStruct.USBTxBuffer[5] = CC_Flag;
		USBStruct.USBTxBuffer[6] = Radio_Flag;
	
		while(usbcount >=0 && usbcount <=6 ){
		USART_SendData(USART3,USBStruct.USBTxBuffer[usbcount]);
		usbcount++;
		}	
		usbcount = 0 ;

		
		

}







