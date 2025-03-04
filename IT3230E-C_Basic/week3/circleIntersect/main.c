#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Circle
{
    int x;
    int y;
    double r;
} circle;

int intersect(circle c1, circle c2) 
{
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    double d_squared = dx * dx + dy * dy;
    double sum = c1.r + c2.r;
    double sum_squared = sum * sum;
    return d_squared <= sum_squared;
}

int main()
{
    circle* c = (circle*)malloc(2 * sizeof(circle));

    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &c[i].x);
        scanf("%d", &c[i].y);
        scanf("%lf", &c[i].r);
    }

    if (intersect(c[0], c[2]))
    {
        printf("2 circles are intersect.");
    }
    else 
    {
        printf("2 circle are not intersect.");
    }

    free(c);

    return 0;
}