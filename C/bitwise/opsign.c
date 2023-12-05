/*
14. Determine if Two Integers Have Opposite Signs. 
Write a function to determine if two integers have opposite signs using bit manipulation.
WTD: You are given two integers. 
Use bitwise operations to determine if they have opposite signs. Your function should return a boolean value.
(e.g.: I/P: -4, 5; O/P: True)
*/

#include <stdio.h>

int sign(int a,int b)
{
    if((a >> 31) & 0x01 != (b >> 31) & 0x01)
        return 1;
    else
        return 0;
}

int main()
{
    int a = -4;
    int b = 5;
    sign(a,b)?printf("True\n"):printf("False\n");
    return 0;
}