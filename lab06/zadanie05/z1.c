#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("PID = %d, PPID = %d, Poziom = 0\n", getpid(), getppid());

    pid_t pid_dziecko1 = fork();

    if (pid_dziecko1 < 0) {
        perror("Blad fork - dziecko 1");
        return 1;
    } 
    else if (pid_dziecko1 == 0) {
        printf("  ├── Dziecko 1: PID = %d, PPID = %d, Poziom = 1\n", getpid(), getppid());
        
        pid_t pid_wnuk1 = fork();
        if (pid_wnuk1 < 0) {
            perror("Blad fork - wnuk 1");
            exit(1);
        }
        else if (pid_wnuk1 == 0) {
            printf("  │   └── Wnuk 1: PID = %d, PPID = %d, Poziom = 2\n", getpid(), getppid());
            exit(0);
        }
        
        wait(NULL); 
        exit(0);
    }

    pid_t pid_dziecko2 = fork();

    if (pid_dziecko2 < 0) {
        perror("Blad fork - dziecko 2");
        return 1;
    }
    else if (pid_dziecko2 == 0) {
        printf("  └── Dziecko 2: PID = %d, PPID = %d, Poziom = 1\n", getpid(), getppid());
        
        pid_t pid_wnuk2 = fork();
        if (pid_wnuk2 < 0) {
            perror("Blad fork - wnuk 2");
            exit(1);
        }
        else if (pid_wnuk2 == 0) {
            printf("      └── Wnuk 2: PID = %d, PPID = %d, Poziom = 2\n", getpid(), getppid());
            exit(0);
        }
        
        wait(NULL);
        exit(0);
    }

    waitpid(pid_dziecko1, NULL, 0);
    waitpid(pid_dziecko2, NULL, 0);

    return 0;
}