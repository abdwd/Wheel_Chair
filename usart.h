/*
 * usart.h
 *
 *  Created on: Mar 24, 2021
 *      Author: Hp
 */

#ifndef USART_H_
#define USART_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "usart_registers.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	OFF,ON
}Usart_DoubleSpeedMode;

typedef enum
{
	FIVE,SIX,SEVEN,EIGHT,NINE=7
}Usart_CharacterSize;

typedef enum{
	DISABLED,EVEN=2,ODD=3
}Usart_ParityBit;

typedef enum{
	ONE,TWO
}Usart_StopBit;

typedef struct{
	Usart_DoubleSpeedMode mode;
	Usart_CharacterSize size;
	Usart_ParityBit parity;
	Usart_StopBit stop;
	uint32 baud_rate;

}Usart_ConfigType;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(const Usart_ConfigType * Config_Ptr );
void UART_sendByte(const uint16 data);
void UART_receiveByte(void);
void UART_sendString(const uint8 * Str);
void UART_setCallBack(void(*a_ptr)(uint16));
//void UART_receiveString(uint8 *Str);

#endif /* USART_H_ */
