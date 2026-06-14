#include <stdio.h>
#include <signal.h>
void sigint_handler(int signum);

int main(int argc, char *argv[])
{
    signal(SIGINT, sigint_handler);

    while (1){
        printf("jestem w mainie\n");
        sleep(1);
    }

    return 0;
}

void sigint_handler(int signum)
{
    printf("ctrl+C nie dziala");
}