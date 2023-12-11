/*
3. Detecting Power of Two. Write a program to check if a given number is a power of
two using bit manipulation.
WTD: Given an integer, determine whether it is a power of 2 or not. Your solution should
only use bitwise operations. Avoid using mathematical functions like logarithms or
multiplication.
(e.g.: I/P: 32; O/P: True)
 */

#include <stdio.h>

int main()
{

	int num = 63;
	if(num <=0)
		printf("Not power of two\n");
	else if(num & (num-1))
		printf("Not power of two\n");
	else
		printf("Power of two\n");
	return 0;
}

