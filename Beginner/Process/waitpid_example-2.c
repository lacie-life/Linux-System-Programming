/* Program to demonstrate wiat and exit */
/* Use of WNOHANG => This is a non blocking call to waitpid() */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int main(){

    pid_t cpid;
    pid_t cpid2;
    pid_t ret_pid;

    int status = 0;

    cpid = fork();

    if (cpid == -1){
        exit(-1);
    }

    if (cpid == 0){
        printf("\n Child 1 executing ist pid = %d \n", getpid());
        sleep(10);

        printf("Child exited \n");
        exit(0);
    }
    else { // This is parent process
        printf("\n Parent executing before wait() \n Parent pid = %d \n",getpid());
        ret_pid = waitpid(80, &status, WNOHANG);
        //ret_pid = waitpid(cpid, &status, WNOHANG);
        if (ret_pid == -1){
            perror("Error: ");
            printf("\n waitpid returned error %d", errno);
        }
        printf("\n cpid returned is %d", ret_pid);
        printf("\n status is %d", status);

        printf("\nParent exited \n");
    }
    return 0;

}

