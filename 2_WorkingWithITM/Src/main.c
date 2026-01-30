# include "stm32f446xx.h"

int sum;

int add(int num1, int num2){
	int temp = 0;
	temp = num1 +  num2;
	return temp;
}

int main(void)
{
	int total;
	for(int i = 0; i < 10; i++)
	{
		total += 1;
	}
	sum = add(10,5);

	while(1)
	{

	}
}
