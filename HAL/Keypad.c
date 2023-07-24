/*
 * Keypad.c
 *
 * Created: 7/23/2023 1:26:27 AM
 *  Author: Osama
 */ 
#include "BIT_MATH.h"
#include "Keypad.h"
void Keypad_init(void)
{
	DIO_setPinDirection(PORT,0,1);
	DIO_setPinDirection(PORT,1,1);
	DIO_setPinDirection(PORT,2,1);
	DIO_setPinDirection(PORT,3,1);
	DIO_setPinDirection(PORT,4,0);
	DIO_setPinDirection(PORT,5,0);
	DIO_setPinDirection(PORT,6,0);
	DIO_setPinDirection(PORT,7,0);
	DIO_connectInternalPullup(PORT,4,1);
	DIO_connectInternalPullup(PORT,5,1);
	DIO_connectInternalPullup(PORT,6,1);
	DIO_connectInternalPullup(PORT,7,1);
}

unsigned char Keypad_read(void)
{
	unsigned char arr[4][4]={{'7','8','9','/'},
							 {'4','5','6','*'},
							 {'1','2','3','-'},
							 {'A','0','=','+'}};
	unsigned char row , col , read_val ;
	unsigned char ret_val = NOTPRESSED ;
	for(row = 0;row < 4;row++)
	{
		DIO_setPinValue(PORT,0,1);
		DIO_setPinValue(PORT,1,1);
		DIO_setPinValue(PORT,2,1);
		DIO_setPinValue(PORT,3,1);
		DIO_setPinValue(PORT,row,0);
		for(col = 0;col < 4;col++)
		{
			read_val = DIO_getPinValue(PORT,col+4);
			if(read_val == 0)
			{
				ret_val = arr[row][col];
				break ;
			}
		}
		if(read_val == 0)
		{
			break ;
		}
	}
	return ret_val;
}