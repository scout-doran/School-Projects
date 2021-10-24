#include "Creature.h"
#include "HashTable.h"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void enterCreatureFromFile(HashTable<Creature*>*);
void enterCreatureManually(HashTable<Creature*>*);
void searchForCreature(HashTable<Creature*>*);
void deleteCreature(HashTable<Creature*>*);

const int HASHTABLESIZE = 10;

int main()
{
	HashTable<Creature*>* creatureTable = new HashTable<Creature*>(HASHTABLESIZE);
	int choice;
	
	do{
	
		cout << "\n\nCREATURE MANAGEMENT MENU\n\n";
		cout << "1.  Add Creatures From File\n";
		cout << "2.  Add Creature Manually\n";
		cout << "3.  Search for Creature\n";
		cout << "4.  Delete a Creature\n";
		cout << "5.  Print Hash Table\n";
		cout << "6.  End Program\n";
		cout << "CHOOSE 1-6: ";
		cin >> choice;
		while(choice < 1 || choice > 6 || !cin)
		{
			cout << "\nInvalid input.  Choose 1-6:  ";
			cin >> choice;
		}
		cout << endl << endl;
		
		switch(choice)
		{
			case 1:		enterCreatureFromFile(creatureTable);
						break;
						
			case 2:		enterCreatureManually(creatureTable);
						break;
						
			case 3:		searchForCreature(creatureTable);
						break;
			
			case 4:		deleteCreature(creatureTable);
						break;
						
			case 5:		creatureTable->printHashTable();
						break;
		}
	}while(choice != 6);
	
	delete creatureTable;	
	
	
	cout << "\n\nGOODBYE!!\n\n";
	return 0;
} //end of main

void enterCreatureFromFile(HashTable<Creature*>* creatureTable)
{
	ifstream inputFile;
	
	inputFile.open("creatureFile.txt");
	if(inputFile.fail())
	{
		cout << "Oops!  creatureFile.txt does not exist or is corrupt.  Sorry.  Can't load creatures.\n";
	}
	else
	{
		string temp, name, desc;
		int idNum, hitPoints, lifePoints;
		char response;
		int numCreatures = 0;
		//load creatures from file
					
		//read first creature id number to see if one exists		
		inputFile >> idNum;
		while(!inputFile.eof())  //if we are not at the end of the file, proceed
		{
			inputFile.ignore();
			getline(inputFile, name);
			getline(inputFile, desc);
			
			inputFile >> lifePoints;
			inputFile >> hitPoints;
			inputFile.ignore();
			
			//create a creature
			Creature *newCreature = new Creature(idNum, name, desc, lifePoints, hitPoints); 

			//add creature to hash table
			cout << "\n\nEntering creature with ID " << newCreature->getID() << " and name " << newCreature->getName() << endl;
			creatureTable->putValue(newCreature->getID(), newCreature);
				
			numCreatures++;
			
			//start reading next line with new creature.						
			inputFile >> idNum;
		}
		
		inputFile.close();
		inputFile.clear();
		
		cout << "\n" << numCreatures << " creatures from creatureFile.txt have been added to the hash table.\n";
		
	}
}

void enterCreatureManually(HashTable<Creature*> *creatureTable)
{
	string temp, name, desc;
	int idNum, hitPoints, lifePoints;
	char response;

	cout << "\n\nKEY:  ";
	cin >> idNum;
	while(!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid key.  Must be an integer.\n";
		cout << "\n\nKEY:  ";
		cin >> idNum;
	}
	cin.ignore();
	cout << "\nNAME:  ";
	getline(cin, name);
	
	cout << "\nDESCRIPTION:  ";
	getline(cin, desc);
	
	cout << "\nLIFE POINTS:  ";
	cin >> lifePoints;
	
	cout << "\nHIT POINTS:  ";
	cin >> hitPoints;
	
	//create a creature
	Creature *newCreature = new Creature(idNum, name, desc, lifePoints, hitPoints); 

	//add creature to hash table
	creatureTable->putValue(newCreature->getID(), newCreature);
	
}

void searchForCreature(HashTable<Creature*> *creatureTable)
{
	int searchKey;
	Creature * tempCreature;

	cout << "\n\nWhat is the key of the creature you are searching for?  ";
	cin >> searchKey;
	while(!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid key.  Must be an integer.\n";
		cout << "\n\nKEY:  ";
		cin >> searchKey;
	}
	tempCreature = creatureTable->getValue(searchKey);
	if(tempCreature != NULL)
			tempCreature->printCreature();
	else
		cout << "\n\nThere are no creatures with that key in the table.\n\n";
}

void deleteCreature(HashTable<Creature*> *creatureTable)
{
	int creatureToDelete;
	
	cout << "The following is a list of all the creatures you take care of:\n";
	creatureTable->printHashTable();
	cout << "\n\n";
	cout << "What is the ID of the creature you wish to remove?\n";
	cout << "CREATURE ID: ";
	cin >> creatureToDelete;
	creatureTable->removeValue(creatureToDelete);
	cout << "\nYou have removed the creature.\n";
}

