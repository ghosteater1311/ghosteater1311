#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void swap(char* a[], char** b)
{
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void Heapify(char* a[], int n, int i)
{
    int L = 2 * i + 1; 
    int R = 2 * i + 2;
    int maxIdx = i;
    if (L < n && strcmp(a[L], a[maxIdx]) > 0) maxIdx = L;
    if (R < n && strcmp(a[R], a[maxIdx]) > 0) maxIdx = R;
    if (maxIdx != i){
        swap(&a[i], &a[maxIdx]);
        Heapify(a, n, maxIdx);
    }
}
 
void HeapSort(char* a[])
{
    for (int i = n / 2 - 1; i >= 0; i--) Heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        Heapify(a, i, 0);
    }
}

int main()
{
    scanf("%d", &n);
    char **a = (char **)malloc(n * sizeof(char *));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        a[i] = (char *)malloc(101 * sizeof(char));
        if (a[i] == NULL) 
        {
            fprintf(stderr, "Memory allocation failed for string %d\n", i);
            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return 1;
        }
        scanf("%100s", a[i]);
    }
    HeapSort(a);
    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", a[i]);
        
    }
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;   
}