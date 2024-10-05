#include <stdio.h>

int linearSearch(int a[], int size, int target)
{ 
    int i;
    for (i = 1; i <= size; i++)
    {
        if (a[i] == target)
        {
            return a[i];
            break;
        }
        else 
        {
            return -1;
            break;
        }
    }
}