#include "Array.h"
#include <iostream>
#include <iomanip>
using namespace std;

Array* createArray (int numGrades)
{
	//ifstream inFile;
	Array* a = new Array;
	a->currentValue = 0;
	a->max = numGrades;
	a->array = new float [a->max];

	return a;
}

void displayArray (Array* a)
{
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < a->max; i++)
	{
		cout << a->array[i] << "   " << endl;
	}
}

void destroyArray (Array* a)
{
	delete[] a->array;						//Destroy array
	delete a;								//Destroy array struct
}


