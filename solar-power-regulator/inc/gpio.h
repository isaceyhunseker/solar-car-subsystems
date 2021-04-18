#include "stm32f4xx.h"
	 
#define Switch1_Port                  GPIOA
#define Switch1_Pin                   GPIO_Pin_0

#define Switch2_Port                  GPIOA
#define Switch2_Pin                   GPIO_Pin_1

#define Switch3_Port                  GPIOA
#define Switch3_Pin                   GPIO_Pin_2

#define Switch4_Port                  GPIOA
#define Switch4_Pin                   GPIO_Pin_3

#define CS_Port                       GPIOA             
#define CS_Pin                        GPIO_Pin_4

#define VOUT_Relay_Port               GPIOA
#define VOUT_Relay_Pin                GPIO_Pin_5

#define ADC_V_Port                    GPIOA
#define ADC_V_Pin                     GPIO_Pin_6

#define	Signal_Port                   GPIOA
#define Signal_Pin              	    GPIO_Pin_7

#define	Alive_Led1_Port               GPIOA
#define Alive_Led1_Pin              	GPIO_Pin_11

#define	Alive_Led2_Port               GPIOA
#define Alive_Led2_Pin              	GPIO_Pin_12

#define Temp_Port                     GPIOB
#define Temp_Pin                      GPIO_Pin_0

#define Can_Rx_Port    			          GPIOB
#define Can_Rx_Pin         	          GPIO_Pin_12
	 
#define Can_Tx_Port						    		GPIOB
#define Can_Tx_Pin                   	GPIO_Pin_13

#define VOUT_MEAS_Port                GPIOC
#define	VOUT_MEAS_Pin                 GPIO_Pin_1

#define VIN_Port                      GPIOC              
#define	VIN_Pin                       GPIO_Pin_2

#define VOUT_Port                     GPIOC              
#define	VOUT_Pin                      GPIO_Pin_3

#define Current_ADC_Port              GPIOC
#define Current_ADC_Pin								GPIO_Pin_4

#define SCL_Port              				GPIOC              //SCK
#define SCL_Pin												GPIO_Pin_10

#define SDO_Port              				GPIOC              //MOSI
#define SDO_Pin												GPIO_Pin_11

#define SDI_Port              				GPIOC              //MISO
#define SDI_Pin												GPIO_Pin_12

#define GPIO_PortSourceCanRx_Port             		GPIOB
#define GPIO_PinSourceCanRx_Pin               		GPIO_PinSource12

#define GPIO_PortSourceCanTx_Port              	  GPIOB
#define GPIO_PortSourceCanTx_Pin               	  GPIO_PinSource13
