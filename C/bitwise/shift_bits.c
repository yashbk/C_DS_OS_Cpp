#include <stdio.h>

void print(int num)
{
    for(int i=15;i>=0;i--)
    {
        printf("%d ",num >> i & 0x01);
    }
    printf("\n");
}

void shift_bits(unsigned short *num1, unsigned short *num2,short pos1, short pos2,short bits)
{
    int diff = (pos1 > pos2)?pos1-pos2:pos2-pos1;
    unsigned short mask = ((1 << pos1+bits)-1) ^ ((1 << pos1)-1);
    unsigned short value = *num1 & mask;
    *num2 = *num2 & ~(mask<< diff);
    *num2 = *num2 | (value << diff);
}

int main()
{
    short num1 = 0b0000000011111111;
    short num2 = 0x0000;
    short pos1 = 0;
    short pos2 = 8;
    short bits = 8; 
    print(num1);
    print(num2);
    shift_bits(&num1,&num2,pos1,pos2,bits);
    print(num2);
}
