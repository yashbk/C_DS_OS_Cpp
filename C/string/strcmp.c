#include <stdio.h>
#include <string.h>

int str_cmp(const char *str1,const char *str2)
{
	while(*str1 || *str2)
	{
		if(*str1 != *str2)
		{
			return (int)*str1 - (int)*str2;
		}
		str1++;str2++;
	}
	return 0;
}

int main()
{
	char str1[] = "Hello world";
	char str2[20] = "Hello world";
	printf("Builtin func %d\n",strcmp(str2,str1));
	printf("Normal %d\n",str_cmp(str2,str1));
}
