#include "stm32f4xx.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int string[4];



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
	EXTI_Restruct();
	TIM_Restruct();
	CAN_Restruct(); 
	USART1_Restruct();	
	USART3_Restruct();		
	USART6_Restruct();		
	NVIC_Restruct();
	
}



