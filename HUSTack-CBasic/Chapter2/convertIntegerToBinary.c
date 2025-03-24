#include <stdio.h>

void IntToBinary(int n)
{
    if (n == 0) return;
    IntToBinary(n / 2);
    int bin = n % 2;
    printf("%d", bin);
}

int main()
{   
    int n;
    scanf("%d", &n);

    IntToBinary(n);

    return 0;
}
