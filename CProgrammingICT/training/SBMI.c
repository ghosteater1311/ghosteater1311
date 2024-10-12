#include <stdio.h>
#define MAX 100

double doublepow(double a)
{
       return a*a;
}

int main() 
{
    int i, j, n = MAX;
    double Sheight[MAX];
    int count = 0;
    double AverageHeight, AverageWeight;
    double Sweight[MAX], SBMI[MAX];
    for (i = 1; i < n; i++)
    {
        scanf("%ld", &Sheight[i]);
        scanf("%ld", &Sweight[i]);
        if ((Sheight[1] == -1) || (Sweight[1] == -1)) 
        {
            printf("0cm 0kg 0");
            return 0;
        }
        if ((Sheight[i] == -1) || (Sweight[i] == -1)) 
        {
            j = i - 1;
            break;
        }
        AverageHeight += Sheight[i];
        AverageWeight += Sweight[i];
    }
    for (i = 1; i <= j; i++)
    {
        SBMI[i] = Sweight[i] / doublepow(Sheight[i] / 100);
        if ((SBMI[i] < 14.5) || (SBMI[i] > 16.8)) count++;
    }
    AverageHeight = AverageHeight / j;
    AverageWeight = AverageWeight / j;
    printf( "%.2fcm %.2fkg %d",AverageHeight,AverageWeight,count);
    return 0;
}
