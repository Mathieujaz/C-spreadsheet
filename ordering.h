#ifndef ORDERING_H
#define ORDERING_H
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define sortID 1
#define SortLastName 2
#define SortExam 3
#define SortTotalGrade 4

void sortStudentsByID(struct Student* students, int count);
void setSortColumn();
void sortStudents(struct Student* students, int count);
void updateLastName(struct Student* students, int studentCount); 
void updateExamGrade(struct Student* students, int studentCount);
void removeStudent(struct Student* students, int* count);  

int compareByID(const void* a, const void* b);
int compareByLastName(const void* a, const void* b);
int compareByExam(const void* a, const void* b);
int compareByTotalGrade(const void* a, const void* b);

#endif 