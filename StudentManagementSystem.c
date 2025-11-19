#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll, marks;
    char mobile[15], name[20];
};

FILE *f, *tmp;
struct Student s, t;

// check if roll exists
int ifexists(int r) {
    int flag = 0;
    f = fopen("studata.dat", "rb");
    if (!f) return 0;

    while (fread(&t, sizeof(t), 1, f)) {
        if (r == t.roll) {
            flag = 1;
            break;
        }
    }
    fclose(f);
    return flag;
}

// Add new student
void addStu() {
    printf("\n\n--- ADD NEW STUDENT ---\n");

again:
    printf("Enter Roll: ");
    scanf("%d", &s.roll);

    if (ifexists(s.roll)) {
        printf("❌ Roll number already exists! Try again.\n\n");
        goto again;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%d", &s.marks);

    printf("Enter Mobile: ");
    scanf(" %[^\n]", s.mobile);

    f = fopen("studata.dat", "ab");
    fwrite(&s, sizeof(s), 1, f);
    fclose(f);

    printf("\n✔ Student record inserted successfully!\n");
}

// Delete student
void delStu() {
    int r, flag = 0;

    printf("\n\n--- DELETE STUDENT ---\n");
    printf("Enter Roll to Delete: ");
    scanf("%d", &r);

    f = fopen("studata.dat", "rb");
    tmp = fopen("tmpdata.dat", "wb");

    while (fread(&t, sizeof(t), 1, f)) {
        if (t.roll == r)
            flag = 1;
        else
            fwrite(&t, sizeof(t), 1, tmp);
    }

    fclose(f);
    fclose(tmp);

    if (flag) {
        remove("studata.dat");
        rename("tmpdata.dat", "studata.dat");
        printf("\n✔ Record Deleted Successfully!\n");
    } else {
        printf("\n❌ Record Not Found!\n");
    }
}

// Display all students
void report() {
    int ctr = 0;
    printf("\n\n--- STUDENT REPORT ---\n");

    f = fopen("studata.dat", "rb");
    if (!f) {
        printf("No records found!\n");
        return;
    }

    printf("\nROLL   NAME                 MARKS   MOBILE\n");
    printf("-----------------------------------------------\n");

    while (fread(&s, sizeof(s), 1, f)) {
        printf("%05d  %-20s  %04d   %s\n", s.roll, s.name, s.marks, s.mobile);
        ctr++;
    }

    printf("\nTotal %d Records Found.\n", ctr);
    fclose(f);
}

// Sort by roll
void sortr() {
    struct Student arr[100];
    int i, j, ctr = 0;

    f = fopen("studata.dat", "rb");
    while (fread(&arr[ctr], sizeof(s), 1, f))
        ctr++;
    fclose(f);

    for (i = 0; i < ctr - 1; i++) {
        for (j = 0; j < ctr - 1 - i; j++) {
            if (arr[j].roll > arr[j + 1].roll) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    f = fopen("studata.dat", "wb");
    for (i = 0; i < ctr; i++)
        fwrite(&arr[i], sizeof(arr[i]), 1, f);
    fclose(f);

    printf("\n✔ Records Sorted Successfully by Roll Number.\n");
}

int main() {
    char choice;

    while (1) {
        printf("\n\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Student\n");
        printf("2. List All Students\n");
        printf("3. Delete Student\n");
        printf("4. Sort Record by Roll\n");
        printf("0. Exit\n");
        printf("Enter Your Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            addStu();
            break;
        case '2':
            report();
            break;
        case '3':
            delStu();
            break;
        case '4':
            sortr();
            break;
        case '0':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("❌ Invalid Choice!\n");
        }
    }

    return 0;
}
