#include <stdio.h>
#include <stdlib.h>

int array_equality_check(int *A, int *B, int n, int m) 
{
    if (n != m) 
    {
        return 0;
    }
    for (int i = 0; i < n; i++) 
    {
        if (A[i] != B[i]) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) 
    {
        int n, m, result;
        scanf("%d %d", &n, &m);
        int A[n];
        int B[m];
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++) 
        {
            scanf("%d", &B[i]);
        }
        result = array_equality_check(A, B, n, m);
        printf("%d\n", result);
    }
    return 0;
}
