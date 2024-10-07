#include <stdio.h> 
#define MAX 1000
   
int main() 
{ 
    int i,b = 0;
    float a[MAX];
    for (i = 0; i <= MAX; i++)
    {
        scanf("%f", &a[i]);
        if (a[i] == 0) break;
        if (a[i] > 1.3) b = b + 30000;
            else b = b + 20000;

    }
    printf("%d", b);

    return 0;
}
