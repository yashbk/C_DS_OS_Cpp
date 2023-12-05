/*
12. Extract n Bits. Design a function to extract n bits from a byte starting from a given position p .
WTD: You have a byte, and you need to extract n bits starting from a given position p. 
Use bitwise operations to isolate these n bits and return them as an integer.
(e.g.: I/P: Byte: 0b10101100, n=3, p=2; O/P: 0b101
*/

#include <stdio.h>

unsigned char extract(unsigned char num, short start,short len)
{
    unsigned char mask = 0;
    char count = 0;
    for(int i=7-start;count< len;i--)
    {
        mask = (mask | (num >> i & 0x01)) << 1;
        count++;
    }
    return mask = mask  >> 1;
}

void print(int num,int size)
{
    for(int i=size;i>=0;i--)
    {
        printf("%d ",num >> i & 0x01);
    }
    printf("\n");
}
int main()
{
    unsigned char num = 0b11101111;
    print(num,7);
    print(extract(num,2,3),2);
}