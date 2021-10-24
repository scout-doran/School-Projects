#if !defined FUNCTIONS_H
#define FUNCTIONS_H

#include "Students.h"
#include <iomanip>

using namespace std;

void curvedGrade(Students* ss, int t, int curve, float testAverage);
float* testAverage(Students* ss);
void displayAverage(float*, Students*, float);
void addStudent(Students* ss, Student* student);
Students* readFile(const char* filename);
void addGrade(Student*, float);
#endif