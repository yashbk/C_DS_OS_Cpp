#include <stdio.h>
#include <string.h>

int str_len(char *str)
{
	int len = 0;
	while(*str++)
	{ 
		len++;
	}
	return len;
}

int main()
{
	char str[] = "Hello world";
	printf("Builtin func %d\n",(int)strlen(str));
	printf("Normal %d\n",str_len(str));
}
