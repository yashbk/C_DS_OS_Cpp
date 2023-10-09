/*
10. Reverse Bits in a Byte. Implement a function to reverse the bits in a byte.
WTD: You have an 8-bit byte. Reverse the order of its bits using bitwise operations. For example, if the input byte is 0b11001001, the output should be 0b10010011.
(e.g.: I/P: 0b11001001; O/P: 0b10010011)
*/

#include <stdio.h>
int reverse(unsigned int num)
{
    unsigned int rev = 0;
    for(int i=0;i<32;i++)
    {
        rev = rev | ((num >> i) & 0x01);
        rev = rev << 1;
    }
    return rev;
}

void print(unsigned int num)
{
    for(int i=31;i>=0 ;i--)
    {
        printf("%d ",(num >> i) & 0x01);
    }
    printf("\n");
}

int main()
{
    unsigned int num = 0x0000FFFF;
    print(num);
    unsigned int rev = reverse(num);
    print(rev);
}