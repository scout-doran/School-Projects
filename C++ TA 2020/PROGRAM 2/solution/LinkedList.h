/*
	Title:  LinkedList.h
	Author:  April Crockett
	Date:  2/4/2018
	Purpose:  A template class which implements a singly-linked list.
*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			T value;           	
			struct ListNode *next;  	
		}; 
		ListNode *head;		
		ListNode *tail;		
		int numNodes;

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
			numNodes = 0;
		}
		~LinkedList();
		int getLength();
		T getNodeValue(int);
		void appendNode(T);
		void insertNode(T, int);
		void deleteNode(int);
		//void swap(int, int);
};

template <typename T>
int LinkedList<T>::getLength()
{
	return numNodes;
}

//returns the node value at a given position
template <typename T>
T LinkedList<T>::getNodeValue(int position)
{
	ListNode *nodePtr;
	nodePtr = head;
	int currentPos = 0;
	
	while(position >= currentPos)
	{
		if(position == currentPos)
			return nodePtr->value;
		currentPos++;
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// appendNode appends a node containing the        *
// value passed into nodeValue, to the end of the list.   *
//**************************************************
template <typename T>
void LinkedList<T>::appendNode(T nodeValue)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list
	// Allocate a new node and store nodeValue there.
	newNode = new ListNode;
	++numNodes;
	newNode->value = nodeValue;
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

template <typename T>
void LinkedList<T>::insertNode(T nodeValue, int iPos)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list
	ListNode *previousNode;
	// Allocate a new node and store nodeValue there.
	newNode = new ListNode;
	++numNodes;
	newNode->value = nodeValue;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at position.
	{
		int pos = 0; 
		nodePtr = head;
		
		if(iPos == 0) //insert at beginning of list
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		if(iPos >= this->getLength()-1) //insert at end
		{
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
			return;
		}
		while(iPos != pos)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			pos++;
		}
		
		newNode->next = nodePtr;
		previousNode->next = newNode;
	}
}
/*
template <typename T>
void LinkedList<T>::swap(int pos1, int pos2)
{
	ListNode *nodePtr1=NULL;
	ListNode *nodePtr2=NULL;
	T tempValue;
	
	nodePtr1 = head;
	
	int curPos = 0;
	while(nodePtr1 != NULL && pos1 != curPos)
	{
		//traverse to next node
		nodePtr1 = nodePtr1->next;
		curPos++;
	}
	//now nodePtr1 is pointing to pos1 
	nodePtr2 = head;
	curPos = 0;
	while(nodePtr2 != NULL && pos2 != curPos)
	{
		//traverse to next node
		nodePtr2 = nodePtr2->next;
		curPos++;
	}	
	//now nodePtr2 is pointing to pos2 	

	//swap the values in the nodes
	tempValue = nodePtr1->value;
	nodePtr1->value = nodePtr2->value;
	nodePtr2->value = tempValue;
	
}*/

//**************************************************
// The deleteNode function finds the node with the argument position & deletes it
//**************************************************
template <typename T>
void LinkedList<T>::deleteNode(int position)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// Determine if the first node is the one.
	if (position == 0)
	{
		nodePtr = head->next;
		delete head;
		--numNodes;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		int ptrPosition = 0;

		// Skip all nodes whose value member is not equal to the sent position.
		while (ptrPosition != position)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			ptrPosition++;
		}

		// If nodePtr is not at the end of the list, link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if(nodePtr == tail)
			tail = previousNode;
		
		previousNode->next = nodePtr->next;
		delete nodePtr;
		--numNodes;
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************
template <typename T>
LinkedList<T>::~LinkedList()
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
		--numNodes;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
#endif