#include <stdio.h>
#include <string.h>

int repeated(char *str)
{
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if((str[i]^str[j]) == 0)
            {
                return str[i];
            }
        }
    }
}

int main()
{
    char str[] = "abcdefgehij";
    printf("%c\n",repeated(str));
}