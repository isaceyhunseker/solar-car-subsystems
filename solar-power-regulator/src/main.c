#include "stm32f4xx.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

void Hardware_Restruct(void);

int main()
{
	Hardware_Restruct();

	
	while(1)
	{	
		
	}
}
	

void Hardware_Restruct(void)
{
	RCC_Restruct();
	GPIO_Restruct();
  ADC_Restruct();
//EXTI_Restruct();	
	TIM_Restruct();	
	CAN_Restruct();
	SPI_Restruct();
	NVIC_Restruct();
}

