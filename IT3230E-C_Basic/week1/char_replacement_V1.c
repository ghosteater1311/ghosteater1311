#include <stdio.h>
#include <string.h>
#define MAX 100

void replace(char str[], char char_in, char char_out)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == char_in)
        {
            str[i] = char_out;
        }
    }
}

int main()
{
    char str[MAX];
    char in, out;
    
    fgets(str, MAX, stdin);
    scanf(" %c", &in);
    scanf(" %c", &out);
    
    replace(str, in, out);

    printf("%s", str);
}