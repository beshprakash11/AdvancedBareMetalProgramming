# include "stm32f446xx.h"
# include <string.h>
# include <stdio.h>
char _a[1] = {'A'};
char *pt_a = _a;

char hello[] = {"Hello from Besh"};
char *p_hello = hello;

int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}
int main(void)
{
	printf("Printf is now available");
	while(1)
	{
		//ITM_SendChar(*pt_a);

	}
}
