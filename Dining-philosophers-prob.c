#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t chopstick[N];

void* philosopher(void* num) {
    int i = *(int*)num;

    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i+1)%N]);

    printf("Philosopher %d is eating\n", i);

    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i+1)%N]);

    return NULL;
}

int main() {
    pthread_t p[N];
    int i, id[N];

    for(i=0;i<N;i++)
        sem_init(&chopstick[i], 0, 1);

    for(i=0;i<N;i++){
        id[i]=i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for(i=0;i<N;i++)
        pthread_join(p[i], NULL);

    return 0;
}
