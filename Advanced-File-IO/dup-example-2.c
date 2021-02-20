#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
    int fd;
    fd = open("newFile.log", O_RDWR | O_CREAT, 0767);

    if (fd == -1){
        printf("\n open() was failed - errno = (%d) \n", errno);
        perror("ERROR:");
        exit(1);
    }
    else {
        printf("\n open() system call executed successfully , fd is (%d) \n", fd);
    }
    close(1);
    dup(fd);
    // dup2(fd, 1);

    printf("\n Output not written to screen, rather written to file using dup() system call \n");
}