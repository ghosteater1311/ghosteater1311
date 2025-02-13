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

    printf("%d\n", integer);
    printf("%0.1lf", fraction);

    return 0;
}