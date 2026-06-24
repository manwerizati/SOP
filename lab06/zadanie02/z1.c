#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Blad fork");
        return 1;
    } 
    else if (pid == 0) {
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
        
        sleep(2);
        
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
        exit(0);
    } 
    else {
        printf("PID rodzica = %d, Dziecko = %d. \n", getpid(), pid);
        exit(0);
    }

    return 0;
}