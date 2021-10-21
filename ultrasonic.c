#include "ultrasonic.h"
#include "ultrasonic_registers.h"
#include <avr\interrupt.h>
static volatile int i = 0; // integer  to access all though the program
volatile int pulse = 0;
 
ISR(INT0_vect)//interrupt service routine when there is a change in logic level
{
	if (i==1)//when logic from HIGH to LOW
	{
		TCCR1B=0;//disabling counter
		pulse=TCNT1;//count memory is updated to integer
		TCNT1=0;//resetting the counter memory
		i=0;
	}
	if (i==0)//when logic change from LOW to HIGH
	{
		TCCR1B|=(1<<CS10);//enabling counter
		i=1;
	}
}
void ULTRASONIC_init(void)
{
	sei();
	TCCR1A = 0;             // timer Init 
	GICR|=(1<<INT0);        //enabling interrupt0
	MCUCR|=(1<<ISC00);      //setting interrupt triggering logic change
}

void ULTRASONIC_trigger(void)
{
	PORTD|=(1<<TRIGGER);
	_delay_us(15);
	PORTD &=~(1<<TRIGGER);
}

