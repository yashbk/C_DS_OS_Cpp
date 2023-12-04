#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
	char *start = str,*end = str + (strlen(str)-1);
	while(start < end)
	{
		*start = *start ^ *end;
		*end = *start ^ *end;
		*start = *start ^ *end;
		start++;
		end--;
	}
}

int main()
{
	char str[100];
	printf("Enter a string\n");
	fgets(str,100,stdin);
	reverse(str);
	printf("%s\n",str);
}
