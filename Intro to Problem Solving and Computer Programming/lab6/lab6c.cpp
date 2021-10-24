//This program takes a distance and if the user enters it 
//as miles the program will convert it to kilometers and 
//viceversa.
// Scout Doran

#include <iostream>
#include <iomanip>
using namespace std;

float kiloToMile (int distance, float mile);
float mileToKilo (int distance, float kilometer);

int main()
{	
	//output format
	cout << fixed << showpoint << setprecision(3);
	float kilometer,
		  mile;
	int	distance;
	char unit;	//miles or kilometers
	
	cout << "How far did you travel?" << endl;
	cin >> distance;
	cout << "Was the distance you entered in Miles or Kilometers? (m or k)" << endl;
	cin >> unit;
	
	//ask user whether the distancce entered is in miles or kilometers
	if (unit == 'k')
	{	mile = kiloToMile (distance, mile);
		cout << "You traveled " << mile << " miles" << endl;
	}
	else if (unit == 'm')
	{	kilometer = mileToKilo (distance, kilometer);
		cout << "You traveled " << kilometer << " kilometers" << endl;
	}
	else
	{	cout << "Invalid Input" << endl;
	}
	
	return 0;
}

//calculates kilometers to miles
float kiloToMile (int distance, float mile)
{	mile = static_cast<float> (distance) / .621;
	return mile;
}

//calculates miles to kilometers
float mileToKilo (int distance, float kilometer)
{	kilometer = static_cast<float> (distance) * 1.61;
	return kilometer;
}