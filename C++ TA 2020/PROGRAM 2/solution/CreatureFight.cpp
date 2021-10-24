#include "Creature.h"
#include "LinkedList.h"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void enterMagicalCreatureFromFile(LinkedList<Creature>*);
void printCreatureNames(LinkedList<Creature> *);
int binarySearch(LinkedList<Creature> *, int, int, string);
//void bubbleSort(LinkedList<Creature> *);
void merge(int i, int j, int k, LinkedList<Creature> *);
void mergeSort(int i, int k, LinkedList<Creature> *);

int main()
{
	char choice; 
	int tempInt, intChoice;
	char response;
	string p1_name, p2_name;
	Creature tempCreature, p1_creature, p2_creature;
	int randomNum;
	bool knockedOutEarly;
	string horizontalLine80(80, '*');
	string horizontalLine40(36, '*');
	string pipe80(80, '|');
	string arrow80(80, 'v');
	srand(time(0));
	
	LinkedList<Creature> creatureList;
	
	enterMagicalCreatureFromFile(&creatureList);
		
	do{ //game loop
		cout << pipe80 << endl << pipe80 << endl << arrow80 << endl;
		cout << "\n\nREADY TO FIGHT!!\n";
		
		//players say their name & select creature
		cout << "PLAYER 1 NAME:  ";
		getline(cin, p1_name);
		cout << "PLAYER 2 NAME:  ";
		getline(cin, p2_name);
		
		cout << "\n\nBefore you have to select your creature, \ndo you want to print details about each one?\n";
		cin >> choice;		
		while(cin.fail() || (tolower(choice) != 'y' && tolower(choice) != 'n')) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou did not enter either 'y' or 'n'.  Do you want to print details ";
			cout << "about each creature?\n";
			cin >> choice;
		}
		
		if(choice == 'y')
		{
			for(int x = 0; x < creatureList.getLength(); x++)
			{
				tempCreature = creatureList.getNodeValue(x);
				cout << horizontalLine80 << endl;
				cout << "CREATURE " << x+1 << ":  \n";
				tempCreature.printCreature();
			}
			cout << horizontalLine80 << endl;
			cout << horizontalLine80 << endl;
		}
		
		cout << endl << p1_name << ", ENTER THE CREATURE NUMBER YOU WISH TO USE TO FIGHT!!\n";
		printCreatureNames(&creatureList);
		cout << endl << endl;
		cout << p1_name << " CREATURE CHOICE (1-" << creatureList.getLength() << "):  ";
		cin >> intChoice;
		while(cin.fail() || intChoice < 1 || intChoice > creatureList.getLength())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou did not enter enter a valid creature number from ";
			cout << "1 to " << creatureList.getLength() << ".\nChoose a valid number:  ";
			cin >> intChoice;
		}
		
		p1_creature = creatureList.getNodeValue(intChoice-1);
		
		
		
		cout << p2_name << ", ENTER THE CREATURE NUMBER YOU WISH TO USE TO FIGHT!!\n";
		printCreatureNames(&creatureList);
		cout << endl << endl;
		cout << p2_name << " CREATURE CHOICE (1-" << creatureList.getLength() << "):  ";
		cin >> intChoice;
		while(cin.fail() || intChoice < 1 || intChoice > creatureList.getLength())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou did not enter enter a valid creature number from ";
			cout << "1 to " << creatureList.getLength() << ".\nChoose a valid number:  ";
			cin >> intChoice;
		}
		
		p2_creature = creatureList.getNodeValue(intChoice-1);
		
		
		
		knockedOutEarly = false;
		cin.ignore();
		for(int x=1; x <= 3; x++)
		{
			cout << pipe80 << endl << pipe80 << endl << pipe80 << endl << pipe80 << endl << pipe80 << endl << arrow80 << endl << endl;
			cout << horizontalLine40 << "ROUND " << x << horizontalLine40 <<endl;
			cout << p1_name << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << p2_name << "\'s "  << p2_creature.getName() << endl;
			cin.get();
			randomNum = (rand() % 6 + 1) * p1_creature.getHitPoints();
			if(randomNum > 1)	cout << "\nYOU HIT " << p2_creature.getName() << " FOR " << randomNum << " POINTS.\n\n";
			else	cout << "\nYOU HIT " << p2_creature.getName() << " FOR " << randomNum << " POINT.\n\n";
			p2_creature.setLifePoints(p2_creature.getLifePoints()-randomNum);
			cout << p2_creature.getName() << " NOW HAS " << p2_creature.getLifePoints() << endl;
			if (p2_creature.getLifePoints() <= 0)
			{
				cout << p1_name << ", " << p1_creature.getName() << " KNOCKED OUT " << p2_creature.getName() << "!!\nYOU WON!!\n\n";
				knockedOutEarly = true;
				break;
			}
			else
			{
				cout << p2_name << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << p1_name << "\'s " << p1_creature.getName() << endl;
				cin.get();
				randomNum = (rand() % 6 + 1) * p2_creature.getHitPoints();
				if(randomNum > 1)	cout << "\nYOU HIT " << p1_creature.getName() << " FOR " << randomNum << " POINTS.\n\n";
				else	cout << "\nYOU HIT " << p1_creature.getName() << " FOR " << randomNum << " POINT.\n\n";
				p1_creature.setLifePoints(p1_creature.getLifePoints()-randomNum);
				cout << p1_creature.getName() << " NOW HAS " << p1_creature.getLifePoints() << endl;
				if (p1_creature.getLifePoints() <= 0)
				{
					cout << p2_name << ", " << p2_creature.getName() << " KNOCKED OUT " << p1_creature.getName() << "!!\nYOU WON!!\n\n";
					knockedOutEarly = true;
					break;
				}
			}
		}
		if(knockedOutEarly == false)
		{
			if(p1_creature.getLifePoints() > p2_creature.getLifePoints()) //player 1 won
			{
				cout << p1_name << ", " << p1_creature.getName() << " KNOCKED OUT " << p2_creature.getName() << "!!\nYOU WON!!\n\n";
			}
			else //player 2 won
			{
				cout << p2_name << ", " << p2_creature.getName() << " KNOCKED OUT " << p1_creature.getName() << "!!\nYOU WON!!\n\n";
			}
		}
		
		cout << "\n\nWould you like to play again? (y/n)\t";
		cin >> choice;
		while(cin.fail() || (tolower(choice) != 'y' && tolower(choice) != 'n')) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou did not enter either 'y' or 'n'.  Would you like to play again? (y/n)\t";
			cin >> choice;
		}
		cin.ignore();
		
	}while(tolower(choice) == 'y');
	
	cout << "\n\nGOODBYE!!\n\n";
	return 0;
} //end of main
/*
void bubbleSort(LinkedList<Creature> *cList)
{
	for(int last = cList->getLength()-1; last > 0; last--)
	{
		for(int i=0; i<last; i++)
		{
			//compare adjacent nodes
			if(cList->getNodeValue(i).getName() > cList->getNodeValue(i+1).getName())
			{
				//swap the values in the two nodes
				cList->swap(i+1, i);
			}
		}
	}
}*/

int binarySearch(LinkedList<Creature> *creatureList, int first, int last, string CreatureName)
{
	int middle = (first+last)/2;
	
	if(first > last)
		return -1;
	if(CreatureName == (creatureList->getNodeValue(middle)).getName())
		return middle;
	if(CreatureName > (creatureList->getNodeValue(middle)).getName())
		return binarySearch(creatureList, middle+1, last, CreatureName);
	else
		return binarySearch(creatureList, first, middle-1, CreatureName);
}

void enterMagicalCreatureFromFile(LinkedList<Creature> *creatureList)
{
	ifstream inputFile;
	int creaturePosition;
	
	inputFile.open("creatureFile.txt");
	if(inputFile.fail())
	{
		cout << "Oops!  creatureFile.txt does not exist or is corrupt.  Sorry.  Can't load creatures.\n";
	}
	else
	{
		string temp, name, desc;
		int hitPoints, lifePoints;
		char response;
		int numCreatures = 0;
		//load creatures from file
					
		//read first creature name to see if one exists
		getline(inputFile, temp);

		while(!inputFile.eof())  //if we are not at the end of the file, proceed
		{
			name = temp;
			getline(inputFile, desc);
			
			inputFile >> lifePoints;
			inputFile >> hitPoints;
			inputFile.ignore();
			
			creaturePosition = binarySearch(creatureList, 0, creatureList->getLength()-1, name);
			if(creaturePosition == -1) //creature doesn't already exist
			{
				//create a creature
				Creature newCreature(name, desc, lifePoints, hitPoints); 

				//append creature to the linked list
				creatureList->appendNode(newCreature);
				mergeSort(0, creatureList->getLength()-1, creatureList);
				//bubbleSort(creatureList);
				numCreatures++;
				cout << endl << name << " has been added to the list of creatures that can fight.";
			}
			else
			{
				cout << endl << name << " was skipped because it is already in the list.";
			}
			//start reading next line with new creature.						
			getline(inputFile, temp);
		}
		
		inputFile.close();
		inputFile.clear();
		
		cout << "\n" << numCreatures << " creatures from creatureFile.txt have been added to the zoo.\n";
		
	}
}
void printCreatureNames(LinkedList<Creature> *creatureList)
{
	string horizontalLine80(80, '*');
	//print all the creatures names
	Creature tempCreature;	
	cout << horizontalLine80 << endl;
	for(int x=0; x<creatureList->getLength(); x++)
	{
		if(x % 4 == 0) cout << endl;
		tempCreature = creatureList->getNodeValue(x);
		cout << right << setw(2) << (x+1) << "-" << left << setw(15) << tempCreature.getName();
	}
	cout << endl << horizontalLine80 << endl;
}
void deleteCreature(LinkedList<Creature> *creatureList)
{
	int creatureToDelete;
	
	//print all the creatures names
	Creature tempCreature;	
	cout << "The following is a list of all the creatures you take care of:\n";
	for(int x=0; x<creatureList->getLength(); x++)
	{
		tempCreature = creatureList->getNodeValue(x);
		cout << (x) << ") " << tempCreature.getName() << "\n";
	}
	cout << "\n\n";
	cout << "What creature do you wish to remove?\n";
	cout << "CREATURE NUMBER: ";
	cin >> creatureToDelete;

	while(creatureToDelete < 1 || creatureToDelete > creatureList->getLength())
	{
		cout << "\nThat number wasn't in the list of creatures.\n";
		cout << "Enter a number between 1 and " << creatureList->getLength() << ".\n";
		cout << "CREATURE NUMBER: ";
		cin >> creatureToDelete;
	}
	
	creatureList->deleteNode(creatureToDelete);
	cout << "\nYou have removed the creature.\n";
}


void saveCreaturesToFile(LinkedList<Creature> *creatureList)
{
	string filename;
	Creature tempCreature;
	
	if(creatureList->getLength() == 0)
	{
		cout << "------------------------------------------------------------------------" << endl;
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!\n";
		cout << endl;
	}
	else
	{
		cout << "\n\nWhat do you want the filename to be?\n";
		cout << "FILENAME:  ";
		cin >> filename;
		cout << endl;
		for(int x = 0; x < creatureList->getLength(); x++)
		{
			tempCreature = creatureList->getNodeValue(x);
			tempCreature.printCreatureToFile(filename);
		}
	}
}

/**********MERGE SORT**********/
// i should be zero when calling this function for the first time and k is size-1
void mergeSort(int i, int k, LinkedList<Creature> *creatureList) 
{
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      mergeSort(i, j, creatureList);
      mergeSort(j + 1, k, creatureList);
      
      // merge left and right partition in sorted order
      merge(i, j, k, creatureList);
   }
}
void merge(int i, int j, int k, LinkedList<Creature> *creatureList) 
{
	int mergedSize = k - i + 1;            // Size of merged partition
	int mergePos = 0;                      // Position to insert merged number
	int leftPos;                           // Position of elements in left partition
	int rightPos;                          // Position of elements in right partition
	Creature leftCreature;
	Creature rightCreature;
	// Dynamically allocate temporary linked list for the merged movies
	LinkedList<Creature> *mergedCreatureList = new LinkedList<Creature>;		 

	leftPos = i;                           // Initialize left partition position
	rightPos = j + 1;                      // Initialize right partition position

	// Add alphebetically smaller node value from left or right partition to merged linked list
	while (leftPos <= j && rightPos <= k) 
	{
	  
		leftCreature = creatureList->getNodeValue(leftPos);
		rightCreature = creatureList->getNodeValue(rightPos);
		if(leftCreature.getName() < rightCreature.getName())
		{
			mergedCreatureList->insertNode(leftCreature, mergePos);
			++leftPos;
		}
		else 
		{
			mergedCreatureList->insertNode(rightCreature, mergePos);
			++rightPos;
		}
		++mergePos;
	}

	// If left partition is not empty, add remaining nodes to merged list
	while (leftPos <= j) 
	{
		leftCreature = creatureList->getNodeValue(leftPos);
		mergedCreatureList->insertNode(leftCreature, mergePos);
		++leftPos;
		++mergePos;
	}
   
	// If right partition is not empty, add remaining nodes to merged list
	while (rightPos <= k) 
	{
		rightCreature = creatureList->getNodeValue(rightPos);
		mergedCreatureList->insertNode(rightCreature, mergePos);
		++rightPos;
		++mergePos;
	}
   
	//REPLACE NODE of original linked list with dynamically created linked list
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) 
	{
		
		//first delete node at i+mergePos
		creatureList->deleteNode(i+mergePos);

		//then insert node at position i+mergePos
		creatureList->insertNode(mergedCreatureList->getNodeValue(mergePos), mergePos+i);
	}
	delete mergedCreatureList;
}
