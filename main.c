
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice, roll, found, i, j;
    struct Student temp;

    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Sort Students by Marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX) {
                    printf("Student list is full!\n");
                    break;
                }

                printf("Enter Roll Number: ");
                scanf("%d", &roll);

                found = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].rollNo == roll) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Roll number already exists!\n");
                    break;
                }

                students[count].rollNo = roll;

                printf("Enter Student Name: ");
                scanf(" %49[^\n]", students[count].name);

                printf("Enter Marks: ");
                scanf("%f", &students[count].marks);

                count++;
                printf("Student added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No student records found.\n");
                } else {
                    printf("\nStudent Records:\n");
                    for (i = 0; i < count; i++) {
                        printf("Roll No: %d, Name: %s, Marks: %.2f\n",
                               students[i].rollNo,
                               students[i].name,
                               students[i].marks);
                    }
                }
                break;

            case 3:
                printf("Enter Roll Number to Search: ");
                scanf("%d", &roll);

                found = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].rollNo == roll) {
                        printf("Student Found:\n");
                        printf("Roll No: %d, Name: %s, Marks: %.2f\n",
                               students[i].rollNo,
                               students[i].name,
                               students[i].marks);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found.\n");
                }
                break;

            case 4:
                printf("Enter Roll Number to Delete: ");
                scanf("%d", &roll);

                found = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].rollNo == roll) {
                        for (j = i; j < count - 1; j++) {
                            students[j] = students[j + 1];
                        }
                        count--;
                        found = 1;
                        printf("Student deleted successfully!\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                for (i = 0; i < count - 1; i++) {
                    for (j = 0; j < count - i - 1; j++) {
                        if (students[j].marks > students[j + 1].marks) {
                            temp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = temp;
                        }
                    }
                }

                printf("Students sorted by marks:\n");
                for (i = 0; i < count; i++) {
                    printf("Roll No: %d, Name: %s, Marks: %.2f\n",
                           students[i].rollNo,
                           students[i].name,
                           students[i].marks);
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
