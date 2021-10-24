#include "course.h"

Course* createCourse(string n, string l, int numSec, int h)
{
	Course *myCourse = new Course;
	myCourse->name = n;
	myCourse->location = l;
	myCourse->hours = h;
	myCourse->numSections = numSec;
	
	myCourse->sections = new string[numSec];
	
	return myCourse;
}

void destroyCourse(Course* myCourse)
{
	delete [] myCourse->sections;
	delete myCourse;
}

void printCourse(Course* myCourse)
{
	cout << "\n\nCOURSE NAME:\t\t" << myCourse->name;
	cout << "\nCOURSE LOCATION:\t" << myCourse->location;
	cout << "\nCOURSE HOURS:\t\t" << myCourse->hours;
	cout << "\nCOURSE SECTIONS:\n";
	for(int i=0; i< myCourse->numSections; i++)
	{
		cout << "\t\t\t" << myCourse->sections[i] << endl;
	}
}