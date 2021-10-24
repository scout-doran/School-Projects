#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>
using namespace std;

class GraphList
{
	private:
		struct ListNode
		{
			int value;
			struct ListNode* next;
		};
		ListNode** headArray;
		
		int numVertices;
		int numEdges;
		
	public:
		GraphList(int numV)
		{
			numEdges = 0;
			numVertices = numV;
			headArray = new ListNode*[numV];
			for(int i = 0; i<numVertices; i++)
			{
				headArray[i] = NULL;
			}
		}
		~GraphList()
		{
			for(int i=0; i<numVertices; i++)
			{
				delete headArray[i];
			}
			delete headArray;	
		}
		
		void addEdge(int v1, int v2)
		{
			//create the node
			ListNode* newNode = new ListNode;
			newNode->value = v2;
			newNode->next = NULL;
			numEdges++;
			
			ListNode* nodePtr = headArray[v1];
			
			if(nodePtr == NULL)
			{
				headArray[v1] = newNode;
			}
			else
			{
				while(nodePtr->next != NULL)
				{
					nodePtr = nodePtr->next;
				}
				nodePtr->next = newNode;
			}
		}
		
		void printGraph()
		{
			ListNode* nodePtr;
			
			for(int i=0; i<numVertices; i++)
			{
				nodePtr = headArray[i];
				cout << i << "--->";
				bool atleastone = false;
				while(nodePtr != NULL)
				{
					atleastone = true;
					cout << nodePtr->value;
					nodePtr = nodePtr->next;
					if(nodePtr != NULL)
						cout << "--->";
					else
						cout << "--->NULL";
				}
				if(!atleastone)
					cout << "NULL";
				cout << endl;
			}
		}
};

#endif