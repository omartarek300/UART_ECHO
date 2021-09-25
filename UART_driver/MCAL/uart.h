/*
 * uart.h
 *
 * Created: 9/22/2021 10:38:09 PM
 *  Author: Omar
 */ 


#ifndef UART_H_
#define UART_H_
#include "../MC/My_avr.h"
#include "../bit_operations.h"
#define F_CPU 8000000UL
#define Enable 1
#define Disable 0
/********************************** GLOBAL VARIABLES *************************************/
 uint8_t divisor;
/********************************** DEFINING NEW TYPES *************************************/
typedef enum
{
	five_bit, six_bit, seven_bit, eight_bit, nine_bit = 7
}bit_size;
typedef enum
{
	one_stop_bit, two_stop_bit
}stop_bit;
typedef enum
{
	asynchronous = 16UL, asynchronous_double_speed = 8UL, synchronous = 2UL
}modes;
typedef enum
{
	no_parity, reserved, even_parity, odd_parity
}parity_mode;
typedef struct
{
	uint16_tm baud_rate;
	modes mode;
	stop_bit stop_bit_en;
	parity_mode parity;
	bit_size data_bits;
	uint8_t iterrupt;
}uart_config;
/************************************** FUNCTION PROTOTYPE *********************************/
void uart_init(uart_config* conf);
void uart_send_byte(uint8_t data, uart_config* conf);
uint8_t uart_receive_byte(uart_config* conf);

/*
void uart_receive_string();
void uart_send_byte();
void uart_send_string();*/




#endif /* UART_H_ */