#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

void mycp(FILE* fin, FILE* fout)
{
    int c;
    
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
    }
}

int main(int argc, char* argv[])
{
    FILE* file_in;
    FILE* file_out;

    if (argc != 3)
    {
        printf("Wrong argument number!");
        exit(1);
    }

    else
    {
        if ((file_in = fopen(argv[1], "r")) == NULL)
        {
            printf("Cannot open the file!");
            exit(1);
        }

        if ((file_out = fopen(argv[2], "r+")) == NULL)
        {
            printf("Cannot open the file!");
            exit(1);
        }

        mycp(file_in, file_out);

        fclose(file_out);
        fclose(file_in);
    }

    return 0;
}