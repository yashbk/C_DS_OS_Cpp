/*
5. Swap Odd and Even Bits. Implement a function to swap odd and even bits in an integer. 
WTD: For a given integer, swap its odd and even bits. 
Bit 1 should swap with Bit 2, Bit 3 with Bit 4, and so on. 
Use bitwise operations to perform the swapping. (e.g.: I/P: 0b10101010; O/P: 0b01010101)
*/

#include <stdio.h>
int swap(unsigned int num)
{
    unsigned int odd,even;
    odd = num & 0xAAAAAAAA;
    even = num & 0x55555555;
    odd = odd >> 1;
    even = even << 1;
    return odd | even;
}

void print(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d ",(num >> i) & 0x01);
    }
    printf("\n");
}

int main()
{
    unsigned int num = 0xAAAAAAAA;
    print(num);
    print(swap(num));

}
