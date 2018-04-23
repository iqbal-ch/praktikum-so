#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void foo(int sig) {
	printf("got signal %d\n", sig); // print signum
	signal(SIGINT, SIG_DFL); // back to default
}

int main() {
	signal(SIGINT, foo);
	while(1) {
		puts("hello");
		sleep(1);
	}
}

