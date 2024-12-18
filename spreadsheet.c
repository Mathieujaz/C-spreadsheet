
//To compile the code, run it,  gcc spreadsheet.c calc.c data.c ordering.c  and ./a.exe


//OR run it,   gcc spreadsheet.c calc.c data.c ordering.c -o spreadsheet          ./spreadsheet

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

#include "data.h"
#include "ordering.h"
#include "calc.h"

#define maxStudents 15

void printSpreadsheetMenu();
void clearScreen();



void printSpreadsheetMenu() {
    printf("Spreadsheet Menu\n");
    printf("____________________\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Set sort column\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Update Grade Mapping\n");
    printf("7. Delete Student\n");
    printf("8. Exit\n");
    printf("\nSelection: ");
}

//This is the method to clear the terminal and only show what the user asked to
void clearScreen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}


int main() {
    int Choice = 0; 
    struct Student students[maxStudents];  
    int studentCount = 0;      
    
    readStudents("students.txt", students, &studentCount);

    //This is the do-while loop that will print 1 time the menu and then enters the switch statements depending on what the user inputs. 
    do {
        clearScreen();  
        printSpreadsheetMenu(); 
        scanf("%d", &Choice); 

        switch (Choice) {
            case 1:
                 sortStudents(students, studentCount);
                 sortStudentsByID(students, studentCount);
                
              
                displaySpreadsheet(students, studentCount);
                printf("\nPress 'c' or 'C' to continue ");
                getchar();
                getchar();  
                break;

            case 2:
                  displayHistogram(students, studentCount);
                break;

            case 3:
                 setSortColumn();
                break;

            case 4:
                updateLastName(students, studentCount); 
                break;

            case 5:
                   updateExamGrade(students, studentCount); 
                break;

            case 6:
                 updateGradeMappings(); 
                break;

            case 7:
                removeStudent(students, &studentCount);
                break;

            case 8:
                printf("Goodbye and thanks for using our spreadsheet app.\n");  
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (Choice != 8);  

    return 0;
}
