/* Named Semaphore */

#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

int main(){
    int flags, sval;
    unsigned int value;
    sem_t *sem;

    sem = sem_open("/sem1", O_CREAT | O_RDWR, 0660, 1);

    if(sem == SEM_FAILED){
        perror("sem_open fail !");
        return -1;
    }
    else {
        printf("\n sem_open success \n");
    }

    sem_getvalue(sem, &sval);
    printf("\n before sem_wait semaphore value = %d \n", sval);

    sem_wait(sem); // wait state
    sem_getvalue(sem, &sval);
    printf("\n after sem_wait semaphore value = %d \n", sval);

    printf("\n process 1: Executing Critical section \n");
    sleep(20);
    sem_post(sem);
    printf("\n critial section executed \n");
    sem_getvalue(sem, &sval);

    printf("\n after sem_post semaphore value = %d \n", sval);

    //sem_unlink("/sem1");
}