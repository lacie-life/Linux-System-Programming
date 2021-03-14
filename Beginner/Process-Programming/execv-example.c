#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("\n Main process execv example \n");
    // A null terminated array of character pointer
    char *args[] = {"arg1", "arg2", "arg3", NULL};
    execv("./execv-2", args);

    printf("\n This line is not printed \n");

    return 0;
}