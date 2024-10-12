#include <math.h>
#include <stdio.h>
#define MAX 100

int main()
{
    int i,j;
    float StockBegin,StockEnd,StockMax,StockMin;
    float StockElement[MAX];

        StockMax = StockElement[0];
    for (i = 0; i <= MAX; i++)
    {
        j = i - 1;
        scanf("%f", &StockElement[i]);
        StockMin = StockElement[0];
        StockBegin = StockElement[0];
        if (StockMax < StockElement[i]) 
        {
            StockMax = StockElement[i];
        }
        for (i = 0; i <= j; i++){
            if (StockMin > StockElement[i]) 
            {
                    StockMin = StockElement[i];
            } 
        }
        if (StockElement[i] == -1) 
        {
            StockEnd = StockElement[i - 1];
            break;
        }
        
    }
    if (StockElement[0] == -1)
    {
            printf("-1 -1 -1 -1");
            return 0;
    }
    printf("%.2f %.2f %.2f %.2f", StockBegin, StockEnd, StockMax, StockMin);
    return 0;
    
}
