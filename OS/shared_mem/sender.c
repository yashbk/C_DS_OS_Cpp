#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

#define SIZE 1024

int main()
{
	int i;
	void *shared_memory;
	char buff[100];
	int shmid; //This is required to store the id returned by shmget func
	shmid=shmget((key_t)1234, SIZE, 0666|IPC_CREAT); //creates shared memory segment with key 1022, having size 1024 bytes. IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permisions on the shared segment
	printf("Key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
	printf("Process attached at %p\n",shared_memory); //this prints the address where the segment is attached with this particular process
	printf("Enter some data to write to shared memory\n");
	fgets(buff,sizeof(buff),stdin);
	strcpy(shared_memory,buff); //data written to shared memory
	printf("You wrote : %s\n",(char *)shared_memory);
}
