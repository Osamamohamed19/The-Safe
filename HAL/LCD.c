/*
 * LCD.c
 *
 * Created: 7/22/2023 11:17:34 AM
 *  Author: Osama
 */ 
#define F_CPU 8000000ul
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD.h"

static void Enable(void)
{
	DIO_setPinValue(PORT_CONTROL,EN,1);
	_delay_ms(2);
	DIO_setPinValue(PORT_CONTROL,EN,0);
	_delay_ms(2);
}

void LCD_send_char(unsigned char data)
{
	#if defined eight_bits_mode
	DIO_setPortValue(PORT_DATA,data);
	DIO_setPinValue(PORT_CONTROL,RS,1);
	Enable();
	_delay_ms(1);
	#elif defined four_bits_mode
	DIO_writeHighNibble(PORT_DATA,data>>4);
	DIO_setPinValue(PORT_CONTROL,RS,1);
	Enable();
	DIO_writeHighNibble(PORT_DATA,data);
	DIO_setPinValue(PORT_CONTROL,RS,1);
	Enable();
	_delay_ms(1);
	#endif
}

void LCD_send_cmd(unsigned char cmd)
{
	#if defined eight_bits_mode
	DIO_setPortValue(PORT_DATA,cmd);
	DIO_setPinValue(PORT_CONTROL,RS,0);
	Enable();
	_delay_ms(1);
	#elif defined four_bits_mode
	DIO_writeHighNibble(PORT_DATA,cmd>>4);
	DIO_setPinValue(PORT_CONTROL,RS,0);
	Enable();
	DIO_writeHighNibble(PORT_DATA,cmd);
	DIO_setPinValue(PORT_CONTROL,RS,0);
	Enable();
	_delay_ms(1);
	#endif
}

void LCD_clr_screen(void)
{
	LCD_send_cmd(CLR_SCREEN);
}

void LCD_init(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	DIO_setPortDirection(PORT_DATA,0xff);
	DIO_setPinDirection(PORT_CONTROL,EN,1);
	DIO_setPinDirection(PORT_CONTROL,RW,1);
	DIO_setPinDirection(PORT_CONTROL,RS,1);
	DIO_setPinValue(PORT_CONTROL,RW,0);
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_OFF_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#elif defined four_bits_mode
	DIO_setPinDirection(PORT_DATA,4,1);
	DIO_setPinDirection(PORT_DATA,5,1);
	DIO_setPinDirection(PORT_DATA,6,1);
	DIO_setPinDirection(PORT_DATA,7,1);
	DIO_setPinDirection(PORT_CONTROL,EN,1);
	DIO_setPinDirection(PORT_CONTROL,RW,1);
	DIO_setPinDirection(PORT_CONTROL,RS,1);
	DIO_setPinValue(PORT_CONTROL,RW,0);
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_OFF_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}

void LCD_movecursor(unsigned char row,unsigned char col)
{
	unsigned char data = 0;
	if((row > 2) || (row < 1) || (col > 16) || (col < 1))
	{
		data = 0x80;
	}
	else if(row == 1)
	{
		data = 0x80 + col -1;
	}
	else if(row == 2)
	{
		data = 0xC0 + col -1;
	}
	LCD_send_cmd(data);
	_delay_ms(1);
}

void LCD_sendstring(unsigned char * data)
{
	while(*data != '\0')
	{
		LCD_send_char(*data);
		data++;
	}
}