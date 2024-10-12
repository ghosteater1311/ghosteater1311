#include <stdio.h>
#include <math.h>
#define MAX 100

int main()
{
    int i, NumPassengers, count;
    float PackageWeight[MAX];

    count = 0;
    scanf("%d", &NumPassengers);
    for (i = 1; i <= NumPassengers; i++){
        scanf("%d", &PackageWeight[i]);
        if (PackageWeight[i] > 7.0) {
            count++;
        }
    }
    print("%d", count);
    return 0;
}
