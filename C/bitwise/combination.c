/*
9. Generate All Possible Combinations of n Bits. Design a program that generates all the possible combinations of n bits.
WTD: For a given integer n, generate all possible binary sequences of length n using bitwise operations.
The output should be a list of all these combinations.
(e.g.: I/P: n=3; O/P: 000, 001, 010, 011, 100, 101, 110, 111)
*/

#include <stdio.h>

void print(int num, int size)
{
    for(int i=size-1;i>=0;i--)
    {
        printf("%d ",(num >> i) & 0x01);
    }
    printf("\n");
}

int combination(int num)
{
    int val = 0;
    for(int i=0;i < (1 << num);i++)
    {
        print(val,num);
        val++;
    }
}

int main()
{
    combination(3);
}
