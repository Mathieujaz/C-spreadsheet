#include "ordering.h"
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <string.h>

int currentSortColumn = sortID;

void sortStudentsByID(struct Student* students, int count) {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (students[j].ID > students[j + 1].ID) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void setSortColumn() {
    int columnChoice;

    printf("Column Options\n");
    printf("------------------\n");
    printf("1. Student ID\n");
    printf("2. Last name\n");
    printf("3. Exam\n");
    printf("4. Total\n");
    printf("\nSort Column: ");
    scanf("%d", &columnChoice);

  
    switch (columnChoice) {
        case sortID:
            currentSortColumn = sortID;
            break;
        case SortLastName:
            currentSortColumn = SortLastName;
            break;
        case SortExam:
            currentSortColumn = SortExam;
            break;
        case SortTotalGrade:
            currentSortColumn = SortTotalGrade;
            break;
        default:
            printf("Invalid choice. Keeping current sort column.\n");
            return;
    }

    printf("\nSort column updated.\n");

    
    printf("\nPress 'c' or 'C' to continue ");
    getchar();  
    getchar();  
}



void sortStudents(struct Student* students, int count) {
    switch (currentSortColumn) {
        case sortID:
            qsort(students, count, sizeof(struct Student), compareByID);
            break;
        case SortLastName:
            qsort(students, count, sizeof(struct Student), compareByLastName);
            break;
        case SortExam:
            qsort(students, count, sizeof(struct Student), compareByExam);
            break;
        case SortTotalGrade:
            qsort(students, count, sizeof(struct Student), compareByTotalGrade);
            break;
        default:
            printf("Invalid sort column.\n");
            break;
    }
}

void updateLastName(struct Student* students, int studentCount) {
    displaySpreadsheet(students, studentCount); 
    printf("\nEnter the student ID: ");
    int idToUpdate;
    scanf("%d", &idToUpdate);

   
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].ID == idToUpdate) {
            
            printf("Enter updated last name: ");
            scanf("%s", students[i].lastName); 
            printf("Last name updated.\n");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", idToUpdate);
    }

   
    printf("\nPress 'c' or 'C' to continue ");
    getchar(); 
    getchar(); 
}

void updateExamGrade(struct Student* students, int studentCount) {
    displaySpreadsheet(students, studentCount); 
    printf("\nEnter the student ID: ");
    int idToUpdate;
    scanf("%d", &idToUpdate);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].ID == idToUpdate) {
            printf("Enter updated exam grade: ");
            scanf("%d", &students[i].exam);
            
            // Recalculate the final grade after updating the exam grade
            students[i].finalGrade = calculateFinalGrade(students[i]);
            
            printf("Exam grade updated.\n");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", idToUpdate);
    }

    printf("\nPress 'c' or 'C' to continue ");
    getchar(); 
    getchar(); 
}



// Comparison function to sort by Student ID
int compareByID(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;
    return (studentA->ID - studentB->ID);
}

// Comparison function to sort by last name
int compareByLastName(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;
    return strcmp(studentA->lastName, studentB->lastName);
}

// Comparison function to sort by exam grade
int compareByExam(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;
    return (studentB->exam - studentA->exam);  // Sorting in descending order
}

// Comparison function to sort by final grade
int compareByTotalGrade(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;
    if (studentB->finalGrade > studentA->finalGrade) return 1;
    else if (studentB->finalGrade < studentA->finalGrade) return -1;
    else return 0;  // Sorting in descending order
}