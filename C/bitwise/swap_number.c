/*
Write a program to swap lowest and the highest digit in a given number. Should not use an array.
Ex:
Input = 123456;
output = 623451;
Input = 612497;
Output= 692417;
*/

#include <stdio.h>

int get_large(int num, int *pos)
{
    int large = 0;
    int temp = num;
    while(num)
    {
        if(num%10 > large)
        {
            large = num%10;
        }
            
        num = num/10;
    }
    while(temp)
    {
        if(large == temp%10)
        {
            return large;
        }
        temp = temp/10;
        (*pos)++;
    }
    
}

int get_small(int num, int* pos)
{
    int small = num%10;
    int temp = num;
    num = num/10;
    while(num)
    {
        if(num%10 < small)
        {
            small = num%10;
        }
        num = num/10;
    }
    
    while(temp)
    {
        if(temp%10 == small)
        {
            return small;
        }
        temp = temp/10;
        (*pos)++;
    }
}

int foo(int val)
{
    int num = 1;
    while(val)
    {
        num = num * 10;
        val--;
    }
    return num;
    
}

int swap(int num,int small, int large,int small_pos,int large_pos)
{
    int temp_small = small_pos;
    int temp_large = large_pos;
    int temp = num;
    
    while(temp_small)
    {   
        num = num/10;
        temp_small--;
    }
    num = num/10;
    num = num * 10 + large;
    num = num * foo(small_pos) + temp % foo(small_pos);
    temp = num;
    
    while(temp_large)
    {
        num = num/10;
        temp_large--;
    }
    num = num / 10;
    num = num * 10 + small;
    num = num * foo(large_pos) + temp % foo(large_pos);
    return num;
}

int main()
{
    int num = 123456789;
    int large_pos = 0;
    int small_pos = 0;
    int small = get_small(num,&small_pos);
    int large = get_large(num,&large_pos);
    printf("swapped number = %d\n",swap(num,small,large,small_pos,large_pos));
    return 0;
}
