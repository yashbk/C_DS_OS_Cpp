#include <stdio.h>
#include <pthread.h>

int num = 0;
pthread_mutex_t lock;

void* handler(void *arg)
{
    pthread_mutex_lock(&lock);
    num++;
    printf("Started %d\n",num);
    for(int i=0;i<0xFFFFFFFF;i++)
    ;
    printf("Stopped %d\n",num);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t[2];

    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }

    for(int i=0;i<2;i++)
    {
        pthread_create(&t[i],NULL,handler,NULL);
    }
        pthread_join(t[0],NULL);
        pthread_join(t[1],NULL);
    printf("%d\n",num);
}