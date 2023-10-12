#include<stdio.h>

char exor(char num1, char num2)
{
    char res = 0;
    for(int i = 7;i >= 0;i--)
    {
        if(((num1>>i) & 1) == ((num2>>i) & 1))
        {
            res = res | 0;
        }
        else{
            res = res | 1;
        }
        res = res<<1;
    }
    return res;
}

int main()
{
    char num1, num2;
    printf("Enter numbers: ");
    scanf("%hhd%hhd", &num1, &num2);
    char res = exor(num1, num2);
    printf("output: %hhd\n", res);
}