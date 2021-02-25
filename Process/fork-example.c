#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t id;
    printf("Parent Process: Executed by parent process before fork() - PID = (%d) \n", getpagesize());
    id = fork();

    if (id < 0){
        printf("\fork failed\n");
        exit(-1);
    }

    if (id > 0){
        printf("\n Parent Process: I have created child process with ID = (%d) \n", id);
    }

    else {
        printf("\n I am child process, id value is (%d) \n", id);
        printf("\n Child process id is (%d) \n", getpid());
        printf("\n The creator of child process is (%d) \n", getppid());
    }

    return 0;
}