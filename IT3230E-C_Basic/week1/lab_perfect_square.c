#include <stdio.h>
#include <math.h>
#define MAX 100000

int main()
{
    int n, temp, arr[MAX];
    int count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp = (int)sqrt(arr[i]);
            if (temp * temp == arr[i]) count++;
        }
    }
    printf("%d", count);
}