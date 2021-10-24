//This program declares a structure called monthData.
//Takes a users input of data per month. Then displays 
//the average monthly number of landing planes, the 
//average monthly number of departing planes, the total 
//number of landing and departing planes for the year, and 
//the greatest and least number of planes that landed on any 
//one day (and which month it occurred in).

// Scout Doran and Sam O'Heron

#include <iostream>
#include <iomanip>  

using namespace std;

struct MonthData 
{
    int landed,
		departed,
		maxLanded,
		leastLanded;
};

const int MONTHS = 12;
MonthData getData(int); //prototype

int main() 
{
	cout << fixed << showpoint << setprecision(2); //set precision
	
    //declare data
    MonthData data[MONTHS];

    //calls function getData to get data for each month
    for (int month = 0; month < MONTHS; month++) 
	{
        data[month] = getData(month + 1);
    }

    //calculate data
    int totalLanded = 0;
    int totalDeparted = 0;
    int maxLandedMonth = 0;
    int leastLandedMonth = 0;
    for (int month = 0; month < MONTHS; month++) 
	{
         totalLanded   += data[month].landed;
         totalDeparted += data[month].departed;
         if (month != 0) 
		 { 
             if (data[month].maxLanded > data[maxLandedMonth].maxLanded) 
			 {
                 maxLandedMonth = month;
             }
             if (data[month].leastLanded < data[leastLandedMonth].leastLanded) 
			 {
                 leastLandedMonth = month;
             }
         }
    }

    //display data
    cout << "Average number of planes landed per month: " << (static_cast<float>(totalLanded) / MONTHS) << endl;
    cout << "Average number of planes departed per month: " << (static_cast<float>(totalDeparted) / MONTHS) << endl;
    cout << "Total number of planes landed: " << totalLanded << endl;
    cout << "Total number of planes departed: " << totalDeparted << endl;
    cout << "Greatest number of planes landed on one day: " << data[maxLandedMonth].maxLanded << " (Month " << maxLandedMonth + 1 << ")" << endl;
    cout << "Least number of planes landed on one day: " << data[leastLandedMonth].leastLanded << " (Month " << leastLandedMonth + 1 << ")" << endl;
 
    return 0;
}

MonthData getData(int month) 
{
	cout << fixed << showpoint << setprecision(2); //set precision
    MonthData data;

    cout << "Enter the total number of planes that landed in month " << month << ": ";
    cin >> data.landed;	
	
    cout << "Enter the total number of planes that departed in month " << month << ": ";
    cin >> data.departed;
	
    cout << "Enter the greatest number of planes to land in a day during month " << month << ": ";
    cin >> data.maxLanded;
	
    cout << "Enter the least number of planes to land in a day during month " << month << ": ";
    cin >> data.leastLanded;
    cout << endl;

    return data;
}
