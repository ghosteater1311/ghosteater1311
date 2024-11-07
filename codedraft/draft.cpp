#include <bits/stdc++.h>

using namespace std;

int check(int n)
{
    return n > 0 ? 1 : 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", check(n));
    return 0;
}