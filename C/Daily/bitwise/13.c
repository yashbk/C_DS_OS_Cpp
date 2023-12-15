/*
13. Count Number of Flips to Convert A to B. Implement a function that counts the
number of flips required to convert integer A to integer B .
WTD: You are given two integers A and B. Determine the number of bits you need to flip
to convert A into B using bitwise operations.
(e.g.: I/P: A=29 (0b11101), B=15 (0b01111); O/P: 2)
 */

#include <stdio.h>

int main()
{
	char num1 = 29;
	char num2 = 15;
	char out = num1 ^ num2;
	int count = 0;
	for(int i=7;i>=0;i--)
	{
		if(out >> i & 1)
			count++;
	}
	printf("%d\n",count);
}
