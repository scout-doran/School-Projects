#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString;
	string userStrModified;
	
	
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nThe result is:  " << sumOfNumbers(num) << endl;
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				if(isMember(myArray, num, ARRAY_SIZE))
					cout << "\n\nYes! " << num << " IS in the array!\n";
				else
					cout << "\n\nNo! " << num << " is NOT in the array.\n";
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString, userString.length());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				if(isPalindrome(userStrModified))
					cout << "\n\nYes! "  << userString << " IS a palindrome!\n"; //print out string with the spaces
				else
					cout << "\n\nNo!  " << userString << " is NOT a palindrome.\n";
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				cout << "\n\nThe value of " << num1 << " x " << num2 << " is " << multiply(num1, num2) << endl;
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

int sumOfNumbers(int max)
{
	if (max > 0)
		return max + sumOfNumbers(max - 1);
	else
		return 0;	
}

bool isMember(int *arr, int val, int size)
{
	if (size == 0)
	{
		// Base case: no elements to search.
		return false;
	}
	else if (arr[size - 1] == val)
	{
		// Base case: the value is found
		// in the last element.
		return true;
	}
	else
	{
		// Recursive case: Search all the elements
		// except the last one.
		return isMember(arr, val, size -1);
	}
}

void stringReverser(string str, int length)
{
	if (length < 0)
	{
		return;
	}
	else
	{
		cout << str[length];
		stringReverser(str, length - 1);
	}
}

bool isPalindrome(string str)
{
	bool status = false;

	if (str.length() <= 1)
		status = true;
	else if (str.at(0) == str.at(str.length()-1))
		status = isPalindrome(str.substr(1, str.length()-2));

	return status;
}

int multiply(int x, int y)
{
	if (x == 1)
		return y;
	else
		return y + multiply(x - 1, y);
	
}