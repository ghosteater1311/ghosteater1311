#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define FILENAME "sinhvien.txt"

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    float score;
    int isAdmin;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void loadStudents();
void saveStudents();
int authenticate(char *username, char *password);
void studentMenu(int studentIndex);
void adminMenu();
void addStudent();
void editStudent();
void deleteStudent();
void listStudents();

int main() {
    loadStudents();
    int choice;
    do {
        printf("1. Dang nhap\n2. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        if (choice == 1) {
            char username[MAX_USERNAME_LENGTH];
            char password[MAX_PASSWORD_LENGTH];
            printf("Username: ");
            gets(username);
            printf("Password: ");
            gets(password);

            int studentIndex = authenticate(username, password);
            if (studentIndex != -1) {
                if (students[studentIndex].isAdmin) {
                    adminMenu();
                } else {
                    studentMenu(studentIndex);
                }
            } else {
                printf("Sai username hoac password.\n");
            }
        }
    } while (choice != 2);

    return 0;
}

void loadStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return;
    }
    while (fscanf(file, "%s %s %f %d", students[studentCount].username, students[studentCount].password, &students[studentCount].score, &students[studentCount].isAdmin) != EOF) {
        studentCount++;
    }
    fclose(file);
}

void saveStudents() {
    FILE *file = fopen(FILENAME, "w");
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s %s %f %d\n", students[i].username, students[i].password, students[i].score, students[i].isAdmin);
    }
    fclose(file);
}

int authenticate(char *username, char *password) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0 && strcmp(students[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

void studentMenu(int studentIndex) {
    int choice;
    do {
        printf("1. Xem diem cua minh\n2. Doi mat khau\n3. Quay lai menu dau\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        if (choice == 1) {
            printf("Diem cua ban: %.2f\n", students[studentIndex].score);
        } else if (choice == 2) {
            char newPassword1[MAX_PASSWORD_LENGTH], newPassword2[MAX_PASSWORD_LENGTH];
            printf("Nhap mat khau moi: ");
            gets(newPassword1);
            printf("Nhap lai mat khau moi: ");
            gets(newPassword2);

            if (strcmp(newPassword1, newPassword2) == 0) {
                strcpy(students[studentIndex].password, newPassword1);
                saveStudents();
                printf("Doi mat khau thanh cong.\n");
            } else {
                printf("Mat khau khong trung khop.\n");
            }
        }
    } while (choice != 3);
}

void adminMenu() {
    int choice;
    do {
        printf("1. Them sinh vien\n2. Xoa sinh vien\n3. Sua thong tin sinh vien\n4. Xem danh sach sinh vien\n5. Quay lai menu dau\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            deleteStudent();
        } else if (choice == 3) {
            editStudent();
        } else if (choice == 4) {
            listStudents();
        }
    } while (choice != 5);
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Khong the them sinh vien moi. Danh sach da day.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    float score;
    int isAdmin;

    printf("Nhap username: ");
    gets(username);
    printf("Nhap password: ");
    gets(password);
    printf("Nhap diem: ");
    scanf("%f", &score);
    printf("La admin? (1: Co, 0: Khong): ");
    scanf("%d", &isAdmin);
    getchar(); // Clear newline character from input buffer

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0) {
            printf("Username da ton tai. Khong the them sinh vien moi.\n");
            return;
        }
    }

    strcpy(students[studentCount].username, username);
    strcpy(students[studentCount].password, password);
    students[studentCount].score = score;
    students[studentCount].isAdmin = isAdmin;
    studentCount++;
    saveStudents();
    printf("Them sinh vien thanh cong.\n");
}

void editStudent() {
    char username[MAX_USERNAME_LENGTH];
    printf("Nhap username cua sinh vien can sua: ");
    gets(username);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0) {
            printf("Sua thong tin sinh vien %s:\n", username);
            printf("Nhap password moi: ");
            gets(students[i].password);
            printf("Nhap diem moi: ");
            scanf("%f", &students[i].score);
            printf("La admin? (1: Co, 0: Khong): ");
            scanf("%d", &students[i].isAdmin);
            getchar(); // Clear newline character from input buffer

            saveStudents();
            printf("Sua thong tin thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien voi username da nhap.\n");
}

void deleteStudent() {
    char username[MAX_USERNAME_LENGTH];
    printf("Nhap username cua sinh vien can xoa: ");
    gets(username);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveStudents();
            printf("Xoa sinh vien thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien voi username da nhap.\n");
}

void listStudents() {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Username: %s, Diem: %.2f, %s\n", students[i].username, students[i].score, students[i].isAdmin ? "Admin" : "Sinh vien");
    }
}
