/*
 * Keypad.h
 *
 * Created: 7/23/2023 1:26:13 AM
 *  Author: Osama
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_interface.h"
#define PORT 'C'
#define NOTPRESSED 0xff
void Keypad_init(void);
unsigned char Keypad_read(void);
#endif /* KEYPAD_H_ */