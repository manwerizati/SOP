#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ITERATIONS 1000

int shared_counter = 0;
pthread_mutex_t mutex;

void *increment_function(void *arg) {
    int thread_id = *(int *)arg;

    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        
        shared_counter++;
        
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Watek %d zakonczyl prace.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1;
        pthread_create(&threads[i], NULL, increment_function, &thread_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Oczekiwana wartosc: %d\n", NUM_THREADS * ITERATIONS);
    printf("Ostateczna wartosc: %d\n", shared_counter);

    return 0;
}