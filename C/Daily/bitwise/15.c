/*
15. Mask Certain Bits. Implement a function that masks (sets to zero) all bits except for
the first n bits of an integer.
WTD: Given an integer, mask (set to zero) all but the first n bits. Use bitwise operations to
perform this masking and return the resulting integer.
(e.g.: I/P: 0b10101111, n=4; O/P: 0b00001111)
 */

#include <stdio.h>

void print(int num)
{
	for(int i=7;i>=0;i--)
		printf("%d ",num >> i & 1);
	printf("\n");
}


int main()
{
	unsigned char num = 0b10101111;
	int n = 4;
	unsigned char mask = (1 << n)-1;
	num = num & mask;
	print(num);
}
	       	
		
