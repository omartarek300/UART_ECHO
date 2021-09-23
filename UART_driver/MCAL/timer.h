/*
 * timer.h
 *
 * Created: 9/7/2021 2:26:26 AM
 *  Author: Omar
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../bit_operations.h"
#include "../MC/My_avr.h"
#include "../types.h"
#define NULL_PTR ((void *)0)
#define time_period (1024.0/1000000.0)
#define millisecond 1000.0
#define compare_match 1
#define overflow_value 255
/********************************** DEFINING TIMER NEW TYPES *************************************/
typedef enum
{
	timer0, timer1, timer2 
}Timers; // timers numbers
typedef enum
{
	normal, compare
}Modes; // timers modes
typedef enum
{
	no_clock, f_cpu_clk, f_cpu_clk_8, f_cpu_clk_32, f_cpu_clk_128, f_cpu_clk_64, f_cpu_clk_256, f_cpu_clk_1024
}pre_scaler; // prescalers
typedef struct  
{
	Timers timer_num;
	Modes  timer_mode;
	pre_scaler timer_preScale;
	uint16_tm ticks_num;
	
}config; // timer configurations 
/************************************** FUNCTION PROTOTYPE *******************************/

/*******
	Function Description: this function is responsible for setting timer first configurations and initializations
	parameter: conf: is a structure that holds all the configurations and consists of :
						1- timer number
						2- timer mode
						3- timer prescaler
						4- timer ticks or counts
	return: none
*/
void Timer_init(const config* conf);

/*******
	Function Description: this is a callback function timer call it in it's ISR to communicate with LED in the upper layer
	parameter: timer_num: to specify which timer will be used
			   Ptr2Func: pointer to function takes the address of the upper layer function
	return: none
*/
void Timer_setCallBack(Timers timer_num, void(*Ptr2Func)(void));

/*******
Function Description: this function generates a delay in milliseconds using timer0
parameter: time_ms: the time in milliseconds
return: none
*/
void delay_ms(float time_ms);



#endif /* TIMER_H_ */