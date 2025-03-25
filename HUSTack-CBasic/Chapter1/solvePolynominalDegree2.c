//C 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    double x, x1, x2;

    double delta = (b * b) - (4 * a * c);

    if (delta > (double)0)
    {
        x1 = 0 - ((b - sqrt(delta)) / (2 * a)); 
        x2 = 0 - ((b + sqrt(delta)) / (2 * a));
        printf("%0.2lf %0.2lf\n", x2, x1);
    }
    else if (delta == (double)0)
    {
        x = 0 - (b/(2 * a));
        printf("%0.2lf\n", x);
    }
    else
    {
        printf("NO SOLUTION\n");
    }

    return 0;
}
