/*
7) Remove duplicates from an array without using any library.
WTD: Navigate through the array, identifying and removing any repetitive occurrences of
numbers, ensuring each number appears only once.
(e.g.: I/P: [1,1,2,2,3,4,4]; O/P: [1,2,3,4])
 */

#include <stdio.h>

void print(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
}

void rem_dup(int *arr,int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[i] == arr[j])
			{
				for(int k=j;k<len-1;k++)
				{
					arr[k] = arr[k+1];
				}
				arr[len-1] = 0;
			}
		}
	}
}

int main()
{
	int arr[] = {1,1,2,2,3,3,4,4};
	int len = sizeof(arr)/sizeof(int);
	print(arr,len);
	rem_dup(arr,len);
	print(arr,len);
	return 0;
}
