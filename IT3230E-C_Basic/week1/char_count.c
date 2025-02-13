#include <stdio.h>
#include <string.h>
#define MAX 100
#define ALPHABET_LEN 26

int main()
{
    char str[MAX];
    int i;
    int count[ALPHABET_LEN] = {0};
    char c = '\0';

    fgets(str, MAX, stdin);

    for (i = 0; i < strlen(str); i++)
    {
        c = str[i];
        if (c <= 'z' && c >= 'a')
        {
            ++count[c - 'a'];
        }
    }

    for (i = 0; i < ALPHABET_LEN; i ++)
    {
        if (count[i] > 0)
        {
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
        }
    }

    return 0;
}