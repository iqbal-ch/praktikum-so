#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ding(int sig){ 
	puts("ding!"); 
	}
	
int main(){

if(fork() == 0) {
	sleep(5);
	kill(getppid(), SIGALRM);
}else{
	signal(SIGALRM, ding);
	puts("waiting...");
	pause();
}
return 0;
}
