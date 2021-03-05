#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


/* handler for SIGINT and SIGTERM */
static void signal_hadler (int signo){
    if (signo == SIGTERM){
        printf("Caught SIGTERM! \n");
    }
    exit(EXIT_SUCCESS);
}

int main(void){
    printf("\n process ID = %d \n", getpid());

    if (signal(SIGINT, SIG_DFL) == SIG_ERR){
        fprintf(stderr, "Cannot ignore STGHUP! \n");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGINT, signal_hadler) == SIG_ERR){
        fprintf(stderr, "Cannot ignore STGHUP! \n");
        exit(EXIT_FAILURE);
    }

    while (1);
    return 0;
    
}