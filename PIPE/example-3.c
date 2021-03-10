/* program to demostrate SIGPIPE */

#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 50

int main(int argc, char *argv[]){
    int pfd[2], loop = 0;
    char buf[BUF_SIZE] = {};
    ssize_t numRead;

    /* Pipe file descriptor */
    if (pipe(pfd) == -1){
        exit(-1);
    }

    switch (fork())
    {
    case -1:
        exit(-1);
        break;
    /* Create the pipe */    
    case 0:
        /* Child - reads from pipe */
        if (close(pfd[1] == -1)){
            /* write end is unused */
            exit(-1);
        }
        for (;;){
            /* Read data from pipe, echo on stdout */
            strcpy(buf, "");
            numRead = read(pfd[0], buf, BUF_SIZE);
            if(numRead == -1){
                exit(-1);
            }
            if(numRead == 0){
                printf("\n Child: parent closed write end \n");
                break;
            }

            /* End-of-file */
            printf("\n Child process: data received in child process is %s \n", buf);
            printf("\n child process: closing read end \n");
            close(pfd[0]);
            sleep(10);
        }
        if (close(pfd[0] == -1)){
            exit(-1);
        }
        break;

    default:
        /* Parent - writes to pipe */
        if(close(pfd[0] == -1)){
            /* Read end is unsued */
            exit(-1);
        } 
        printf("\n Parent: seinding user input string to child process - s %s \n", argv[1]);
        write(pfd[1], argv[1], strlen(argv[1]));
        while (1)
        {
            sleep(2);
            printf("\n parent: about to write data to pipe \n");
            write(pfd[1], "test", 4); // SIG_PIPE is generated if we try to write to pipr which has already closed its read end
        }
        exit(0);
    }
}    
