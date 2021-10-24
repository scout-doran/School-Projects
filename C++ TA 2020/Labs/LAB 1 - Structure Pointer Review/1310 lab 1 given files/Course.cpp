#include "Course.h"

#include <iostream>

using namespace std;

Course* createCourse(string n, string l, int num_sec, int h){
    Course *myCourse = new Course;
    myCourse -> name = n;
    myCourse -> location = l;
    myCourse -> hours = h;
    myCourse -> numSections = num_sec;

    myCourse -> sections = new string[num_sec];
    
    return myCourse;
}

void destroyCourse(Course* myCourse){
    delete [] myCourse->sections;
    delete myCourse;
}

void printCourse(Course* myCourse){
    cout << "\nCOURSE NAME:\t\t";
	cout << "\nCOURSE LOCATION:\t";
	cout << "\nCOURSE HOURS:\t\t";
	cout << "\nNUMBER OF SECTIONS?\t";
    for(int x=0; x<myCourse->numSections; x++)
	{
		cout << "\t\t\t" << myCourse->sections[x] << endl;
	}
}