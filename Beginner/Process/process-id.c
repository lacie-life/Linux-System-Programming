#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void){

    printf("\n Process ID is (%d) \n", getpid());
    printf("\n Process IF of creator (parent) is (%d) \n", getppid());

    sleep(5);
}