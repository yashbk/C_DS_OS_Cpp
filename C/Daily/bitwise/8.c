/*
8. Isolate the Rightmost Set Bit. Write a function to isolate the rightmost set bit of an
integer.
WTD: Given an integer, isolate the rightmost bit set to 1 in its binary representation. Use
bitwise operations to find this bit while setting all other bits to 0.
(e.g.: I/P: 0b10100000; O/P: 0b00100000)
 */

#include <stdio.h>

int find_bit(unsigned char num)
{
	for(int i=0;i<8;i++)
	{
		if((num >> i) & 1)
			return i;
	}
}

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
	unsigned char ip = 0b10100000;
	print(ip);
	int shift = find_bit(ip);
	ip = ip & (1 << shift);
	print(ip);
}
	
