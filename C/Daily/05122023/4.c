/*
 4) Find all pairs of an integer array whose sum is equal to a given number.
WTD: Explore combinations of integer pairs in the array. Check if the sum of any of these
pairs matches a specified target number.
(e.g.: I/P: [2,4,3,5,6,-2,4,7,8,9], Sum: 7; O/P: [2,5],[4,3] )
 */

#include <stdio.h>

void print_pair(int *arr,int i,int j)
{
	printf("[%d,%d]",arr[i],arr[j]);
}

void get_pair(int *arr,int len,int num)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[i] + arr[j] == num)
				print_pair(arr,i,j);
		}
	}
	printf("\n");
}

int main()
{
	int num = 7;
	int arr[] = {2,4,3,5,6,-2,4,7,8,9};
	int len = sizeof(arr)/sizeof(int);

	get_pair(arr,len,num);
	return 0;
}
