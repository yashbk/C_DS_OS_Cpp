/*
 1. Write a function that toggles the 3rd and 5th bits of an 8-bit number.
WTD: You have an 8-bit number. Your task is to toggle the bits at positions 3 and 5
(counting from the least significant bit). Use bitwise operations to modify these specific bits
while leaving the others unchanged.
(e.g.: I/P: 0b10100101; O/P: 0b10000101)

 */

#include <stdio.h>

void print(char num)
{
	for(char i = 7;i>=0;i--)
	{
		printf("%d ",(num >> i) & 1);
	}
	printf("\n");
}

int main()
{
	unsigned char num = 0b10100101;
	unsigned char mask = 0;
	print(num);
	for(int i=0;i<8;i++)
	{
		if(i == 2 || i == 5)
		{
			mask = mask | (0x01 << i);
		}
	}
	print(mask);
	num = num ^ mask;
	print(num);
}
	


