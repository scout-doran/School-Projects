//This program reads in test scores into a dynamic array,
// takes the lowest number out of the data set then finds the average.
// Scout Doran and James Clark

#include <iostream>
#include <iomanip>
#define nullptr 0
using namespace std;

int findLowest (const int[], int); // finds lowest of all grades

int main()
{
	cout << fixed << showpoint << setprecision(3);
	int *grades = nullptr; // the array holding the grades. 
	int numberOfGrades = 0; // the number of grades read.
	float avgOfGrades; // contains the average of the grades. 
	int lowestGrade; // contains the lowest grade.
	int counter = 0;
	
	cout << "How many grades do you want to enter?" << endl;
	cin >> numberOfGrades;
	
	grades = new int [numberOfGrades];
	for (counter = 0; counter < numberOfGrades; counter++)
	{	cout << "Enter grade " << counter + 1 << " : " << endl;
		cin >> grades[counter];
	}
	
	// Fill in the call to the function that calculates lowest grade
	lowestGrade = findLowest(grades, numberOfGrades);
	// Fill in code to write the lowest to the screen
	cout << endl << "The lowest grade is " << lowestGrade << endl;
	
	float sum = 0; // holds the sum of all the numbers 
	for (int counter = 0; counter < numberOfGrades; counter++)
	{	
		sum = sum + grades[counter];
	}
	
	//subtract the lowest number from the sum and decrement the numberOfGrades by 1
	numberOfGrades = numberOfGrades - 1;
	avgOfGrades = ((sum - lowestGrade) / numberOfGrades); //returns the average
	cout << endl << "The average of all the grades is " << avgOfGrades << endl;
	
	delete[] grades;
	return 0;
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
int findLowest (const int grades[], int numberOfGrades)
{
	// Fill in the code for this function
	int lowest = grades[0];
	for (int counter = 0; counter < numberOfGrades; counter++)
	{	if (grades[counter] < lowest)
			lowest = grades[counter];
	}
	return lowest;
}