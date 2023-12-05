#include <stdio.h>

int main()
{
	printf("With volatile keyword:\n");
	volatile int num = 2,x;
	x = ++num + ++num;// + ++num + ++num;
	printf("x is %d and num is %d\n",x,num);

	printf("Without volatile keyword:\n");
	int num1 = 2,y;
	y = ++num1 + ++num1;
	printf("y is %d and num1 is %d\n",y,num1);

}
