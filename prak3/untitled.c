#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main(){
pid_t child = fork();
    if (child == 0) {
        while (1) {				//tiap satu detik print child
            puts("child");
            sleep(1);
        }
    } else {
        sleep(4);               //mensleep parent 4 detik dan child tetap berjalan
        kill(child , SIGSTOP);  //menstop clid
        sleep(3);				//stop clid selama 3 detik
        kill(child , SIGCONT);  //peren hidup lagi
        sleep(2);				//parnt hidup 2 detik
        kill(child, SIGTERM);   // terminate
    }
return 0;
}
