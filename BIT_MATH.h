/*
 * BIT_MATH.h
 *
 * Created: 7/4/2023 7:50:12 PM
 *  Author: Osama
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define		SET_BIT(reg,bit)	reg |= (1<<(bit))
#define		CLR_BIT(reg,bit)	reg &= (~(1<<(bit)))
#define		TOG_BIT(reg,bit)	reg ^= (1<<(bit))
#define		GET_BIT(reg,bit)	((reg & (1<<(bit)))>>(bit))

#endif /* BIT_MATH_H_ */