#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *ptr1, const void *ptr2)
{
    int *x = (int*)ptr1;
    int *y = (int*)ptr2;
    if (*x < *y) return -1;
    else return 1;
}

int binarySearch(int a[], int low, int high, int key)
{
    if (low <= high) 
    {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) return binarySearch(a, low, mid - 1, key);
        else return binarySearch(a, mid + 1, high, key);
    }
    else return -1;
}

void solve()
{
    int a[100000], n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    char cmd[50];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        if (strcmp(cmd, "check") == 0)
        {
            int k; 
            scanf("%d", &k);
            int op = binarySearch(a, 1, n, k);
            if (op > -1) printf("%d\n", 1);
            else printf("%d\n", 0);
        }
    }
}

int main()
{
    solve();
}