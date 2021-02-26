#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

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
        printf(" \n Child 1 executinh its pid = (%d) \n", getpid());
        sleep(10);
        printf("Child 1 pid = %d \n", getpid());
        exit(0);
    }
    else {
        cpid2 = fork();
        if (cpid2 == -1){
            exit(-1);
        }
        if (cpid2 == 0){
            printf(" \n Child 2 executinh its pid = (%d) \n", getpid());
            sleep(5);
            printf("Child 2 pid = %d \n", getpid());
            exit(1);
        }

        printf("\n Parent exacuting before wait() \n Parent pid is (%d) \n", getpid());
        ret_pid = waitpid(cpid2, &status, 0);
        printf("\n cpid returned is (%d) \n",ret_pid );
        printf("\n status is (%d) \n", status);

        ret_pid = waitpid(cpid, &status, 0);
        printf("\n cpid returned is (%d) \n", ret_pid);
        printf("\n status is (%d) \n", status);

        printf("Parent exited");
    }

    return 0;
}