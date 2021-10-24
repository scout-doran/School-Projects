//This program calculates the distance fallen by a watermelon
// Scout Doran and Steven Gibson 

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	float d; //distance in meters
	float t; //time in seconds
	float g = 9.8; //acceleration of gravity in meters/second^2
	float h; //height of the bridge
	float total_distance;
	
	//user inputs time (t) and height (h)
	cout << "Input the number of seconds it took for the watermelon to fall" << endl;
	cin >> t;
	while (t < 0)
	{	cout << "Invalid input" << endl;
		cout << "Input the number of seconds it took for the watermelon to fall" << endl;
		cin >> t;
	}
	
	cout << "Input the height of the bridge" << endl;
	cin >> h;
	while (h < 0)
	{	cout << "Invalid input" << endl;
		cout << "Input the height of the bridge" << endl;
		cin >> h;
	}
	
	//Calcuate the total distance
	total_distance = 0.5 * g * pow (t,2);
	
	//Calculate distance (d) for each second
	for (t; t > 0; t--)
	{	d = 0.5 * g * pow (t,2);
		cout << "The distance is: " << d << " meters at " << t << " seconds" << endl;
	}
	cout << "The total distance fallen is " << total_distance << endl;
	
	if (total_distance > h)
		cout << "The distance fallen is not valid" << endl;
	
	return 0;
}