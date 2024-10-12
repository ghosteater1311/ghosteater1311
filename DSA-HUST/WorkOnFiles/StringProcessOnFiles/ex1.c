#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 80
void BlockReadWrite(FILE* fin, FILE* fout)
{
    int num;
    char buff[MAX_LEN + 1];
    while (!feof(fin))
    {
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
    }
}
void LineReadWrite(FILE* fin, FILE* fout)
{
    char buff[MAX_LEN + 1];
    while (fgets(buff, sizeof(buff), fin) != NULL)
    {
        fputs(buff, fout);
        printf("%s", buff);
    }
}
void CharReadWrite(FILE* fin, FILE* fout)
{
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
    }
}
int main(int argc, char* argv[])
{
    int num, n;
    FILE* fptr1, * fptr2;
    fptr1 = fopen("file1.txt", "w");
    fptr2 = fopen("file2.txt", "r");
    if (fptr1 == NULL)
    {
        perror("Failed to open file 1!");
        exit(1);
    }
    if (fptr2 == NULL)
    {
        perror("Failed to open file 2!");
        exit(1);
    }
    printf("1.Copy by character\n2.Copy by line\n3.Copy by block - optional size\n4.Quit\nEnter your selection: ");
    scanf("%c", &num);
    switch (num)
    {
        case '1': CharReadWrite(fptr2, fptr1); break;
        case '2': LineReadWrite(fptr2, fptr1); break;
        case '3': BlockReadWrite(fptr2, fptr1); break;
        case '4': exit(1); return 0;
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
