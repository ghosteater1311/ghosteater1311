#include <stdio.h>

int D[1000][1000];

unsigned long long C(int n, int k)
{
    if (D[n][k] > 0) return D[n][k];
    else
    {        
        D[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % (long long)(1e9+7);
        return D[n][k];
    }

}

int main()
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
        {            
            D[i][0] = 1;            
            D[i][i] = 1;
        }

    int a, b;

    scanf("%d %d",&a, &b);

    printf("%llu", (C(b, a)) % (unsigned long long)(1e9+7));

    return 0;
}
