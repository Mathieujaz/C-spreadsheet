
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data.h"


void readStudents(const char* filename, struct Student* students, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    int i = 0;
    while (fscanf(file, "%d|%19[^|]|%19[^|]|%d|%d|%d|%d|%d",
        &students[i].ID, 
       students[i].lastName, 
        students[i].firstName, 
        &students[i].A1, 
        &students[i].A2, 
        &students[i].A3, 
        &students[i].midterm, 
        &students[i].exam) == 8) {
        
       
        students[i].finalGrade = (students[i].A1 + students[i].A2 + students[i].A3 + students[i].midterm + students[i].exam) / 5.0;
        i++;
    }

    *count = i;  
    fclose(file);
}

