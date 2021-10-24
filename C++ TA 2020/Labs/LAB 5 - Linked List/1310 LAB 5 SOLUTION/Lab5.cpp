/*****************************************************************
	Title:  	Lab5.cpp
	Date:  		9-26-2019
	Author: 	April Crockett
	Purpose:	lab 6
******************************************************************/

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	// Define a LinkedList object.
	List halloweenList;
	
	// Append (add to the end) values to the list
	cout << "\n\nI am appending several strings to the list.\n\n";
	halloweenList.appendNode("boogeyman");
	halloweenList.appendNode("ghost");
	halloweenList.appendNode("scarecrow");
	halloweenList.appendNode("witch");
	halloweenList.appendNode("zombie");
	
	halloweenList.displayList();
	
	//Insert
	cout << "\n\nI am inserting vampire in the list.\n\n";
	halloweenList.insertNode("vampire");
	
	halloweenList.displayList();
	
	
	//Delete
	cout << "\n\nI am deleting ghost from the list.\n\n";
	halloweenList.deleteNode("ghost");
	
	halloweenList.displayList();

	return 0;
}