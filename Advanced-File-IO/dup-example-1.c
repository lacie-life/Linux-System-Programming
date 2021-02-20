#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
    int fd;
    int newfd;
    fd = open("newFile.log", O_RDWR | O_CREAT, 0767);

    if (fd == -1){
        printf("\n open() was failed - errno = (%d) \n", errno);
        perror("ERROR:");
        exit(1);
    }
    else {
        printf("\n open() system call executed successfully , fd is (%d) \n", fd);
    }

    newfd = dup(fd);

    printf("\n new fd value after dup() is (%d) \n", newfd);
    write(newfd, "writing using new fd, but will be written to old fd's file \n", 60);

    close(fd);
    close(newfd);
}