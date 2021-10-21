/*
 * ultrasonic_registers.h
 *
 * Created: 10/9/2021 8:52:37 PM
 *  Author: Hp
 */ 


#ifndef ULTRASONIC_REGISTERS_H_
#define ULTRASONIC_REGISTERS_H_

/* Timer Registers */

#define TCCR1A  (*(volatile u8*)(0x2F))
#define TCCR1B  (*(volatile u8*)(0x2E))
#define TCNT1   (*(volatile u8*)(0x2C))
#define CS10    0

/* Interrupt Registers */

#define GICR    (*(volatile u8*)(0x3B))
#define IVCE    0
#define IVSEL   1
#define INT2    5
#define INT0    6
#define INT1    7

#define MCUCR   (*(volatile u8*)(0x35))
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3


#define SREG (*(volatile u8*)(0x3F))



#endif /* ULTRASONIC_REGISTERS_H_ */