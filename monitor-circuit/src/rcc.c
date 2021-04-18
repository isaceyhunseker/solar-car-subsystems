#include "stm32f4xx.h"
#include <string.h>
#include "rcc.h"

void RCC_Restruct(void)
{	
	ErrorStatus HSEStartUpStatus;
	
	RCC_DeInit();											// RCC system reset(for debug purpose)
	
	RCC_HSEConfig(RCC_HSE_ON);							// Enable HSE
	HSEStartUpStatus = RCC_WaitForHSEStartUp();	// Wait till HSE is ready
	
		if(HSEStartUpStatus == SUCCESS)
	{		
		FLASH_PrefetchBufferCmd(ENABLE);		// Enable Prefetch Buffer

		FLASH_SetLatency(FLASH_Latency_2);	// Flash 2 wait state
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);		// HCLK = SYSCLK		
		RCC_PCLK2Config(RCC_HCLK_Div2);		// PCLK2 = HCLK / 2
		RCC_PCLK1Config(RCC_HCLK_Div4);		// PCLK1 = HCLK / 4
	//	RCC_ADCCLKConfig(RCC_PCLK2_Div4); 
		

		RCC_PLLConfig(RCC_PLLSource_HSE,8,288,4,4);	//  PLLCLK = 96MHz 
		RCC_PLLCmd(ENABLE);													// Enable PLL

		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)			// Wait till PLL is ready
		{
		}

		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);					// Select PLL as system clock source

		while(RCC_GetSYSCLKSource() != 0x08)							// Wait till PLL is used as system clock source
		{
		}
	}


RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);	
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);  
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);		
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);	
RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE); 
RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);	 	
RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC, ENABLE);	


	

	
}

