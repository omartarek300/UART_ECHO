/*
 * bit_operations.h
 *
 * Created: 9/7/2021 2:40:02 PM
 *  Author: Omar
 */ 


#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

#define	SETBIT(reg,n)		((reg) |= (1 << (n)))
#define CLRBIT(reg,n)		((reg) &= ~(1<<(n)))
#define GETBIT(reg,n)		((reg) & (1 << (n)))
#define TOGGLEBIT(reg,n)	((reg) ^= (1<<(n)))



#endif /* BIT_OPERATIONS_H_ */