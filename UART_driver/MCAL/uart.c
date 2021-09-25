/*
 * uart.c
 *
 * Created: 9/22/2021 10:37:56 PM
 *  Author: Omar
 */ 
#include "uart.h"
/**************************************************************************************************************
 *                                                 ISRs UART
 * *************************************************************************************************************/
static void( *RX_CALL_BACK) (void) = NULL_PTR;
static void( *TX_CALL_BACK) (void) = NULL_PTR;
static void( *DATA_REGEmpty_CALL_BACK) (void) = NULL_PTR;
void uart_setCallback(interrupt_names intrrupt_type,void (*ptr2func)(void))
{
	if(intrrupt_type == RX_complete)
	{
		RX_CALL_BACK = ptr2func;
	}
	else if(intrrupt_type == TX_complete)
	{
		TX_CALL_BACK = ptr2func;
	}
	else if(intrrupt_type == DataReg_empty)
	{
		DATA_REGEmpty_CALL_BACK = ptr2func;
	}
}
void __vector_13(void)//USART, Rx Complete
{
	(*RX_CALL_BACK)();
}
void __vector_14(void)//USART Data Register Empty
{
	(*TX_CALL_BACK)();
}
void __vector_15(void)//USART, Tx Complete
{
	(*DATA_REGEmpty_CALL_BACK)();	
}

void uart_init(uart_config configs)
{
	conf = configs;
	//select the mode
	if(conf.mode == asynchronous)
	{
		divisor = asynchronous;
		SETBIT(UCSRC, bit7);  // enable writing to UCSRC
		CLRBIT(UCSRC, bit6);  //asynchronous
		CLRBIT(UCSRA, bit1); //double speed off
	}
	else if(conf.mode == asynchronous_double_speed)
	{
		divisor = asynchronous_double_speed;
		SETBIT(UCSRC, bit7); // enable writing to UCSRC
		CLRBIT(UCSRC, bit6);  //asynchronous
		SETBIT(UCSRA, bit1); //double speed on
		
	}
	else if(conf.mode == synchronous)
	{
		divisor = synchronous;
		SETBIT(UCSRC, bit7); // enable writing to UCSRC
		SETBIT(UCSRC, bit6); 
		SETBIT(UCSRC, bit0);  //set UCPOL bit
	}
	/*enable interrupt*/
	if(conf.iterrupt == Enable)
	{
		SETBIT(UCSRB, bit7); //RX Complete Interrupt Enable
		SETBIT(UCSRB, bit6); //TX Complete Interrupt Enable
		SETBIT(UCSRB, bit5); //Data Register Empty Interrupt Enable
	}
	
	/* Enable receiver and transmitter */
	SETBIT(UCSRB, bit4);
	SETBIT(UCSRB, bit3);
	
	/* Set frame format: 8data, 2stop bit */
	SETBIT(UCSRC, bit7); // enable writing to UCSRC
	switch(conf.parity) // select parity
	{
		case no_parity:
			CLRBIT(UCSRC, bit4);
			CLRBIT(UCSRC, bit5);
			break;
		case reserved:
			SETBIT(UCSRC, bit4);
			CLRBIT(UCSRC, bit5);
			break;
		case even_parity:
			CLRBIT(UCSRC, bit4);
			SETBIT(UCSRC, bit5);
			break;
		case odd_parity:
			SETBIT(UCSRC, bit4);
			SETBIT(UCSRC, bit5);
			break;	
	}
	// stop bit
	if(conf.stop_bit_en == one_stop_bit)
	{
		SETBIT(UCSRC, bit7); // enable writing to UCSRC
		CLRBIT(UCSRC,bit3);
	}
	else if(conf.stop_bit_en == two_stop_bit)
	{
		SETBIT(UCSRC, bit7); // enable writing to UCSRC
		SETBIT(UCSRC,bit3);
	}
	SETBIT(UCSRC, bit7); // enable writing to UCSRC
	// select data bits in frame
	switch(conf.data_bits)
	{
		case five_bit:
			CLRBIT(UCSRC, bit1);
			CLRBIT(UCSRC, bit2);
			CLRBIT(UCSRB, bit2);
			break;
		case six_bit:
			SETBIT(UCSRC, bit1);
			CLRBIT(UCSRC, bit2);
			CLRBIT(UCSRB, bit2);
			break;
		case seven_bit:
			CLRBIT(UCSRC, bit1);
			SETBIT(UCSRC, bit2);
			CLRBIT(UCSRB, bit2);
			break;
		case eight_bit:
			SETBIT(UCSRC, bit1);
			SETBIT(UCSRC, bit2);
			CLRBIT(UCSRB, bit2);
			break;
		case nine_bit:
			SETBIT(UCSRC, bit1);
			SETBIT(UCSRC, bit2);
			SETBIT(UCSRB, bit2);
			break;	
	}
	/* Set baud rate */
	short unsigned int UBRR_value = ((F_CPU/(divisor * conf.baud_rate)) - 1);
	CLRBIT(UCSRC, bit7); // enable writing to UBRR
	UBRRL = (uint8_t)(UBRR_value);
	UBRRH = (uint8_t)(UBRR_value >> 8);
}
void uart_send_byte(uint8_t data)
{
	if(conf.data_bits == eight_bit || conf.data_bits == five_bit || conf.data_bits == six_bit || conf.data_bits == seven_bit)
	{
		/* Wait for empty transmit buffer */
		while (!GETBIT(UCSRA, bit5));
		/* Put data into buffer, sends the data */
		UDR = data;
		SETBIT(UCSRA,bit6);
	}
	else if(conf.data_bits == nine_bit)
	{
		/* Wait for empty transmit buffer */
		while ( !GETBIT(UCSRA, bit5));
		/* Copy 9th bit to TXB8 */
		CLRBIT(UCSRB, bit0);
		SETBIT(UCSRB, bit0);
		/* Put data into buffer, sends the data */
		UDR = data;
	}
}
uint32_t uart_receive_byte()
{
	SETBIT(UCSRA,bit6); //TX Finished sending data and now UDR is waiting for received data
	if(conf.data_bits == eight_bit || conf.data_bits == five_bit || conf.data_bits == six_bit || conf.data_bits == seven_bit)
	{
		/* Wait for data to be received */
		while (!GETBIT(UCSRA,bit7));
		/* Get and return received data from buffer */
		return UDR;
	}
	else if(conf.data_bits == nine_bit)
	{
		uint8_t status, ninth_bit, data_eight_bits;
		/* Wait for data to be received */
		while ( !GETBIT(UCSRA,bit7) );
		/* Get status and 9th bit, then data */
		/* from buffer */
		status = UCSRA;
		ninth_bit = UCSRB;
		data_eight_bits = UDR;
		/* If error, return -1 */
		if ( status & ((1<<bit4)|(1<<bit3)|(1<<bit2)))
		return -1;
		/* Filter the 9th bit, then return */
		ninth_bit = (ninth_bit >> 1) & 0x01;
		return ((ninth_bit << 8) | data_eight_bits);
	}
}
void uart_send_string(const uint8_t* str)
{
	uint8_t char_index =0;
	while(str[char_index] != '\0')
	{
		uart_send_byte(str[char_index]);
		char_index++;
	}
}
void uart_receive_string(uint8_t* str)
{
	uint8_t char_index =0;
	str[char_index] = uart_receive_byte();
	while(str[char_index] != '#')
	{
		char_index++;
		str[char_index] = uart_receive_byte();
	}
	str[char_index] = '\0';
}

