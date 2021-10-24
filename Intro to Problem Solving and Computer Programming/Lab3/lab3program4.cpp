// This program will determine the batting average of a player.
// The number of hits and at bats are set internally in the program.

// Scout Doran  Devin Thompson

#include <iostream>
#include <iomanip>
using namespace std;
float AT_BAT = 421;
float HITS = 123;

int main()
{
	cout << setprecision(3) << fixed << showpoint ; 	// formatted output 
	
	float batAvg;
	batAvg = HITS / AT_BAT; // an assignment statement 
	cout << "The batting average is " << batAvg << endl; // output the result
	return 0;
}