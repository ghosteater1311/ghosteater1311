#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Student{
    int order;
    char mssv[9];
    char name[30];
    char sdt[11];
    int diem;
} STD;

int main()
{
    int cnt = 0, i = 0;
    FILE *fptr1, *fptr2;
    STD std[100];
    fptr2 = fopen("bangdiem.txt", "w");
    fptr1 = fopen("filemoi.txt", "r");
    if (fptr1 == NULL)
    {
        perror("failed to open file 1!");
        exit(1);
    }
    if (fptr2 == NULL)
    {
        perror("failed to open file 2!");
        exit(1);
    }
    while((fscanf(fptr1, "%d %s %s %s", &std[i].order, &std[i].mssv, &std[i].name, &std[i].sdt))!= EOF)
    {
        i++;
    }
    cnt=i;
    for(i=0; i < cnt; i++)
    {
        printf("Nhap diem cua hoc sinh thu %d:", i+1);
        scanf("%d", &std[i].diem);
    }
    for(i=0; i < cnt; i++)
    {
        fprintf(fptr2,"%d %s %s %s: %d\n", std[i].order, std[i].mssv, std[i].name, std[i].sdt, std[i].diem);
        printf("%d %s %s %s: %d\n", std[i].order, std[i].mssv, std[i].name, std[i].sdt, std[i].diem);
    }
    fclose(fptr1);
    fclose(fptr2); 
    return 0; 
}