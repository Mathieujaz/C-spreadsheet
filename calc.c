#include <stdio.h>
#include "data.h"
#include "ordering.h"

int A_baseline = 80;
int B_baseline = 70;
int C_baseline = 60;
int D_baseline = 50;

float calculateFinalGrade(struct Student student) {
  
    float finalGrade = (((((student.A1)*100)/40) * 25/3)/100) + 
                       (((((student.A2)*100)/40) * 25/3)/100) + 
                       (((((student.A3)*100)/40) * 25/3)/100) + 
                       (((((student.midterm)*100)/25) * 0.25)) + 
                       (((((student.exam)*100)/40) * 0.50));

    return (finalGrade);
}

char calculateLetterGrade(float finalGrade) {
    if (finalGrade >= A_baseline) {
        return 'A';
    } else if (finalGrade >= B_baseline) {
        return 'B';
    } else if (finalGrade >= C_baseline) {
        return 'C';
    } else if (finalGrade >= D_baseline) {
        return 'D';
    } else {
        return 'F'; 
    }
}

void displaySpreadsheet(struct Student* students, int count) {
    
    for (int i = 0; i < count; i++) {
        students[i].finalGrade = calculateFinalGrade(students[i]);
    }

   
    sortStudents(students, count);
    
    printf("\nCOMP 348 GRADE SHEET\n");
    printf("%-6s %-10s %-10s %-5s %-5s %-5s %-8s %-5s %-6s %-6s\n", 
        "ID", "Last", "First", "A1", "A2", "A3", "Midterm", "Exam", "Total", "Grade");
    printf("--     ----       -----      --    --    --    -------  ----  -----  ----- \n");

    for (int i = 0; i < count; i++) {
        struct Student s = students[i];
        char letterGrade = calculateLetterGrade(s.finalGrade); 
        
        printf("%-6d %-10s %-10s %-5d %-5d %-5d %-8d %-5d %-6.2f %-6c\n", 
            s.ID, s.lastName, s.firstName, s.A1, s.A2, s.A3, s.midterm, s.exam, s.finalGrade, letterGrade);
    }

    
}

void displayHistogram(struct Student* students, int count) {
    int gradeCount[5] = {0};  

  
    for (int i = 0; i < count; i++) {
        float finalGrade = calculateFinalGrade(students[i]);
        char letterGrade = calculateLetterGrade(finalGrade);

        switch (letterGrade) {
            case 'A': gradeCount[0]++; break;
            case 'B': gradeCount[1]++; break;
            case 'C': gradeCount[2]++; break;
            case 'D': gradeCount[3]++; break;
            case 'F': gradeCount[4]++; break;
        }
    }

    printf("\nCOMP 348 Grade Distrubition:\n");
    printf("A: ");
    for (int i = 0; i < gradeCount[0]; i++) printf("*");
    printf("\n");

    printf("B: ");
    for (int i = 0; i < gradeCount[1]; i++) printf("*");
    printf("\n");

    printf("C: ");
    for (int i = 0; i < gradeCount[2]; i++) printf("*");
    printf("\n");

    printf("D: ");
    for (int i = 0; i < gradeCount[3]; i++) printf("*");
    printf("\n");

    printf("F: ");
    for (int i = 0; i < gradeCount[4]; i++) printf("*");
    printf("\n");

     printf("\nPress 'c' or 'C' to continue ");
    getchar(); 
    getchar();
    
}



void updateGradeMappings() {
    printf("Current Mapping:\n");
    printf("A: >= %d\n", A_baseline);
    printf("B: >= %d\n", B_baseline);
    printf("C: >= %d\n", C_baseline);
    printf("D: >= %d\n", D_baseline);
    printf("F: <  %d\n", D_baseline); 

    printf("\nEnter a new A baseline: ");
    scanf("%d", &A_baseline);
    printf("Enter a new B baseline: ");
    scanf("%d", &B_baseline);
    printf("Enter new C baseline: ");
    scanf("%d", &C_baseline);
    printf("Enter new D baseline: ");
    scanf("%d", &D_baseline);

    printf("\nNew Mapping:\n");
    printf("A: >= %d\n", A_baseline);
    printf("B: >= %d\n", B_baseline);
    printf("C: >= %d\n", C_baseline);
    printf("D: >= %d\n", D_baseline);
    printf("F: <  %d\n", D_baseline); 

    printf("\nPress 'c' or 'C' to continue ");
    getchar(); 
    getchar(); 
}

void removeStudent(struct Student* students, int* studentCount) {
    displaySpreadsheet(students, *studentCount); 
    printf("\nEnter the student ID to remove: ");
    int idToRemove;
    scanf("%d", &idToRemove);

    bool found = false;
    for (int i = 0; i < *studentCount; i++) {
        if (students[i].ID == idToRemove) {
           
            for (int j = i; j < *studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            (*studentCount)--; 
            printf("Student successfully deleted.\n");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", idToRemove);
    }

    printf("\nPress 'c' or 'C' to continue ");
    getchar(); 
    getchar();
}