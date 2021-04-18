#include "stm32f4xx.h" 
#include "spi.h"
#include "common.h"

void SPI_Restruct(void)
{
	
	SPI_InitTypeDef SPI_InitStructure;
	
	SPV1020_CS_HIGH();
	
	SPI_I2S_DeInit(SPI3);
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	SPI_InitStructure.SPI_CPHA 							= SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CPOL							= SPI_CPOL_High;
	SPI_InitStructure.SPI_DataSize 					= SPI_DataSize_8b;
	SPI_InitStructure.SPI_Direction					= SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit					= SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode 							= SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS 							= SPI_NSS_Soft|SPI_NSSInternalSoft_Set;
	
	SPI_Init(SPI3, &SPI_InitStructure);

	SPI_Cmd(SPI3, ENABLE);	

}	


