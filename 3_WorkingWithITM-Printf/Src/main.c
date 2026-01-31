# include "stm32f446xx.h"
# include <string.h>
char _a[1] = {'A'};
char *pt_a = _a;

char hello[] = {"Hello from Besh"};
char *p_hello = hello;
int main(void)
{
	for(int i = 0; i < strlen(hello); i++){
		ITM_SendChar(*p_hello++);
	}
	while(1)
	{
		//ITM_SendChar(*pt_a);

	}
}
