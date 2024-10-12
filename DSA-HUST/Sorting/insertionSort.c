#include <stdio.h>

void insertionSort(int a[], int n)
{
    for (int k = 1; k <= n - 1; k++)
    {
        int temp = a[k];
        int pos = k;
        while ((pos >= 0) && (a[pos - 1] > temp)) 
        {
            a[pos] = a[pos - 1];
            pos--;
        } 
        a[pos] = temp;  
    }
}

int main()
{
    int n; 
    int a[100];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}