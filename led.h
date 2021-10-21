#ifndef LED_H_
#define LED_H_

#include "DIO_interface.h"
#include <stdint.h>
#include "common_macros.h"
#include "micro_config.h"

typedef struct
{
	EN_port port;
	uint8_t pin;

}ST_LED_config_t;

void LED_init(ST_LED_config_t* config);
void LED_write(ST_LED_config_t* config,uint8_t value);



#endif /* LED_H_ */
