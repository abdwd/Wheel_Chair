/*
 * ultrasonic.h
 *
 * Created: 10/8/2021 5:53:58 PM
 *  Author: Hp
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 8000000UL
#include <util/delay.h>

#define TRIGGER PIND4

extern volatile int pulse; //integer  to access all though the program

void ULTRASONIC_init(void);
void ULTRASONIC_trigger(void);



#endif /* ULTRASONIC_H_ */