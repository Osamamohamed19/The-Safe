/*
 * DIO_prog.c
 *
 * Created: 7/4/2023 7:49:22 PM
 *  Author: Osama
 */ 
#include "BIT_MATH.h"
#include "DIO_private.h"

void DIO_setPinDirection(unsigned char port,unsigned char pin,unsigned char direction)
{
	switch(port)
	{
		case 'A':
			if(direction == 1)
			{
				SET_BIT(DDRA,pin);
			}
			else
			{
				CLR_BIT(DDRA,pin);
			}
			break;
			
		case 'B':
			if(direction == 1)
			{
				SET_BIT(DDRB,pin);
			}
			else
			{
				CLR_BIT(DDRB,pin);
			}
			break;
			
		case 'C':
			if(direction == 1)
			{
				SET_BIT(DDRC,pin);
			}
			else
			{
				CLR_BIT(DDRC,pin);
			}
			break;	
			
		case 'D':
			if(direction == 1)
			{
				SET_BIT(DDRD,pin);
			}
			else
			{
				CLR_BIT(DDRD,pin);
			}
			break;
	}
}

void DIO_setPinValue(unsigned char port,unsigned char pin,unsigned char value)
{
	switch(port)
	{
		case 'A':
			if(value == 1)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
			
		case 'B':
			if(value == 1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
			
		case 'C':
			if(value == 1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
			
		case 'D':
			if(value == 1)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
	}
}

unsigned char DIO_getPinValue(unsigned char port,unsigned char pin)
{
	unsigned char value = 0;
	switch(port)
	{
		case 'A':
			value = GET_BIT(PINA,pin);
			break;
			
		case 'B':
			value = GET_BIT(PINB,pin);
			break;
			
		case 'C':
			value = GET_BIT(PINC,pin);
			break;
			
		case 'D':
			value = GET_BIT(PIND,pin);
			break;
	}
	return value;
}

void DIO_setPortDirection(unsigned char port,unsigned char direction)
{
	switch(port)
	{
		case 'A':
			DDRA = direction;
			break;
			
		case 'B':
			DDRB = direction;
			break;
			
		case 'C':
			DDRC = direction;
			break;
			
		case 'D':
			DDRD = direction;
			break;
	}
}

void DIO_setPortValue(unsigned char port,unsigned char value)
{
	switch(port)
	{
		case 'A':
			PORTA = value;
			break;
			
		case 'B':
			PORTB = value;
			break;
			
		case 'C':
			PORTC = value;
			break;
			
		case 'D':
			PORTD = value;
			break;
	}
}

unsigned char DIO_getPortValue(unsigned char port)
{
	unsigned char value = 0;
	switch(port)
	{
		case 'A':
			value = PINA;
			break;
			
		case 'B':
			value = PINB;
			break;
			
		case 'C':
			value = PINC;
			break;
			
		case 'D':
			value = PIND;
			break;
	}
	return value;
}

void DIO_toggPin(unsigned char port,unsigned pin)
{
	switch(port)
	{
		case 'A':
			TOG_BIT(PORTA,pin);
			break;
			
		case 'B':
			TOG_BIT(PORTB,pin);
			break;
			
		case 'C':
			TOG_BIT(PORTC,pin);
			break;
			
		case 'D':
			TOG_BIT(PORTD,pin);
			break;
	}
}

void DIO_connectInternalPullup(unsigned char port,unsigned char pin,unsigned char connect_pullup)
{
	switch(port)
	{
		case 'A':
			if(connect_pullup == 1)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
			
		case 'B':
			if(connect_pullup == 1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
			
		case 'C':
			if(connect_pullup == 1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
			
		case 'D':
			if(connect_pullup == 1)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
	}
}

void DIO_writeLowNibble(unsigned char port,unsigned char value)
{
	DIO_setPinValue(port,0,GET_BIT(value,0));
	DIO_setPinValue(port,1,GET_BIT(value,1));
	DIO_setPinValue(port,2,GET_BIT(value,2));
	DIO_setPinValue(port,3,GET_BIT(value,3));
}

void DIO_writeHighNibble(unsigned char port,unsigned char value)
{
	DIO_setPinValue(port,4,GET_BIT(value,0));
	DIO_setPinValue(port,5,GET_BIT(value,1));
	DIO_setPinValue(port,6,GET_BIT(value,2));
	DIO_setPinValue(port,7,GET_BIT(value,3));
}