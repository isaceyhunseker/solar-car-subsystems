#include "stm32f4xx.h"
#include "nvic.h"

void NVIC_Restruct(void)
{
	NVIC_InitTypeDef	NVIC_InitStructure;
	
	
	NVIC_EnableIRQ(USART2_IRQn);
	
	NVIC_InitStructure.NVIC_IRQChannel 										= TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority 				= 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd 								= ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel                   = CAN2_RX0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x00;
	NVIC_Init(&NVIC_InitStructure);
	
//	NVIC_InitStructure.NVIC_IRQChannel                   = Switch1_Interrupt;
//  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x01;
//	NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel                   = Switch2_Interrupt;
//  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x01;
//	NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel                   = Switch3_Interrupt;
//  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x01;
//	NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel                   = Switch4_Interrupt;
//  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x01;
//	NVIC_Init(&NVIC_InitStructure);
	
		NVIC_EnableIRQ(TIM2_IRQn);
	  NVIC_EnableIRQ(CAN2_RX0_IRQn);
}	
