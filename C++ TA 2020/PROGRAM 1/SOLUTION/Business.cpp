#include <iostream>
#include <fstream>
#include "Business.h"

using namespace std;

Business::Business(Text* name, int maxG, int maxR)
{
	numGames = 0;
	numRentItems = 0;
	maxGames = maxG;
	maxRentItems = maxR;
	businessName = new Text(name->getText());
	
	gameArray = new Game*[maxGames];
	rentItemArray = new RentItem*[maxRentItems];	
	
}

Business::~Business()
{
	cout << "\nBusiness Destructor:\n";
	//release memory for all games
	for(int x=0; x<numGames; x++)
	{
		cout << "\nRELEASING MEMORY FOR GAME IN ARRAY: ";
		gameArray[x]->printGameName();
		delete gameArray[x];
	}
	
	//release memory for all rent items
	for(int x=0; x<numRentItems; x++)
	{
		cout << "\nRELEASING MEMORY FOR RENT ITEM IN ARRAY: ";
		rentItemArray[x]->printRentItemName();
		delete rentItemArray[x];
	}
	cout << "\n\nRELEASING MEMORY FOR businessName, gameArray, & rentItemArray.\n";
	delete businessName;
	delete [] gameArray;
	delete [] rentItemArray;
}

void Business::addGamesFromFile()
{
	//add games from a file in to the array
	ifstream inFile;
	char temp[10000];
	char filename[100];
	cout << "\n\nWhat is the name of the file that contains games?\n";
	cin>>filename;
	inFile.open(filename);
	if(inFile)
	{
		Text* name;
		Text* description;
		Game* oneGame;
		float cost;
		int players;	
		int maxOccupancy;
		float duration;
	
		inFile.getline(temp, 10000);
		while(!inFile.eof())
		{
			if(numGames == maxGames) //we have reached the limit of the array, need to resize the array
				resizeGameArray(); //double the size of the array
				
			name = new Text(temp);
			
			inFile.getline(temp, 10000);
			
			description = new Text(temp);
			
			inFile >> cost;
			inFile >> players;
			inFile >> maxOccupancy;
			inFile >> duration;
			
			
			//one game's data has been read from the file, now create one game
			oneGame = new Game(name, description, cost, players, maxOccupancy, duration);
			//now add this game to the game array
			gameArray[numGames] = oneGame;
			
			oneGame->getGameName()->displayText();
			cout << " was added to the array.\n";

			numGames++;  //increment the number of games
			//read in the next game name if there is one left in the file
			inFile.ignore();
			inFile.getline(temp, 10000);		
				
		}
		cout << "\n\nAll games from " << filename << " have been added.\n";
	}
	else{
		cout << "\n\nI'm sorry, that file doesn\'t exist.\n\n";
	}
}

void Business::addItemsFromFile()
{
	ifstream inFile;
	char temp[1000];
	char filename[100];
	cout << "\n\nWhat is the name of the file that contains items for rent?\n";
	cin>>filename;
	inFile.open(filename);
	if(inFile)
	{		
		Text* name;
		Text* description;
		RentItem* oneRentItem;
		float cost;
		int numInStock;	
		int duration;
		cout << endl;
		inFile.getline(temp, 1000);
		while(!inFile.eof())
		{
			if(numRentItems == maxRentItems) //we have reached the limit of the array, need to resize the array
				resizeRentItemArray();	//double the size of the array
			name = new Text(temp);
			inFile.getline(temp, 1000);
			description = new Text(temp);
			inFile >> cost;
			inFile >> numInStock;
			inFile >> duration;
			
			
			//one rental item's data has been read from the file, now create one rental item
			oneRentItem = new RentItem(name, description, cost, numInStock, duration);
			
			//now add this rental item to the rent item array
			rentItemArray[numRentItems] = oneRentItem;
			
			
			oneRentItem->getItemName()->displayText();
			cout << " was added to the array.\n";
			
			//read in the next rent item name if there is one left in the file
			inFile.ignore();
			inFile.getline(temp, 1000);
			
			numRentItems++;  //increment the number of games
		}
		inFile.close();
		inFile.clear();
		cout << "\n\nAll items from " << filename << " have been added.\n";
	}
	else{
		cout << "\n\nI'm sorry, that file doesn\'t exist.\n\n";
	}
}

void Business::addGameToItem()
{
	Game* oneGame;
	int gameNum;
	
	//print out all the game names
	printGameNames();
	
	cout << endl;
	
	//go through each rent item and if it isn't associated with a game, 
	//then ask user for game it should be associated with
	for(int x=0; x<numRentItems; x++)
	{
		oneGame = rentItemArray[x]->getGameAssociation();
		if(oneGame == NULL)
		{
			cout << "\n\nWhich game would you like the ";
			rentItemArray[x]->printRentItemName();
			cout << " to be associated with?\n";
			cout << "Enter the number of the game from the list above, or enter -1 to skip this item.\n";
			cin >> gameNum;
			if(gameNum != -1)
				rentItemArray[x]->setGameAssociation(gameArray[gameNum-1]);
		}
	}
}

void Business::addGameToArray()
{
	char temp[10000];
	float cost, durationInHours;
	int numPlayers, maxPlayers;
	
	if(numGames == maxGames) //we have reached the limit of the array, need to resize the array
		resizeGameArray();	//double the size of the array
	
	//get the game details from the user
	cout << "\n\nWhat is the name of the game?\n";
	cin.ignore();
	cin.getline(temp, 10000);
	Text* name = new Text(temp);
	cout << "\nWhat is the description?\n";
	cin.getline(temp, 10000);
	Text* description = new Text(temp);
	cout << "\nWhat is the cost to play the game?\n";
	cout << "Enter 0 (zero) if the game is free.\n";
	cin >> cost;
	cout << "\nWhat is the number of players?\n";
	cout << "If pricing is per game instead of per player, enter 0(zero).\n";
	cin >> numPlayers;
	cout << "\nWhat is the maximum number of people who can play the game simultaneously?\n";
	cin >> maxPlayers;
	cout << "\nWhat is the duration of the game?\n";
	cout << "If the duration is unknown, enter 0 (zero).\n";
	cin >> durationInHours;
	
	//create the game
	Game* oneGame = new Game(name, description, cost, numPlayers, maxPlayers, durationInHours);
	
	//add game to array
	gameArray[numGames] = oneGame;
	
	//increment the number of games
	numGames++;
}

void Business::editGameInArray()
{
	if(numGames > 0)
	{
		int gameNum; 
		
		//print out game names
		printGameNames();
		
		//ask user which game should be edited
		cout << "\n\nWhich game would you like to edit?\nEnter a number from the list of games above.\n";
		cin >> gameNum;
		while(gameNum < 1 || gameNum > numGames)
		{
			cout << "\nThat is not a valid game number.  Please enter a number from the list of games above.\n";
			cin >> gameNum;
		}
		
		//edit the game
		gameArray[gameNum-1]->editGameDetails();
	}
	else
		cout << "\n\nThere are no games to edit.\n\n";
}

void Business::removeGameFromArray()
{
	int gameToDelete; 
	
	//print out game names
	printGameNames();
	
	//ask user which game should be deleted
	cout << "\n\nWhich game would you like to remove?\nEnter a number from the list of games above.\n";
	cin >> gameToDelete;
	
	int index = gameToDelete-1;
	
	//check to see if any rent items have this game associated with it and if so, then set the game pointer to null
	for(int i=0; i<numRentItems; i++)
	{
		if(gameArray[index] == rentItemArray[i]->getGameAssociation())
		{
			cout << "\nThis game was associated with rental item ";
			rentItemArray[i]->getItemName()->displayText();
			cout << ", so I am removing this association now before deleting the game.\n";
			rentItemArray[i]->setGameAssociation(NULL);
		}
	}
	
	//send confirmation to the user
	gameArray[index]->getGameName()->displayText();
	cout << " has been removed.\n\n";
	
	//delete the game
	delete gameArray[index];
	
	//move array elements starting with deleted index all the way through the end
	for(int x=index; x<numGames; x++)
	{
		gameArray[x] = gameArray[x+1];
	}
	
	//set the last element to null
	gameArray[numGames] = NULL;
	
	//decrement the number of games
	numGames--;	
}

void Business::addRentItemToArray()
{
	int gameNum;
	char temp[10000];
	float cost, duration;
	int stock;
	
	if(numRentItems == maxRentItems) //we have reached the limit of the array, need to resize the array
		resizeRentItemArray();	//double the size of the array
	
	//first print the list of game names
	printGameNames();
	
	//get the rent item details from the user
	cout << "\n\nWhat is the game that this rent item is associated with?\n";
	cout << "Enter the number of the game listed above.\n";
	cin >> gameNum;
	cin.ignore();
	cout << "\nWhat is the name of the rental item?\n";
	cin.getline(temp, 10000);
	Text* name = new Text(temp);
	cout << "\nWhat is the description?\n";
	cin.getline(temp, 10000);
	Text* description = new Text(temp);
	cout << "\nWhat is the cost to rent this item?\n";
	cout << "Enter 0 (zero) if the rental fee is free.\n";
	cin >> cost;
	cout << "\nHow many of this item do you have in stock?\n";
	cin >> stock;
	cout << "\nHow long (in hours) can this item be rented out?\n";
	cin >> duration;
	
	//create the rental items
	RentItem* oneRentItem = new RentItem(gameArray[gameNum-1], name, description, cost, stock, duration);
	
	//add rental item to array
	rentItemArray[numRentItems] = oneRentItem;
	
	//increment the number of rent items
	numRentItems++;
}

void Business::editRentItemInArray()
{
	if(numRentItems > 0)
	{
		int rentItemNum; 
		
		//print out rental item names
		printRentItemNames();
		
		//ask user which rental item should be edited
		cout << "\n\nWhich rental item would you like to edit?\nEnter a number from the list of items above.\n";
		cin >> rentItemNum;
		while(rentItemNum < 1 || rentItemNum > numRentItems)
		{
			cout << "\nThat is not a valid game number.  Please enter a number from the list of games above.\n";
			cin >> rentItemNum;
		}
		
		//edit the game
		rentItemArray[rentItemNum-1]->editRentItemDetails();
	}
	else
		cout << "\n\nThere are no rental items to edit.\n\n";
}

void Business::removeRentItemFromArray()
{
	int rentItemToDelete; 
	
	//print out rental item names
	printRentItemNames();
	
	//ask user which rental item should be deleted
	cout << "\n\nWhich rental item would you like to remove?\nEnter a number from the list of items above.\n";
	cin >> rentItemToDelete;
	
	int index = rentItemToDelete-1;
	
	//send confirmation to the user
	rentItemArray[index]->getItemName()->displayText();
	cout << " has been removed.\n\n";
	
	//delete the game
	delete rentItemArray[index];
	
	//move array elements starting with deleted index all the way through the end
	for(int x=index; x<numRentItems-1; x++)
	{
		rentItemArray[x] = rentItemArray[x+1];
	}
	
	//set the last element to null
	rentItemArray[numRentItems] = NULL;
	
	//decrement the number of rental items
	numRentItems--;	
}

int Business::getNumGames() const
{
	return numGames;
}

int Business::getNumRentItems() const
{
	return numRentItems;
}

void Business::printGameNames()
{
	if(numGames > 0)
	{
		//print out all the game names
		cout << "\n\nHere is the list of games you currently have:\n";
		for(int x=0; x<numGames; x++)
		{
			cout << x+1 << ".\t";
			gameArray[x]->printGameName();
			cout << endl;
		}
	}
	else
		cout << "\n\nThere are no games entered yet.\n\n";
}

void Business::printRentItemNames()
{
	if(numRentItems > 0)
	{
		//print out all the game names
		cout << "\n\nHere is the list of rent items you currently have:\n";
		for(int x=0; x<numRentItems; x++)
		{
			cout << x+1 << ".\t";
			rentItemArray[x]->printRentItemName();
			cout << endl;
		}
	}
	else
		cout << "\n\nThere are no rental items entered yet.\n\n";
	
}

void Business::printGames()
{
	if(numGames > 0)
	{
		//print out all the games - including all details
		cout << "\n\nHere is the list of all your games:\n\n";
		for(int x=0; x<numGames; x++)
		{
			cout << "****************************************\n";
			cout << "GAME " << x+1 << endl;
			gameArray[x]->printGameDetails();
		}
	}
	else
		cout << "\n\nThere are no games entered yet.\n\n";
}

void Business::printRentItems()
{
	if(numRentItems > 0)
	{
		//print out all the rental items - including all details
		cout << "\n\nHere is the list of all your rental items:\n\n";
		for(int x=0; x<numRentItems; x++)
		{
			cout << "****************************************\n";
			cout << "RENT ITEM " << x+1 << endl;
			rentItemArray[x]->printRentItemDetails();
		}
	}
	else
		cout << "\n\nThere are no rental items entered yet.\n\n";
}

void Business::resizeRentItemArray()
{
	cout << "\n\nRESIZING RENTITEM ARRAY...from " << maxRentItems;
	int max = maxRentItems * 2; //increase size by 2
	
	//make an array that is twice as big as the one I've currently got
	RentItem** newRentItemArray = new RentItem*[max];
	for(int x = 0; x < numRentItems; x++)
	{
		newRentItemArray[x] = rentItemArray[x];
	}
	delete [] rentItemArray;
	rentItemArray = newRentItemArray;
	maxRentItems = max;
	cout << " to a new size of " << maxRentItems << endl << endl;
}

void Business::resizeGameArray()
{
	cout << "\n\nRESIZING GAME ARRAY...from " << maxGames;
	int max = maxGames * 2; //increase size by 2
	
	//make an array that is twice as big as the one I've currently got
	Game** newGameArray = new Game*[max];
	for(int x = 0; x < numGames; x++)
	{
		newGameArray[x] = gameArray[x];
	}
	delete [] gameArray;
	gameArray = newGameArray;
	maxGames = max;
	cout << " to a new size of " << maxGames << endl << endl;
}

void Business::saveData()
{	
	char rentFilename[100];
	char gameFilename[100];
	ofstream rentOutfile;
	ofstream gameOutfile;
	
	char temp[10000];
	
	cout << "\n\nWhat do you want to name the file containing the games?\n";
	cin.ignore();
	cin.getline(gameFilename, 100);
		
	gameOutfile.open(gameFilename);
	
	for(int x=0; x<numGames; x++)
	{
		gameOutfile << gameArray[x]->getGameName()->getText() << endl;
		gameOutfile << gameArray[x]->getGameDescription()->getText() << endl;
		gameOutfile << gameArray[x]->getGameCost() << endl;
		gameOutfile << gameArray[x]->getNumPlayers() << endl;
		gameOutfile << gameArray[x]->getMaxOccupancy() << endl;
		gameOutfile << gameArray[x]->getGameDurationInHours() << endl;
	}
	gameOutfile.close();
	gameOutfile.clear();
	
	cout << "What do you want to name the file containing the rent items?\n";
	cin.getline(rentFilename, 100);
	
	rentOutfile.open(rentFilename);
	
	for(int x=0; x<numRentItems; x++)
	{
		rentOutfile << rentItemArray[x]->getItemName()->getText() << endl;
		rentOutfile << rentItemArray[x]->getItemDescription()->getText() << endl;
		rentOutfile << rentItemArray[x]->getItemCost() << endl;
		rentOutfile << rentItemArray[x]->getHowManyInStock() << endl;
		rentOutfile << rentItemArray[x]->getRentDurationInHours() << endl;
	}
	rentOutfile.close();
	rentOutfile.clear();
	
	cout << "\n\nAll data has been saved to " << gameFilename << " and " << rentFilename << endl << endl;
}






