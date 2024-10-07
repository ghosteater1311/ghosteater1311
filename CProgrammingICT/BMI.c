#include <stdio.h>

double pow2(float a)
{
    return a*a;
}
float BMICalculate(float height, float weight)
{
    float BMI;
    BMI = weight / pow2(height);
    return BMI;
}

int main()
{
    float height, weight;
    scanf("%f %f", &height, &weight);
    printf("%.2f", BMICalculate(height, weight));
    return 0;
}
