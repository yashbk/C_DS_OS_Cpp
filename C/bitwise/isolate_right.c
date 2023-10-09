/*
8. Isolate the Rightmost Set Bit. Write a function to isolate the rightmost set bit of an integer.
WTD: Given an integer, isolate the rightmost bit set to 1 in its binary representation. 
Use bitwise operations to find this bit while setting all other bits to 0.
(e.g.: I/P: 0b10100000; O/P: 0b00100000)
*/

#include <stdio.h>

void rightmost(unsigned char *num)
{
    char mask = 0;
    for(int i=0;i<8;i++)
    {
        if((*num >> i) & 0x01 == 1)
        {
            mask = mask | (0x01 << i);
            break;
        }
    }
    *num = *num & mask;
}

void print(char num)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d ",(num >> i) & 0x01);
    }
    printf("\n");
}

int main()
{
    unsigned char num = 0b10100000;
    print(num);
    rightmost(&num);
    print(num);
}