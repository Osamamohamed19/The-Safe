/*
 * The Safe.c
 *
 * Created: 7/23/2023 2:16:23 PM
 * Author : Osama
 */ 
#define F_CPU 8000000ul
#include <util/delay.h>
#include "LCD.h"
#include "EEPROM_interface.h"
#include "Keypad.h"
#define EEPROM_STATUS_LOCATION 0x20
#define EEPROM_PASSWORD_LOCATION1 0x21
#define EEPROM_PASSWORD_LOCATION2 0x22
#define EEPROM_PASSWORD_LOCATION3 0x23
#define EEPROM_PASSWORD_LOCATION4 0x24
#define MAXTRIES 3
unsigned char arr[4];
int main(void)
{
	unsigned char value = NOTPRESSED;
	unsigned char flag = 0 , i ;
	unsigned char tries = MAXTRIES ;
    LCD_init();
	Keypad_init();
	if(EEPROM_read(EEPROM_STATUS_LOCATION) == NOTPRESSED)
	{
		LCD_sendstring("Set Pass : ");
		for(i = 0;i < 4;i++)
		{
			do 
			{
				value = Keypad_read();
			} while (value == NOTPRESSED);
			LCD_send_char(value);
			LCD_movecursor(1,12+i);
			LCD_send_char('*');
			_delay_ms(500);
			EEPROM_write(EEPROM_PASSWORD_LOCATION1+i,value);
		}
		EEPROM_write(EEPROM_STATUS_LOCATION,0x00);
	}
	while(flag == 0)
	{
		arr[0] = arr[1] = arr[2] = arr[3] = NOTPRESSED;
		LCD_clr_screen();
		LCD_sendstring("Check Pass :");
		for(i = 0;i < 4;i++)
		{
			do
			{
				arr[i] = Keypad_read();
			} while (arr[i] == NOTPRESSED);
			LCD_send_char(arr[i]);
			LCD_movecursor(1,13+i);
			LCD_send_char('*');
			_delay_ms(500);
		}
	
	if((EEPROM_read(EEPROM_PASSWORD_LOCATION1) == arr[0]) && (EEPROM_read(EEPROM_PASSWORD_LOCATION2) == arr[1]) && (EEPROM_read(EEPROM_PASSWORD_LOCATION3) == arr[2]) && (EEPROM_read(EEPROM_PASSWORD_LOCATION4) == arr[3]))
	{
		LCD_clr_screen();
		LCD_sendstring("Right Pass");
		LCD_movecursor(2,1);
		LCD_sendstring("Safe Opened");
		flag = 1;
	}
	else
	{
		tries--;
		if(tries > 0)
		{
			LCD_clr_screen();
			LCD_sendstring("Wrong Pass");
			_delay_ms(1000);
			LCD_clr_screen();
			LCD_sendstring("Tries Left : ");
			LCD_send_char(tries+48);
			_delay_ms(1000);
		}
		else
		{
			LCD_clr_screen();
			LCD_sendstring("Wrong Pass");
			LCD_movecursor(2,1);
			LCD_sendstring("Safe Closed");
			flag = 1;
		}
	}
	}
}

