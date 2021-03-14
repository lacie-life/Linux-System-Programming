#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main(){
    int fd;
    //fd = open ("newFile.log", Q_RDWR | O_CREAT, S_IRWXU|S_IRWXG|S_IROTH);
    fd = open("newFile.log", O_RDWR | O_CREAT, 0774);

    if (fd == -1){
        printf("\n open() failed - errno = (%d) \n", errno);
        perror ("ERROR:");
    }
    else {
        printf("\n open() sys call excutel successfully \n");
    }
}