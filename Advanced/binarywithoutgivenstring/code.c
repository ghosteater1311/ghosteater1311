#include <stdio.h>
#include <stdbool.h>


int a[1000], n, count = 0;

bool check(int v, int k)
{
    if ()
}


void Try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        a[k] = v;
        if (k == n - 1) count++;
        else Try(k + 1);
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);
    printf("%d", count);
}