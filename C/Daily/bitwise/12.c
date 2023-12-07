/*
12. Extract n Bits. Design a function to extract n bits from a byte starting from a given
position p .
WTD: You have a byte, and you need to extract n bits starting from a given position p. Use
bitwise operations to isolate these n bits and return them as an integer.
(e.g.: I/P: Byte: 0b10101100, n=3, p=2; O/P: 0b101

 */


#include <stdio.h>

int extract_bits(unsigned char num,int n,int pos)
{
	int out = 0;
	for(int i=7-pos;n--;i--)
	{
		out = out << 1;
		out = out | (num >> i) & 1;
		
	}
	return out;
}

void print(char num)
{
	for(int i=7;i>=0;i--)
	{

		printf("%d ",num >> i & 1);
	}
	printf("\n");
}


int main()
{
	unsigned char num = 0b10101100;
	int n = 3,pos = 2;
	print(extract_bits(num,n,pos));
}
