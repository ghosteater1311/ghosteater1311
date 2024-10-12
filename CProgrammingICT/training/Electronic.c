#include <stdio.h>

int main() 
{
    int elec;
    float times;
    float avg = 0;
    scanf("%d %f", &elec, &times);
    avg = ((elec * times) * 30) / 1000;
    printf("%.2f", avg);

    return 0;
}
