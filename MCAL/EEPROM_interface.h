/*
 * EEPROM_interface.h
 *
 * Created: 7/12/2023 3:31:22 PM
 *  Author: Osama
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_write(unsigned short address,unsigned char data);

unsigned char EEPROM_read(unsigned short address);

#endif /* EEPROM_INTERFACE_H_ */