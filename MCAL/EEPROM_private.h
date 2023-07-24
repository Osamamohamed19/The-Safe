/*
 * EEPROM_private.h
 *
 * Created: 7/12/2023 3:31:38 PM
 *  Author: Osama
 */ 


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define	   EEARH	 *((volatile unsigned char*)(0x3F))
#define	   EEARL	 *((volatile unsigned char*)(0x3E))
#define	   EEDR	     *((volatile unsigned char*)(0x3D))
#define	   EECR	     *((volatile unsigned char*)(0x3C))

#define	   EERE		 0
#define	   EEWE		 1
#define	   EEMWE	 2
#define	   EERIE	 3

#endif /* EEPROM_PRIVATE_H_ */