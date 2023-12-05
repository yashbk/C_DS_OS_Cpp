#include <stdio.h>

int bubble(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }
}

void print(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int main()
{
    int arr[] = {4,3,6,2,78,9,3,2,4,6,3};
    print(arr,sizeof(arr)/sizeof(int));
    bubble(arr,sizeof(arr)/sizeof(int));
    print(arr,sizeof(arr)/sizeof(int));
}