#include "ldr.h"

f32 static getLevel(u16 adcValue){
	f32 voltage = adcValue;
	if (voltage <= 100)
	{
		return 1;
	}
	else if(voltage>100 && voltage <200)
	{
		return 2;
	}
	else if(voltage>200 && voltage <300)
	{
		return 3;
	}
	else if(voltage>300 && voltage <400)
	{
		return 4;
	}
	else if(voltage>400 && voltage <500)
	{
		return 5;
	}
	else if(voltage>500 && voltage <600)
	{
		return 6;
	}
	else if(voltage>600 && voltage <700)
	{
		return 7;
	}
	else if(voltage>700 && voltage <800)
	{
		return 8;
	}
	else if(voltage>800 && voltage <900)
	{
		return 9;
	}
	else
	{
		return 10;
	}
}
void LDR_init()
{
	ADC_voidInit(ADC_MODE_SINGLE_CONVERSION , ADC_AUTO_TRIGGER_FREE_RUNNING , ADC_PRESCALAR_DIV_8);
}
u16 LDR_read(LDR* ldr)
{
	ADC_voidStartConversion(ADC_CHANNEL_SINGLE_0);
	return getLevel(ADC_u16ReadChannel());
}


