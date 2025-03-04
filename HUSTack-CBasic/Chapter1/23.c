//C 
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    int *prefix = (int*)malloc((n + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        prefix[i] = (prefix[i-1] + (a[i-1] % 2)) % 2;
    }

    int Q = 0;
    int max_i = n - k;
    for (int i = 0; i <= max_i; i++) 
    {
        if (prefix[i] == prefix[i + k]) 
        {
            Q++;
        }
    }

    printf("%d\n", Q);

    free(a);
    free(prefix);
    return 0;
}
