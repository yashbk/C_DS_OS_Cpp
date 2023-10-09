/*
11. Check for Alternate Bits. Write a function to check if bits in a given number are in alternate pattern.
WTD: Given an integer, check if the bits in its binary representation alternate between 0 and 1. Use bitwise operations to traverse the bits and perform the check.
(e.g.: I/P: 0b10101010; O/P: True)
*/

#include <stdio.h>

unsigned char isalternate(unsigned char num)
{
    int what = 0;
    for(int i=0;i<8;i= i+2)
    {
        if((num >> i & 0x01) == (num >> i+1 & 0x01))
        {
            what = 1;
        }
    }
    return what;
}

int main()
{
    unsigned char num = 0b01010101;
    if(isalternate(num))
    {
        printf("false\n");
    }
    else
        printf("True\n");
}