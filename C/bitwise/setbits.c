/*
Set Bits Without Using Arithmetic Operations. Implement a function that sets the first n bits of a byte to 1.
WTD: You are given an integer n. Use bitwise operations to set the first n bits of an 8-bit number to 1 while setting the remaining bits to 0. You cannot use arithmetic operations like addition or multiplication.
(e.g.: I/P: n=4; O/P: 0b11110000)
*/
#include <stdio.h>

void print(char val)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d ",(val >> i) & 0x01);
    }
    printf("\n");
}

void set(char *byte, int n)
{
    for(int i=n;i>=0;i++)
    {
        *byte = *byte | ((0x01 << n+1)-1);
    }
}

int main()
{
    char num = 0b00000000;
    print(num);
    set(&num,4);
    print(num);
}