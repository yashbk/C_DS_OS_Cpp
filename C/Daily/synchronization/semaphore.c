#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int counter = 0;
sem_t semaphore;


void * increment(void * some)
{
	for(int i=0;i<10;i++)
	{
		sem_wait(&semaphore);
		counter++;
		printf("Increment %d\n",counter);
		sem_post(&semaphore);
	}
	return NULL;
}

void * decrement(void * some)
{
	for(int i=0;i<10;i++)
	{
		sem_wait(&semaphore);
		counter--;
		printf("Decrement %d\n",counter);
		sem_post(&semaphore);
	}
	return NULL;
}

int main()
{
	sem_init(&semaphore,0,1);

	pthread_t threads[2];

	pthread_create(&threads[0],NULL,increment,NULL);
	pthread_create(&threads[1],NULL,decrement,NULL);
	
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);

	sem_destroy(&semaphore);
	printf("Count value %d\n",counter);
	return 0;
}
