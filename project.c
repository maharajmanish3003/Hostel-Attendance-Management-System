//Project :- Programming in C (CUCS1001)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int room;
};

struct Attendance {
    char date[15];
    int id;
    char status; // 'P' or 'A'
};

// Function Prototypes
void addStudent();
void viewStudents();
void markAttendance();
void viewAttendanceByDate();
void searchStudentAttendance();
void generateMonthlyReport();

int main() {
    int choice;

    while(1) {
        printf("\n====== HOSTEL / PG ATTENDANCE SYSTEM ======\n");
        printf("1. Add New Student\n");
        printf("2. View Students\n");
        printf("3. Mark Attendance\n");
        printf("4. View Attendance (By Date)\n");
        printf("5. Search Student Attendance\n");
        printf("6. Generate Monthly Report\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: markAttendance(); break;
            case 4: viewAttendanceByDate(); break;
            case 5: searchStudentAttendance(); break;
            case 6: generateMonthlyReport(); break;
            case 7: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


/******************* ADD STUDENT *******************/
void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    struct Student s;

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Room Number: ");
    scanf("%d", &s.room);

    fprintf(fp, "%d %s %d\n", s.id, s.name, s.room);
    fclose(fp);

    printf("Student added successfully!\n");
}

/******************* VIEW STUDENTS *******************/
void viewStudents() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;

    if(fp == NULL) {
        printf("No students found!\n");
        return;
    }

    printf("\n--- Student List ---\n");
    while(fscanf(fp, "%d %s %d", &s.id, s.name, &s.room) != EOF) {
        printf("ID: %d | Name: %s | Room: %d\n", s.id, s.name, s.room);
    }

    fclose(fp);
}

/******************* MARK ATTENDANCE *******************/
void markAttendance() {
    FILE *fs = fopen("students.txt", "r");
    FILE *fa = fopen("attendance.txt", "a");

    if(fs == NULL) {
        printf("Add students first!\n");
        return;
    }

    struct Student s;
    struct Attendance a;

    printf("\nEnter Date (DD-MM-YYYY): ");
    scanf("%s", a.date);

    printf("\n--- Mark Attendance ---\n");

    while(fscanf(fs, "%d %s %d", &s.id, s.name, &s.room) != EOF) {
        printf("%d - %s (P/A): ", s.id, s.name);
        scanf(" %c", &a.status);
        a.id = s.id;

        fprintf(fa, "%s %d %c\n", a.date, a.id, a.status);
    }

    fclose(fs);
    fclose(fa);

    printf("\nAttendance saved successfully!\n");
}

/******************* VIEW ATTENDANCE BY DATE *******************/
void viewAttendanceByDate() {
    FILE *fa = fopen("attendance.txt", "r");
    FILE *fs = fopen("students.txt", "r");

    if(fa == NULL || fs == NULL) {
        printf("No attendance or student data found!\n");
        return;
    }

    char date[15];
    printf("\nEnter Date (DD-MM-YYYY): ");
    scanf("%s", date);

    struct Student s;
    struct Attendance a;

    printf("\n--- Attendance for %s ---\n", date);

    while(fscanf(fa, "%s %d %c", a.date, &a.id, &a.status) != EOF) {
        if(strcmp(a.date, date) == 0) {
            rewind(fs);

            while(fscanf(fs, "%d %s %d", &s.id, s.name, &s.room) != EOF) {
                if(s.id == a.id) {
                    printf("Name: %-10s | Status: %c\n", s.name, a.status);
                    break;
                }
            }
        }
    }

    fclose(fa);
    fclose(fs);
}

/******************* SEARCH STUDENT MONTHLY ATTENDANCE *******************/
void searchStudentAttendance() {
    FILE *fa = fopen("attendance.txt", "r");
    if(fa == NULL) {
        printf("No attendance found!\n");
        return;
    }

    int id, present = 0, absent = 0;
    struct Attendance a;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    while(fscanf(fa, "%s %d %c", a.date, &a.id, &a.status) != EOF) {
        if(a.id == id) {
            if(a.status == 'P') present++;
            else absent++;
        }
    }

    printf("\n--- Attendance Summary ---\n");
    printf("Student ID: %d\n", id);
    printf("Present: %d days\n", present);
    printf("Absent: %d days\n", absent);

    fclose(fa);
}

/******************* GENERATE MONTHLY REPORT *******************/
void generateMonthlyReport() {
    FILE *fs = fopen("students.txt", "r");
    FILE *fa = fopen("attendance.txt", "r");

    if(fs == NULL || fa == NULL) {
        printf("Data not found!\n");
        return;
    }

    struct Student s;
    struct Attendance a;

    printf("\n--- Monthly Attendance Report ---\n");

    while(fscanf(fs, "%d %s %d", &s.id, s.name, &s.room) != EOF) {
        int present = 0, absent = 0;

        rewind(fa);
        while(fscanf(fa, "%s %d %c", a.date, &a.id, &a.status) != EOF) {
            if(a.id == s.id) {
                if(a.status == 'P') present++;
                else absent++;
            }
        }

        printf("\nName: %s\nID: %d\nPresent: %d | Absent: %d\n", 
               s.name, s.id, present, absent);
    }

    fclose(fs);
    fclose(fa);
}
