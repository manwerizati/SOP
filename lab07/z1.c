#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *plik;
    plik = fopen("plik.txt", "r");
    char slowo[100] = "Hello World";

    if (plik == NULL)
    {
        perror("Plik nie istnieje\n");
        return 1;
    }

    while (fscanf(plik, "%s", slowo) != EOF)
    {
        printf("%s\n", slowo);
    }

    fclose(plik);
    return 0;
}