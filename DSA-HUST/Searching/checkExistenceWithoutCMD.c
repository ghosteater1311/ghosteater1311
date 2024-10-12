#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

void insertSorted(int a[], int *n, int key) 
{
    int pos = *n;
    while (pos > 0 && a[pos - 1] > key) 
    {
        a[pos] = a[pos - 1];
        pos--;
    }
    a[pos] = key;
    (*n)++;
}

void solve() 
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int *s = (int *)malloc(n * sizeof(int));
    int sCnt = 0;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) 
    {
        if (bsearch(&a[i], s, sCnt, sizeof(int), cmp)) 
        {
            printf("1\n");
        } else 
        {
            printf("0\n");
            insertSorted(s, &sCnt, a[i]);
        }
    }
    free(a);
    free(s);
}

int main() 
{
    solve();
    return 0;
}
