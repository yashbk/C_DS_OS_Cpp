#include <stdio.h>
#include <string.h>

int non_repeated(char *str)
{
    int len = strlen(str);
    int sum = 0;
    for(int i=0;i<len;i++)
    {
        sum ^=str[i];
    }
    return sum;
}


int main()
{
    char str[] = "abcdfabcd";
    printf("%c\n",non_repeated(str));
}