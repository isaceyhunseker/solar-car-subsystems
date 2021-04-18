#include "stm32f4xx.h"
#include "tim.h"
#include "common.h"

void TIM_Restruct (void)
{


	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	TIM_TimeBaseStructure.TIM_ClockDivision     = TIM_CKD_DIV2;
	TIM_TimeBaseStructure.TIM_CounterMode       = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period            = 4;
	TIM_TimeBaseStructure.TIM_Prescaler         = 31999;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_Cmd(TIM2, ENABLE);
		
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
}



