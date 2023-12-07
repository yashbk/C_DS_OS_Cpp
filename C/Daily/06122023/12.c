/*
 12) Move all zeros to the left of an array while maintaining the order of other numbers.
WTD: Reorder the array by moving all zero values to the leftmost positions while ensuring
the relative order of the non-zero numbers remains unchanged.
(e.g.: I/P: [1,2,0,4,3,0,5,0]; O/P: [0,0,0,1,2,4,3,5] )

 *
 */

#include <stdio.h>

void print(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
}	


void move_left(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		if(arr[i] == 0)
		{
			for(int j=0;j<i;j++)
			{
				arr[i-1-j]  =  arr[i-1-j] ^ arr[i-j];
				arr[i-j]  =  arr[i-1-j] ^ arr[i-j];
				arr[i-1-j]  =  arr[i-1-j] ^ arr[i-j];
			}
		}
	}
}


int main()
{
	int arr[] = {1,2,0,4,3,0,5,0};
	int len = sizeof(arr)/sizeof(int);
	print(arr,len);
	move_left(arr,len);
	print(arr,len);
	return 0;
}

