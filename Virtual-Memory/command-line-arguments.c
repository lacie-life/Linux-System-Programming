/* Demo program to show the command line arguments of process */

#include <stdio.h>
#include <string.h>

// argc and argv are command line arguments and are stored in stack frame of main()
// argv is array of pointers to string

void main(int argc, char *argv[]){

    int count = 0;
    printf("\n Demonstrate the command line arguments \n");
    printf("\n The value of argc is (%d)", argc);

    while (count < argc){
        printf("\n (%d) th string is (%s) ", count, argv[count]);
        count++;
    }
}