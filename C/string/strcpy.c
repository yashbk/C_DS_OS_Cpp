#include <stdio.h>
#include <string.h>

char* str_cpy(char *dest,const char *src)
{
	int i=0;
	while(*(src+i))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return  dest;
}

int main()
{
	char str1[] = "Hello world";
	char str2[20] = "";
	char str3[] = "Hello world";
	char str4[20] = "";
	printf("Builtin func %s\n",strcpy(str2,str1));
	printf("Normal %s\n",str_cpy(str4,str3));
}
