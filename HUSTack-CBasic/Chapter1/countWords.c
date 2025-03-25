//C 
#include <stdio.h>
#include <string.h>
#define MAX 3000000

int main()
{
    int count = 0;
    char str[MAX];

    while(fgets(str,sizeof(str),stdin) != NULL)
    {
        int word = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] != ' ' && str[i] != '\n') word = 1;
            if (str[i] == ' ' || str[i] == '\n')
            {
                count += word;
                word = 0;
            }
        }
        count += word;
    }

    printf("%d", count);
}
