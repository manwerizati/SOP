#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 5
#define ITEMS_TO_PRODUCE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t *empty;
sem_t *full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    for (int i = 1; i <= ITEMS_TO_PRODUCE; i++) {
        sem_wait(empty);
        pthread_mutex_lock(&mutex);
        
        buffer[in] = i;
        printf("Producent wyprodukowal: %d pozycja %d\n", i, in);
        in = (in + 1) % BUFFER_SIZE;
        
        pthread_mutex_unlock(&mutex);
        sem_post(full);
        
        usleep(100000);
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 1; i <= ITEMS_TO_PRODUCE; i++) {
        sem_wait(full);
        pthread_mutex_lock(&mutex);
        
        int item = buffer[out];
        printf("Konsument pobral: %d pozycja %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        
        pthread_mutex_unlock(&mutex);
        sem_post(empty);
        
        usleep(200000);
    }
    return NULL;
}

int main() {
    pthread_t prod_tid, cons_tid;

    sem_unlink("/sem_empty");
    sem_unlink("/sem_full");

    empty = sem_open("/sem_empty", O_CREAT, 0644, BUFFER_SIZE);
    full = sem_open("/sem_full", O_CREAT, 0644, 0);

    if (empty == SEM_FAILED || full == SEM_FAILED) {
        perror("Blad tworzenia semaforow");
        exit(1);
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    sem_close(empty);
    sem_close(full);
    sem_unlink("/sem_empty");
    sem_unlink("/sem_full");
    
    pthread_mutex_destroy(&mutex);
    return 0;
}