#include "stm32f4xx.h"
#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>


// SPI Stuffs


// I2C Stuffs



extern void GPIO_Restruct(void);
extern void RCC_Restruct(void);	
extern void NVIC_Restruct(void);
extern void EXTI_Restruct(void);
extern void TIM_Restruct(void);
extern void CAN_Restruct(void);
extern void USART1_Restruct(void);
extern void USART3_Restruct(void);
extern void USART6_Restruct(void);



extern CanRxMsg CanTempMess;
extern void ParseCanMessage(void);

extern void USART_Sending (USART_TypeDef* USARTx, volatile char *s);
extern void Monitor_Data_Send(unsigned char veri);  
extern void USART_Send(void);

extern void SendUSBData(void);
extern void SendMonitorData(void);
extern void SendWifiData(void);
extern void USART_Puts(USART_TypeDef* USARTx, volatile char *s);
extern void USART3_PrepareSend(void);


extern void BrakeStatusSend(void);
extern void ContactorControl(void);

extern u16 CC_Flag;
extern u8 CC_Negative_Flag;
extern u8 CC_Positive_Flag;
extern u8 Controller_Flag;
extern u8 Controller_Negative_Flag;
extern u8 Controller_Positive_Flag;
extern u8 Solar_Flag;
extern u8 RightSignal_Flag;
extern u8 LeftSignal_Flag;
extern u8 Radio_Flag;
extern u8 Emergency_Flag;
extern u8 Horn_Flag;
extern u8 Screen_Button_Flag;
extern u8 Drive_Flag ;
extern u8 Neutral_Flag;
extern u8 Reverse_Flag ;
extern u16 ContactorFlag;

extern u16 currentstateofdatas;
extern int RcvdMonitor;
extern int testintusart3;
extern int testintusart6; 
extern int testintusart1;

extern u8 Brake_Flag;
extern u16 Regenative;
extern u8 Velocity;
extern u16 BusVoltage;
extern u16 BusCurrent;
extern u16 MotorTemp;
extern u8 Shift_Status;
extern u32 Power;


extern u16 Min_Voltage;
extern u16 Max_Voltage;
extern u16 Min_Temp;
extern u16 Max_Temp;


// RightSignalCircuit
extern double MPPTGroup1Voltage_Double;
extern double MPPTGroup1Current_Double;
extern double MPPTGroup1Temp_Double;
extern u16 MPPTGroup1Voltage;
extern u16 MPPTGroup1Current;
extern u16 MPPTGroup1Temp;

// LeftSignalCircuit
extern double MPPTGroup2Voltage_Double;
extern double MPPTGroup2Current_Double;
extern double MPPTGroup2Temp_Double;
extern u16 MPPTGroup2Voltage;
extern u16 MPPTGroup2Current;
extern u16 MPPTGroup2Temp;
extern u16 MPPTMaxTemp;
extern u16 MPPTThirdTemp;

extern u16	EmusMinVoltage; 		
extern u16	EmusMaxVoltage;
extern u16	EmusAverageVoltage; 
extern u16 EmusMaxTemp;
extern u16 EmusMinTemp;
extern u16 EmusAverageTemp;
extern u16 EmusEstimatedSOC;

