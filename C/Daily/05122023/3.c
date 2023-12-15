/*
3) Find the largest and smallest number in an unsorted integer array.
WTD: Navigate through the elements of the unsorted array, continuously updating the
largest and smallest values found to identify the extremities in the array.
(e.g.: I/P: [34, 15, 88, 2]; O/P: Max: 88, Min: 2 )
 */

#include <stdio.h>

struct larsma{
	int large;
	int small;
};


struct larsma foo(int *arr, int len)
{
	struct larsma obj;
	obj.large = 0;
	obj.small = 0x7FFFFFFF; 
	for(int i=0;i<len;i++) 
	{
		if(obj.small > arr[i])
			obj.small = arr[i];
		if(obj.large < arr[i])
			obj.large = arr[i];
	}
	return obj;
}


int main() {
	int arr[] = {34,15,88,2};
	struct larsma obj;
	obj = foo(arr,sizeof(arr)/sizeof(int));
	printf("Max is %d\nSmall is %d\n",obj.large,obj.small);
	return 0;
}

