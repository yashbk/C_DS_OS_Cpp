#include <stdio.h>
#include <string.h>

char* str_cat(char *dest,const char *src)
{
	char *ptr = dest;
	while(*ptr++);
	while(*src)
	{
		*ptr = *src;
		ptr++; src++;
	}
	*ptr = '\0';
	return dest;
}


int main()
{
	char str1[] = " Source";
	char str2[30] = "Destination";
	printf("Builtin func %s\n",strcat(str2,str1));
	printf("Normal %s\n",str_cat(str2,str1));
}
