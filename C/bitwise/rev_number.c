#include <stdio.h>

int reverse(int num)
{
    int temp = 0;
    while(num)
    {
        temp = temp * 10 + num%10;
        num = num/10;
    }
    return temp;
}

int main()
{
    int num = 123456;
    printf("Reversed number is %d\n",reverse(num));
}