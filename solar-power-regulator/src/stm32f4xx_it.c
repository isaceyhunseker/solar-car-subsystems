#include "stm32f4xx.h"                  // Device header
#include "common.h"
#include "math.h"

TAnalog  Analog;
double PotControlTask(double array[]);
double Vout_MPPT;
double Current_MPPT;
double MPPT_V;
double ADC_V; 
double Temp_MPPT;
double Temp_MPPT_Meas(double temp_adc);
double A = 0.001125308852122;
double B = 0.000234711863267;
double C = 0.000000085663516;
void Signal(void);

uint8_t Switch1 = 0;
uint8_t Switch2 = 0;
uint8_t Switch3 = 0;
uint8_t Switch4 = 0;
int     SignalCounter = 0;;

void SPI3_IRQHandler(void){

}

void CAN2_RX0_IRQHandler(void){

	CanRxMsg CanRcvdMsg;
	
	if(CAN_GetITStatus(CAN2, CAN_IT_FF0))
		CAN_ClearITPendingBit(CAN2, CAN_IT_FF0);
	else if(CAN_GetITStatus(CAN2, CAN_IT_FOV0))
		CAN_ClearITPendingBit(CAN2, CAN_IT_FOV0);
	else
	{
		CanRcvdMsg.StdId = 0x00;
		CanRcvdMsg.ExtId = 0x00;
		CanRcvdMsg.IDE = 0;
		CanRcvdMsg.DLC = 0;
		CanRcvdMsg.FMI = 0;
		
		CanRcvdMsg.Data[0] = 0x00;
		CanRcvdMsg.Data[1] = 0x00;
		CanRcvdMsg.Data[2] = 0x00;
		CanRcvdMsg.Data[3] = 0x00;
		CanRcvdMsg.Data[4] = 0x00;
		CanRcvdMsg.Data[5] = 0x00;
		CanRcvdMsg.Data[6] = 0x00;
		CanRcvdMsg.Data[7] = 0x00;
		
		CAN_Receive(CAN2, CAN_FIFO0, &CanRcvdMsg);
		CanTempMess = CanRcvdMsg;
 		RcvCANMessage();
	}

}

void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	
		Analog.DataArrThermistorAnalogChannel[Analog.CntDataThermistorAnalogChannel]  					= ADC_ValueArray[0];
		Analog.DataArr_ADC_V_AnalogChannel[Analog.CntData_ADC_V_AnalogChannel]                  = ADC_ValueArray[1];
		Analog.DataArr_MPPT_VOUT_MEAS_AnalogChannel[Analog.CntDataMPPT_VOUT_MEAS_AnalogChannel] = ADC_ValueArray[2];
		Analog.DataArrMPPTCurrentAnalogChannel[Analog.CntDataMPPTCurrentAnalogChannel] 					= ADC_ValueArray[3];
		
		Analog.CntDataThermistorAnalogChannel++;
		Analog.CntData_ADC_V_AnalogChannel++;
		Analog.CntDataMPPT_VOUT_MEAS_AnalogChannel++;
		Analog.CntDataMPPTCurrentAnalogChannel++;
			
				if(Analog.CntDataMPPT_VOUT_MEAS_AnalogChannel==5)
			{
			Analog.CntDataMPPT_VOUT_MEAS_AnalogChannel = 0;
	   	Analog.DataMPPT_VOUT_MEAS_AnalogChannel    = PotControlTask(Analog.DataArr_ADC_V_AnalogChannel);
			Vout_MPPT 															   = ((Analog.DataMPPT_VOUT_MEAS_AnalogChannel/4096)*3.3)*16; // Gerilim bölücü devre direnç degerleri 330 Ohm - 22 Ohm 352/22 = 16
			Send_Vout_MPPT();
			}
			
				if(Analog.CntData_ADC_V_AnalogChannel==5)
			{
			Analog.CntData_ADC_V_AnalogChannel = 0;
      Analog.Data_ADC_V_AnalogChannel	   = PotControlTask(Analog.DataArr_ADC_V_AnalogChannel);
			ADC_V       										 	 = (Analog.Data_ADC_V_AnalogChannel/4096)*3.3;
			//Send_ADC_V();
			}
			
				if(Analog.CntDataMPPTCurrentAnalogChannel==5)
			{
			Analog.CntDataMPPTCurrentAnalogChannel = 0;
	   	Analog.DataMPPTCurrentAnalogChannel  	 = PotControlTask(Analog.DataArrMPPTCurrentAnalogChannel);
			MPPT_V 													 			 = ((Analog.DataMPPTCurrentAnalogChannel/4096)*3.3);
 			Current_MPPT     											 = (((ADC_V - MPPT_V)/0.132)*100);
			Send_Current_MPPT();
			}
					
				if(Analog.CntDataThermistorAnalogChannel==5)
			{
			Analog.CntDataThermistorAnalogChannel = 0;
	   	Analog.DataThermistorAnalogChannel    = PotControlTask(Analog.DataArrThermistorAnalogChannel);
			Temp_MPPT    													= Temp_MPPT_Meas(Analog.DataThermistorAnalogChannel);  	
			Send_Temp_MPPT();}	

			if ((RSignal_Flag == 1)||(Emergency_Flag==1)){
					Signal();
					}	
			
			else if((RSignal_Flag == 0) &&(Emergency_Flag ==0)){
				
				GPIO_ResetBits(Signal_Port,Signal_Pin);
				
			
			}
					
	}
}

double PotControlTask(double array[]){

double Total_Value = 0;
	
	for(int counter =0; counter < 5; counter++){Total_Value += array[counter];}
	
	return Total_Value/5;
}

double Temp_MPPT_Meas(double temp_adc){

double Vres;

double Rther;
double thermonboard;

Vres  = (temp_adc/4096)*3.3;
Rther = (3.3-Vres)*1000/Vres;
thermonboard = 1/(A+B*(log(Rther))+C*(log(Rther))*(log(Rther))*(log(Rther))) - 273;
	
	return thermonboard;
}



void Signal(void)
{
		if (SignalCounter<=75)
			 { 
					GPIO_SetBits(Signal_Port,Signal_Pin); 
			 }
	
		else if (75<SignalCounter && SignalCounter<150)
			{ 
				GPIO_ResetBits(Signal_Port,Signal_Pin);
			}
		SignalCounter++;
			
						if (SignalCounter==150){
						SignalCounter=0;    
						} 
}

