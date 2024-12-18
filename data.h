#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

struct Student {
    int ID;
    char lastName[20];
    char firstName[20];
    int A1, A2, A3; 
    int midterm;
    int exam;
    float finalGrade;
};


void readStudents(const char* filename, struct Student* students, int* count);

#endif 