/*
 7. Implement Bitwise Right Shift. Implement a function to perform a bitwise right shift
without using the '>>' operator.
WTD: Given an integer and a shift count, implement the bitwise right shift operation
without using the '>>' operator. Your function should return the integer after shifting its bits
to the right.
(e.g.: I/P: 0b1101, 2; O/P: 0b0011)

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
	int shift = 2;
	char num = 0b00001101;
	print(num);
	for(int i=0;i<shift;i++)
		num /=2;
	print(num);
}
