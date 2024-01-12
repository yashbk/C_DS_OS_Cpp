#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *rd;
	char buffer[50];
	sprintf(buffer,"yashas b k");
	rd = popen("wc -c","w");
	fwrite(buffer,1,strlen(buffer),rd);
	pclose(rd);
}
