#include "stm32f4xx.h"
#include "gpio.h"



void GPIO_Restruct(void)
	
{
GPIO_InitTypeDef GPIO_InitStructure;
		
		//SPI
		
		GPIO_InitStructure.GPIO_Pin = SCL_Pin | SDO_Pin | SDI_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);	
		
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_SPI3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_SPI3);
		
		
		GPIO_InitStructure.GPIO_Pin   = CS_Pin;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
		GPIO_Init( CS_Port, &GPIO_InitStructure );
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource4,GPIO_AF_SPI3);
		
		//OUT
		
		GPIO_InitStructure.GPIO_Pin   = VOUT_Relay_Pin;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	  GPIO_Init(VOUT_Relay_Port, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin   = Signal_Pin;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	  GPIO_Init(Signal_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin   = Alive_Led1_Pin;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	  GPIO_Init(Alive_Led1_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin   = Alive_Led2_Pin;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	  GPIO_Init(Alive_Led2_Port, &GPIO_InitStructure);
		
		//CAN
		
		GPIO_InitStructure.GPIO_Pin   = Can_Rx_Pin;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Can_Rx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(Can_Rx_Port, GPIO_PinSourceCanRx_Pin, GPIO_AF_CAN2);
		
		GPIO_InitStructure.GPIO_Pin   = Can_Tx_Pin;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Can_Tx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(Can_Tx_Port, GPIO_PortSourceCanTx_Pin, GPIO_AF_CAN2);
		
//		GPIO_InitStructure.GPIO_Pin   = Switch1_Pin;
//	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
//	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
//	  GPIO_Init(Switch1_Port, &GPIO_InitStructure);
//	
//		GPIO_InitStructure.GPIO_Pin   = Switch2_Pin;
//	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
//	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
//	  GPIO_Init(Switch2_Port, &GPIO_InitStructure);
//	
//		GPIO_InitStructure.GPIO_Pin   = Switch3_Pin;
//	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
//	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
//	  GPIO_Init(Switch3_Port, &GPIO_InitStructure);
//		
//		GPIO_InitStructure.GPIO_Pin   = Switch4_Pin;
//	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
//	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL; // Kullanilmayan pin
//	  GPIO_Init(Switch4_Port, &GPIO_InitStructure);
				
		//ADC
						
		GPIO_InitStructure.GPIO_Pin   = Temp_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(Temp_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin   = ADC_V_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(ADC_V_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin   = Current_ADC_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(Current_ADC_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin   = VOUT_MEAS_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(VOUT_MEAS_Port, &GPIO_InitStructure);
		
		//EXTI
		/*
SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);
SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource2);
SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource3);
*/	
}
