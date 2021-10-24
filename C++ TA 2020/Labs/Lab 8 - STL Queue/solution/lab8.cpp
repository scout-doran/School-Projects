/*
	Title:  lab8.cpp
	Author: April Crockett
	Date:  10/23/2020
	Purpose:  Practice with STL Queue library
*/
/*note:
	Ofstream: File handling class that signifies the output file stream and is used for writing data to files. 
	Ifstream: File handling class that signifies the input file stream and is used for reading data from the file. 
	Fstream: File handling class that has the ability to handle both ifstream and ofstream.
*/
#include <iostream>
#include <fstream>
//#include<cstdlib>
#include <queue>
using namespace std;

int main()
{
	char filename1[25];
	char filename2[25];
	
	cout << "\nWhat is the name of your first file?     ";
	cin.getline(filename1, 25);
	cout << "\nWhat is the name of your second file?     ";
	cin.getline(filename2, 25);
	
	
	// Create an input file stream object.
	fstream file1(filename1, ios::in);

	// Create an input file stream object.
	fstream file2(filename2, ios::in);

	// Create two queues to hold characters.
	queue<char> queue1;
	queue<char> queue2;
	char ch1, ch2;

	// Read all the characters from file #1
	// and enqueue them in queue1.
	file1.get(ch1);
	while (!file1.eof())
	{
		queue1.push(ch1);
		file1.get(ch1);
	}

	// Read all the characters from file #2
	// and enqueue them in queue2.
	file2.get(ch2);
	while (!file2.eof())
	{
		queue2.push(ch2);
		file2.get(ch2);
	}

	// Close the files.
	file1.close();
	file2.close();

	// Dequeue the characters from each queue
	// one-at-a-time and compare them.
	bool status = true;

	while (!queue1.empty() && !queue2.empty())
	{
		ch1 = queue1.front();
		queue1.pop();
		ch2 = queue2.front();
		queue2.pop();

		if (ch1 != ch2)
		{
			status = false;
		}
	}

	if (status)
	{
		cout << "The files are identical.\n";
	}
	else
	{
		cout << "The files are not identical.\n";
	}
	
	return 0;
}