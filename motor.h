/*
 * motor.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Hp
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "common_macros.h"
#include <stdint.h>

#define MOTOR_NUMBER 2
#define PWM_PORT D
#define PWM_PIN  5


typedef struct
{
	EN_port port;
	uint8_t pin1;
	uint8_t pin2;

}ST_MOTOR_config_t;

typedef struct{
	ST_MOTOR_config_t motor[MOTOR_NUMBER];
}ST_MOTOR_channels_t;

void MOTOR_init(ST_MOTOR_config_t* config);
void MOTOR_cw(uint8_t motor_number,uint8_t duty_cycle);
void MOTOR_ccw(uint8_t motor_number,uint8_t duty_cycle);
void MOTOR_stop(uint8_t motor_number);


#endif /* MOTOR_H_ */
