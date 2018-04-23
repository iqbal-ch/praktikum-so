#include<stdio.h>
#include<pthread.h>
void* hello(void* arg){
	printf("hello\n");
	pthread_exit(NULL);
}
int main(){
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1,NULL,hello,NULL);
	pthread_create(&thread2,NULL,hello,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
}
