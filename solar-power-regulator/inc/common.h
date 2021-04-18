#include "stm32f4xx.h"
#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include "adc.h"

extern void GPIO_Restruct(void);
extern void RCC_Restruct(void);	
extern void CAN_Restruct(void);
extern void NVIC_Restruct(void);
extern void USART_Restruct(void);
extern void SPI_Restruct(void);
extern void TIM_Restruct(void);
extern void I2C1_Restruct(void);
extern void ADC_Restruct(void);
extern void EXTI_Restruct(void);


extern void USART_Prepare (USART_TypeDef* USARTx, volatile char *s);
extern void USART_Send(void);
extern uint32_t delay;

// SPI Stuffs
extern uint32_t SpiStartCnt;
extern void SPI_Tx(uint8_t adress, uint8_t data);
extern uint16_t SPI_Rx(uint8_t adress);
extern void SPI_Read(void);
extern void SPI_Begin(void);


extern void RcvCANMessage(void);
extern CanRxMsg CanTempMess;

extern uint16_t ADC_ValueArray[NumberOfADC_Conversion];

typedef struct
{
	double DataMPPTCurrentAnalogChannel;
	double DataThermistorAnalogChannel;
	double DataMPPT_VOUT_MEAS_AnalogChannel;
	double Data_ADC_V_AnalogChannel;
	double DataArrThermistorAnalogChannel[5];
	double DataArrMPPTCurrentAnalogChannel[5];
	double DataArr_MPPT_VOUT_MEAS_AnalogChannel[5];
	double DataArr_ADC_V_AnalogChannel[5];
  int    CntDataMPPTCurrentAnalogChannel;
	int 	 CntDataThermistorAnalogChannel;
	int  	 CntDataMPPT_VOUT_MEAS_AnalogChannel;
	int    CntData_ADC_V_AnalogChannel;

}TAnalog;

extern uint8_t Solar_Flag;									// Flag for Solar Button
extern uint8_t RSignal_Flag;								// Flag for Right Signal		
extern uint8_t LSignal_Flag;						 		// Flag for Left Signal	
extern uint8_t Emergency_Flag;              // Flag for Emergency

extern double Vout_MPPT;
extern double Current_MPPT;
extern double ADC_V; 
extern double Temp_MPPT;

extern void Send_Vout_MPPT(void);
extern void Send_ADC_V(void);
extern void Send_Current_MPPT(void);
extern void Send_Temp_MPPT(void);
