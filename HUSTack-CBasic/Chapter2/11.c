#include <stdio.h>
#include <stdlib.h>

int n;
int permutation[100000];
int mark[100000] = {0};

void printSol()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", permutation[i]);
    }
    printf("\n");
}

int check(int v, int k)
{
    return (mark[v] == 1) ? 0 : 1;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            permutation[k] = v;
            mark[v] = 1;
            if (k == n)
            {
                printSol();
            }
            else 
            {
                Try(k + 1);
            }
            mark[v] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    return 0;
}