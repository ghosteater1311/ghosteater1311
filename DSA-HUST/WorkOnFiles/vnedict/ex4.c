#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr1, *fptr2;
    fptr1 = fopen("vnedict.txt", "r");
    fptr2 = fopen("vnedict.dat", "w+b");
    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("Cannot open the file!");
        exit(1);
    }
    char c;
    int num, start, end;
    while (!feof(fptr1))
    {
        fread(&c, sizeof(char), 1, fptr1);
        fwrite(&c, sizeof(char), 1, fptr2);
    }
    printf("Enter the number: ");
    scanf("%d %d", &start, &end);
    char str[end - start + 1]; 
    fseek(fptr1, start, SEEK_SET);   
    num = fread(str, sizeof(char), end - start, fptr1);
    str[num] = '\0';
    printf("%s", str);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}