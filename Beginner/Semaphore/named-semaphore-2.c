#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

int main(){
    int ret, sval;
    sem_t *sem;

    sem = sem_open("/sem1", O_RDWR);

    if(sem == SEM_FAILED){
        perror("sem_open fail.");
        return -1;
    }
    else{
        printf("\n sem_open success");
    }

    sem_getvalue(sem, &sval);
    printf("\n semaphore val = %d \n", sval);

    ret = sem_wait(sem); // wait state
    printf("\n Process excuting critical section \n");
    sleep(10);
    printf("\n ret is %d \n", ret);
    printf("\n process 2: \n");
    sem_post(sem);

    printf("\n Process excuted critical section \n");

    //sem_unlink("/sem1");
}