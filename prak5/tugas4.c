#include <stdio.h>
#include <pthread.h>
#define N 16

int sum = 0;

void *array_sum(void *arg){
	int *cas = (int *) arg;
	int i;
	for(i=0;i<4;i++){
	sum=sum+cas[i];
	}
}
int main() {
	int A[N] = {68,34,64,95,35,78,65,93,51,67, 7,77, 4,73,52,91};
	int i;
	
	//TODO: array sum
	pthread_t thread[4];
	for(i=0;i<4;i++) pthread_create(&thread[i],NULL,array_sum,&A[i*4]);
	for(i=0;i<4;i++) pthread_join(thread[i],NULL);
	
	printf("%d\n", sum);	// 954
return 0;
}

