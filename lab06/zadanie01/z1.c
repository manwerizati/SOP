#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t children_pids[3]; 

    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            return 1;
        } 
        else if (pid == 0) {
            exit(i + 1); 
        } 
        else {
            children_pids[i] = pid;
        }
    }

    for (int i = 0; i < 3; i++) {
        int status;
        
        pid_t finished_pid = waitpid(children_pids[i], &status, 0);

        if (finished_pid > 0) {
            if (WIFEXITED(status)) {
                int exit_code = WEXITSTATUS(status);
                printf("PID: %d  kod: %d\n", finished_pid, exit_code);
            } else {
                printf("PID: %d zakonczyl sie nieprawidlowo\n", finished_pid);
            }
        }
    }

    return 0;
}