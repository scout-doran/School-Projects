#if !defined ARRAY_H
#define ARRAY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Array
{
	float* array;
	int currentValue;
	int max;
};

Array* createArray (int numGrades);
void displayArray (Array* a);
//void displayFinal(Array*);
void destroyArray (Array* a);


#endif