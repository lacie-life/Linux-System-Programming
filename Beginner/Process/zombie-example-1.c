/* 
Demonstrate Zombie process
run command on terminal - ps aux | grpe Z

Note: If a process is in Zombie state, this means a en try of that process is still present in the process table
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
    if (id > 0){ // Parent process
        sleep(15);
        printf("\n Parent Process: I have created child process with ID = %d \n ", id);
        printf("\n Parent process exited \n");
        return 0;
    }
    else { // Child process
        printf("Child process executing\n");
        sleep(5);
        printf("\n I am child process, id value is %d", id);
        printf("\n child process id is %d \n", getpid());
        printf("\n the creator of child process is %d", getppid());
    }
    return 0;
}

