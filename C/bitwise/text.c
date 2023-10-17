//pyramid pattern
#include <stdio.h>
#include <string.h>

void pattern(int num)
{
    int k=0;
    int bit = 0;
    for(int i=1;i<=num;i++)
    {
        bit = 0;
        k = i*2-1;
        for(int j=1;j<num*2;j++)
        {
            if(j < num - i + 1)
                {
                    printf(" ");
                }
            else if(k>0)
            {
                if(bit == 0)
                {
                    printf("*");
                    bit = 1;
                }
                else if(bit == 1)
                {
                    printf(" ");
                    bit = 0;
                }
                k--;
            }
        }
        printf("\n");
    }
}

int main(int argc,char *argv[])
{
    int num = 0;
    for(int i=0;i<strlen(argv[1]) && argc == 2;i++)
    {
        num = num * 10 + (argv[1][i] - '0');
    }
    pattern(num);
}