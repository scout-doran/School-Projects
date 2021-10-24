//A program that prompts the user to input a string 
//of a size 50 characters or less. Program determines 
//whether or not the entered string is a palindrome. 
//Then displays results.

// Scout Doran and Madison Gibbs

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//function prototypes
bool testPalindrome(char[]);

int main()
{	
	char palindrome[50];
	cout << "Enter a string of 50 characters or less: ";
	cin.getline(palindrome,50);

	if (testPalindrome(palindrome) == true)
		cout << palindrome << " is a palindrome" << endl;
		
	if (testPalindrome(palindrome) == false)		
	{	
		cout << palindrome << " is not a palindrome" << endl;
	}
	return 0;
}

bool testPalindrome(char palindrome[])
{
	int length = strlen(palindrome);
	for (int i = 0; i < length; i++)
		{	
			if (palindrome[i] != palindrome[length - i -1])
				return false;
		}		
	return true;
}