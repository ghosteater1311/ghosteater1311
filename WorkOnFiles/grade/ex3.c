#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//Students Struct
typedef struct 
{
    int order;
    char mssv[9];
    char name[30];
    char sdt[11];
    int diem;
} STD;
//Convert .txt file to .dat file
void Text_To_Dat() 
{
    FILE *fptr1 = fopen("bangdiem.txt", "r");
    FILE *fptr2 = fopen("grade.dat", "wb");
    if (fptr1 == NULL || fptr2 == NULL) 
    {
        printf("Cannot open files.\n");
        return;
    }
    int count = 0;
    STD student;
    while (fscanf(fptr1, "%d %s %s %s %d", &student.order, student.name, student.mssv, student.sdt, &student.diem) == 5) {
        fwrite(&student, sizeof(STD), 1, fptr2);
        count++;
    }
    fclose(fptr1);
    fclose(fptr2);
    printf("Convert Successful.\n");
}
//Display the information in console
void Display_Dat_File() 
{
    FILE *file = fopen("grade.dat", "rb");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    STD student;
    printf("Order\t\tName\t\tStudent ID\t\tPhone\t\tGrade\n");
    printf("---------------------------------------------------------------------------------\n");
    while (fread(&student, sizeof(STD), 1, file) == 1) 
    {
        printf("%d\t%s\t\t%s\t\t%s\t%d\n", student.order, student.name, student.mssv, student.sdt, student.diem);
    }
    fclose(file);
}
//Search for student's ID and Update the grade
void Search_And_Update() 
{
    FILE *file = fopen("grade.dat", "r+b");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    char searchID[9];
    printf("Enter student ID to search: ");
    scanf("%s", searchID);
    STD student;
    int found = 0;
    while (fread(&student, sizeof(STD), 1, file) == 1) 
    {
        if (strcmp(student.mssv, searchID) == 0) {
            found = 1;
            printf("Student found. Enter new grade: ");
            scanf("%d", &student.diem);
            fseek(file, -sizeof(STD), SEEK_CUR);
            fwrite(&student, sizeof(STD), 1, file);
            printf("Grade updated successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Student not found.\n");
    }
    fclose(file);
}
//Command-line Interface
void printMenu() 
{
    printf("1. TextToDat\n");
    printf("2. Display Dat file\n");
    printf("3. Search and Update\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}
//Main Function
int main(int argc, char *argv[]) 
{
int choice;
do {
    system("cls");
    printMenu();
    scanf("%d", &choice);
    getchar();
    switch(choice) 
    {
        case 1:
            system("cls");
            printf("\n");
            Text_To_Dat();
            printf("Press any key to contiune...");
            getch();
            system("cls");
            break;
        case 2:
            system("cls");
            Display_Dat_File();
            printf("Press any key to contiune...");
            getch();
            printf("\n\n");
            break;
        case 3:
            system("cls");
            Search_And_Update();
            printf("Press any key to contiune...");
            getch();
            system("cls");
            break;
        case 4:
            system("cls");
            break;
        default:
            system("cls");
            printf("Invalid choice. Please try again.\n");
            getch();
            system("cls");
    }
} while(choice != 4);
return 0;
}