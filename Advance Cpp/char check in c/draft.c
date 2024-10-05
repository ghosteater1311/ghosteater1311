#include <stdio.h>
#include <string.h>

int main(void)
{
    int i,n,j;
    char a[5] = {'u', 'e', 'o', 'a', 'i'};
    char c[80];
    fgets(c, 81, stdin);
    n = 0;
    for (i = 0; i < 80; i++)
    {
        for (j = 0; j <= 4; j++)
        {
            if (c[i] == a[j]) n++;
        }
    }

    printf("%d\n", n);

    return 0;
}