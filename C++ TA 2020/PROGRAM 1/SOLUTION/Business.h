#ifndef BUSINESS_H
#define BUSINESS_H

#include "Game.h"
#include "RentItem.h"
#include "Text.h"

class Business
{
	private:
		Text* businessName;
		Game** gameArray;
		RentItem** rentItemArray;

		int maxGames;
		int numGames;
		int maxRentItems;
		int numRentItems;
		
		void resizeGameArray();
		void resizeRentItemArray();
	
	public:
		/*
			Function Name:  Business() Constructor
			Purpose:  this function is automatically called when the new Business object is created and will 
					set the businessName, maxGames, and maxRentItems attributes to the data that was sent to the function.  A Text object holding the business name is dynamically created with the new operator.
					An array of maxGames elements holding pointers to Game objects is dynamically created.  An array of
					maxRentItems elements holding pointers to RentItem objects is dynamically created.  
					The numGames and numRentItems attributes are set to zero.
		*/	
		Business(Text* name, int maxG, int maxR);
		
		
		
		/*
			Function Name:  Business() Destructor
			Purpose:  this function is automatically called when the Business object is destroyed.  All dynamically
					created objects are released - including the businessName, Game array, and RentItem array.
		*/	
		~Business();

		
		
		/*
			Function Name:  addGamesFromFile()
			Parameters:  none
			Returns:  none (void)
			Purpose:  allows the user to enter in the filename of the file that contains game data.  Reads in each
				detail of a game, then creates a Game object, and then adds a pointer to this new Game object
				to the array in the correct element, and then increments the numGames attribute.  Reads in games
				until the end of the file, entering each one in to the array & resizes the array (doubles it) if
				needed.
		*/	
		void addGamesFromFile();
		
		
		
		/*
			Function Name:  addItemsFromFile()
			Parameters:  none
			Returns:  none (void)
			Purpose:  allows the user to enter in the filename of the file that contains rent item data.  Reads in each
				detail of a rent item, then creates a RentItem object, and then adds a pointer to this new RentItem object
				to the array in the correct element, and then increments the numRentItems attribute.  Reads in rent items
				until the end of the file, entering each one in to the array & resizes the array (doubles it) if
				needed.
		*/	
		void addItemsFromFile();
		
		
		
		/*
			Function Name:  addGameToItem()
			Parameters:  none
			Returns:  none (void)
			Purpose:  Checks each RentItem in the RentItem array to see if it does not have a Game associated with
					the item and if not, allows the user to pick a Game in the Game array to associate the item with.
		*/			
		void addGameToItem();
		
		
		
		/*
			Function Name:  addGameToArray()
			Parameters:  none
			Returns:  none (void)
			Purpose:  First checks if the Game array can hold another game and if not, resizes the game array by 
					calling resizeGameArray function.  Then, asks the user for all the necessary information for 
					one Game - including the name, description, cost to play, number of players, and duration of 
					the game.  The function then creates a new Game object with this data.  Then it puts the pointer
					to this game in the Game array.  Last, it increments the numGames attribute.
		*/		
		void addGameToArray();


		
		/*
			Function Name:  editGameInArray()
			Parameters:  none
			Returns:  none (void)
			Purpose:  Prints all the names of the games that are pointed to in the Game array.  Then, asks the 
					user to enter in the number of the Game that they want to edit.  Then, calls the editGameDetails()
					function for that Game.
		*/	
		void editGameInArray();

		
		
		/*
			Function Name:  removeGameFromArray()
			Parameters:  none
			Returns:  none (void)
			Purpose:  Prints all the names of the games that are pointed to in the Game array.  Then, asks the 
					user to enter in the number of the Game that they want to remove.  The function prints out
					a confirmation to the user that they have successfully deleted this Game.  Then, the function
					releases the dynamically allocated memory for the game, then moves array elements back one 
					starting with this element to the end of the array.  Then, the function decreases the number
					of games in the array.
		*/			
		void removeGameFromArray();


		
		/*
			Function Name:  addRentItemToArray()
			Parameters:  none
			Returns:  none (void)
			Purpose:  First checks if the RentItem array can hold another RentItem and if not, resizes the array by 
					calling resizeRentItemArray function.  Then, asks the user for all the necessary information for 
					one RentItem.  In order to do this, it prints out all the game names and then asks the user which game the RentItem should be associated with.  Then asks for the RentItem name, description, cost, number in stock, and rental duration.  The function then creates a new RentItem object with this data.  Then it puts the pointer to this RentItem in the RentItem array.  Last, it increments the numRentItems attribute.
		*/	
		void addRentItemToArray();
		
		
		
		/*
			Function Name:  editRentItemInArray()
			Parameters:  none
			Returns:  none (void)
			Purpose:  Prints all the names of the rent items that are pointed to in the RentItem array.  Then, asks the 
					user to enter in the number of the RentItems that they want to edit.  Then, calls the editRentItemDetails()	function for that RentItem.
		*/	
		void editRentItemInArray();
		
		
		/*
			Function Name:  removeRentItemFromArray()
			Parameters:  none
			Returns:  none (void)
			Purpose:  Prints all the names of the RentItems that are pointed to in the RentItem array.  Then, asks the 
					user to enter in the number of the RentItem that they want to remove.  The function prints out
					a confirmation to the user that they have successfully deleted this RentItem.  Then, the function
					releases the dynamically allocated memory for the RentItem, then moves array elements back one 
					starting with this element to the end of the array.  Then, the function decreases the number
					of RentItems in the array.
		*/			
		void removeRentItemFromArray();
		
		
		
		/*
			Function Name:  printGameNames()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints the name attribute of ALL the Game objects in the Game array.
		*/			
		void printGameNames();
		
		
		
		/*
			Function Name:  printRentItemNames()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints the name attribute of ALL the RentItem objects in the RentItem array.
		*/			
		void printRentItemNames();
	

	
		/*
			Function Name:  printGames()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints ALL the details of ALL the Game objects (with formatting) in the Game array.
		*/	
		void printGames();
		
		
		
		/*
			Function Name:  printRentItems()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints ALL the details of ALL the RentItem objects (with formatting) in the RentItem array.
		*/			
		void printRentItems();
		
		
		
		/*
			Function Name:  saveData()
			Parameters:  none
			Returns:  none (void)
			Purpose:  This function gets the filename from the user of where they want to save their Game data
					and then prints all the Game details of ALL games in the Game array to this file.  Then, the 
					function gets the filename from the user of where they want to save their RentItem data and
					then prints all the RentItem details (except for Game association) of ALL rent items in the 
					RentItem array to this file.
		*/			
		void saveData();



		/*
			The following two functions are accessor functions to retrieve attribute values from the Business object
		*/		
		int getNumGames() const;
		int getNumRentItems() const;
		
};

#endif