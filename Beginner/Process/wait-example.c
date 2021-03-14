/* Program to demonstrate wait and exit */

/*
Process terminate status (int) 16bit number
1. Status value if child process has nomarl exit/termination

 15......8   | 7 ..... 0
 XXXXXXXXX   | XXXXXXXXX
 exitStautus | 0

2. Killed by signal
 15......8   | 7 .....0
 unused      | X termination signal
               | 
               | -----> core dump flag
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    pid_t cpid;
    int status = 0;

    cpid = fork();

    if (cpid == -1){
        exit(-1);    // Terminate child
    }

    if (cpid == 0){
        printf(" \n Child executinh first its pid = (%d) \n", getpid());
        sleep(20);
        printf("CHild pid = %d \n", getpid());
        exit(3);
    }
    else {
        printf("\n Parent executinh before wiat()\n");
        //cpid = wait(NULL);
        cpid = wait(&status);
        printf("\n wait() is parent done \n Parent pid = %d \n", getpid());
        printf("\n cpid return is (%d) \n", cpid);
        printf("\n status is (%d) \n", status);
    }

    return 0;
}