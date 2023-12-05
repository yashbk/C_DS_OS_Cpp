/*
 9) Rotate an array to the right by k steps.
WTD: Modify the array by moving its elements to the right, wrapping them around when
they reach the end, for a specified number of steps.
(e.g.: I/P: [1,2,3,4,5], k=2; O/P: [4,5,1,2,3] )

 */

#include <stdio.h>

void print(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void rotate(int *arr,int k, int len)
{
	int temp = 0;
	for(int i=0;i<k;i++)
	{
		temp = arr[len-1];
		for(int i=0;i<len-1;i++)
		{
			arr[len-i-1] = arr[len-i-2];
		}
		arr[0] = temp;
	}
}


int main()
{
	int arr[] = {1,2,3,4,5};
	int k = 2;
	int len = sizeof(arr)/sizeof(int);
	print(arr,len);
	rotate(arr,k,len);
	print(arr,len);
	return 0;
}
