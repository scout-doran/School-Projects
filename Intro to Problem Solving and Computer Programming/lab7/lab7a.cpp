//This program calculates a persons 
//BMI based on inputs for height and weight

//Scout Doran and Edward Headon

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{	static float weight,
				 BMI;
	int height,
		feet,
		inches;
	cout << fixed << showpoint << setprecision(2);
	
	//Ask for weight
	cout << "Please enter your weight (in lbs)" << endl;
	cin >> weight;
	while (cin.fail() || weight <= 0)
	{	cin.clear();
		cin.ignore();
		cout << "Invalid Input" << endl;
		cout << "Please enter your weight (in lbs)" << endl;
		cin >> weight;
	}
	//Ask for height	
	cout << "Please enter in your height" << endl;
	cout << "Feet: ";
	cin >> feet;
	while (cin.fail() || feet <= 0)
	{	cin.clear();
		cin.ignore();
		cout << "Invalid input" << endl;
		cout << "Feet: ";
		cin >> feet;
	}
	cout << "Inches: ";
	cin >> inches;
	while (cin.fail() || inches <= 0)
	{	cin.clear();
		cin.ignore();
		cout << "Invalid input" << endl;
		cout << "Inches: ";
		cin >> inches;
	}
	
	//convert feet to inches
	height = ((feet * 12) + inches);
	//Calculate BMI 
	BMI = (weight * 703) / pow(height,2);
	cout << "Your BMI is " << BMI << " kg/m^2" <<endl;

	return 0;
}