#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

void line_length_and_content(FILE* file_in, FILE* file_out)
{
    char buff[MAX];
    int len = 0;

    while (fgets(buff, MAX, file_in) != NULL)
    {
        len = strlen(buff);
        fprintf(file_out, "%d: %s", len, buff);
        printf("%s", buff);
    }
}

int main()
{
    FILE* file_in;
    FILE* file_out;

    if ((file_in = fopen("input.txt", "r")) == NULL)
    {
        printf("Cannot open the file!\n");
    }

    if ((file_out = fopen("output.txt", "w+")) == NULL)
    {
        printf("Cannot open the file!\n");
    }

    line_length_and_content(file_in, file_out);

    fclose(file_in);

    return 0;
}