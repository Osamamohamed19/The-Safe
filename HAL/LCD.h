/*
 * LCD.h
 *
 * Created: 7/22/2023 11:17:47 AM
 *  Author: Osama
 */ 
#ifndef LCD_H_
#define LCD_H_
#include "LCD_config.h"
#define PORT_DATA 'A'
#define PORT_CONTROL 'B'
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define CURSOR_OFF_DISPLAY_ON 0x0c
#define ENTRY_MODE 0x06
#if defined eight_bits_mode
#define EN 1
#define RS 0
#define RW 2
#define EIGHT_BITS 0x38
#elif defined four_bits_mode
#define EN 1
#define RS 0
#define RW 2
#define FOUR_BITS 0x28
#endif
static void Enable(void);
void LCD_send_char(unsigned char data);
void LCD_send_cmd(unsigned char cmd);
void LCD_clr_screen(void);
void LCD_init(void);
void LCD_movecursor(unsigned char row,unsigned char col);
void LCD_sendstring(unsigned char * data);
#endif /* LCD_H_ */