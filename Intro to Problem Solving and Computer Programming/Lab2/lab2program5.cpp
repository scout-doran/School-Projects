// This program demonstrates the use of characters and strings

//Scout Doran Jackson Fite

#include <iostream>
#include <string>
using namespace std;

// Definition of Constants
const string FAVORITESODA = "Dr. Dolittle";		// Note the double quotes
const string FAVORITESNACK = "Crackers";
const char BESTRATING = 'A';					// Note the single quotes
const char RATING = 'B';
const int NUMBEROFPEOPLE = 250;
const int TOPCHOICETOTAL = 148;

int main()
{

	char rating;								// 2nd highest product rating
	string favoriteSnack;						// Most preferred snack
	int numberOfPeople;							// The number of people in the survey
	int topChoiceTotal;							// The number of people who prefer the top choice

	// Fill in the code to do the following:
	// Assign the value of "crackers" to favoriteSnack
	// Assign the grade of 'B' to rating
	// Assign the number 250 to the numberOfPeople
	// Assign the number 148 to the topChoiceTotal

	// Fill in the blanks of the following:
	cout << "The preferred soda is " << FAVORITESODA << endl;
	cout << "The preferred snack is " << FAVORITESNACK << endl;
	cout << "Out of " << NUMBEROFPEOPLE << " people surveyed " << TOPCHOICETOTAL 
		 << " chose those items!" << endl;
	cout << "Each of these products were given a rating of " << BESTRATING;
	cout << " from our expert tasters" << endl;
	cout << "The other products were rated no higher than a " << RATING<< endl;

	return 0;

}