#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char name[MAX][MAX];
    int n;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        fgets(name[i], MAX, stdin);
        name[i][strcspn(name[i], "\n")] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        printf("%s\n", name[i]);
    }

    return 0;
}