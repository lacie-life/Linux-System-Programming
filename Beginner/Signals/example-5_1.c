/* Demo to show SIGUSR signal between child-parent process */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void signal_handler (int signo){
    if (signo == SIGUSR2){
        printf("Child: Caught SIGUSR2 in child! \n");
    }
}

int main(int argc, char *argv[]){
    int i = 0; 
    printf("Child: I am new process called by execl() \n");
    printf("Child: new program pid = %d \n", getpid());

    if (signal(SIGUSR2, signal_handler) == SIG_ERR){
        fprintf(stderr, "Cannot handle SIGUSR2! \n");
        exit(-1);
    }

    for (i = 0; i < argc; i++){
        printf("\n Child: argv[%d] = %s \n", i, argv[i]);
    }

    sleep(5);
    printf("\n Child: sending sigusr1 to parent \n");
    kill(getppid(), SIGUSR1);
    sleep(10);
    printf("\n Child:exiting \n");
    return 0;
}