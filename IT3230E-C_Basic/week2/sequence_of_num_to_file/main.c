#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void into_file(FILE* file, int arr[], int size)
{
    int sum = 0;

    fprintf(file, "%d ", size);

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        fprintf(file, "%d ", arr[i]);        
    }
    
    fprintf(file, "\nSum: %d", sum);
}

int main()
{
    int sequence[MAX];
    int n;

    FILE* file_out = fopen("out.txt", "w+");

    if (file_out == NULL)
    {
        printf("Cannot open the file!\n");
    } 

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sequence[i]);
    }

    into_file(file_out, sequence, n);

    fclose(file_out);

    return 0;

}