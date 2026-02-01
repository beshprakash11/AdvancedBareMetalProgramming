# include "swo.h"
# include "stm32f446xx.h"
# include <stdio.h>

int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}

void log_error(char *p)
{
	printf("log error:");
	printf((char *)p);
	printf("\r\n");
}
