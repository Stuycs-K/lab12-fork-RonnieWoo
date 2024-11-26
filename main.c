#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "random.h"

int main(){
    pid_t p0 = 0;
    pid_t p1;
    pid_t p2;
    printf("%d about to create 2 child processes\n", getpid());

    //fork child 1
    p1  = fork();
    if (p1 == 0){
        p0 = 1;
    }
    //fork child 2
    if (p0 == 0){
        p2  = fork();
    }
    if (p2 == 0){
        p0 = 1;
    }
    if (p1 == 0 || p2 == 0){
        int x = randomInt();
        printf("%d %dsec\n", getpid(), x);
        sleep(x);
        printf("%d finished after %dsec\n", getpid(), x);
        exit(x);
    }
    //wait
    if (p0 == 0){
        int status;
        pid_t c = wait(&status);
        printf("Main process %d is done. Child %d slept for %dsec\n", getpid(), c, WEXITSTATUS(status));
    }
}