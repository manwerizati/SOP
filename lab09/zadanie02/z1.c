#include <stdio.h>
#include <pthread.h>

void *print_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        printf("Watek: iteracja %d\n", i + 1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, print_thread, NULL);

    for (int i = 0; i < 10; i++) {
        printf("Main: iteracja %d\n", i + 1);
    }

    pthread_join(thread_id, NULL);

    return 0;
}