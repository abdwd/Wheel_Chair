/*
 * usart.c
 *
 *  Created on: Mar 24, 2021
 *      Author: Hp
 */
#include "usart.h"
#include <avr/interrupt.h>

static volatile void (*g_callBackPtr)(uint16)= NULL_PTR;
Usart_CharacterSize size;

ISR(USART_RXC_vect)
{
//	CLEAR_BIT(UCSRB,RXCIE);
	uint16 data;
	if(size==NINE)
	{
		data = (UCSRB & 0x02) <<7;
		data |= UDR;
	}
	else{
		data=UDR;
	}
	if(g_callBackPtr != NULL_PTR )
	{
		(*g_callBackPtr)(data);
	}
}


void UART_init(const Usart_ConfigType * Config_Ptr )
{
	uint32 BAUD_PRESCALE;
	size= Config_Ptr->size;
	/* U2X = 1/0 for double transmission speed, Depending on the mode */
	UCSRA = ( (Config_Ptr->mode) << U2X );
	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0/1  Depending on the data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	UCSRB = 1<<RXEN | 1<< TXEN | (Config_Ptr->size & 0x04);
	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	UCSRC = (1<<URSEL) | ( (Config_Ptr->size & 0x03) << UCSZ0 ) | ( Config_Ptr->parity << UPM0)
			| ( (Config_Ptr->stop) << USBS )  ;
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/

	if(Config_Ptr->mode == ON)
	{
		BAUD_PRESCALE =(F_CPU) / ( ( Config_Ptr->baud_rate) * 8UL) - 1;
	}
	else if(Config_Ptr->mode == OFF)
	{
		BAUD_PRESCALE =(F_CPU) / ( ( Config_Ptr->baud_rate) * 16UL) - 1;
	}
	UBRRH= BAUD_PRESCALE>>8;
	UBRRL= BAUD_PRESCALE;
}

void UART_sendByte(const uint16 data)
{
	while( BIT_IS_CLEAR(UCSRA,UDRE) );
	/* Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now */
	if(size==NINE)
	{
		UCSRB = (UCSRB & 0xFE) | ( ( data & (0x0100) ) >>8 ) ;
		UDR = data;
	}
	else
	{
		UDR=data;
	}
}

void UART_receiveByte(void)
{
	SET_BIT(UCSRB,RXCIE);

}
void UART_setCallBack(void(*a_ptr)(uint16))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr=a_ptr;
}
void UART_sendString(const uint8 * Str)
{
	uint8 i=0;
	while( Str[i]!='\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}
