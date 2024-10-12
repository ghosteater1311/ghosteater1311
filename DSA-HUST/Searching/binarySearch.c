#include <stdio.h>

int binarySearch(int a[], int low, int high, int key)
{
    if (low <= high) 
    {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) return binarySearch(a, low, mid - 1, key);
        else return binarySearch(a, mid + 1, high, key);
    }
    else return -1;
}