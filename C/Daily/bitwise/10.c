/*
10. Reverse Bits in a Byte. Implement a function to reverse the bits in a byte.
WTD: You have an 8-bit byte. Reverse the order of its bits using bitwise operations. For
example, if the input byte is 0b11001001, the output should be 0b10010011.
(e.g.: I/P: 0b11001001; O/P: 0b10010011)

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
	unsigned int num = 0b11001001;
	print(num);
	num = (num & 0xF0) >> 4 | (num & 0x0F) << 4;
	print(num);
}


