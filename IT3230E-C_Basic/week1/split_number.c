#include <stdio.h>

void split(double num, int* int_part, double* frac_part)
{
    *int_part = (int)num;
    *frac_part = num - *int_part;
}

int main()
{
    double num, fraction;
    int integer;

    scanf("%lf", &num);

    split(num, &integer, &fraction);

    printf("%d ", integer);
    if (fraction < 0) printf("%0.2lf", 0 - fraction);
    else printf("%0.2lf", fraction);

    return 0;
}