/*
18. Find Parity of a Number. Implement a function to check if the number of 1s in the
binary representation of a given number is even or odd.
WTD: Given an integer, find the parity of its binary representation. Use bitwise operations
to count the number of bits set to 1 and determine if it's odd or even.
(e.g.: I/P: 7 (0b0111); O/P: Odd)
 */

#include <stdio.h>

int main()
{
	char num = 0b0111;
	int parity = 0;

	for(int i=7;i>=0;i--)
	{
		if(num >> i & 1)
			parity++;
	}
	if(parity%2 == 0)
		printf("Even\n");
	else
		printf("Odd\n");
}

