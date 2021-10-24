// This program prints "You Pass" if a student's average is
// 60 or higher and prints "You Fail" otherwise

//Scout Doran & Devin Thompson  

#include <iostream>
using namespace std;

int main()
{
	float average; // holds the grade average 
	cout << "Input your average:" << endl;
	cin >> average;
	if (average > 100 )
	cout << " invalid score " << endl;
	else if (average >= 90 && average < 100  )
	cout << "you have an A " << endl;
	else if ( average >= 80 && average < 90)
	cout << " you have a B " << endl; 
	else if ( average >= 60 && average < 80)
	cout << " you pass " << endl;
	else if ( average >= 0 && average < 60)
	cout << " you fail " << endl;
	else
	cout << " invalid score" << endl;
	

	//if (average > 60)
	//cout << "You Pass" << endl;
	//if (average < 60)
	//cout << "You Fail" << endl;
	return 0;
}

