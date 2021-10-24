/*****************************************************************
	Title:  	List.h
	Date:  		9-26-2019
	Author: 	April Crockett
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains a ListNode
				structure variable.  List node values are strings
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>
using namespace std;

class List
{
	private:
		
		struct ListNode
		{
			string value; 
			struct ListNode *next;  	// To point to the next node
		}; 

		ListNode *head;		//List head pointer
		ListNode *tail;		//List tail pointer

	public:
		// Constructor
		List()
		{ 
			head = NULL; 
			tail = NULL;
			cout << "\n\nThe linked list has been created.\n\n";
		}

		// Destructor (deallocates all nodes)
		~List();
		
		void appendNode(string);
		void insertNode(string);
		void deleteNode(string);
		void displayList() const;
};

//**************************************************
// appendNode appends a node containing the        *
// value passed into num, to the end of the list.   *
//**************************************************
void List::appendNode(string str)
{
	ListNode *newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = str;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		
		//now the tail is the new node
		tail = newNode;
	}
}

//insert a node in ascending order value
void List::insertNode(string newValue)
{
	ListNode *newNode;				// A new node
	ListNode *nodePtr;				// To traverse the list
	ListNode *previousNode = NULL; // The previous node
	
	newNode = new ListNode;
	newNode->value = newValue;

	// If there are no nodes in the list make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to NULL.
		previousNode = NULL;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != NULL && nodePtr->value < newValue)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list, insert it before all other nodes.
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
void List::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while (nodePtr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void List::deleteNode(string str)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == str)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to str.
		while (nodePtr != NULL && nodePtr->value != str)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}


//Destructor
List::~List()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	cout << "\n\nAll list nodes have been removed.\n\n";
}

#endif