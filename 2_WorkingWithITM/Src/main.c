# include "stm32f446xx.h"

char _a[1] = {'A'};
char *pt_a = _a;
int main(void)
{

	while(1)
	{
		ITM_SendChar(*pt_a);

	}
}
