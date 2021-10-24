#if !defined STUDENT_H
#define STUDENT_H

#include <string>
#include "Array.h"
using namespace std;

struct Student
{
	string name;
	Array* scores;
};

Student* createStudent (string name, int numGrades);
void displayStudent (Student* s);
void destroyStudent (Student* s);
//void addGrade(Student*, float);

#endif