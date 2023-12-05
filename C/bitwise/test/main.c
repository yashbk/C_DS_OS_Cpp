#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    int num = 0;
    pid = fork(); 
    if(pid == 0)
    {
        num = 20;
        printf("This is child executing\n");
        printf("The child pid is %d\n",getpid());

        printf("Num from child %d and address is %p\n",num,&num);

    }
    else if(pid > 0)
    {
        num = 50;
        printf("This is parent executing\n");
        printf("Parent pid is %d and child pid is %d\n",getpid(),pid);
        printf("Num from parent %d and address is %p\n",num,&num);
    }
}


