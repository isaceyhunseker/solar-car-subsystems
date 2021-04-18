#include "stm32f4xx.h"
#include "tim.h"
#include "common.h"

void TIM_Restruct (void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	/* Step 0: 1Mhz=1000000 Hz */ 
	/* Step 1: 50Mhz / (1999 + 1) = 25000Hz */
	/* Step 2: 25000Hz / (249+1) = 100Hz (10ms) */

	/*Time base configuration for 0.01 sn */
	TIM_TimeBaseStructure.TIM_Period		 		= 9;
	TIM_TimeBaseStructure.TIM_Prescaler	 		= 23999;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode		= TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit (TIM2, &TIM_TimeBaseStructure);
	

	TIM_Cmd(TIM2, ENABLE);
		
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
}
