#include <stdio.h>

int bestTrip[10000];
int n;
int cost[10000][10000];
int minStep;
int minCost= 1e97;
int trip[10000];
int mark[10000] = {0};
int currentCost = 0;

void input()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i != j)
            {
                if (cost[i][j] < minStep)
                {
                    minStep = cost[i][j];
                }
            }
        }
    }

    printf("MinStep: %d\n", minStep);
    //1 -> 2 -> ... -> 1
    trip[0] = 1;
    trip[n] = 1;
    mark[1] = 0;
}

void updateSolution()
{
    int totalCost = currentCost + cost[trip[n - 1]][trip[n]];
    if (totalCost < minCost)
    {
        minCost = totalCost;
        for (int i = 0; i <= n; i++)
        {
            bestTrip[i] = trip[i];
        }
    }
}

int check(int k, int v)
{
    if (mark[v] == 0)
    {
        return 1;
    }
}

void Try(int k)
{
    for (int v = 2; v <= n; v++)
    {
        if (check(k, v))
        {
            trip[k] = v;
            mark[v] = 1;
            currentCost += cost[trip[k - 1]][trip[k]];
            
            if (k == n - 1)
            {
                updateSolution();
            }

            else
            {
                if (currentCost + (n - k) * minStep < minCost)
                {
                    Try(k + 1);
                }
            }
            mark[v] = 0;
            currentCost -= cost[trip[k - 1]][trip[k]]; 
        }
    }
}

int main()
{
    input();
    Try(2);
    printf("Best trip with cost: %d\n", minCost);
    for (int i = 0; i <= n; i++)
    {
        printf("%d", bestTrip[i]);
    }
    printf("\n");
    return 0;
}