#include "motor.h"
static ST_MOTOR_channels_t channels;
static uint8_t counter=0;
void MOTOR_init(ST_MOTOR_config_t* config)
{

	TIMER0_voidInit(TIMER0_CTC_MODE , TIMER0_CTC_DISCONNECT , TIMER0_PRESCALAR_64 , 0);
	EN_port port = config->port;
	uint8_t pin1 = config->pin1;
	uint8_t pin2 = config->pin2;
	DIO_voidSetPinDirection(pin1,port,OUTPUT);
	DIO_voidSetPinDirection(pin2,port,OUTPUT);
	channels.motor[counter].port =port;
	channels.motor[counter].pin1 =pin1;
	channels.motor[counter].pin2 =pin2;
	counter++;
}
void MOTOR_cw(uint8_t motor_number,uint8_t duty_cycle)
{
	motor_number -=1;
	EN_port port = channels.motor[motor_number].port;
	uint8_t pin1 = channels.motor[motor_number].pin1;
	uint8_t pin2 = channels.motor[motor_number].pin2;
	DIO_voidSetPinValue(pin1,port,LOW);
	DIO_voidSetPinValue(pin2,port,HIGH);
	TIMER0_voidSoftwarePWM(PWM_PORT , PWM_PIN , duty_cycle);
}
void MOTOR_ccw(uint8_t motor_number,uint8_t duty_cycle)
{
	motor_number -=1;
	EN_port port = channels.motor[motor_number].port;
	uint8_t pin1 = channels.motor[motor_number].pin1;
	uint8_t pin2 = channels.motor[motor_number].pin2;
	DIO_voidSetPinValue(pin1,port,HIGH);
	DIO_voidSetPinValue(pin2,port,LOW);
	TIMER0_voidSoftwarePWM(PWM_PORT , PWM_PIN , duty_cycle);
}
void MOTOR_stop(uint8_t motor_number)
{
	motor_number -=1;
	EN_port port = channels.motor[motor_number].port;
	uint8_t pin1 = channels.motor[motor_number].pin1;
	uint8_t pin2 = channels.motor[motor_number].pin2;
	DIO_voidSetPinValue(pin1,port,LOW);
	DIO_voidSetPinValue(pin2,port,LOW);
}

