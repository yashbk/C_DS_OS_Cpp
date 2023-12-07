/*
 *
2. Set Bits Without Using Arithmetic Operations. Implement a function that sets the
first n bits of a byte to 1.
WTD: You are given an integer n. Use bitwise operations to set the first n bits of an 8-bit
number to 1 while setting the remaining bits to 0. You cannot use arithmetic operations like
addition or multiplication.
(e.g.: I/P: n=4; O/P: 0b11110000)

 */


#include <stdio.h>

void print(int num)
{
	for(int i=7;i>=0;i--)
	{
		printf("%d ",(num >> i) & 1);
	}
	printf("\n");
}

int main()
{
	char num = 0;
	int n = 4;
	for(int i=7;i>=0 && n--;i--)
	{
		num = ((unsigned char)1 << i) | num;
	}

	print(num);
}		

