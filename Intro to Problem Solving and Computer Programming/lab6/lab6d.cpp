//This program takes a range of numbers from a text file,
//"range.txt", and checks to see which numbers are prime.
//If it is prime the number is displayed in another text 
//file called "primes.txt"
// Scout Doran and Madison Gibbs

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{	int upper_bound,	//variable for the greatest number in the range
		lower_bound,	//variable for the lowest number in the range
		i,	//counter
		j;	//counter
	bool isPrime = true;	//tests a number to check if its prime
	
	//inputs the text into the program from the file "range.txt"
	ifstream inFile;
	inFile.open("range.txt");
	inFile >> lower_bound;
	inFile >> upper_bound;
	
	//Takes the results and displays it in a file called "primes.txt"
	ofstream outFile;
	outFile.open("primes.txt");
	
	//input validation
	if (lower_bound < 2)
		lower_bound = 2;
	
	//test numbers in a range to see if its prime 
	outFile << "Below are the primes from 1 to 20:" << endl;
	for(i = lower_bound; i <= upper_bound; ++i)
	{	
		for(j = 2; j <= upper_bound / 2; ++j)
		{	if(i % j == 0 && j < i)
			{	isPrime = false;
			}
		}
		if (isPrime )
		{	
			outFile << i << endl;
		}
		isPrime = true;
	}
	
  return 0;
}