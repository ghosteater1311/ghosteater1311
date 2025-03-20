#include <stdio.h>
#define MAX 100

int n;
int x[MAX];
int a[MAX];
int mark[MAX];
int markD1[2 * MAX];
int markD2[2 * MAX];
int count;

int check(int v, int k)
{
    if (mark[v] == 1) return 0;
    if (markD1[n + k - v] == 1) return 0;
    if (markD2[k + v] == 1) return 0;
    return 1;
}

void Try(int k)
{
    if (x[k] > 0)
    {
        if (k == n)
        {
            count ++;
        }
        else 
        {
            Try(k + 1);
        }
        return;
    }

    for (int r = 1; r <= n; r++)
    {
        if (check(r, k))
        {
            x[k] = r;
            mark[r] = 1;
            markD1[n + k - r] = 1;        
            markD2[k + r] = 1;
            
            if (k == n)
            {
                count++;
            }
            else 
            {
                Try(k + 1);
            }

            x[k] = 0;
            mark[r] = 0;
            markD1[n + k - r] = 0;        
            markD2[k + r] = 0;            
        }
    }
}

void input()
{
    for (int i = 1; i < MAX; i++)
    {
        mark[i] = 0;
    }

    for (int i = 0; i < 2 * MAX; i++)
    {
        markD1[i] = 0;
        markD2[i] = 0;
    }

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int e;
            scanf("%d", &e);

            if (e == 1)
            {
                x[j] = i;
                mark[i] = 1;
                markD1[n + j - i] = 1;
                markD2[i + j] = 1;
            }
        }
    }
}

int main()
{
    input();
    count = 0;
    Try(1);
    printf("%d", count);
    return 0;
}