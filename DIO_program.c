/*
 * DIO_program.c
 *
 * Created: 9/1/2021 9:12:49 PM
 *  Author: Karim Essam
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"


void DIO_voidSetPinDirection (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8Direction)
{
	switch (Copy_u8PortNumber)
	{
		case PORTA_ID:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRA_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRA_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT_PULL_UP)
		{
			SET_BIT(PORTA_REG , Copy_u8PinNumber);
			CLR_BIT(DDRA_REG , Copy_u8PinNumber);
		}
		break;

		case PORTB_ID:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRB_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRB_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT_PULL_UP)
		{
			SET_BIT(PORTB_REG , Copy_u8PinNumber);
			CLR_BIT(DDRB_REG , Copy_u8PinNumber);
		}
		break;

		case PORTC_ID:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRC_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRC_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT_PULL_UP)
		{
			SET_BIT(PORTC_REG , Copy_u8PinNumber);
			CLR_BIT(DDRC_REG , Copy_u8PinNumber);
		}
		break;

		case PORTD_ID:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRD_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT)
		{
			CLR_BIT(DDRD_REG , Copy_u8PinNumber);
		}
		else if (Copy_u8Direction == INPUT_PULL_UP)
		{
			SET_BIT(PORTD_REG , Copy_u8PinNumber);
			CLR_BIT(DDRD_REG , Copy_u8PinNumber);
		}
		break;
	}
}

void DIO_voidSetPortDirection (u8 Copy_u8PortNumber, u8 Copy_u8PortDirection)
{
	switch (Copy_u8PortNumber)
	{
		case PORTA_ID:

		if(Copy_u8PortDirection == OUTPUT)
		{
			DDRA_REG=0xFF;
		}
		else if (Copy_u8PortDirection == INPUT)
		{
			DDRA_REG=0x00;
		}
		else if (Copy_u8PortDirection == INPUT_PULL_UP)
		{
			PORTA_REG=0xFF;
			DDRA_REG=0x00;
		}
		break;

		case PORTB_ID:

		if(Copy_u8PortDirection == OUTPUT)
		{
			DDRB_REG=0xFF;
		}
		else if (Copy_u8PortDirection == INPUT)
		{
			DDRB_REG=0x00;
		}
		else if (Copy_u8PortDirection == INPUT_PULL_UP)
		{
			PORTB_REG=0xFF;
			DDRB_REG=0x00;
		}
		break;

		case PORTC_ID:

		if(Copy_u8PortDirection == OUTPUT)
		{
			DDRC_REG=0xFF;
		}
		else if (Copy_u8PortDirection == INPUT)
		{
			DDRC_REG=0x00;
		}
		else if (Copy_u8PortDirection == INPUT_PULL_UP)
		{
			PORTC_REG=0xFF;
			DDRC_REG=0x00;
		}
		break;

		case PORTD_ID:

		if(Copy_u8PortDirection == OUTPUT)
		{
			DDRD_REG=0xFF;
		}
		else if (Copy_u8PortDirection == INPUT)
		{
			DDRD_REG=0x00;
		}
		else if (Copy_u8PortDirection == INPUT_PULL_UP)
		{
			PORTD_REG=0xFF;
			DDRD_REG=0x00;
		}
		break;
	}

}

void DIO_voidSetPinValue (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8Value)
{
	switch (Copy_u8PortNumber)
	{
		case PORTA_ID:
			if( Copy_u8Value == HIGH)
			{
				SET_BIT(PORTA_REG , Copy_u8PinNumber);
			}
			else if ( Copy_u8Value ==LOW)
			{
				CLR_BIT(PORTA_REG , Copy_u8PinNumber);
			}
			break;

		case PORTB_ID:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTB_REG , Copy_u8PinNumber);
			}
			else if ( Copy_u8Value ==LOW)
			{
				CLR_BIT(PORTB_REG , Copy_u8PinNumber);
			}
			break;

		case PORTC_ID:

			if( Copy_u8Value == HIGH)
			{
				SET_BIT(PORTC_REG , Copy_u8PinNumber);
			}
			else if ( Copy_u8Value ==LOW)
			{
				CLR_BIT(PORTC_REG , Copy_u8PinNumber);
			}
			break;

		case PORTD_ID:

			if( Copy_u8Value == HIGH)
			{
				SET_BIT(PORTD_REG , Copy_u8PinNumber);
			}
			else if ( Copy_u8Value ==LOW)
			{
				CLR_BIT(PORTD_REG , Copy_u8PinNumber);
			}
			break;
	}
}

void DIO_voidSetPortValue (u8 Copy_u8PortNumber, u8 Copy_u8Value)
{
	switch(Copy_u8PortNumber)
	{
		case PORTA_ID:
		PORTA_REG=Copy_u8Value;
		break;

		case PORTB_ID:
		PORTB_REG=Copy_u8Value;
		break;

		case PORTC_ID:
		PORTC_REG=Copy_u8Value;
		break;

		case PORTD_ID:
		PORTD_REG=Copy_u8Value;
		break;

	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber)
{
	switch (Copy_u8PortNumber)
	{
		case PORTA_ID:
		return GET_BIT(PINA_REG , Copy_u8PinNumber);

		case PORTB_ID:
		return GET_BIT(PINB_REG , Copy_u8PinNumber);

		case PORTC_ID:
		return GET_BIT(PINC_REG , Copy_u8PinNumber);

		case PORTD_ID:
		return GET_BIT(PIND_REG , Copy_u8PinNumber);

	}
	return 0;  //34an el warning :D
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortNumber)
{
	switch (Copy_u8PortNumber)
	{
		case PORTA_ID:
		return PINA_REG;

		case PORTB_ID:
		return PINB_REG;

		case PORTC_ID:
		return PINC_REG;

		case PORTD_ID:
		return PIND_REG;
	}
	return 0;   //34an el warning tany :D
}

void DIO_voidTogglePinValue (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber)
{
	switch (Copy_u8PortNumber)
	{
		case PORTA_ID:
			TOG_BIT(PORTA_REG , Copy_u8PinNumber);
			break;

		case PORTB_ID:
			TOG_BIT(PORTB_REG , Copy_u8PinNumber);
			break;
		
		case PORTC_ID:
			TOG_BIT(PORTC_REG , Copy_u8PinNumber);
			break;

		
		case PORTD_ID:
			TOG_BIT(PORTD_REG , Copy_u8PinNumber);
			break;

	}
}
