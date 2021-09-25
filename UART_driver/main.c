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
	uart_config conf = {2400, asynchronous, one_stop_bit, no_parity, eight_bit, Disable};
	uart_init(conf);
	uint8_t* string = "";
    while (1) 
    {
		uart_receive_string(string);
		uart_send_byte(new_line);
		uart_send_string(string);
		uart_send_byte(new_line);
    }
}

