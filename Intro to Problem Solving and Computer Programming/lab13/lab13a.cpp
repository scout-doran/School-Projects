// This program uses a structure to hold data about a rectangle

// Scout Doran and Sam O'Heron
#include <iostream>
#include <iomanip>
using namespace std;

// Fill in code to declare a structure named rectangle which has
// members length, width, area, and perimeter all of which are floats
struct Rectangle
{
	float length,
		  width,
		  area,
	      perimeter;
};

int main()
{
	// Fill in code to define a rectangle variable named box
	Rectangle box;
	cout << "Enter the length of a rectangle: ";
	
	// Fill in code to read in the length member of box
	cin >> box.length;
	cout << "Enter the width of a rectangle: ";
	
	// Fill in code to read in the width member of box
	cin >> box.width;
	cout << endl << endl;
	
	// Fill in code to compute the area member of box
	box.area = box.width * box.length;
	// Fill in code to compute the perimeter member of box
	box.perimeter = box.width + box.width + box.length + box.length;

	cout << fixed << showpoint << setprecision(2);
	// Fill in code to output the area with an appropriate message
	cout << "The area of the rectangle is " << box.area << endl;
	// Fill in code to output the perimeter with an appropriate message
	cout << "The perimeter of the rectangle is " << box.perimeter << '\n';

	return 0;
}