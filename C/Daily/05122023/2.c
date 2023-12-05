/*
   2) Find the duplicate number on a given integer array.
WTD: Inspect the provided array. Determine if there's any integer that appears more
frequently than it should, signifying a duplicate.
(e.g.: I/P: [3,1,3,4,2]; O/P: 3 )

*/

#include <stdio.h>

int main()
{
	int arr[] = {3,1,3,4,2};
	int len = sizeof(arr)/sizeof(int);

	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[i] == arr[j])
				printf("%d\n",arr[i]);
		}
	}
}


