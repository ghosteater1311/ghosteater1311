#include <stdio.h>

void move(int n, int A, int B, int C) 
{
    if (n == 1) 
    {
        printf("%d %d\n", A, B);
        return;
    }
    move(n - 1, A, C, B);
    move(1, A, B, C);
    move(n - 1, C, B, A);
}

int main() 
{
    int n, A, B, C;
    scanf("%d %d %d %d", &n, &A, &B, &C);

    int step = 1;
    for (int i = 0; i < n; i++) 
    {
        step *= 2;
    }
    step -= 1;
    printf("%d\n", step);

    move(n, A, B, C);

    return 0;
}