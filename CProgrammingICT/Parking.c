#include <stdio.h>
#include <string.h>

int main()
{
    char time_begin[5];
    char time_end[5];

    fgets(time_begin, strlen(time_begin), stdin);
    fgets(time_end, strlen(time_end), stdin);
    if (strcmp(time_begin, time_end) == 0) printf("0");
    else if (strcmp(time_begin, time_end) < 0) printf("-1");    
    else if ((strcmp(time_begin, "18:00") >= 0 || strcmp(time_end, "18:00") >= 0)) printf("8000");
    else printf("5000");
}