#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char str[MAX];
    int count = 0;

    fgets(str, MAX, stdin);
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n') 
        {
            count ++;
        }
    }

    printf("%d", count);

    return 0;
}