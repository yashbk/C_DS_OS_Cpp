#include <stdio.h>

int ispowerofthree(int num)
{
    int even=0,odd = 0,diff = 0;
    for(int i=31;i>=0;i--)
    {
        if(i%2 == 0 && (num >> i & 0x01 == 1))
        {
            even++;
        }
        else if(num >> i & 0x01 != 0)
            odd++;
    }
    if(even > odd)
    {
        diff = even - odd;
    }
    else
        diff = odd - even;

    return diff%3;
}

int main()
{
    int num = 3;
    ispowerofthree(num)?printf("No\n"):printf("Yes\n");
}