#include <stdio.h> 

int main() 
{
    int sotien, dem, i, j, k, l;
    //Nhap vao so tien
    scanf("%d\n", &sotien);
    dem = 0;
    //Kiem tra so tien hop le va so cach
    if (sotien > 5000000) 
    {
        printf("%d", dem);
        return 0;
    }
    else if (sotien < 50000 || sotien % 50000 != 0) 
    {
        printf("%d", dem);
        return 0 ;
    }
    else 
    {
        for (i = 0; i <= 10; i++)
        for (j = 0; j <= 25; j++)
        for (k = 0; k <= 50; k++)
        for (l = 0; l <= 100; l++)
        if (500000 * i + 200000 * j + 100000 * k + 50000 * l == sotien) 
        dem++;
    }
    printf("%d", dem);
return 0;

}