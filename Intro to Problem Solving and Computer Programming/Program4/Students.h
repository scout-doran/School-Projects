#if !defined STUDENTS_H
#define STUDENTS_H

#include "Student.h"

struct Students
{
	Student** students;
	int maxSize;
	int current;
};

Students* createStudents ();
void displayStudents (Students* ss);
void destroyStudents (Students* ss);
//void addStudent(Students*, Student*);
void resize(Students*);

#endif