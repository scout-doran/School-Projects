#include "Extra.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

int main (int argc, char** argv)
{
	cout << fixed << showpoint << setprecision(2);

	int numGrades = 0;
	if (argc != 3)
	{
		cout << "Invalid Command Line" << endl;
		cout << "Format: program.exe <textfile> <curve>" <<endl;
		return 0;
	}
	Students* s = readFile(argv[1]);
	
	float* avg = testAverage(s);

	float curve = atof(argv[2]);

	displayAverage(avg, s, curve);

	displayStudents(s);

	destroyStudents(s);
	
	delete [] avg;
	
	return 0;
}

/*{

	cout << "line 13" << endl;
	Students* s = readFile(argv[1]);
	cout << "line 15" << endl;
	float* average = findAverage(s);
	cout << "line 17" << endl;
	float curve = atof(argv[2]);
	cout << "line 19" << endl;
	displayAverage(average, s, curve);
	cout << "line 21" << endl;
	displayStudents(s);
	cout << "line 23" << endl;
	destroyStudents(s);
	delete [] average;
	return 0;
}*/