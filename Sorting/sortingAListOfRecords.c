#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate
{
    char code[50];
    int score;
} Candidate;

int n;

void swap(Candidate a[], int i, int j)
{
    Candidate tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
 
void Heapify(Candidate a[], int i, int t)
{
    int L = 2 * i; 
    int R = 2 * i + 1;
    int minIdx = i;
    if (L <= t && a[L].score < a[minIdx].score) minIdx = L;
    if (R <= t && a[R].score < a[minIdx].score) minIdx = R;
    if (minIdx != i){
        swap(a, i, minIdx);
        Heapify(a, minIdx, t);
    }
}
 
void BuildHeap(Candidate a[])
{
    for (int i = n / 2; i >= 1; i--)
    {
        Heapify(a, i, n);
    }
}
 
void HeapSort(Candidate a[])
{
    BuildHeap(a);
    for (int i = n; i >= 2; i--)
    {
        swap(a, 1, i);
        Heapify(a, 1, i - 1);
    }
}

int main()
{
    Candidate a[1000];
    for (int i = 1; i < 1000; i++)
    {
        scanf("%s", &a[i].code);
        if (strcmp(a[i].code, "#") == 0) 
        {
            n = i - 1;
            break;
        }
        scanf("%d", &a[i].score);
    } 
    quickSort(a->score);
    for (int i = 1; i < n; i++)
    {
        printf("%s %d", a[i].code, a[i].score);
    }
}