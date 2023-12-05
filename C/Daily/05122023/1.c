/*
 1) Find the missing number in a given integer array of 1 to 500.
WTD: Examine an array expected to contain consecutive integers from 1 to 500. Identify
any integer that is missing from this sequence.
(e.g.: I/P: [1,2,4,5]; O/P: 3)

*/

#include <stdio.h>
#define INDEX 6
int main()
{
	int arr[500];
	int arr_sum = 0;
	int full_sum = 0;
	for(int i=0;i<500;i++)
	{
		full_sum += i+1;
		if(i == INDEX)
			continue;
		arr[i] = i+1;
		arr_sum += arr[i];
	}
	printf("%d\n",full_sum-arr_sum);
}
