#include <stdio.h>

int main()
{
    int a[10];
    a[0] = 4;
    printf("%d\n", a[0]);
    printf(&a[0]);
}