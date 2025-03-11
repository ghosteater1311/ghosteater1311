#include <stdio.h>
#include <stdlib.h>

int n;
int binary[10000];

void printSol()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int check(int v, int k)
{
    return 1;
}

void Try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            binary[k] = v;
            if (k == n)
            {
                printSol();
            }
            else 
            {
                Try(k + 1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);

    Try(1);
    return 0;
}