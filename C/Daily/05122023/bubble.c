/*
 6) Sort an array using quicksort algorithm.
WTD: Implement the quicksort sorting technique on the provided array to rearrange its
elements in ascending order.
(e.g.: I/P: [64, 34, 25, 12, 22, 11, 90]; O/P: [11, 12, 22, 25, 34, 64, 90] )

 */

#include <stdio.h>

void print(int *arr,int len)
{
	for(int i=0;i<len ;i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
}

void bubble_sort(int *arr, int len)
{
	for(int i=1;i<len;i++)
	{
		for(int j=0;j<len-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}


}

int main()
{
	int arr[] = {64,34,25,12,22,11,90};
	int len = sizeof(arr)/sizeof(int);

	print(arr,len);
	bubble_sort(arr,len);
	print(arr,len);
	return 0;
}

