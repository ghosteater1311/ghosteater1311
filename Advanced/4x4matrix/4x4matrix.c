#include <stdio.h>

int main()
{
    int a[4][4];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }      
    return 0;
}