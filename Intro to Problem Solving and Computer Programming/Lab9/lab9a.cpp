#include "OtherFunctions.h"
#include <stdlib.h>
using namespace std;
int main(int argc, char** argv)
{
	int numOfTests = 0;
	if (argc != 3)
	{
		cout << "Invalid Command Line Options." << endl;
		cout << "Format: program.exe <textfile> <curve>" <<endl;
		return 0;
	}
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
}