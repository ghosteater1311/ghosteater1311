#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int* apples = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &apples[i]);
    }

    for (int i = 0; i < n; i++) printf("%d ", apples[i]);
    free(apples);
}