#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double a, b, c;
    
    if (argc != 4)
    {
        printf("Wrong number of arguments!\n");
        return 1;
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    double x, x1, x2;

    double delta = (b * b) - (4 * a * c);

    if (delta > (double)0)
    {
        x1 = 0 - ((b - sqrt(delta)) / (2 * a)); 
        x2 = 0 - ((b + sqrt(delta)) / (2 * a));
        printf("x1 = %lf\nx2 = %lf\n", x1, x2);
    }
    else if (delta == (double)0)
    {
        x = 0 - (b/(2 * a));
        printf("x1 = x2 = %lf\n", x);
    }
    else
    {
        printf("No solution found!\n");
    }

    return 0;
}