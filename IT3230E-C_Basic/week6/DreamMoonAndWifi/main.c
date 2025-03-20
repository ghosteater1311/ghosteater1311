#include <stdio.h>
#include <string.h>

int n;
char Drazil[11];
char Dreamoon[11];

void input()
{
    scanf("%s %s", Drazil, Dreamoon);
    if (strlen(Drazil) != strlen(Dreamoon) && strlen(Drazil) > 10) return;
}

long long combination(int n, int k) 
{
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; i++) 
    {
        res *= (n - k + i);
        res /= i;
    }
    return res;
}

void solve()
{
    int original_pos = 0;
    for (int i = 0; Drazil[i]; i++) 
    {
        original_pos += (Drazil[i] == '+') ? 1 : -1;
    }

    int current_sum = 0, q = 0;
    for (int i = 0; Dreamoon[i]; i++) 
    {
        if (Dreamoon[i] == '+') current_sum++;
        else if (Dreamoon[i] == '-') current_sum--;
        else q++;
    }

    int required = original_pos - current_sum;
    if ((required + q) % 2 != 0) 
    {
        printf("0.000000000\n");
        return 0;
    }

    int k = (required + q) / 2;
    if (k < 0 || k > q) 
    {
        printf("0.000000000\n");
        return 0;
    }

    long long comb = combination(q, k);
    long long denominator = 1LL << q;
    double probability = (double)comb / denominator;
    printf("%.9f\n", probability);
}

int main()
{
    input();
    solve();
    return 0;
}