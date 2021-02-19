#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>

int main(){
    int sz;
    char buf[100];

    strcpy(buf, "This is example of Q_APPEND: Sample file write \n");

    /* O_TRUNC => write to file from beginning, discarding old contents*/
    /* O_APPEND => write the contents of file from the end of existing file contents*/
    // Open existing file
    // int fd = open("output.txt", O_WRONLY | O_APPEND);

    // Create new file
    int fd = open("new_output.txt", O_CREAT | O_WRONLY | O_EXCL, 0774);
    
    if (fd < 0){
        perror("Error occured during open");
        exit(1);
    }
    printf("length of buf is (%d)", (int)strlen(buf));

    sz = write(fd, buf, strlen(buf));

    printf("\n write() returned %d \n", sz);

    close(fd);

    return 0;

}