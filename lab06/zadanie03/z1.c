#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

void print_timestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("[%ld.%06d] ", tv.tv_sec, tv.tv_usec);
}

int main(void) {
    pid_t pids[2];

    print_timestamp();

    pids[0] = fork();
    if (pids[0] < 0) {
        perror("Blad fork 1");
        return 1;
    } else if (pids[0] == 0) {
        print_timestamp();
        printf("Jestem procesem 1 PID: %d\n", getpid());
        sleep(1);
        exit(1);
    }

    pids[1] = fork();
    if (pids[1] < 0) {
        perror("Blad fork 2");
        return 1;
    } else if (pids[1] == 0) {
        sleep(2);
        print_timestamp();
        printf("Jestem procesem 2 PID: %d\n", getpid());
        exit(2);
    }

    for (int i = 1; i <= 2; i++) {
        int status;
        
        pid_t finished_pid = waitpid(-1, &status, 0);

        if (finished_pid > 0) {
            print_timestamp();
            if (WIFEXITED(status)) {
                int exit_code = WEXITSTATUS(status);
                printf("PID: %d zakonczyl sie jako %d. Kod wyjscia: %d\n", finished_pid, i, exit_code);
            } else {
                printf("PID: %d zakonczyl się nieprawidlowo.\n", finished_pid);
            }
        }
    }

    print_timestamp();

    return 0;
}