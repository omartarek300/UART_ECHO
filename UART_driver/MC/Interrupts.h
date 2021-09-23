/*
 * Interrupts.h
 *
 * Created: 9/7/2021 11:49:17 PM
 *  Author: Omar
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../bit_operations.h"

void __vector_11(void) __attribute__((signal,used));	 // TIMER1 COMPARE MATCH A
void __vector_7(void) __attribute__((signal,used)); // ISR Timer/Counter1 Compare Match A
void __vector_9(void) __attribute__((signal,used)); // ISR Timer/Counter1 Overflow
void __vector_10(void) __attribute__((signal,used)); // ISR Timer/Counter0 Compare Match
void __vector_11(void) __attribute__((signal,used)); // ISR Timer/Counter0 Overflow
void __vector_4(void) __attribute__((signal,used)); // ISR Timer/Counter2 Compare Match
void __vector_5(void) __attribute__((signal,used)); // ISR Timer/Counter2 Overflow



#endif /* INTERRUPTS_H_ */