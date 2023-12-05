#include <stdio.h>

int size(char *str)
{
    int num = 0;
    while(*str)
    {
        num++;str++;
    }
    return num;
}

void my_atoi(int *num,char *str)
{
    int len = size(str);
    for(int i=0;i<len;i++)
    {
        *num = *num * 10 + (str[i] - '0');
    }
}

int main(int argc,char *argv[])
{
    int num = 0;
    argv[1] = "1234";
    my_atoi(&num,argv[1]);
    printf("%d\n",num);
}