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
#define new_line 0x0d
#define NULL_PTR (void*)(0)
/************************************ UART INTERRUPTS **************************************/
void __vector_13(void) __attribute__((signal,used)); //USART, Rx Complete
void __vector_14(void) __attribute__((signal,used)); //USART Data Register Empty
void __vector_15(void) __attribute__((signal,used)); //USART, Tx Complete

/********************************** DEFINING NEW TYPES *************************************/
typedef enum
{
	RX_complete, TX_complete, DataReg_empty
}interrupt_names;
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
/********************************** GLOBAL VARIABLES *************************************/
uint8_t divisor;
uart_config conf;

/************************************** FUNCTION PROTOTYPE *********************************/
/*******
Function Description: this function initiates the UART pripheral and turn in sending and receiving
parameter: configs: a structure contains all the required configurations: baud_rate,
																		  mode;
																		  stop_bit_en;
																		  parity;
																		  data_bits;
																		  iterrupt;
return: none
*/
void uart_init(uart_config configs);

/*******
Function Description: this function sends a byte 
parameter:  data: the data needed to be sent
return: none
*/
void uart_send_byte(uint8_t data);

/*******
Function Description: this function receives a byte
parameter:  none
return: the received data
*/
uint32_t uart_receive_byte();

/*******
Function Description: this function receives a string
parameter:  none
return: none
*/
void uart_receive_string();

/*******
Function Description: this function sends a string
parameter:  string: the string needed to be sent
return: none
*/
void uart_send_string(const uint8_t* string);

/*******
	Function Description: this is a callback function timer call it in it's ISR to communicate with LED in the upper layer
	parameter: intrrupt_type: to specify which type of interrupt RXC, TXC, DATA REGISTER EMPTY
			   Ptr2Func: pointer to function takes the address of the upper layer function
	return: none
*/
void uart_setCallback(interrupt_names intrrupt_type,void (*ptr2func)(void))



#endif /* UART_H_ */