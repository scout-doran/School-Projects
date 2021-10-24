// This program will output perimeter and area
// of the rectangle with a given length and width

//Scout Doran Jackson Fite

#include <iostream>
using namespace std;

const double LENGTH = 8;
const double WIDTH = 3;

int main()
{

	int area; 				// definition of area of a rectangle

	int perimeter;				// definition of perimeter

	perimeter = (LENGTH * 2) + (WIDTH * 2);	// computes perimeter

	area = LENGTH * WIDTH;				// computes area
	
	cout << "The perimeter of the rectangle is: " << perimeter << endl;
	cout << "The area of the rectangle is: " << area << endl;

	// Fill in the code for the cout statement that will output (with description)
	// the perimeter

	// Fill in the code for the cout statement that will output (with description)
	// the area of the rectangle

	return 0;

}