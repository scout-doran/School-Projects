#include "Student.h"
#include "Array.h"
#include <iostream>
//#include <fstream>
#include <iomanip>

using namespace std;

Student* createStudent (string name, int numGrades)
{
	Student* s = new Student;
	s->name = name;
	s->scores = createArray(numGrades);
	
	return s;
}

void displayStudent (Student* s)
{
	cout << "Name : " << s->name << endl;
	displayArray(s->scores);
}

void destroyStudent (Student* s)
{
	destroyArray(s->scores);
	delete s;
}

