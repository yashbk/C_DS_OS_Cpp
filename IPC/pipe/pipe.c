#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	char buffer[100];
	int fd[2],n;
	pid_t p;
	pipe(fd);
	p = fork();
	if(p > 0) //parent
	{
		printf("Passing value to child\n");
		write(fd[1],"hello\n",6);
	}
	else
	{
		printf("Child received data\n");
		n = read(fd[0],buffer,100);
		write(1,buffer,n);
	}
}
