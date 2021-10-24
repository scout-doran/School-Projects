#if !defined STUDENTS_H
#define STUDENTS_H
#include "Student.h"
struct Students
{
	Student** studentArray;
	int currElem;
	int maxElem;
};
Students* createStudents();
void displayStudents(Students* s);
void destroyStudents(Students* s);
void addStudent(Students*, Student*);
void resize(Students*);
#endif