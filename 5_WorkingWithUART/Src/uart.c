#include "uart.h"

#define UART2EN 			     (1U<<17) // Position 17 set to 1
#define GPIOAEN			     (1U<<0) //ALL bit set to 0's

#define CR1_TE                   (1U<<3) // Control register 1 (USART_CR1) Enable Transmitter
#define CR1_RE                   (1U<<2) // Control register 1 (USART_CR1) Enable Receiver

#define UART_BAUDRATE   115200 //Set standard baudrate
#define CLK 						 1600000 //16MHz

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate);

void uart2_tx_init(void)
{
	/*+++++++++++Configure UART GPIO pin+++++++++++++++++*/
	/*1. Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*2. Set PA2 mode to alternate function mode*/
	GPIOA ->MODER &= ~(1U<<4); //Set bit 4 to 0
	GPIOA ->MODER |= (1U<<5); // Set bit 5 to 1

	/*3. Set PA2 alternate function function type to AF7  (UART2_TX)*/
	GPIOA->AFR[0]  |= (1U<<8);
	GPIOA->AFR[0]  |= (1U<<9);
	GPIOA->AFR[0]  |= (1U<<10);
	GPIOA->AFR[0]  &= ~(1U<<11);

	/*+++++++++++Configure UART Module+++++++++++++++++*/
	/*4. Enable clock access to UART2*/
	RCC->APB1ENR |= UART2EN;

	/*5. Set Baudrate*/
	uart_set_baudrate(CLK, UART_BAUDRATE);

	/*6. Set transfer direction*/
	USART2->CR1 = CR1_TE;


	/*7. Enable UART Module*/
}

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
}

static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	USART2->BBR = int16_t_compute_uart_bd( periph_clk,  baudrate);
}
