#include <stdio.h>

int a[1000], n;

int check(int b[])
{
    for(int i = 0; i < n - 1; i++)
    {
        if(b[i] == b[i + 1] && b[i] == 1)
        {
            return 0;
        }
    }
    return 1;
}

void solution()
{
    if(check(a) == 0)
    {
        return;
    }
    else{
        for(int i = 0; i < n; i++)
        {
            printf("%d", a[i]);
        }
        printf("\n");
    }
}

void Try(int k)
{
    for(int y = 0; y <= 1; y++)
    {
        a[k] = y;
        if(k == n - 1) solution();
        else Try(k + 1);
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);
    return 0;
}
