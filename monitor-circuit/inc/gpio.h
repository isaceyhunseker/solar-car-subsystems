#include "stm32f4xx.h"

/*GPIOA*/

#define RightSignal_Port                          GPIOA									
#define RightSignal_Pin		                        GPIO_Pin_8

#define LeftSignal_Port                          	GPIOA									
#define LeftSignal_Pin		                        GPIO_Pin_9

#define Buzzer_Port                         		  GPIOA									
#define Buzzer_Pin		                       		  GPIO_Pin_10

#define Monitor_Tx_Port                           GPIOA									
#define Monitor_Tx_Pin		                        GPIO_Pin_11

#define Monitor_Rx_Port 												  GPIOA									
#define Monitor_Rx_Pin		                        GPIO_Pin_12

/*GPIOB*/

#define Wifi_Reset_Port                           GPIOB									
#define Wifi_Reset_Pin		                        GPIO_Pin_5

#define Wifi_Tx_Port                              GPIOB									
#define Wifi_Tx_Pin		                        		GPIO_Pin_6

#define Wifi_Rx_Port                          		GPIOB									
#define Wifi_Rx_Pin		                        		GPIO_Pin_7

#define GreenLed_Port                          		GPIOB									
#define GreenLed_Pin		                        	GPIO_Pin_8

#define BlueLed_Port                          		GPIOB									
#define BlueLed_Pin		                        		GPIO_Pin_9

#define Radio_Port                          			GPIOB									
#define Radio_Pin		                        			GPIO_Pin_10

#define Can_Rx_Port                          			GPIOB									
#define Can_Rx_Pin		                        		GPIO_Pin_12

#define Can_Tx_Port                          			GPIOB									
#define Can_Tx_Pin		                        		GPIO_Pin_13

/*GPIOC*/

#define Button4_Port                          		GPIOC									
#define Button4_Pin		                        		GPIO_Pin_0

#define Button3_Port                          		GPIOC									
#define Button3_Pin		                        		GPIO_Pin_1

#define Brake_Port                          			GPIOC									
#define Brake_Pin		                        			GPIO_Pin_2

#define GasPot_Port                          			GPIOC									
#define GasPot_Pin		                        		GPIO_Pin_3

#define Horn_Port                          				GPIOC									
#define Horn_Pin		                        			GPIO_Pin_7

#define Button2_Port                          		GPIOC									
#define Button2_Pin		                        		GPIO_Pin_8

#define Button1_Port                          		GPIOC									
#define Button1_Pin		                        		GPIO_Pin_9

#define USB_Tx_Port                          			GPIOC									
#define USB_Tx_Pin		                        		GPIO_Pin_10

#define USB_Rx_Port                          			GPIOC									
#define USB_Rx_Pin		                        		GPIO_Pin_11

#define RedLed_Port                          			GPIOC									
#define RedLed_Pin		                        		GPIO_Pin_13

#define EXTI_PortSourceButton1_Port          			EXTI_PortSourceGPIOC
#define EXTI_PinSourceButton1_Pin             		EXTI_PinSource9

#define EXTI_PortSourceButton2_Port          			EXTI_PortSourceGPIOC
#define EXTI_PinSourceButton2_Pin             		EXTI_PinSource8

#define EXTI_PortSourceButton3_Port          			EXTI_PortSourceGPIOC
#define EXTI_PinSourceButton3_Pin             		EXTI_PinSource1

#define EXTI_PortSourceButton4_Port          			EXTI_PortSourceGPIOC
#define EXTI_PinSourceButton4_Pin             		EXTI_PinSource0

#define EXTI_PortSourceBrake_Port          				EXTI_PortSourceGPIOC
#define EXTI_PinSourceBrake_Pin 	            		EXTI_PinSource2



