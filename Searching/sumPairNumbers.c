#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}


int binarySearch(int* arr, int left, int right, int target) 
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) 
        {
            return mid;
        } 
        else if (arr[mid] < target) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return -1;
}

void solve() 
{
    int n, M;
    scanf("%d %d", &n, &M);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int count = 0;
    for (int i = 0; i < n; ++i) 
    {
        int k = M - a[i];
        if (binarySearch(a, i + 1, n - 1, k) != -1) 
        {
            count++;
        }
    }
    printf("%d\n", count);
    free(a);
}

int main() 
{
    solve();
    return 0;
}
