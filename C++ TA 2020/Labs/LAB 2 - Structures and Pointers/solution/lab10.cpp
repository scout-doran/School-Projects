/*
	Title:  Lab10.cpp
	Author: April Crockett
	Date:  8/15/2020
	Purpose: practice with structures
*/
#include <iostream>
using namespace std;

struct Friends
{
	string name;
	string birthday;
	int age;
	string description;
};

void enterFriends(Friends*, int);
void printFriends(Friends*, int);
void sortFriends(Friends*, int);

int main()
{
	Friends * myFriends;
	int numFriends, choice; 
	
	cout << "\nHow many friends do you have?\n";
	cin >> numFriends;
	
	myFriends = new Friends[numFriends];
	
	do
	{
		cout << "\n\nChoose from the following options:\n";
		cout << "1. Enter friends\n";
		cout << "2. Print my friends\n";
		cout << "3. End Program\n";
		cout << "CHOOSE 1-3:  ";
		cin >> choice;
		
		//validate user input
		while(choice < 1 || choice > 3)
		{
			cout << "\n\nINVALID CHOICE!!  Enter 1-3:  ";
			cin >> choice;
		}
		//used to ignore or clear one or more characters from the input buffer.
		cin.ignore();
		
		switch(choice)
		{
			case 1: enterFriends(myFriends, numFriends);
					break;
			case 2: sortFriends(myFriends, numFriends);
					printFriends(myFriends, numFriends);
					break;
			case 3: cout << "\n\nThanks for using my friend program!!\n\n";
		}
	}while(choice != 3);
	
	return 0;
}

void enterFriends(Friends* myFriends, int numFriends)
{
	cout << "\n\nEnter your friend's information!";
	
	for(int i=0; i<numFriends; i++)
	{
		cout << "\n\nFRIEND " << i+1 << endl;
		cout << "Name:  ";
		getline(cin, myFriends[i].name);
		cout << "Birthday:  ";
		getline(cin, myFriends[i].birthday);
		cout << "Age:  ";
		cin >> myFriends[i].age;
		cin.ignore(); //called cin.ignore() bc we used cin to get info not getline
		cout << "Description:  ";
		getline(cin, myFriends[i].description);
	}
}

void printFriends(Friends* myFriends, int numFriends)
{
	cout << "\n\nPrinting your friends!\n\n";
	
	for(int i=0; i<numFriends; i++)
	{
		cout << "\n\nFRIEND " << i+1;
		cout << "\nName:  " <<myFriends[i].name;
		cout << "\nBirthday:  "<< myFriends[i].birthday;
		cout << "\nAge:  " << myFriends[i].age;
		cout << "\nDescription:  " << myFriends[i].description;
	}
}

//given 
//uses selection sort algorithm
void sortFriends(Friends* myFriends, int numFriends)
{
	int lowest;
	Friends temp;
	cout << "\n\nSorting your friends!\n\n";
	for(int i=0; i<numFriends; i++)
	{
		//find next lowest name (alphabetically)
		lowest = i;
		for(int x=i; x<numFriends; x++)
			if(myFriends[x].name < myFriends[lowest].name)
				lowest = x;
		//swap
		temp = myFriends[lowest];
		myFriends[lowest] = myFriends[i];
		myFriends[i] = temp;
	}
}