#include <stdio.h>
#include <stdlib.h>
#define MAX 81

void mycp(FILE* fin, FILE* fout)
{
    char buff[MAX];
    while (fgets(buff, MAX, fin) != NULL)
    {
        fputs(buff, fout);
        printf("%s", buff);
    }
}

int main(void)
{
    FILE* file_in;
    FILE* file_out;

    if ((file_in = fopen("input.txt", "r")) == NULL)
    {
        printf("Cannot open the file!\n");
    }

    if ((file_out = fopen("output.txt", "r+")) == NULL)
    {
        printf("Cannot open the file!\n");
    }

    mycp(file_in, file_out);

    fclose(file_in);
    fclose(file_out);

    return 0;
}