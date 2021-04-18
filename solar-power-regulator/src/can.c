#include "stm32f4xx.h"                  // Device header
#include "can.h"
#include "Common.h"
#include "gpio.h"

CanRxMsg CanTempMess;
group_64 canTempMess64;
group_32 canTempMess32;

uint8_t Solar_Flag = 0;									// Flag for Solar Button
uint8_t RSignal_Flag=0;									// Flag for Right Signal		
uint8_t LSignal_Flag=0;						  		// Flag for Left Signal	
uint8_t Emergency_Flag = 0;             // Flag for Emergency
uint8_t Brake_Flag = 0;         				// Flag for Brake Status

void CAN_Restruct(){
    
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
    CAN_InitStructure.CAN_BS1=CAN_BS1_8tq;	//8
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

void RcvCANMessage(void){
	
	CanRxMsg         CanIncomingMsg;
  CanIncomingMsg = CanTempMess;

  if(CanIncomingMsg.StdId == 0x201)
	{
		// If MPPT Drive Left or Right Signal
			RSignal_Flag =CanIncomingMsg.Data[6];
//		LSignal_Flag =CanIncomingMsg.Data[7];
	}	
 
	else if(CanIncomingMsg.StdId == 0x202)
	{
		Solar_Flag     = CanIncomingMsg.Data[0];
  	Emergency_Flag = CanIncomingMsg.Data[2];
		
		if(Solar_Flag == 1){		
			GPIO_SetBits(GPIOA, GPIO_Pin_5);			
		}	
		
		else if(Solar_Flag == 0){
		
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			
		}			
	}
	
			if(CanIncomingMsg.StdId == 0x0350)
	{
		//  Brake_Flag =   CanIncomingMsg.Data[0];		
		
		// If MPPT drive stop Lamb.
		
		//if(Brake_Flag == 1){GPIO_SetBits(Signal_Port,Signal_Pin);}
		//else{GPIO_ResetBits(Signal_Port,Signal_Pin);}
	}

}


void Send_Vout_MPPT(void)
	{
		 CanTxMsg Vout_MPPT_CanTxMsg;	
		
		canTempMess64.data_d64 = Vout_MPPT;

     Vout_MPPT_CanTxMsg.StdId		= 0x250;
     Vout_MPPT_CanTxMsg.IDE			= CAN_ID_STD; 
     Vout_MPPT_CanTxMsg.RTR			= CAN_RTR_DATA;
     Vout_MPPT_CanTxMsg.DLC			= 8;
		
     Vout_MPPT_CanTxMsg.Data[0] = canTempMess64.data_u8[0];
		 Vout_MPPT_CanTxMsg.Data[1] = canTempMess64.data_u8[1];
		 Vout_MPPT_CanTxMsg.Data[2] = canTempMess64.data_u8[2];
		 Vout_MPPT_CanTxMsg.Data[3] = canTempMess64.data_u8[3];
		 Vout_MPPT_CanTxMsg.Data[4] = canTempMess64.data_u8[4];
		 Vout_MPPT_CanTxMsg.Data[5] = canTempMess64.data_u8[5];
		 Vout_MPPT_CanTxMsg.Data[6] = canTempMess64.data_u8[6];
		 Vout_MPPT_CanTxMsg.Data[7] = canTempMess64.data_u8[7];

     CAN_Transmit(CAN2,&Vout_MPPT_CanTxMsg);
}
	

void Send_ADC_V(void)
	{
		 CanTxMsg ADC_V_CanTxMsg;
		
		canTempMess64.data_d64 = ADC_V;

     ADC_V_CanTxMsg.StdId		= 0x262;
     ADC_V_CanTxMsg.IDE			= CAN_ID_STD; 
     ADC_V_CanTxMsg.RTR			= CAN_RTR_DATA;
     ADC_V_CanTxMsg.DLC			= 8;
		
     ADC_V_CanTxMsg.Data[0] = canTempMess64.data_u8[0];
		 ADC_V_CanTxMsg.Data[1] = canTempMess64.data_u8[1];
		 ADC_V_CanTxMsg.Data[2] = canTempMess64.data_u8[2];
		 ADC_V_CanTxMsg.Data[3] = canTempMess64.data_u8[3];
		 ADC_V_CanTxMsg.Data[4] = canTempMess64.data_u8[4];
		 ADC_V_CanTxMsg.Data[5] = canTempMess64.data_u8[5];
		 ADC_V_CanTxMsg.Data[6] = canTempMess64.data_u8[6];
		 ADC_V_CanTxMsg.Data[7] = canTempMess64.data_u8[7];

     CAN_Transmit(CAN2,&ADC_V_CanTxMsg);
}
	

void Send_Current_MPPT(void)
	{
		 CanTxMsg Current_MPPT_CanTxMsg;
			
		canTempMess64.data_d64 = Current_MPPT;

     Current_MPPT_CanTxMsg.StdId		= 0x251;
     Current_MPPT_CanTxMsg.IDE			= CAN_ID_STD; 
     Current_MPPT_CanTxMsg.RTR			= CAN_RTR_DATA;
     Current_MPPT_CanTxMsg.DLC			= 8;
		
     Current_MPPT_CanTxMsg.Data[0] = canTempMess64.data_u8[0];
		 Current_MPPT_CanTxMsg.Data[1] = canTempMess64.data_u8[1];
		 Current_MPPT_CanTxMsg.Data[2] = canTempMess64.data_u8[2];
		 Current_MPPT_CanTxMsg.Data[3] = canTempMess64.data_u8[3];
		 Current_MPPT_CanTxMsg.Data[4] = canTempMess64.data_u8[4];
		 Current_MPPT_CanTxMsg.Data[5] = canTempMess64.data_u8[5];
		 Current_MPPT_CanTxMsg.Data[6] = canTempMess64.data_u8[6];
		 Current_MPPT_CanTxMsg.Data[7] = canTempMess64.data_u8[7];

     CAN_Transmit(CAN2,&Current_MPPT_CanTxMsg);
}


void Send_Temp_MPPT(void)
	{	
		 CanTxMsg Temp_MPPT_CanTxMsg;	
		
		canTempMess64.data_d64 = Temp_MPPT;

     Temp_MPPT_CanTxMsg.StdId		= 0x252;
     Temp_MPPT_CanTxMsg.IDE			= CAN_ID_STD; 
     Temp_MPPT_CanTxMsg.RTR			= CAN_RTR_DATA;
     Temp_MPPT_CanTxMsg.DLC			= 8;
		
     Temp_MPPT_CanTxMsg.Data[0] = canTempMess64.data_u8[0];
		 Temp_MPPT_CanTxMsg.Data[1] = canTempMess64.data_u8[1];
		 Temp_MPPT_CanTxMsg.Data[2] = canTempMess64.data_u8[2];
		 Temp_MPPT_CanTxMsg.Data[3] = canTempMess64.data_u8[3];
		 Temp_MPPT_CanTxMsg.Data[4] = canTempMess64.data_u8[4];
		 Temp_MPPT_CanTxMsg.Data[5] = canTempMess64.data_u8[5];
		 Temp_MPPT_CanTxMsg.Data[6] = canTempMess64.data_u8[6];
		 Temp_MPPT_CanTxMsg.Data[7] = canTempMess64.data_u8[7];

     CAN_Transmit(CAN2,&Temp_MPPT_CanTxMsg);
}
