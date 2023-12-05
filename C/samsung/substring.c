#include <stdio.h>
#include <string.h>

int is_substring(char *str1,char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i=0,j=0;
    while(i<len1 && j < len2)
    {
        if(str1[i] == str2[j])
        {
            j++;
        }
        i++;
    }
    return (j == len2);
}

int main()
{
    char str1[] = "abcdefgh";
    char str2[] = "agd";

    if(is_substring(str1,str2))
    {
        printf("It is a substring\n");
    }
    else
        printf("It is not a substring\n");
}