#include <stdio.h>

int main()
{
    int max_weight;
    int max_people_45kg;
    int max_people_80kg;
    
    scanf("%d", &max_weight);
    max_people_45kg = max_weight / 45;
    max_people_80kg = max_weight / 80;
    printf("%d-%d", max_people_80kg, max_people_45kg);
}