#include <stdio.h>
#include <string.h>

#define MAX 1000

void replace_char(char* str, char char_in, char char_out)
{
    if (str == NULL)
    {
        return;
    }
    
    while (*str != '\0')
    {
        if (*str == char_in)
        {
            *str = char_out;
        }
        ++str;
    }
}

int main()
{
    char in, out;
    char* str;

    fgets(str, MAX, stdin);
    scanf(" %c", &in);
    scanf(" %c", &out);

    replace_char(str, in, out);

    printf("%s", str);

    return 0;
}