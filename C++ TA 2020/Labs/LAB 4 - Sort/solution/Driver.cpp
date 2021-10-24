#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

void insertionSort(Song *mySongArray, int numSongs);
void bubbleSortReverse(Song *mySongArray, int numSongs);
void quicksort(Song *mySongArray, int low, int high);
int partition(Song *mySongArray, int left, int right);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	insertionSort(mySongArray, numSongs);
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	bubbleSortReverse(mySongArray, numSongs);
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	quicksort(mySongArray, 0, numSongs-1);
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//ascending order 
void insertionSort(Song *mySongArray, int numSongs)
{
	Song key;
	int j;
	
	for(int i=1; i < numSongs; i++)
	{
		key = mySongArray[i]; //select item to be sorted
		j = i-1;
		while(j >= 0 && mySongArray[j].getTitle() > key.getTitle()) 
		{
			mySongArray[j+1] = mySongArray[j]; //move elements out of the way
			j = j-1;
		}	
		mySongArray[j+1] = key; //insert item in final sorted position
	}		
}

//descending order 
void bubbleSortReverse(Song *mySongArray, int numSongs)
{
	Song temp;
	
	for(int last = numSongs-1; last > 0; last--)
	{
		for(int i=0; i<last; i++)
		{
			//compare adjacent elements
			if(mySongArray[i].getTitle() < mySongArray[i+1].getTitle())
			{
				//swap the array elements
				temp = mySongArray[i];
				mySongArray[i] = mySongArray[i+1];
				mySongArray[i+1] = temp;
			}
		}
	}
}

//ascending order 
void quicksort(Song *mySongArray, int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot_location = partition(mySongArray, low, high); //returns location of last element in low partition
	quicksort(mySongArray, low, pivot_location); //recursively sort low partition
	quicksort(mySongArray, pivot_location + 1, high); //recursively sort high partition
}

//mid partition algorithm
int partition(Song *mySongArray, int left, int right) 
{
	string pivot, l_string, r_string;
	Song temp;
	bool done = false;
	int middle = left + (right-left) / 2;
   
	//pivot starts at middle
	pivot = mySongArray[middle].getTitle();
	int l = left;
	int r = right;
	while(!done)
	{
		
		while(mySongArray[l].getTitle() < pivot) 
			++l;
		while(pivot < mySongArray[r].getTitle())
			--r;
		
		if(l >= r)
		{
			done = true;
		}
		else
		{
			temp = mySongArray[l];
			mySongArray[l] = mySongArray[r];
			mySongArray[r] = temp;
			
			++l;
			--r;
		}
		return r;
	}
}