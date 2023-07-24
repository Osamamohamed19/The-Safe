/*
 * EEPROM_prog.c
 *
 * Created: 7/12/2023 3:30:58 PM
 *  Author: Osama
 */ 
#include "BIT_MATH.h"
#include "EEPROM_private.h"

void EEPROM_write(unsigned short address,unsigned char data)
{
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	EEDR = data;
	
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	
	while(GET_BIT(EECR,EEWE)==1);
}

unsigned char EEPROM_read(unsigned short address)
{
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	SET_BIT(EECR,EERE);
	
	return EEDR;
}