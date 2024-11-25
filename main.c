#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t p  = fork();
    if (p == 0){
        printf("Child 1 pid: %d\n", getpid());
    }
}