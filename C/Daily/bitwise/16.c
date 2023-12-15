/*
16. Rotate Bits. Design a program to rotate bits of a number to the left by k positions.
WTD: You have an integer and a number k. Rotate the bits of the integer to the left by k
positions using bitwise operations.
(e.g.: I/P: 0b10110011, k=3; O/P: 0b10011101)
 */

#include <stdio.h>

void print(char num)
{
	for(int i=7;i>=0;i--)
		printf("%d ",num >> i & 1);
	printf("\n");
}

int main()
{
	unsigned char num = 0b10110011;
	int k = 3;
	print(num);
	int bit = 0;
	while(k--)
	{
		bit = num >> 7 & 1;
		num = num << 1;
		if(bit)
			num = num | bit;
	}
	print(num);
}

