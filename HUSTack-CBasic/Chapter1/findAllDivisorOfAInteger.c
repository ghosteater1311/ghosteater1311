//C 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *divisors = (int *)malloc(2 * n * sizeof(int));
    if (divisors == NULL) 
    {
        exit(0);
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) 
    {
        if (n % i == 0) {
            divisors[count++] = -i;
            if (i != n / i) 
            {
                divisors[count++] = -n / i;
            }
        }
    }
    for (int i = 1; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
        {
            divisors[count++] = i;
            if (i != n / i) 
            {
                divisors[count++] = n / i;
            }
        }
    }
    qsort(divisors, count, sizeof(int), compare);
    for (int i = 0; i < count; i++) 
    {
        printf("%d ", divisors[i]);
    }
    free(divisors);
    return 0;
}
