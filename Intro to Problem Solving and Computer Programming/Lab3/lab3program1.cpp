// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Scout Doran  Devin Thompson

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int quantity; 									// contains the amount of items purchased 
	float itemPrice; 								// contains the price of each item
	float totalBill; 								// contains the total bill.

	cout << setprecision(2) << fixed << showpoint; 	// formatted output 
	
	cout << "Please input the number of items bought" << endl;
	cin >> quantity ; // Fill in the input statement to bring in the quantity.
	 
	cout << "Please input the price of items bought" << endl; // Fill in the prompt to ask for the price.
	cin >> itemPrice ; // Fill in the input statement to bring in the price of each item.
	
	cout << "This is your total bill:" << endl;// Fill in the assignment statement to determine the total bill.
	totalBill = quantity * itemPrice;
	cout << totalBill << endl; // Fill in the output statement to print total bill,
						 // with a label to the screen.
	
	return 0;
}