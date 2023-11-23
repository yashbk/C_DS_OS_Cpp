#include <stdio.h>
#include <limits.h>

void high_low(int *ptr,int len)
{
    int low = INT_MAX,high = INT_MIN;
    for(int i=0;i<len;i++)
    {
        if(high < ptr[i])
            high = ptr[i];
        if(low > ptr[i])
        {
            low = ptr[i];
        }
    }
    printf("The max is %d\nThe min is %d\n",high,low);

}

int main()
{
    int arr[] = {4,3,2,6,8,9,1};
    high_low(arr,sizeof(arr)/sizeof(int));
}