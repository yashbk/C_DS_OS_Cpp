/*
5. Swap Odd and Even Bits. Implement a function to swap odd and even bits in an
integer.
WTD: For a given integer, swap its odd and even bits. Bit 1 should swap with Bit 2, Bit 3
with Bit 4, and so on. Use bitwise operations to perform the swapping.
(e.g.: I/P: 0b10101010; O/P: 0b01010101)

 */


#include <stdio.h>

void print(char num)
{
	for(int i=7;i>=0;i--)
	{
		printf("%d ",(num >> i) & 1);
	}
	printf("\n");
}

int main()
{
	char num = 0b10011011;
	print(num);
	num = (num & (unsigned char)0xAA)>>1 | (num & (unsigned char)0x55) << 1;
	print(num);
}

	
