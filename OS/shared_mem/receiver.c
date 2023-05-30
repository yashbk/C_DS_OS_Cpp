/* Program to read data sent by another process*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid=shmget((key_t)1234, 1024, 0666); //The values given should be same as sender
	printf("Key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
	printf("Process attached at %p\n",shared_memory);
	printf("Data read from shared memory is : %s\n",(char *)shared_memory);
	printf("Memory detachment status %d\n",shmdt(shared_memory)); //Detaching the shared memory address space
}
