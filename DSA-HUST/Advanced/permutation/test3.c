#include <stdio.h>
#include <stdbool.h>

int n, a[10000], b[10000];

bool check(int v, int k)
{
    if (b[v] == 1) return false;
    else return true;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            a[k] = v;
            b[v] = 1;
            if (k == n - 1) solution();
            else Try(k + 1);
            b[v] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);
    return 0;
}