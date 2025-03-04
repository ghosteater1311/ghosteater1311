#include <stdio.h>
#include <stdlib.h>

int term[1000000];

unsigned long long Fibonacci(int n)
{
    if (n <= 1)  return n;
    if (term[n] != 0) return term[n];
    else
    {
        term[n] = (Fibonacci(n-1) + Fibonacci(n-2)) % (unsigned long long)(1e9+7);
        return term[n];
    }  
}

int main()
{
    int n;

    scanf("%d", &n);
    int result = Fibonacci(n);

    printf("%d", result);

    return 0;
}