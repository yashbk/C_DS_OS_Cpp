#include <stdio.h>

int main()
{
	int num = 0;
	int temp = 0;
	int rev = 0;
	printf("Enter a multidigit number\n");
	scanf("%d",&num);
	temp = num;
	while(num)
	{
		rev = rev * 10 + num%10;
		num /=10;
	}
	printf("Reverse of number %d is %d\n",temp,rev);
}
