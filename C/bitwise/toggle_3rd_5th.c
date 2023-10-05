/*
1. Write a function that toggles the 3rd and 5th bits of an 8-bit number.
WTD: You have an 8-bit number. Your task is to toggle the bits at positions 3 and 5 (counting from the least significant bit). Use bitwise operations to modify these specific bits while leaving the others unchanged.
(e.g.: I/P: 0b10100101; O/P: 0b10001101)
*/

#include <stdio.h>

void toggle(unsigned char *num)
{
    char mask = 0b00101000;
    *num = *num ^ mask;
}

void print(char val)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d ",(val >> i) & 0x01);
    }
    printf("\n");
}

int main()
{
    unsigned char val = 0b10100101;
    print(val);
    toggle(&val);
    print(val);
}