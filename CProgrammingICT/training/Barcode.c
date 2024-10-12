#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str_barcode[20];
    int num_barcode[20];

    fgets(str_barcode, 13, stdin);

    for (int i = 0; i <= 12; i++)
    {
        num_barcode[i] = atoi(str_barcode[i]);
    }
    if (strcmp(str_barcode[0], "8") == 0)
    {
        if (strcmp(str_barcode[1], "9") == 0)
        {
            if (strcmp(str_barcode[2], "3") == 0)
            {
                int even_sum = num_barcode[1] + num_barcode[3] + num_barcode[5] + num_barcode[7] + num_barcode[9] + num_barcode[11];
                int odd_sum = num_barcode[0] + num_barcode[2] + num_barcode[4] + num_barcode[6] + num_barcode[8] + num_barcode[10];
                if ((even_sum * 3 + odd_sum + num_barcode[12]) % 10 == 0)
                {
                    printf("1");
                    return 0;
                }
                else 
                {
                    printf("0");
                    return 0;
                }
            }
            else 
            {
                printf("0");
                return 0;
            }
        }
        else 
        {
            printf("0");
            return 0;
        }
    }
    else
    {
        printf("0");
        return 0;
    }
}