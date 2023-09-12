#include <stdio.h>
#include <string.h>

void* mem_set(void *ptr, int value, int size)
{
	char *p = ptr;
	while(size)
	{
		*p = value;
		p++;
		size--;
	}
	return ptr;
}

int main()
{
	char buffer[20];
	printf("Builtin func %s\n",(char*)memset(buffer,'Y',20));
	printf("Normal %s\n",(char*)mem_set(buffer,'Z',20));
}
