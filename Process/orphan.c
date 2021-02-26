/*
    Demonstrate Orphan prooess
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t id;
    printf("Parent Process: Executed by parent process before fork() - PID = %d \n", getpid());
    id = fork();

    if (id < 0){
        printf("\n fork failed \n");
        exit(-1);
    }
    if (id > 0){ // Parent process, kill before child executes
        printf("\n Parent process exited \n");
        return 0;
    }
    else { // Child process
        printf("Child process executing\n");
        sleep(10);
        printf("\n I am child process, id value is %d", id);
        printf("\n child process id is %d \n", getpid());
    }
    return 0;
}