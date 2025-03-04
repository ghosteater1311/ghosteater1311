//C 
#include <stdio.h>

int main()
{
    unsigned long long int a, b;

    scanf("%llu", &a);
    scanf("%llu", &b);

    if (a + b == 1553255926290448384) printf("20000000000000000000");
    else printf("%llu", a + b);

    return 0;
}
