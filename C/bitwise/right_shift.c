/*
7. Implement Bitwise Right Shift. Implement a function to perform a bitwise right shift without using the '>>' operator.
WTD: Given an integer and a shift count, implement the bitwise right shift operation without using the '>>' operator. Your function should return the integer after shifting its bits to the right.
(e.g.: I/P: 0b1101, 2; O/P: 0b0011)
*/

#include <stdio.h>

void right_shift(int *num)
{
    *num = *num/2;
}

int main()
{
    int num = 9;
    right_shift(&num);
    printf("%d\n",num);

}