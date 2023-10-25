#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int num = 0;
pthread_mutex_t var,var1;
void* thread1(void* ptr)
{
    int x = 10000;
    while(x--)
    {
        pthread_mutex_lock(&var);
        num++;
        printf("thread1 %d\n",num);
        pthread_mutex_unlock(&var);
    }
}

void* thread2(void* ptr)
{
    int x = 10000;
    while(x--)
    {
        pthread_mutex_lock(&var1);
        num--;
        printf("******thread2 %d\n",num);
        pthread_mutex_unlock(&var1);
    }
}

int main()
{
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL,thread1,NULL);
    pthread_create(&t2,NULL,thread2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t1,NULL);
    printf("%d\n",num);
}