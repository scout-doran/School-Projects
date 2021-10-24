#include "statistics.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

//Reads in the data into the program
int* readData (const char* filename , int& size)
{	
	ifstream inFile;
	inFile.open(filename);
	inFile >> size;			//first number in file is the size
	int* numbers = new int[size];
	
	for (int pos = 0; pos < size; pos++)
	{	inFile >> numbers[pos];
	}
	inFile.close();
	return numbers;
}

//Calculates the mean of the data
float findMean (int* numbers, int& size)
{
	int sum = 0;
	float mean;
	for (int pos = 0; pos < size; pos++)
	{
		sum = sum + numbers[pos];
	}
	mean = static_cast<float>(sum) / size;
	return mean;
}

//finds the median of the data
float findMedian (int* numbers, int& size)
{	int middleNum;
    float median;
    middleNum = size / 2.0;
	
	//If size is even take average of the 2 middle numbers
    if ((size % 2) == 0)
    {   
		float sum = numbers[middleNum - 1] + numbers[middleNum];
		median = static_cast<float>(sum) / 2.0;
    }
    else
    {
        median = numbers[middleNum];
    }
	return median;
}

//finds the mode of the data
int findMode (int* numbers, int& size)
{	
	//Keeps track of how many times an integer occurs
	int counter = 1;	
	int counterTwo = 0;	
	int minMode[size];	//seperate array for modes (if tie occurs)
	int mode;
	int i = 0;	//counter

	for (int pos = 0; pos < size - 1; pos++)
	{
		if (numbers[pos] == numbers[pos + 1])
		{
			counter++;
			if (counter > counterTwo)
			{	
				counterTwo = counter;
				minMode[i] = numbers[pos];	//In case of a tie modes go into seperate array
				i++;
			}
			
			else
			{
				counter = 1; // Reset counter
			}
			
		}
		
	}
	mode = minMode[0];	//Takes the first mode in case of a tie
	return mode;
}

//Prints the mean, median, and mode
void displayInformation (float mean, float median, int mode, int& size)
{
	cout << "The statistics for the " << size << " read in values are : " << endl;
	cout << "The mean of the data given is : " << mean << endl;
	cout << "The median of the data given is : " << median << endl;
	cout << "The mode of the data given is : " << mode << endl;
	cout << "Thank you and have a nice day" << endl;
}