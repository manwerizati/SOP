#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    while(1) {
        printf("Jestem watkiem\n");
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    
    pthread_create(&thread_id, NULL, thread_function, NULL);

    while(1) {
        printf("Jestem mainem\n");
    }

    return 0;
}