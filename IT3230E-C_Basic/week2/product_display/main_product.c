#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct product
{
    int index;
    char name[20];
    double price;
} product;


int main()
{
    FILE* file_in;
    product arr[MAX];
    int i, n;

    if ((file_in = fopen("product.txt", "r")) == NULL)
    {
        printf("Cannot open the file!");
    }
    else
    {
        while (fscanf(file_in,"%d%s%lf", &arr[i].index, arr[i].name, &arr[i].price) != EOF)
        {
            i++;
        }

        n = i;

        for (int j = 0; j < n; j++)
        {
            printf("%-6d%-24s%-6.2lf\n", arr[j].index, arr[j].name, arr[j].price);
        }
    }

    fclose(file_in);

    return 0;
}