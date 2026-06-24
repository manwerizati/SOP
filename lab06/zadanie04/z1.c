#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Blad fork");
        return 1;
    } 
    else if (child_pid == 0) {
        printf("PID = %d.\n", getpid());
        
        pid_t grandchild_pid = fork();

        if (grandchild_pid < 0) {
            perror("Blad fork()");
            return 1;
        } 
        else if (grandchild_pid == 0) {
            printf("Wnuk dziala PID: %d\n", getpid());
            sleep(2);
            exit(5);
        } 
        else {
            int status;
            
            pid_t finished_pid = wait(&status);

            if (finished_pid > 0) {
                if (WIFEXITED(status)) {
                    int exit_code = WEXITSTATUS(status);
                    printf("Wnuk PID: %d skonczyl sie kodem %d\n", finished_pid, exit_code);
                }
            }
            exit(0); 
        }
    } 
    else {
        printf("Dziecko PID: %d\n", child_pid);
        exit(0);
    }

    return 0;
}