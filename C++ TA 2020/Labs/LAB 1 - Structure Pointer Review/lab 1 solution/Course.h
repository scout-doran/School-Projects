/*
*/
#ifndef COURSE_H
#define COURSE_H


#include <iostream>
using namespace std;

struct Course
{
	string name;
	string location;
	string* sections;
	int numSections;
	int hours;
};
/*
	Function: createCourse
	
	Parameters: a string containing the name of the course
				a string containing the location of the course
				an integer containing how many sections the course has
				an integer containing how many credit hours the course has
				
	Purpose:	to create a new course
	
	Returns:	a pointer to the Course variable just created with all the given data
*/
Course* createCourse(string, string, int, int);
void destroyCourse(Course*);
void printCourse(Course*);


#endif

