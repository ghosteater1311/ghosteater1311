#include <stdio.h>     
#include <stdlib.h>   

int n, m, min = 1000001, x[16], f = 0, mark[16] = {0}, result = 0, cost[50][50]; 

int check(int i)
{         
    if (mark[i] == 1) return 0;         
    return 1;     
}     
void Try(int k)
{         
    for(int i = 2; i <= n; i++)
    {             
        if (check(i))
        {                 
            x[k] = i;                 
            mark[i] = 1;                 
            f = f + cost[x[k - 1]][x[k]];                 
            if (k == n)
            {                     
                f += cost[x[k]][1];                     
                if (f <= m) result++;                     
                f -= cost[x[k]][1];                 
            }                 
            else
            {                     
                int g = f + min * (n - k + 1);                     
                if (g < m) Try(k + 1);                 
            }                 
            f -= cost[x[k - 1]][x[k]];                 
            mark[i] = 0;             
        }         
    }     
}    
 
int main()
{         
    scanf("%d %d", &n, &m);         
    for(int i = 1; i < n + 1; i++)
    {             
        for(int j = 1; j < n + 1; j++)
        {                 
            scanf("%d", &cost[i][j]);                 
            if(cost[i][j] < min) min = cost[i][j];             
        }         
    }         
    x[1] = 1;         
    Try(2);         
    printf("%d", result);     
}
