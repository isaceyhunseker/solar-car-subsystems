#include "stm32f4xx.h"                  // Device header
#include "math.h"
#include "common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


uint16_t MonitorRxBuffer[8];
uint8_t NbrOfDataToTransfer = 8;
uint8_t NbrOfDataToRead = 8;
__IO uint8_t MonitorTxCounter = 0; 
__IO uint16_t MonitorRxCounter = 0;
	
extern CanRxMsg CanTempMess;

void Flashor(void);
void LeftSignal(void);
void RightSignal(void);

uint64_t GelenCANID;
int Regencounter;
int Velocitycounter;
int testintusart3 ;
int RcvdMonitor ; 
int testintusart1;
uint8_t RcvdWifi;

int intflag=0;	

char testcharusart6;
char *velusartchar[1];

u8 Brake_Flag = 0;
u8 SignalCounter = 0;

char testint ;
int intdata ;
int usartflag;
char *received;
char *usartdatas;
char usartdata;


uint32_t usartdelay;


void CAN2_RX0_IRQHandler(void){

	CanRxMsg CanRcvdMsg;
	
	if(CAN_GetITStatus(CAN2, CAN_IT_FF0))
		CAN_ClearITPendingBit(CAN2, CAN_IT_FF0);
	else if(CAN_GetITStatus(CAN2, CAN_IT_FOV0))
		CAN_ClearITPendingBit(CAN2, CAN_IT_FOV0);
	else
	{
		CanRcvdMsg.StdId = 0x00;
		CanRcvdMsg.ExtId = 0x00;
		CanRcvdMsg.IDE = 0;
		CanRcvdMsg.DLC = 0;
		CanRcvdMsg.FMI = 0;
		
		CanRcvdMsg.Data[0] = 0x00;
		CanRcvdMsg.Data[1] = 0x00;
		CanRcvdMsg.Data[2] = 0x00;
		CanRcvdMsg.Data[3] = 0x00;
		CanRcvdMsg.Data[4] = 0x00;
		CanRcvdMsg.Data[5] = 0x00;
		CanRcvdMsg.Data[6] = 0x00;
		CanRcvdMsg.Data[7] = 0x00;
		
		CAN_Receive(CAN2, CAN_FIFO0, &CanRcvdMsg);
		CanTempMess = CanRcvdMsg;
		GelenCANID = CanTempMess.StdId; 
		if(GelenCANID == 0x00){
		
		GPIO_SetBits(Buzzer_Port, Buzzer_Pin);
		
		}
		
		else {
		
		GPIO_ResetBits(Buzzer_Port, Buzzer_Pin);
		
		}
 		ParseCanMessage();
	}

}


void EXTI0_IRQHandler(){
	
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
    {
		
	    EXTI_ClearITPendingBit(EXTI_Line0);	
			 
			GPIO_SetBits(Horn_Port,Horn_Pin);
			GPIO_SetBits(GreenLed_Port,GreenLed_Pin);
			ContactorFlag = 0x00;
			ContactorControl();
			Horn_Flag = 1;
					
			
	}
}

void EXTI1_IRQHandler(){

if(EXTI_GetITStatus(EXTI_Line1) != RESET)
    {
			
			EXTI_ClearITPendingBit(EXTI_Line1);
			GPIO_ResetBits(Horn_Port,Horn_Pin);
			GPIO_ResetBits(GreenLed_Port,GreenLed_Pin);
			ContactorFlag = 0x01;
			ContactorControl();
			Horn_Flag = 0;						

}
}

void EXTI2_IRQHandler(){
	
	if(EXTI_GetITStatus(EXTI_Line2) != RESET){
		
				EXTI_ClearITPendingBit(EXTI_Line2);
				Brake_Flag = 1;
				GPIO_SetBits(BlueLed_Port, BlueLed_Pin);
				}
	else{
				Brake_Flag = 0;
				GPIO_ResetBits(BlueLed_Port, BlueLed_Pin);

			}							
}


	
void EXTI9_5_IRQHandler(){


		
		if(EXTI_GetITStatus(EXTI_Line8) != RESET)
    {
		
		EXTI_ClearITPendingBit(EXTI_Line8);
		

			
			
		}
	
		if(EXTI_GetITStatus(EXTI_Line9) != RESET)
    {
		EXTI_ClearITPendingBit(EXTI_Line9);
//		GPIO_ToggleBits(Buzzer_Port,Buzzer_Pin);
		}

}



	
void TIM2_IRQHandler(){

		if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
			TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		
		if((LeftSignal_Flag == 0) && (RightSignal_Flag == 0) && (Emergency_Flag == 0)){
		GPIO_ResetBits(Buzzer_Port,Buzzer_Pin);
			GPIO_ResetBits(RightSignal_Port,RightSignal_Pin);
			GPIO_ResetBits(LeftSignal_Port,LeftSignal_Pin);
			
		}
		
		
		
			if(Radio_Flag == 1){
				GPIO_SetBits(Radio_Port, Radio_Pin);
				}
			
			else if(Radio_Flag == 0){
			GPIO_ResetBits(Radio_Port, Radio_Pin);
				}
				
				
			//BrakeStatusSend();
			 
			if ((LeftSignal_Flag == 1)&&(Emergency_Flag==0)&&(RightSignal_Flag==0 )){
					LeftSignal();
					}	
		
			if ((RightSignal_Flag == 1)&&(Emergency_Flag==0)&&(LeftSignal_Flag==0 )){ 
				  RightSignal();  
					}			

			if (Emergency_Flag==1){
					Flashor();
					}
		
					
					
			if (usartdelay == 3){
					//SendUSBData();
					//SendWifiData();
				SendMonitorData();
					
					usartdelay = 0;
		  }
				
				usartdelay++;
			if (SignalCounter==150){
						SignalCounter=0;    
						} 
	}
}

// Datas from Monitor 
void USART6_IRQHandler(){
	
 if(USART_GetITStatus(USART6, USART_IT_RXNE) != RESET){
	 	USART_ClearITPendingBit(USART6, USART_IT_RXNE);	 
		RcvdMonitor	= (char)USART_ReceiveData(USART6) + '0'- 48;
			 
  }


}




void USART3_IRQHandler(){
	// Datas from USB 
 if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
  
 { 
			USART_ClearITPendingBit(USART3, USART_IT_RXNE);
				testintusart3	= USART_ReceiveData(USART3);
  }


}




void USART1_IRQHandler(){
	// Datas from Wifi Modem	
 if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){ 
		
			USART_ClearITPendingBit(USART1, USART_IT_RXNE);	 
			RcvdWifi	= (char)USART_ReceiveData(USART1) + '0'- 48;
   
  


	}
}

void LeftSignal(void)	
{

		if (SignalCounter<=75)
		{ 
		 GPIO_SetBits(LeftSignal_Port,LeftSignal_Pin);
		 GPIO_SetBits(Buzzer_Port, Buzzer_Pin);	
		 GPIO_ResetBits(RightSignal_Port,RightSignal_Pin);

			

		}
		else if (75<SignalCounter && SignalCounter<150)
		{ 
			GPIO_ResetBits(LeftSignal_Port,LeftSignal_Pin);
			GPIO_ResetBits(Buzzer_Port, Buzzer_Pin);	
   		GPIO_ResetBits(RightSignal_Port,RightSignal_Pin);

			
		} 
 SignalCounter++;
}

void RightSignal(void)
{
		if (SignalCounter<=75)
			 { 
					GPIO_SetBits(RightSignal_Port,RightSignal_Pin);
					GPIO_SetBits(Buzzer_Port, Buzzer_Pin);	
			    GPIO_ResetBits(LeftSignal_Port,LeftSignal_Pin);	 
			 }
	
		else if (75<SignalCounter && SignalCounter<150)
			{ 
					GPIO_ResetBits(RightSignal_Port,RightSignal_Pin);
					GPIO_ResetBits(Buzzer_Port, Buzzer_Pin);	
					GPIO_ResetBits(LeftSignal_Port,LeftSignal_Pin);
			}
		SignalCounter++;
}

void Flashor(void)
	
{
	
	if (SignalCounter<=75)
			{ 
				GPIO_SetBits(RightSignal_Port,RightSignal_Pin);
				GPIO_SetBits(LeftSignal_Port,LeftSignal_Pin);
				 
		  }
		 else if (75<SignalCounter && SignalCounter<150)
			{ 
			  GPIO_ResetBits(RightSignal_Port,RightSignal_Pin);
				GPIO_ResetBits(LeftSignal_Port,LeftSignal_Pin);		
	       
			} 
		SignalCounter++;		
			
}

