/*
 * DIO_interface.h
 *
 * Created: 7/4/2023 7:49:37 PM
 *  Author: Osama
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_setPinDirection(unsigned char port,unsigned char pin,unsigned char direction);
void DIO_setPinValue(unsigned char port,unsigned char pin,unsigned char value);
unsigned char DIO_getPinValue(unsigned char port,unsigned char pin);
void DIO_setPortDirection(unsigned char port,unsigned char direction);
void DIO_setPortValue(unsigned char port,unsigned char value);
unsigned char DIO_getPortValue(unsigned char port);
void DIO_toggPin(unsigned char port,unsigned pin);
void DIO_connectInternalPullup(unsigned char port,unsigned char pin,unsigned char connect_pullup);
void DIO_writeLowNibble(unsigned char port,unsigned char value);
void DIO_writeHighNibble(unsigned char port,unsigned char value);

#endif /* DIO_INTERFACE_H_ */