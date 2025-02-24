#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 81

int countLine(FILE* fin)
{
    char buff[MAX];
    int count = 0;

    while (fgets(buff, MAX, fin) != NULL)
    {
        count++;
        printf("%s", buff);
    }

    return count;
}

int main(void)
{
    FILE* file_in;

    if ((file_in = fopen("input.txt", "r")) == NULL)
    {
        printf("Cannot open the file!\n");
    }
    else
    {
        printf("Reading the file");
        sleep(2);
        printf(".");
        sleep(2);
        printf(".");
        sleep(2);
        printf(".");
        sleep(2);
        printf("\nDone!\n");
        sleep(1);
    }

    printf("\nResult: %d\n", countLine(file_in));

    fclose(file_in);

    return 0;
}