#include <stdio.h>
#include <stdlib.h>


typedef struct coor{
    int co;
    int ro;
}coor;

coor used[200];
int n, ma[12][12], usedco[13], usedrow[13], count = 0, dem = 0;

int check(int i, int k)
{
    if (usedco[i] == 1) return 0;
    for (int j = 0; j < dem; j++)
    {
        if(abs(used[j].co - i) == abs(used[j].ro - k)) return 0;
    }
    return 1;
}

void Try(int k)
{
    if(usedrow[k] == 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(check(i, k))
            {
                usedco[i] = 1;
                usedrow[k] = 1;
                used[dem].co = i;
                used[dem].ro = k;
                dem++;
                if(k == n-1) count++;
                else Try(k + 1);
                dem--;
                usedco[i] = 0;
                usedrow[k] = 0;
            }
        }

    }
    else
    {
        if(k < n - 1) Try(k + 1);
        else count++;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &ma[i][j]);
            if(ma[i][j] == 1)
            {
                used[dem].co = j;
                used[dem].ro = i;
                dem++;
                usedco[j] = 1;
                usedrow[i] = 1;
            }
        }
    }
    Try(0);
    printf("%d", count);
}