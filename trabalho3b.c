#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;
#define COUNT_MAX 1000

pthread_mutex_t mutexsum;


void *countSum(void *tid){
    long id = (long)tid;

    while(count < COUNT_MAX){
        pthread_mutex_lock (&mutexsum);
        count = count +1;
        printf("Thread %ld: contador em %d\n", id, count);
        pthread_mutex_unlock (&mutexsum);

        sleep(rand() % 3);

    }
    pthread_exit(NULL);
}


int main(){
    pthread_t t1, t2, t3, t4, t5 ,t6, t7, t8;
    int create;
    long num;

    pthread_mutex_init(&mutexsum, NULL);

    num = 1;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t1, NULL, countSum, (void *)num);

    num = 2;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t2, NULL, countSum, (void *)num);

    num = 3;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t3, NULL, countSum, (void *)num);

    num = 4;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t4, NULL, countSum, (void *)num);

    num = 5;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t5, NULL, countSum, (void *)num);

    num = 6;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t6, NULL, countSum, (void *)num);

    num = 7;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t7, NULL, countSum, (void *)num); //criando thread 1

    num = 8;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t8, NULL, countSum, (void *)num);



    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);

    printf("Fim\n");

    pthread_mutex_destroy(&mutexsum);

    return 0;
}
