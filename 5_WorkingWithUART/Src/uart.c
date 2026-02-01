#include "uart.h"

#define UART2EN 			(1U<<17) // Position 17 set to 1

void uart2_tx_init(void)
{
	/*+++++++++++Configure UART GPIO pin+++++++++++++++++*/
	/*1. Enable clock access to GPIOA*/
	/*2. Set PA2 mode to alternate function mode*/
	/*3. Set PA2 alternate function function type to AF7  (UART2_TX)*/


	/*+++++++++++Configure UART Module+++++++++++++++++*/
	/*4. Enable clock access to UART2*/
	/*5. Set Baudrate*/
	/*6. Set transfer direction*/
	/*7. Enable UART Module*/
}
