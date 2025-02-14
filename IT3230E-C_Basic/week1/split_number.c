#include <stdio.h>
#include <math.h>

void split(float num, int* int_part, float* frac_part)
{
    *int_part = (int)floor(num);
    *frac_part = num - *int_part;
}

int main()
{
    float num, fraction;
    int integer;

    scanf("%f", &num);

    split(num, &integer, &fraction);

    printf("%d %0.2f", integer, fraction);

    return 0;
}