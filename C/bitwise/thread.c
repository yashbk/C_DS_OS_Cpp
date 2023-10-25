#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

void *myThreadFun(void *vargp) 
{ 
	sleep(1); 
	printf("Printing GeeksQuiz from Thread \n");
	return vargp; 
} 

int main() 
{ 
	pthread_t thread_id; 
	int num = 65567;
	int *ptr = NULL;
	printf("Before Thread\n"); 
	pthread_create(&thread_id, NULL, myThreadFun, &num); 
	pthread_join(thread_id, (void**)&ptr); 
	printf("After Thread %d \n",*ptr);
	exit(0); 
}
