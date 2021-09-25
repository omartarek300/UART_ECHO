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
	uart_config conf = {2400, asynchronous,one_stop_bit,no_parity, eight_bit, Disable};
	uart_init(&conf);
	//SETBIT(UCSRA, bit1);
	uart_send_byte('A',&conf);

    while (1) 
    {
		uint8_t data = uart_receive_byte(&conf);
		uart_send_byte(data,&conf);
		
    }
}

