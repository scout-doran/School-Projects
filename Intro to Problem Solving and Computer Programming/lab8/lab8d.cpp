// This program will read in prices and store them into a two-dimensional array.
// It will print those prices in a table form.

// Scout Doran and Michael Stoner

#include <iostream>
#include <iomanip>

using namespace std;
const int MAXROWS = 10;
const int MAXCOLS = 10;

typedef float PriceType[MAXROWS][MAXCOLS]; 

void getPrices(float [][MAXCOLS], int&, int&); // gets the prices into the array 
void printPrices(const float [][MAXCOLS], int, int); // prints data as a table
float findHighest(const float table[] [MAXCOLS], int numOfRows, int numOfCols);  // finds the highest number in the array
float findLowest(const float table[] [MAXCOLS], int numOfRows, int numOfCols);   // finds the lowest number in the array

int main()
{
	int rowsUsed; // holds the number of rows used
	int colsUsed; // holds the number of columns used
	
	PriceType priceTable; // a 2D array holding the prices
	getPrices(priceTable, rowsUsed, colsUsed);    // calls getPrices to fill the array 
	printPrices(priceTable, rowsUsed, colsUsed);  // calls printPrices to display array
	findHighest(priceTable, rowsUsed, colsUsed);  // calls findHighest to find the highest number in the array
	findLowest(priceTable, rowsUsed, colsUsed);   // calls findLowest to find the lowest number in the array
	
	float highest = findHighest(priceTable, rowsUsed, colsUsed);
	cout << "" << endl;
	cout << "Your highest price is $ " << highest << endl;
	float lowest = findLowest(priceTable, rowsUsed, colsUsed); 
	cout << "Your lowest price is $ " << lowest << endl;
	return 0;
}

//*******************************************************************************
// getPrices
//
// task: This procedure asks the user to input the number of rows and
// columns. It then asks the user to input (rows * columns) number of
// prices. The data is placed in the array.
// Precondition : none
// Postcondition : an array filled with numbers and the number of rows
// and columns used.
//
//*******************************************************************************
void getPrices(float table[] [MAXCOLS], int& numOfRows, int& numOfCols)
{
	do
	{	cout << "Please input the number of rows from 1 to "<< MAXROWS << endl;
		cin >> numOfRows;
	} while (numOfRows < 1 || numOfRows > 10);
	do 
	{	cout << "Please input the number of columns from 1 to "<< MAXCOLS << endl;
		cin >> numOfCols;
	} while (numOfCols < 1 || numOfCols > 10);	
	
	for (int row = 0; row < numOfRows; row++)
	{
		for (int col = 0; col < numOfCols; col++)
		// Fill in the code to read and store the next value in the array
		{
			do
			{	cout << "Please enter in the price for row " << row + 1 << " and column " << col + 1 << endl;	
				cin >> table[row][col];
			} while (table[row][col] < 0);
		}
	}
}
//***************************************************************************
// printPrices
//
// task: This procedure prints the table of prices
// Precondition : an array of floating point numbers and the number of rows
// and columns used.
// Postcondition : none
//
//****************************************************************************
void printPrices(const float table[] [MAXCOLS], int numOfRows, int numOfCols)
{
	cout << fixed << showpoint << setprecision(2);
	for (int row = 0; row < numOfRows; row++)
	{
		for (int col = 0; col < numOfCols; col++)
		// Fill in the code to print the table
		{
			cout << "Your price for row "<< row + 1 << " and column " << col + 1 << " is $ " << table[row][col] << endl;
		}
	}
}

//This function finds the highest number in the array
float findHighest(const float table[] [MAXCOLS], int numOfRows, int numOfCols)
{
	
	int highest = -999999;// Fill in the code for this function
	for (int row = 0; row < numOfRows; row++)
	{	
		for (int col = 0; col < numOfCols; col++)
		{
			if (table[row][col] > highest)
			highest = table[row][col];
		}
	}	
	return highest;
}

//This function finds the lowest number in the array
float findLowest(const float table[] [MAXCOLS], int numOfRows, int numOfCols)
{
	int lowest = 999999;// Fill in the code for this function
	for (int row = 0; row < numOfRows; row++)
	{	
		for (int col = 0; col < numOfCols; col++)
		{
			if (table[row][col] < lowest)
			lowest = table[row][col];
		}
	}	
		
	return lowest;
}