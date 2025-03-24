#include <stdio.h>

int UCLN(int n, int m)
{
    if (n == 0) return m;
    return UCLN(m % n, n);
}

int main()
{
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    int result;

    result = UCLN(a, b);

    printf("%d", result);

    return 0;
}
