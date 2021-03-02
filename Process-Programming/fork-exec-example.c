#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t cpid;
    int status = 0;
    int num = 5;
    cpid = fork();

    if(cpid == -1){
        exit(0);  /*terminate child*/
    }

    if(cpid == 0){
        printf("\n Before exec \n");
        execl("./program2", "arg1", "arg2", NULL);
        printf("\n line is not printed \n");
    }
    else {
        printf("Parent executing before wait(), child process created by prent is %d \n", cpid);
        cpid = wait(&status); /* wait for child process to exit */
        printf("wait() in parent done \n Parent pid = %d \n", getpid());
        printf("\n cpid returned is %d \n",cpid);
        printf("\n status is %d \n", status);
    }

    return 0;
}