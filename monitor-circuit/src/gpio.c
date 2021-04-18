#include "stm32f4xx.h"
#include "gpio.h"



void GPIO_Restruct(void)
	
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = RightSignal_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(RightSignal_Port, &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = LeftSignal_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(LeftSignal_Port, &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = Buzzer_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(Buzzer_Port, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = Monitor_Tx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(Monitor_Tx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource11,GPIO_AF_USART6);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = Monitor_Rx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(Monitor_Rx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource12,GPIO_AF_USART6);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_Pin   = Wifi_Reset_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(Wifi_Reset_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = Wifi_Tx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(Wifi_Tx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_USART1);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = Wifi_Rx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(Wifi_Rx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_USART1);
	
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = GreenLed_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GreenLed_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = BlueLed_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(BlueLed_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = Radio_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(Radio_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin 	= Can_Rx_Pin;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
		GPIO_Init(Can_Rx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_CAN2);

		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = Can_Tx_Pin;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Can_Tx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_CAN2);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;	
		GPIO_InitStructure.GPIO_Pin   = Button4_Pin;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Button4_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_Pin   = Button3_Pin;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Button3_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_Pin   = Brake_Pin;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Brake_Port, &GPIO_InitStructure);
		
	// ADC GPIO CONFIG 
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
		GPIO_InitStructure.GPIO_Pin   = GasPot_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GasPot_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = Radio_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(Radio_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_Pin   = Button2_Pin;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Button2_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_Pin   = Button1_Pin;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(Button1_Port, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = USB_Tx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(USB_Tx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_USART3);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_Pin   = USB_Rx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(USB_Rx_Port, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_USART3);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = RedLed_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(RedLed_Port, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Pin   = Horn_Pin;
	  GPIO_InitStructure.GPIO_OType =	GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(Horn_Port, &GPIO_InitStructure);
		
		SYSCFG_EXTILineConfig(EXTI_PortSourceButton1_Port,EXTI_PinSourceButton1_Pin);
		SYSCFG_EXTILineConfig(EXTI_PortSourceButton2_Port,EXTI_PinSourceButton2_Pin);
		SYSCFG_EXTILineConfig(EXTI_PortSourceButton3_Port,EXTI_PinSourceButton3_Pin);
		SYSCFG_EXTILineConfig(EXTI_PortSourceButton4_Port,EXTI_PinSourceButton4_Pin);
		SYSCFG_EXTILineConfig(EXTI_PortSourceBrake_Port,EXTI_PinSourceBrake_Pin);

	
		

	
}
