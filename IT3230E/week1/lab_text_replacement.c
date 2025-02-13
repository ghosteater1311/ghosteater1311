#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int main()
{
    char text_in[3];
    char text_out[MAX];
    char str[MAX];
    char temp[MAX];

    scanf("%s", text_in);
    getchar();
    fgets(text_out, MAX, stdin);
    fgets(str, MAX, stdin);

    strcpy(temp, str);

    char* tok = strtok(temp, " ");

    while (tok != NULL)
    {
        if (strcmp(tok, text_in) != 0)
        {
            printf("%s ", tok);
        }
        else 
        {
            for (int i = 0; i < strlen(text_out); i++)
            {
                if (text_out[i] != '\n')
                {
                    printf("%c", text_out[i]);
                }
            }
            printf(" ");
        }
        tok = strtok(NULL, " ");
    }

    return 0;
}