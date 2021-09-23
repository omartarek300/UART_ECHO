/*
 * UART_driver.c
 *
 * Created: 9/22/2021 10:33:34 PM
 * Author : Omar
 */ 

#include "MCAL/uart.h"
#include "MCAL/timer.h"
int main(void)
{
    /*Replace with your application code */
	uart_config conf = {9600, asynchronous,two_stop_bit,even_parity, eight_bit, Disable};
	uart_init(&conf);
    while (1) 
    {
		uint8_t data = uart_receive_byte(&conf);
		uart_send_byte(data,&conf);
		
    }
}

