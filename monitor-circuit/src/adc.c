#include "adc.h"



//void ADC_Config(void){


//	ADC_InitTypeDef ADC_InitStructure;
//	DMA_InitTypeDef DMA_InitStructure;
//	ADC_CommonInitTypeDef ADC_CommonInitStructure;


//	DMA_DeInit(DMA2_Stream0);
//	DMA_InitStructure.DMA_Memory0BaseAddr    = (uint32_t)&ADC_ValueArray;
//	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
//	DMA_InitStructure.DMA_BufferSize         = NumberOfADC_Conversion;
//	DMA_InitStructure.DMA_Channel            = DMA_Channel_0;
//	DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralToMemory;
//	DMA_InitStructure.DMA_FIFOMode           = DMA_FIFOMode_Disable;
//	DMA_InitStructure.DMA_FIFOThreshold      = DMA_FIFOThreshold_HalfFull;
//	DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
//	DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
//	DMA_InitStructure.DMA_Mode               = DMA_Mode_Circular;
//	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
//	DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
//	DMA_InitStructure.DMA_Priority           = DMA_Priority_High;
//	DMA_InitStructure.DMA_MemoryBurst        = DMA_MemoryBurst_Single;
//	DMA_InitStructure.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single;

//	DMA_Init(DMA2_Stream0, &DMA_InitStructure);
//	DMA_Cmd(DMA2_Stream0, ENABLE); 
//	
//	ADC_DeInit();
//	ADC_CommonInitStructure.ADC_Mode             = ADC_Mode_Independent;
//	ADC_CommonInitStructure.ADC_Prescaler        = ADC_Prescaler_Div4;
//	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
//	ADC_CommonInitStructure.ADC_DMAAccessMode    = ADC_DMAAccessMode_Disabled;
//	ADC_CommonInit(&ADC_CommonInitStructure);
//	
//	
//	ADC_InitStructure.ADC_ContinuousConvMode   = ENABLE;
//	ADC_InitStructure.ADC_DataAlign            = ADC_DataAlign_Right;
//	ADC_InitStructure.ADC_ExternalTrigConv     = DISABLE;
//	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
//	ADC_InitStructure.ADC_NbrOfConversion      = NumberOfADC_Conversion;
//	ADC_InitStructure.ADC_Resolution  	       = ADC_Resolution_12b;
//	ADC_InitStructure.ADC_ScanConvMode         = ENABLE;
//	ADC_Init(ADC1,&ADC_InitStructure);
//	
//	ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
//	ADC_DMACmd(ADC1, ENABLE);
//	ADC_Cmd(ADC1, ENABLE);

//	ADC_RegularChannelConfig(ADC1,GasPot_Channel, 1, ADC_SampleTime_480Cycles);
//	


//    ADC_SoftwareStartConv(ADC1);

//}