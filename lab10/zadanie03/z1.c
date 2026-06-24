#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

int shared_data = 0;
int read_count = 0;

sem_t *rw_mutex;
pthread_mutex_t mutex;

void *reader(void *arg) {
    int id = *(int *)arg;

    pthread_mutex_lock(&mutex);
    read_count++;
    if (read_count == 1) {
        sem_wait(rw_mutex);
    }
    pthread_mutex_unlock(&mutex);
    
    printf("Czytelnik %d czyta, wartosc danych to %d Aktywnych czytelnikow: %d\n", id, shared_data, read_count);
    usleep(150000); 
    
    pthread_mutex_lock(&mutex);
    read_count--;
    if (read_count == 0) {
        sem_post(rw_mutex);
    }
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;
    
    sem_wait(rw_mutex);
    
    shared_data += 10;
    printf("Pisarz %d pisze, nowa wartosc: %d\n", id, shared_data);
    usleep(300000);
    
    sem_post(rw_mutex);
    
    return NULL;
}

int main() {
    pthread_t r_tid[5], w_tid[2];
    int r_ids[5], w_ids[2];

    sem_unlink("/sem_rw_mutex");

    rw_mutex = sem_open("/sem_rw_mutex", O_CREAT, 0644, 1);
    
    if (rw_mutex == SEM_FAILED) {
        perror("Blad tworzenia semafora");
        exit(1);
    }

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 5; i++) {
        r_ids[i] = i + 1;
        pthread_create(&r_tid[i], NULL, reader, &r_ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        w_ids[i] = i + 1;
        pthread_create(&w_tid[i], NULL, writer, &w_ids[i]);
    }

    for (int i = 0; i < 5; i++) pthread_join(r_tid[i], NULL);
    for (int i = 0; i < 2; i++) pthread_join(w_tid[i], NULL);

    sem_close(rw_mutex);
    sem_unlink("/sem_rw_mutex");
    
    pthread_mutex_destroy(&mutex);

    return 0;
}