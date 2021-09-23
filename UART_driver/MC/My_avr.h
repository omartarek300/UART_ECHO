/*
 * My_avr.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */

#ifndef MY_AVR_H_
#define MY_AVR_H_
#include "../types.h"
//DIFINE BITS FOR BIT OPERATIONS
#define bit0 0
#define bit1 1
#define bit2 2
#define bit3 3
#define bit4 4
#define bit5 5
#define bit6 6
#define bit7 7

// DEFINE IO DIRECTION REGISTERS
#define DDRA *((volatile uint8_t*)(0X3A))
#define DDRB *((volatile uint8_t*)(0X37))
#define DDRC *((volatile uint8_t*)(0X34))
#define DDRD *((volatile uint8_t*)(0X31))

// Define IO DATA REGISTERS
#define PORTA *((volatile uint8_t*)(0X3B))
#define PORTB *((volatile uint8_t*)(0X38))
#define PORTC *((volatile uint8_t*)(0X35))
#define PORTD *((volatile uint8_t*)(0X32))

// DEFINE IO STATUS REGISTERS
#define PINA *((volatile uint8_t*)(0X39))
#define PINB *((volatile uint8_t*)(0X36))
#define PINC *((volatile uint8_t*)(0X33))
#define PIND *((volatile uint8_t*)(0X30))

//DEFINE TIMER0 REGISTERS
#define TCCR0 *((volatile uint8_t*)(0X53))
#define TCNT0 *((volatile uint8_t*)(0X52))
#define OCR0  *((volatile uint8_t*)(0X5C))
#define TIMSK *((volatile uint8_t*)(0X59))
#define TIFR  *((volatile uint8_t*)(0X58))

//DEFINE TIMER2 REGISTERS
#define TCCR2 *((volatile uint8_t*)(0X45))
#define TCNT2 *((volatile uint8_t*)(0X44))
#define OCR2  *((volatile uint8_t*)(0X43))

//DEFINE TIMER1 REGISTERS
#define TCCR1A  *((volatile uint8_t*)(0X4F))
#define TCCR1B  *((volatile uint8_t*)(0X4E))
#define TCNT1H  *((volatile uint8_t*)(0X4D))
#define TCNT1L  *((volatile uint8_t*)(0X4C))
#define OCR1AH  *((volatile uint8_t*)(0X4B))
#define OCR1AL  *((volatile uint8_t*)(0X4A))

//UART REGISTERS
#define UCSRC *((volatile uint8_t*)(0X40))
#define UBRRH *((volatile uint8_t*)(0X40))
#define UBRRL *((volatile uint8_t*)(0X29))
#define UDR   *((volatile uint8_t*)(0X2C))
#define UCSRA *((volatile uint8_t*)(0X2B))
#define UCSRB *((volatile uint8_t*)(0X2A))

//GLOBAL INTERRUPT
#define SREG    *((volatile uint8_t*)(0X5F))








#endif /* MY_AVR_H_ */
