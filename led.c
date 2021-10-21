#include "led.h"

void LED_init(ST_LED_config_t* config)
{
	EN_port port = config->port;
	uint8_t pin = config->pin;
	DIO_voidSetPinDirection(pin,port,OUTPUT);
}
void LED_write(ST_LED_config_t* config,uint8_t value)
{
	EN_port port = config->port;
	uint8_t pin = config->pin;
	DIO_voidSetPinValue(pin,port,value);
}



