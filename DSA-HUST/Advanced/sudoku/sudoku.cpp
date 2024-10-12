//C
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[n][9][9];
    int result[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 9; j++)
        {
            int sum = 0;
            for (int k = 0; k < 9; k++)
            {
                scanf("%d", &matrix[i][j][k]);
                if (matrix[i][j][k] < 1 || matrix[i][j][k] > 9)
                    result[i] = 0;
                sum += matrix[i][j][k];
            }
            if (sum != 45){
                result[i] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < 9; i++)
        {
            int tong = 0;
            for (int j = 0; j < 9; j++)
            {
                tong += matrix[k][j][i];
            }
            if (tong != 45)
                result[k] = 0;
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < 9; i+=3)
        {
            int sum = 0,count = 0;
            for (int j = 0; j < 9; j++)
            {
                sum = sum + matrix[k][i][j] + matrix[k][i+1][j] + matrix[k][i+2][j];
                count++;
                if (count == 3)
                {
                    if (sum != 45)
                        result[k] = 0;
                    sum = 0;
                    count = 0;
                }
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d\n", result[j]);
    }
}
