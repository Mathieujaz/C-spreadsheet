#ifndef CALC_H
#define CALC_H

#include "data.h"


float calculateFinalGrade(struct Student student);
char calculateLetterGrade(float finalGrade);
void displaySpreadsheet(struct Student* students, int count);
void displayHistogram(struct Student* students, int count); 
void updateGradeMappings();



#endif 
