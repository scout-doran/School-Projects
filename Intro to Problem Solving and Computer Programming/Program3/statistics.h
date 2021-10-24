#if !defined STATISTICS
#define STATISTICS
#include <iostream>

//This function reads in the users input for a file name
//preconditions : file name must exist if it doesn't then program is terminated
//postcondition : Imports data in file into the program
int* readData (const char* filename, int& size);

//This function finds the mean of the data given 
//precondition : array is an integer array of size
//postcondition : returns the calculated mean 
float findMean (int* numbers, int& size);

//This function finds the median of the data given
//precondition : array is an integer array of size
//postcondition : returns the calculated median
float findMedian (int* numbers, int& size);

//This function finds the mode of the data given
//precondition : array is an integer array of size
//postcondition : returns the calculated mode 
int findMode (int* numbers, int& size);

//This function displays the mean, median and mode 
//precondition : array is an integer array of size
//postcondition : none
void displayInformation (float mean, float median, int mode, int& size);

#endif