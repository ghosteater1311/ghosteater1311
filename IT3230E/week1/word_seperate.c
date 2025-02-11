#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char str[MAX];
    int i = 0;

    fgets(str, MAX, stdin);

    while (str[i] != '\0')
    {
        while (str[i] == ' ') 
        {
            i++;
        }

        if (str[i] == '\0' || str[i] == '\n') 
        {
            break;
        }

        while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n') 
        {
            printf("%c", str[i]);
            i++;
        }

        printf("\n");
    }

    return 0;
}