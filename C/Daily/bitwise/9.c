/*
9. Generate All Possible Combinations of n Bits. Design a program that generates all
the possible combinations of n bits.
WTD: For a given integer n, generate all possible binary sequences of length n using bitwise
operations. The output should be a list of all these combinations.
(e.g.: I/P: n=3; O/P: 000, 001, 010, 011, 100, 101, 110, 111)

 */

#include <stdio.h>

void print(int num,int bits)
{
    for(int i = bits-1;i>=0;i--)
    {
        printf("%d ", (num >> i) & 1);
    }
    printf("\n");
}

void generateBinary(int n) {
    int max_combination = 1 << n; // Calculate the maximum combination (2^n)

    for (int i = 0; i < max_combination; ++i) {
        print(i,n);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("All possible combinations of %d bits:\n", n);
    generateBinary(n);

    return 0;
}

