/*
14. Determine if Two Integers Have Opposite Signs. Write a function to determine if
two integers have opposite signs using bit manipulation.
WTD: You are given two integers. Use bitwise operations to determine if they have
opposite signs. Your function should return a boolean value.
(e.g.: I/P: -4, 5; O/P: True)

 */

#include <stdio.h>

int main()
{
	int a = 4;
	int b = 5;
	if((a >> 31) & 1 != (b >> 31) & 1)
		printf("YES\n");
	else
		printf("NO\n");
}
