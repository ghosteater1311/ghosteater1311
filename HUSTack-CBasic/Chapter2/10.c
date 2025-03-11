#include <stdio.h>
#include <stdlib.h>

int n, M, T;
int equation[100000];
int mark[100000] = {0};

void printSol()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", equation[i]);
    }
    printf("\n");
}

int check(int v, int k)
{
    return (k < n) ? 1 : (T + v == M);
}

void Try(int k)
{
    for (int v = 1; v <= M - T - n + k; v++)
    {
        if (check(v, k))
        {
            equation[k] = v;
            T = T + v;
            if (k == n)
            {
                printSol();
            }
            else 
            {
                Try(k + 1);
            }
            T = T - v;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &M);
    Try(1);
    return 0;
}