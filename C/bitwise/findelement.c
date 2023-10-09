/*
6. Single Number in Array. Given an array where every element appears twice except for one, find the element using bitwise operations.
WTD: You are given an array where each element appears exactly twice except for one element, which appears only once. Find that unique element using bitwise operations. Do this in constant space.
(e.g.: I/P: [4,1,2,1,2]; O/P: 4)
*/

#include <stdio.h>

int find_single(int *arr,int size)
{
    int num = 0;
    for(int i=0;i<size;i++)
    {
        num ^= arr[i];
    }
    return num;
}

int main()
{
    int arr[] = {1,2,3,4,4,3,2,1,6,7,7,6,5};
    printf("%d ", find_single(arr,sizeof(arr)/sizeof(int)));
}