/*
11. Check for Alternate Bits. Write a function to check if bits in a given number are in
alternate pattern.
WTD: Given an integer, check if the bits in its binary representation alternate between 0
and 1. Use bitwise operations to traverse the bits and perform the check.
(e.g.: I/P: 0b10101010; O/P: True)

 */

#include <stdio.h>
#define CHAR 8

int is_alternate(unsigned char  num)
{
	int prev = num >> 7 & 1;
	for(int i=6;i>=0;i--)
	{
		if(num >> i & 1 == prev)
			return 0;
		prev = num >> i & 1;
	}
	return 1;
}

int main()
{
	int ip = 0b10101010;
	if(is_alternate(ip))
		printf("Alternate\n");
	else
		printf("Not alternate\n");
}

