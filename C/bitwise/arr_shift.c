#include <stdio.h>
#define LEFT 0
#define RIGHT 1

void shift_arr(int direction,int shifts,int *arr,int size)
{
    int temp = 0;
    if(direction == LEFT)
    {
        while(shifts)
        {
            temp = arr[0];
            for(int i=0;i<size-1;i++)
            {
                arr[i] = arr[i+1];
            }
            arr[size-1] = temp;
            shifts--;
        }
    }
    else
    {
        while(shifts)
        {
            temp = arr[size-1];
            for(int i=0;i<size-1;i++)
            {
                arr[size-1-i] = arr[size-1-i-1];
            }
            arr[0] = temp;
            shifts--;
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
    int arr[] = {1,2,3,4,5};
    print(arr,sizeof(arr)/sizeof(int));
    shift_arr(LEFT,9,arr,sizeof(arr)/sizeof(int));
    print(arr,sizeof(arr)/sizeof(int));
    shift_arr(RIGHT,9,arr,sizeof(arr)/sizeof(int));
    print(arr,sizeof(arr)/sizeof(int));
    return 0;
}