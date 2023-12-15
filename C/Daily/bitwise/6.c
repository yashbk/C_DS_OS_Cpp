/*
6. Single Number in Array. Given an array where every element appears twice except for
one, find the element using bitwise operations.
WTD: You are given an array where each element appears exactly twice except for one
element, which appears only once. Find that unique element using bitwise operations. Do
this in constant space.
(e.g.: I/P: [4,1,2,1,2]; O/P: 4)


 */

#include <stdio.h>

int main()
{
	int arr[] = {4,1,2,1,2};
	int out;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		out ^= arr[i];
		
	}
	printf("%d \n " ,out);
}

