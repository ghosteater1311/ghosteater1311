#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    char ch;
    scanf(" %c", &ch);
    
    char query[20];
    while (scanf("%s", query) == 1) 
    {
        if (strcmp(query, "***") == 0) 
        {
            break;
        }
        else if (strcmp(query, "find-max") == 0) 
        {
            int max_val = arr[0];
            for (int i = 1; i < n; i++) 
            {
                if (arr[i] > max_val) max_val = arr[i];
            }
            printf("%d\n", max_val);
        }
        else if (strcmp(query, "find-min") == 0) 
        {
            int min_val = arr[0];
            for (int i = 1; i < n; i++) 
            {
                if (arr[i] < min_val) min_val = arr[i];
            }
            printf("%d\n", min_val);
        }
        else if (strcmp(query, "sum") == 0) 
        {
            int sum = 0;
            for (int i = 0; i < n; i++) 
            {
                sum += arr[i];
            }
            printf("%d\n", sum);
        }
        else if (strcmp(query, "find-max-segment") == 0) 
        {
            int i, j;
            scanf("%d %d", &i, &j);
            int max_seg = arr[i-1];
            for (int k = i; k < j; k++) 
            {
                if (arr[k] > max_seg) 
                {
                    max_seg = arr[k];
                }
            }
            printf("%d\n", max_seg);
        }
    }
    
    free(arr);
    return 0;
}
