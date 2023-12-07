/*
13) Merge two sorted arrays to produce one sorted array.
WTD: Sequentially compare the elements of two sorted arrays, combining them into a
single array that remains sorted.
(e.g.: I/P: [1,3,5], [2,4,6]; O/P: [1,2,3,4,5,6] )

 */

#include <stdio.h>

void combine(int *arr1,int *arr2,int len1,int len2)
{
	int i=0,j=0,m=0;
	while(m < (len1 + len2))
	{
		if(arr1[i]<= arr2[j] && i < len1)
		{
			printf("%d ",arr1[i++]);
		}
		else if(j < len2)
			printf("%d ",arr2[j++]);
		m++;
	}
}

int main()
{
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,3,4,5};

	int len1 = sizeof(arr1)/sizeof(int);
	int len2 = sizeof(arr2)/sizeof(int);

	combine(arr1,arr2,len1,len2);
}
