#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void unconvert(FILE* file)
{
    int c;

    while ((c = fgetc(file)) != EOF)
    {
        if (islower(c)) c = toupper(c);
        fputc(c, file);
        putchar(c);
    }
}

int main(int argc, char* argv[])
{
    FILE* file;

    if (argc != 2)
    {
        printf("Wrong argument number!");
        exit(1);
    }

    else 
    {
        if ((file = fopen(argv[1], "r+")) == NULL)
        {
            printf("Cannot open the file!");
            exit(1);
        }

        unconvert(file);

        fclose(file);
    }
    
    return 0;
}
