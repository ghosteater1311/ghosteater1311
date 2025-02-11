#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int array_compare(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

int main(void)
{
    int input1[SIZE], input2[SIZE], i;

    printf("Please enter a list of %d integers:\n", SIZE);
    for (i = 0; i < SIZE; ++i) scanf("%d", &input1[i]);

    printf("Please enter another list of %d integers:\n", SIZE);
    for (i = 0; i < SIZE; ++i) scanf("%d", &input2[i]);

    if (array_compare(input1, input2, SIZE) == 1)
        printf("Both lists are identical!\n");
    else
        printf("The lists are not identical\n");

    return 0;
}
