/* Demo to show SIGUSR signal between child-parent process */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void signal_handler (int signo){
    if (signo == SIGUSR1){
        printf("Parent: Caught SIGUSR1 in parent! \n ");
    }
}

int main(){
    pid_t cpid;
    int status = 0;
    int num = 5;
    cpid = fork();

    if (cpid == -1){
        exit(-1);
    }

    if (cpid == 0){
        printf("\n Child: Before exec \n");
        execl("./program2", "arg1", "arg2", NULL);
        printf("\n Child: line is not printted \n");
    }
    else {
        if (signal(SIGUSR1, signal_handler) == SIG_ERR){
            fprintf(stderr, "Cannot handle SIGUSR1! \n");
            exit(-1);
        }

        printf("\n Parent: Parent executinh before wait(), child process created by parent is = %d \n", cpid);
        sleep(2);
        kill(cpid, SIGUSR2);
        cpid = wait(&status);
        printf( "\n Parent: wait() in parent done \n Parent PID = %d \n", getpid());
        printf("\n Parent: cpid return is %d \n", cpid);
        printf("\n Parent: status is %d \n", status);
    }

    return 0;
}