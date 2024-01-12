#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	FILE *rd;
	char buffer[50];
	rd = popen("ls /home/yashas/C_DS_OS_Cpp/IPC","r");
	fread(buffer,1,sizeof(buffer),rd);
	write(1,buffer,sizeof(buffer));
	printf("\n");
	pclose(rd);
}
