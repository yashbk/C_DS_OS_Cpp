/*
 5) Find duplicate numbers in an array if it contains multiple duplicates.
WTD: Examine the array to identify numbers that appear more than once. Compile a list of
these repetitive numbers.
(e.g.: I/P: [4,3,2,7,8,2,3,1]; O/P: [2,3] )
 */

#include <stdio.h>

void get_dup(int *arr,int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j= i+1;j<len ;j++)
		{
			if(arr[i] == arr[j])
				printf("%d ",arr[i]);
		}
	}
	printf("\n");
}

int main()
{
	int arr[] = {4,3,2,7,8,2,3,1};

	int len = sizeof(arr)/sizeof(int);
	get_dup(arr,len);
	return 0;
}
