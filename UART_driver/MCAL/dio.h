/*
 * dio.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Omar
 */

#ifndef DIO_H_
#define DIO_H_
#include "../MC/My_avr.h"
#include "../bit_operations.h"

/****************************************************Macros*******************************************************/
#define PA 0 //port A
#define PB 1 //port B
#define PC 2 //port C
#define PD 3 //port D
#define pin0 0 //pin0 of the port 
#define pin1 1 //pin1 of the port 
#define pin2 2 //pin2 of the port 
#define pin3 3 //pin3 of the port 
#define pin4 4 //pin4 of the port 
#define pin5 5 //pin5 of the port 
#define pin6 6 //pin6 of the port 
#define pin7 7 //pin7 of the port 
/****************************************************Functions Definetions****************************************/

/*******
	Function Description: this function sets the directions of the port whether input or output
	parameter:  port_name: is the port name 
			   pins: is an integer number specifies the pins you want to select		   
	return: none
*/
void DIO_init(uint8_t port_name, uint8_t pins );

/*******
	Function Description: this function outs a specific value on the port
	parameter: port_name: is the port name 
			   pins: is an integer number describes the output on the pins of that port  	   
	return: none
*/
void DIO_set(uint8_t port_name, uint8_t pins);

/*******
	Function Description: this function reads the coming input to the port
	parameter: port_name: is the port name 
			   pins: is an integer number specifies the pins you want to read from
	return: it returns unsigned 8-bit integer carries the read data
*/
uint8_t DIO_read(uint8_t port_name, uint8_t value );

/*******
	Function Description: function to reset(off) pins on the port
	parameter: Port_name: is the port name 
			   pins: is an integer number specifies the pins you want to reset
	return: none
*/
void DIO_CLR(uint8_t Port_name, uint8_t pins);

/*******
	Function Description: function to clear only one bit
	parameter: Port_name: is the port name 
			   pins: is an integer number specifies the pin you want to clear
	return: none
*/
void DIO_CLR_BIT(uint8_t Port_name, uint8_t pin);

/*******
	Function Description: function to set only one bit
	parameter: Port_name: is the port name 
			   pins: is an integer number specifies the pin you want to set
	return: none
*/
void DIO_SET_BIT(uint8_t Port_name, uint8_t pin);


/*******
	Function Description: function to read only one bit
	parameter: Port_name: is the port name 
			   pin: is an integer number specifies the pin you want to read
	return: returns the read bit
*/
uint8_t DIO_READ_BIT(uint8_t Port_name, uint8_t pin);
#endif /* DIO_H_ */
