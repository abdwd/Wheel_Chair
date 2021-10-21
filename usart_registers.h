/*
 * usart_registers.h
 *
 *  Created on: Sep 21, 2021
 *      Author: Hp
 */

#ifndef USART_REGISTERS_H_
#define USART_REGISTERS_H_

#define UCSRA				(*(volatile uint8_t*)(0x2B))
#define UCSRB				(*(volatile uint8_t*)(0x2A))
#define UCSRC				(*(volatile uint8_t*)(0x40))
#define UBRRH				(*(volatile uint8_t*)(0x40))
#define UBRRL				(*(volatile uint8_t*)(0x29))
#define UDR				    (*(volatile uint8_t*)(0x2C))

#define U2X                 1
#define RXEN				4
#define TXEN				3
#define URSEL				7
#define UCSZ0				1
#define UPM0				4
#define USBS				3
#define UDRE				5
#define RXC					7
#define RXCIE				7





#endif /* USART_REGISTERS_H_ */
