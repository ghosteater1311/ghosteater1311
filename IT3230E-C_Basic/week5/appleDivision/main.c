#include <stdio.h>
#include <stdlib.h>
#define llu unsigned long long int

llu n;
llu apple[100000];
llu total = 0;
llu half = 0;
int dp[100000][100000] = {0};

void solve()
{
    for (llu i = 0; i < n; i++)
    {
        total += apple[i];
    }

    half = total / 2;

    dp[0][0] = 1;

    for (llu i = 0; i < n; i++)
    {
        for (llu j = 0; j < half; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
            }
            
            if ((j >= apple[i - 1]) && (dp[i - 1][j - apple[i - 1]]))
            {
                dp[i][j] = 1;
            }
        }
    }

    llu max_weight = 0;
    
    for (llu j = half; j > 0; j--)
    {
        if (dp[n][j])
        {
            
        }
    }

}

int main()
{
    scanf("%llu", &n);
    for (llu i = 0; i < n; i++)
    {
        scanf("%llu", &apple[i]);
    }


}
