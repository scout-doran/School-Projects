// This function takes take in the miles travelled
// and the time in hours travelled and will calculate
// the miles per hour. This value is calculated in a 
// value returning function and printed in main.

// Scout Doran

#include <iostream>
#include <iomanip>
using namespace std;

float milesPerHour (int miles, int hours);


int main()
{
	int miles,
		hours;

	// Fill in code necessary to set output to 2 decimal place notation
	cout << fixed << showpoint << setprecision(2);
	
	// Fill in code necessary to read in the miles travelled and hours travelled
	cout << "How many miles did you travel?" << endl;
	cin >> miles;
	
	cout << "How many hours did you travel?" << endl;
	cin >> hours;
	
	// Fill in code necessary to call milesPerHour
	float mph = milesPerHour (miles, hours);
	
	// Print result
	cout << "You travelled " << mph << " MPH" << endl;
	
	return 0;
}	


//*******************************************************************************
//
// task: This function is given two integer values for miles travelled and
// hours travelled and calculates and returns the miles per hour travelled
//
// Precondition: miles and hours which are both integers
// Postcondition: miles per hour which is a float is returned.
//
//
//*******************************************************************************
float milesPerHour (int miles, int hours)
{
	float mph;
	//Fill in the code to calculate the miles per hour and return to main
	mph = static_cast<float> (miles) / static_cast<float> (hours);

	return mph;
}