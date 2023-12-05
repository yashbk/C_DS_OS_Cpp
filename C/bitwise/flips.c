/*
13. Count Number of Flips to Convert A to B. 
Implement a function that counts the number of flips required to convert integer A to integer B .
WTD: You are given two integers A and B. 
Determine the number of bits you need to flip to convert A into B using bitwise operations.
(e.g.: I/P: A=29 (0b11101), B=15 (0b01111); O/P: 2)
*/

#include <stdio.h>

int flip(char ip, char op)
{
    unsigned char val = ip ^ op;
    int count = 0;
    for(int i=7;i>=0;i--)
    {
        if((val >> i & 0x01) == 1)
            count++;
    }
    return count;
}

int main()
{
    char ip = 29;
    char op = 15;
    printf("%d\n",flip(ip,op));
    return 0;
}