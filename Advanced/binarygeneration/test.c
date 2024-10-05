#include <stdio.h>
#include <stdbool.h>

int n, a[10000];

bool check(int v, int k)
{
    return true;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            a[k] = v;
            if (k == n - 1) solution();
            else Try(k + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);
    return 0;
}