#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thr_function(void *thr_args) {
    printf("Jestem wątkiem!\n");
    sleep(5);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t thr;

    pthread_create(&thr, NULL, thr_function, NULL);
    printf("Jestem w mainie!\n");
    pthread_join(thr, NULL);
    printf("Koniec programu!\n");
    return 0;
}