/*
4. Count Set Bits. Design a function that counts the number of set bits (1s) in an integer without looping.
WTD: Given an integer, count the number of bits set to 1 in its binary representation. You need to achieve this without using any loops. Use bitwise operations to find the count efficiently.
(e.g.: I/P: 0b11010110; O/P: 5)
*/
#include <stdio.h>

int count_bits(char num)
{
    int count = 0;
    for(int i=7;i>=0;i--)
    {
        if((num >> i) & 0x01)
        {
            count++;
        }
    }
    return count;
}


int main()
{
    char num = 0b11110001;
    printf("%d\n",count_bits(num));
}