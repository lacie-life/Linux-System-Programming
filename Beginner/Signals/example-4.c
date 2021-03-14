#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void display_message(int s){
    printf("Generated SIGALRM \n");

    // signal(SIGALRM, SIG_IGN);
    // signal(SIGALRM, SIG_DFL);

    alarm(2);
}

int main(void){
    signal(SIGALRM, display_message);

    alarm(2);
    while (1);
}