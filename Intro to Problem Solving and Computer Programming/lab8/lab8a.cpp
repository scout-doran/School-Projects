// This program will read in a group of test scores (positive integers from 1 to 100)
// from the keyboard and then calculate and output the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

// Scout Doran and Michael Stoner

#include <iostream>
using namespace std;

float findAverage (const int[], int); // finds average of all grades 
int findHighest (const int[], int); // finds highest of all grades 
int findLowest (const int[], int); // finds lowest of all grades

int main()
{
	int grades[100]; // the array holding the grades. 
	int numberOfGrades = 0; // the number of grades read.
	int pos = 0; // index to the array.
	float avgOfGrades; // contains the average of the grades. 
	int highestGrade; // contains the highest grade.
	int lowestGrade; // contains the lowest grade.
	
	// Read in the values into the array pos = 0;
	cout << "Please input a grade from 1 to 100, (or -99 to stop)" << endl;
	cin >> grades[pos];
	while (grades[pos] != -99)
	{	// Fill in the code to read the grades
		pos++;
		cin >> grades[pos];
		{	while (cin.fail() || grades[pos] < 1 || grades[pos] > 100)
			{	if (grades[pos] == -99)
					break;
				cin.clear();
				cin.ignore();	
				cout << "Invalid Input. Try again." <<endl;
				cin >> grades[pos];
			}
		}
	}

	numberOfGrades = pos; // Fill blank with appropriate identifier
	// call to the function to find average
	avgOfGrades = findAverage(grades, numberOfGrades);
	cout << endl << "The average of all the grades is " << avgOfGrades << endl;

	// Fill in the call to the function that calculates highest grade
	highestGrade = findHighest(grades, numberOfGrades);
	cout << endl << "The highest grade is " << highestGrade << endl;
	
	// Fill in the call to the function that calculates lowest grade
	lowestGrade = findLowest(grades, numberOfGrades);
	// Fill in code to write the lowest to the screen
	cout << endl << "The lowest grade is " << lowestGrade << endl;
	

	return 0;
}

//********************************************************************************
// findAverage
//
// task: This function receives an array of integers and its size.
// It finds and returns the average of the numbers in the array
// precondition : array of floating point numbers
// postcondition : average of the numbers in the array
//
//********************************************************************************
float findAverage (const int array[], int size)
{
	float sum = 0; // holds the sum of all the numbers 
	for (int pos = 0; pos < size; pos++)
		sum = sum + array[pos];
	return (sum / size); //returns the average
}

//****************************************************************************
// findHighest
//
// task: This function receives an array of integers and its size.
// It finds and returns the highest value of the numbers in the array
// precondition : array of floating point numbers
// postcondition : highest value of the numbers in the array
//
//****************************************************************************
int findHighest (const int array[], int size)
{
	// Fill in the code for this function
	int highest = array[0];
	for (int pos = 0; pos < size; pos++)
	{	if (array[pos] > highest)
			highest = array[pos];
	}
	return highest;
}

//****************************************************************************
// findLowest
//
// task: This function receives an array of integers and its size.
// It finds and returns the lowest value of the numbers in the array
// precondition : array of floating point numbers
// postcondition : lowest value of the numbers in the array
//
//****************************************************************************
int findLowest (const int array[], int size)
{
	// Fill in the code for this function
	int lowest = array[0];
	for (int pos = 0; pos < size; pos++)
	{	if (array[pos] < lowest)
			lowest = array[pos];
	}
	return lowest;
}