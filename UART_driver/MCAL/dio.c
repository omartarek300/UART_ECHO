/*
 * dio.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */
#include "dio.h"
void DIO_init(uint8_t Port_name, uint8_t pins )
{
	switch(Port_name)
	{
		case PA:
		{
			DDRA |= pins;
		}
		break;
		case PB:
		{
			DDRB |= pins;
		}
		break;
		case PC:
		{
			DDRC |= pins;
		}
		break;
		case PD:
		{
			DDRD |= pins;
		}
		break;
	}
}
void DIO_set(uint8_t Port_name, uint8_t pins)
{
	switch(Port_name)
	{
		case PA:
		{
			PORTA |= pins;
		}
		break;
		case PB:
		{
			PORTA |= pins;
		}
		break;
		case PC:
		{
			PORTA |= pins;
		}
		break;
		case PD:
		{
			PORTA |= pins;
		}
		break;
	}
}
void DIO_CLR(uint8_t Port_name, uint8_t pins)
{
	switch(Port_name)
	{
		case PA:
		{
			PORTA = PORTA & (~pins);
		}
		break;
		case PB:
		{
			PORTB = PORTB & (~pins);
		}
		break;
		case PC:
		{
			PORTC = PORTC & (~pins);
		}
		break;
		case PD:
		{
			PORTD = PORTD & (~pins);
		}
		break;
	}
}
uint8_t DIO_read(uint8_t Port_name, uint8_t pins )
{
	uint8_t Data = 0;
	switch(Port_name)
	{
		case PA:
		{
			Data =  PINA & pins;
		}
		break;
		case PB:
		{
			Data =  PINB & pins;
		}
		break;
		case PC:
		{
			Data =  PINC & pins;
		}
		break;
		case PD:
		{
			Data =  PIND & pins;
		}
		break;
	}
	return Data;
}
void DIO_CLR_BIT(uint8_t Port_name, uint8_t pin)
{
	switch(Port_name)
	{
		case PA:
		{
			CLRBIT(PORTA,pin);
		}
		break;
		case PB:
		{
			CLRBIT(PORTB,pin);
		}
		break;
		case PC:
		{
			CLRBIT(PORTC,pin);
		}
		break;
		case PD:
		{
			CLRBIT(PORTD,pin);
		}
		break;
	}
}
void DIO_SET_BIT(uint8_t Port_name, uint8_t pin)
{
	switch(Port_name)
	{
		case PA:
		{
			SETBIT(PORTA,pin);
		}
		break;
		case PB:
		{
			SETBIT(PORTB,pin);
		}
		break;
		case PC:
		{
			SETBIT(PORTC,pin);
		}
		break;
		case PD:
		{
			SETBIT(PORTD,pin);
		}
		break;
	}
}
uint8_t DIO_READ_BIT(uint8_t Port_name, uint8_t pin)
{
	switch(Port_name)
	{
		case PA:
		{
			return GETBIT(PINA,pin);
		}
		break;
		case PB:
		{
			return GETBIT(PINB,pin);
		}
		break;
		case PC:
		{
			return GETBIT(PINC,pin);
		}
		break;
		case PD:
		{
			return GETBIT(PIND,pin);
		}
		break;
	}
}
