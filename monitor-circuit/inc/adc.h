#include <string.h>
#include "stm32F4xx.h"                  
//#include "common.h"


#define GasPot_Channel							ADC_Channel_13
#define NumberOfADC_Conversion      1


#define ADC_OPERATING_VOLTAGE 3.3
#define ADC_QUANTA_COUNT			4096
#define ADC_TO_VOLTAGE(x)	((float)x)*ADC_OPERATING_VOLTAGE/ADC_QUANTA_COUNT

extern uint16_t ADC_ValueArray[NumberOfADC_Conversion];
				
