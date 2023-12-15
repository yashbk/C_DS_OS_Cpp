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

void selection_sort(int *arr, int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[i] > arr[j])
			{
				arr[i] = arr[i] + arr[j];
				arr[j] = arr[i] - arr[j];
				arr[i] = arr[i] - arr[j];
			}
		}
	}

}

int main()
{
	int arr[] = {64,34,25,12,22,11,90};
	int len = sizeof(arr)/sizeof(int);

	print(arr,len);
	selection_sort(arr,len);
	print(arr,len);
	return 0;
}

