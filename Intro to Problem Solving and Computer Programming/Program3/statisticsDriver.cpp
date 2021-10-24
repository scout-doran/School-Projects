// Scout Doran

#include <iomanip>
#include <iostream>
#include <fstream>
#include "BasicSort.h"
#include "statistics.h"


using namespace std;

int main( int argc, char** argv)
{
	//Takes filename from command line argument
	// and imports data into the program
	int size, mode, *data;
	float mean, median;
	if (argc != 2)
	{
		cout << "invalid command line options" << endl;
		cout << "Format: program.exe textfile" << endl;
		return 0;
	}
	data = readData (argv[1], size);
	selectionSort (data, size);
	mean = findMean (data, size);
	median = findMedian (data, size);
	mode = findMode (data, size);
	displayInformation (mean, median, mode, size);
	delete [] data;
}