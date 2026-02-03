# include "stm32f446xx.h"
# include "uart.h"

#include <stdio.h>
int main(void)
{
	uart2_tx_init();
	while(1)
	{
		printf("Hello from main function\n\r");
	}
}
