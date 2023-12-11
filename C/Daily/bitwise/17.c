/*
17. Check if Binary Representation of a Number is Palindrome. Write a function to
check if the binary representation of a number is a palindrome.
WTD: For a given integer, determine whether its binary representation reads the same
forwards and backwards. Use bitwise operations to extract each bit for the check.
(e.g.: I/P: 9 (0b1001); O/P: True)
 */

#include <stdio.h>

int main()
{
	char num = 0x88;
	int pos = 0;
	for(int i=7;i>=0;i--)
	{
		if(num >> i & 1)
		{
			pos = i;
			break;
		}
	}

	printf("%d\n",pos);


	for(int i=pos,j=0;i>=0;i--,j++)
	{
		if((num >> i & 1) != (num >> j & 1))
		{
			printf("Not a palindrome\n");
			return 0;
		}
	}
	printf("Palindrome\n");
}


