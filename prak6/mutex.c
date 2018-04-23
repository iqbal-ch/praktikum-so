// counting to one million
#include <stdio.h>
#include <pthread.h>
#define N 1000000
#define T 4

pthread_mutex_t mutex;
int count = 0;

void *counting(void *arg)
{
    int i;
    for (i = 0; i < N/T; i++){
    
    pthread_mutex_lock(&mutex);
        count++;        // critical section
    pthread_mutex_unlock(&mutex);
}
    pthread_exit(NULL);
}

int main()
{
    pthread_t t[T];
    int i;
	pthread_mutex_init(&mutex,NULL);
    for (i = 0; i < T; i++)
        pthread_create(&t[i], NULL, counting, NULL);

    for (i = 0; i < T; i++)
        pthread_join(t[i], NULL);

    printf("%d\n", count);      // 1000000, no?
    return 0;
}
