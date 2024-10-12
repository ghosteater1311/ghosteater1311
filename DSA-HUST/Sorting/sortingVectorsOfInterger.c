#include <stdio.h>
#include <stdlib.h>

int n, m;

int cmp(int *a[], int i, int j)
{
    for (int k = 1; k <= m; k++)
    {
        if (a[i][k] < a[j][k] ) return -1;
        else if(a[i][k] > a[j][k]) return 1;
    }
    return 0;
}
 
void swap(int *a[], int i, int j)
{
    int * tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
 
void Heapify(int *a[], int i, int t)
{
    int L = 2 * i; 
    int R = 2 * i + 1;
    int maxIdx = i;
    if (L <= t && cmp(a, L, maxIdx) == 1) maxIdx = L;
    if (R <= t && cmp(a, R, maxIdx) == 1) maxIdx = R;
    if (maxIdx != i){
        swap(a, i, maxIdx);
        Heapify(a, maxIdx, t);
    }
}
 
void BuildHeap(int *a[])
{
    for (int i = n / 2; i >= 1; i--)
    {
        Heapify(a, i, n);
    }
}
 
void HeapSort(int *a[])
{
    BuildHeap(a);
    for (int i = n; i >= 2; i--)
    {
        swap(a, 1, i);
        Heapify(a, 1, i - 1);
    }
}
 
int main(){
    int *a[100001];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * (m + 1));
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    }
    HeapSort(a);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}