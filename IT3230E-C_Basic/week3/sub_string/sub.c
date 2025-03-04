#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* subStr(char* s1, int offset, int number)
{
    int len = strlen(s1);
    char* substr;

    if (offset < 0 || offset >= len) 
    {
        substr = (char*)malloc(1);
        if (substr != NULL) 
        {
            substr[0] = '\0';
        }
        return substr;
    }

    int available = len - offset;
    int actual_number = (number > available) ? available : number;

    substr = (char*)malloc(actual_number + 1); 

    for (int i = 0; i < actual_number; i++) 
    {
        substr[i] = s1[offset + i];
    }
    substr[actual_number] = '\0';

    return substr;
}

int main()
{
    char strIn[100];
    fgets(strIn, 100, stdin);
    int offset, number;

    strIn[strcspn(strIn, "\n")] = '\0';

    scanf("%d", &offset);
    scanf("%d", &number);

    char* result = subStr(strIn, offset, number);

    if (result != NULL) 
    {
        printf("%s", result);
        free(result); 
    }

    return 0;
}