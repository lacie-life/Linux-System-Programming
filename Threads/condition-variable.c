#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myConvar = PTHREAD_COND_INITIALIZER;

int doneFlag = 0;
char buf[100];

/* Producer thread */
void *threadA(void *p){
    printf("\n threadA Scheduled first \n");
    sleep(1);
    pthread_mutex_lock(&my_mutex);
    printf("\n threadA: critical section executed always first \n");

    /* producer will produce data here */
    sprintf(buf, "This is data buffer");
    doneFlag = 1;
    pthread_cond_signal(&myConvar);
    pthread_mutex_unlock(&my_mutex);
}

#if 1
    /* Consumer thread */
void *threadB(void *p){
    printf("\n threadB Scheduled first \n");
    pthread_mutex_lock(&my_mutex);
    if(doneFlag == 0){
        pthread_cond_wait(&myConvar, &my_mutex);
    }

    /* Consumer will data here */

    printf("threadB: signal received from threadA, this is always executed after threadA critial section %d \n", doneFlag);
    printf("\n The buffer received from producer thread is %s \n", buf);
}
#endif

int main(int argc, char **argv[]){
    srand(time(0));

    pthread_t pthreadA;
    pthread_create(&pthreadA, NULL, threadA, NULL);
    pthread_t pthreadB;
    pthread_create(&pthreadB, NULL, threadB, NULL);

    pthread_join(pthreadA, NULL);
    pthread_join(pthreadB, NULL);

    printf("\n Main thread is exiting now \n");
    return (EXIT_SUCCESS);
}




