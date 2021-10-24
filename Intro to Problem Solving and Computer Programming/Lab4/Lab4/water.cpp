
//Devin Thompson & Scout Doran

#include <iostream>
#include<iomanip>
using namespace std;

float firstQuarter;				// the different quarter amounts
float secondQuarter;
float thirdQuarter;
float fourthQuarter;
float average; 				// the average


int main()
{
	cout << setprecision(2) << fixed << showpoint;
	cout << " What is your first quarter water bill? " << endl;
	cin >> firstQuarter; 											
	cout << " What is your second quarter water bill? " << endl;
	cin >> secondQuarter; 
	cout << " What is your third quarter water bill? " << endl;
	cin >> thirdQuarter;
	cout << " What is your fourth quarter water bill? " << endl;
	cin >> fourthQuarter;
	average = ( firstQuarter + secondQuarter + thirdQuarter + fourthQuarter) / 4;
	
	if ( average > 75)
	cout << "Wow a "<< average <<" you are using to much water " << endl;
	else if ( average >= 25 && average <= 75)
	cout << "Nice a " << average <<" you are using the average amount of water " << endl;
	else if ( average >= 0 && average < 25)
	cout << "Wow a "<< average <<" how did you conserve so much water " << endl;
	else
	cout << "A " << average <<" its not possible to use negative water :< Try a valid amount." << endl; 
	return 0;
}
