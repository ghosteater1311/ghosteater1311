#include <stdio.h>

int n, m;
int d[16][16];
int x[16];
int mark[16];
int f;
int Cm;
int count = 0;

void Try(int k) 
{
    for (int v = 1; v <= n; v++) 
    {
        if (mark[v] == 0) 
        {
            x[k] = v;
            mark[v] = 1;
            f += d[x[k-1]][v];

            if (k == n) 
            {
                int total = f + d[v][1];
                if (total <= m) 
                {
                    count++;
                }
            }
             
            else 
            {
                int remaining_steps = (n - k) + 1;
                int min_remaining = remaining_steps * Cm;
                if (f + min_remaining <= m) 
                {
                    Try(k + 1);
                }
            }

            mark[v] = 0;
            f -= d[x[k - 1]][v];
        }
    }
}

void input() {
    scanf("%d %d", &n, &m);
    Cm = 10000000;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] < Cm) 
            {
                Cm = d[i][j];
            }
        }
    }
}

int main() 
{
    input();
    for (int v = 1; v <= n; v++) 
    {
        mark[v] = 0;
    }
    x[1] = 1;
    mark[1] = 1;
    f = 0;
    count = 0;
    Try(2);
    printf("%d", count);
    return 0;
}