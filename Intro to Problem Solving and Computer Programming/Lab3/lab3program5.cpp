//This program will take the input 
//of the amount of chairs sold in each style,
//then display the total sales of each style 
//as well as the overall total amount.

// Scout Doran  Devin Thompson

#include <iostream>
#include <iomanip>
using namespace std;

int quantityAC;		//contains the amount of American Colonial chairs sold
int quantityM;		//contains the amount of Modern chairs sold
int quantityFC;		//contains the amount of French Classical chairs sold

float totalPriceAC;		//contains the total price of American Colonial chairs
float totalPriceM;		//contains the total price of Modern chairs
float totalPriceFC;		//contains the total price of French Colonial chairs
float overall_price;	//contains the overall price of all chairs

float AC = 85.00;		//set price for American Colonial
float M = 57.50;		//set price for Modern
float FC = 127.75;		//set price for French Classical

int main()
{
	cout << setprecision(2) << fixed << showpoint ; 	// formatted output 
	
	//prompt the user to enter the amount of chairs for each type 
	cout << "Please input the number of American Colonial chairs sold:" << endl;	
	cin >> quantityAC ;

	cout << "Please input the number of Modern chairs sold:" << endl;	
	cin >> quantityM ;

	cout << "Please input the number of French Classical chairs sold:" << endl;	
	cin >> quantityFC ;

	
	//calculate the total sales for each chair type
	totalPriceAC = quantityAC * AC;
	totalPriceM = quantityM * M;
	totalPriceFC = quantityFC * FC;
	
	
	//display the total sales for each chair type
	cout << "The total sales of American Colinial chairs : $" << totalPriceAC << endl;

	cout << "The total sales of Modern chairs : $" << totalPriceM << endl;

	cout << "The total sales of French Classical chairs : $" << totalPriceFC << endl;
	
	
	overall_price = totalPriceAC + totalPriceM + totalPriceFC;	//calculate the overall price of all chair types
	cout << "The total sales of all chairs : $" << overall_price << endl;	//display the overall price of all chair types
	return 0;
}
