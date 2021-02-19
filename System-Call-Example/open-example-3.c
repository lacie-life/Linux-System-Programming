#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main(){
    int fd;
    fd = open("newFile2.log", O_RDWR | O_CREAT | O_EXCL, 0774);
    if (fd == -1){
        printf("\n open() failed - errno = (%d) \n", errno);
        perror ("ERROR:");
    }
    else {
        printf("\n open() sys call excutel successfully \n");
    }
}