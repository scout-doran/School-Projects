#include "Students.h"
//#include <iostream>
//#include <iomanip>

using namespace std;

Students* createStudents ()
{

	Students* ss = new Students;
	ss->maxSize = 2;
	ss->current = 0;					//Set initial values
	Student** students = new Student*[2];
	ss->students = students;
	return ss;

}

void displayStudents (Students* ss)
{

	int current = ss->current;
	for (int i = 0; i < current; i++)
	{
		//Print array as we go
		displayStudent (ss->students[i]);
		cout << endl;
	}
}

void destroyStudents (Students* ss)
{
	int current = ss->current;
	for (int i = 0; i < current; i++)		//Destroy the VALUES in the array
	{
		//delete array as we go
		destroyStudent (ss->students[i]);
	}
	delete[] ss->students;						//Destroy the ARRAY
	delete ss;								//Destroy the STRUCT	
}

void resize (Students* ss)
{
	int newMax = ss->current * 2;

	Student** newArray = new Student*[newMax];			//Make new array
	for (int i = 0; i < ss->maxSize; i++)			//Copy old array to the new
	{	
		newArray[i] = ss->students[i];
	}
	
	for (int i = 0; i< ss->maxSize; i++)
	{
		destroyStudent(ss->students[i]);
	}
	
	delete [] ss->students;					//Delete old array
	ss->students = newArray;							//Assign new array
	ss->maxSize = newMax;						//double max
}

