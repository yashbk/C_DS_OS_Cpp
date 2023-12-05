/*
3. Detecting Power of Two. Write a program to check if a given number is a power of two using bit manipulation.
WTD: Given an integer, determine whether it is a power of 2 or not. Your solution should only use bitwise operations. Avoid using mathematical functions like logarithms or multiplication.
(e.g.: I/P: 32; O/P: True)
*/

#include <stdio.h>

int ispoweroftwo(int num)
{
    if(num < 0)
        return -1;
    else
        return num & (num-1);
}

int main()
{
    int num = 8;
    int val = ispoweroftwo(num);
    if(val == 0)
        printf("True\n");
    else
        printf("False\n");
}