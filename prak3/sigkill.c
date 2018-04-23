#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void foo(int sig) {
	printf("got signal %d\n", sig); // print signum
	signal(SIGINT, SIG_DFL); // back to default
}

int main() {
	signal(SIGINT, foo);	
	pid_t child = fork();
	if(child == 0) {
		while(1) {
			puts("child");
			sleep(1);
		}
	}else{
		sleep(5);
		kill(child, SIGTERM); // terminate
	}
}


