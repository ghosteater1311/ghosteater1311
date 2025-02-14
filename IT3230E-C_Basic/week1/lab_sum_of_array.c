#include <stdio.h>
#define MAX 100000

int main()
{
    int n, arr[MAX];
    int sum = 0;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    printf("%d", sum);
}