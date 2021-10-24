// This program will help illustrate the problems with bad data
// It will prompt for an integer then perform mathematical functions.

// Scout Doran and Edward Headon

#include <iostream>

using namespace std;

int main()
{
	int userInput;
	int secondInput;

	cout << "Please enter an integer value : ";
	cin >> userInput;
	while (cin.fail())
	{	cin.clear();
		cin.ignore();
		cout << "That is invalid.  Please enter an INTEGER value : ";
		cin >> userInput;
	}

	cout << "Please enter a second integer value : ";
	cin >> secondInput;
	while (cin.fail())
	{	cin.clear();
		cin.ignore();
		cout << "That is invalid.  Please enter an INTEGER value : ";
		cin >> secondInput;
	}

	cout << "You entered " << userInput << " when prompted for the first value\n";
	cout << "You entered " << secondInput << " when prompted for the second value\n";
	cout << "5 x " << userInput << " = " << 5 * userInput << endl;
	cout << "5 x " << secondInput << " = " << 5 * secondInput << endl;

	if (userInput > 10)
		cout << userInput << " - 10 = " << userInput - 10 << endl;
	else
		cout << "10 - " << userInput << " = " << 10 - userInput << endl;

	return 0;
}