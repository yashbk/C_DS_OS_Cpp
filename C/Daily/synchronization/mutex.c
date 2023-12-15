#include <stdio.h>
#include <pthread.h>
#include <string.h>

int shared_data = 0;

pthread_mutex_t mutex; //Mutex variable

void* thread_function(void * some)
{
	int i = 20;
	while(i--){
	pthread_mutex_lock(&mutex);
	shared_data++;
	printf("thread%d and data %d\n",*(int*)some,shared_data);
	pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_mutex_init(&mutex,NULL);

	pthread_t threads[2];
	int t[] = {1,2};

	for(int i=0;i<2;i++){
		pthread_create(&threads[i],NULL,thread_function,&t[i]);
	}

	for(int i=0;i<2;i++){
		pthread_join(threads[i],NULL);
	}

	pthread_mutex_destroy(&mutex);
	return 0;
}

