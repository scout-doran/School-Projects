#include <iostream>
#include <fstream>
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Stack.h"

using namespace std;

int main()
{
	int numVerticies;
	int v1, v2;
	ifstream inFile;
	char filename[25];
	
	cout << "\n\nEnter the name of your file that contains the graph vertices:  ";
	cin.getline(filename, 25);
	inFile.open(filename);
	if(!inFile)
	{
		cout << "\n\nSorry.  That file doesn't exist!\n\n";
		exit(1);
	}
	inFile >> numVerticies;
	
	GraphMatrix myMatrix(numVerticies);  
	GraphList myGraphList(numVerticies);
	
	while(inFile >> v1)
	{
		inFile >> v2;
		myMatrix.addEdge(v1, v2);
		myGraphList.addEdge(v1, v2);
	}
	
	cout << "\n\nAdjacency Matrix:\n";
	myMatrix.printGraph();

	cout << "\n\nAdjacency List...\n";
	myGraphList.printGraph();
	
	cout << "\n\nNow traversing & printing graph vertices with DFS.\n";
	
	//create a stack to use for DFS
	Stack<int> dfs_stack;
	
	//create a boolean array to keep track of what has been visited
	bool *visited = new bool[numVerticies];
	
	for(int i=0; i<numVerticies; i++)
		visited[i] = false; //mark all vertices as not visited
	
	int first = myMatrix.getFirstVertex();   //THIS IS EXTRA CREDIT!!!!!!!!!!!!!!!!!!!!!!!!!
	//int first = 0;
	cout << "\n\n" << first << "\t";
	
	dfs_stack.push(first); //push first vertex on stack
	int current_vertex;
	bool cycle = false;
	
	while(!dfs_stack.isEmpty())//while stack isn't empty
	{
		dfs_stack.peek(current_vertex);

		if(visited[current_vertex] == false)
		{
			visited[current_vertex] = true;
		}
		bool startover = false;
		for(int i=0; i<numVerticies || startover == true; i++)
		{
			if(startover == true)
			{
				//set i back to zero
				i = 0;
				startover = false;
			}
			if(myMatrix.isThereAnEdge(current_vertex, i) && visited[i] == false)
			{
				//push on stack
				dfs_stack.push(i);
				visited[i] = true;

				cout << i << "\t";
				current_vertex = i;
				startover = true;
			}
			//THIS IS EXTRA CREDIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			if(myMatrix.isThereAnEdge(current_vertex, i) && visited[i] == true && dfs_stack.find(i)) // we have a cycle!!
			{
				cycle = true;
				cout << "\n\nAh shooty pooty.  This graph has a cycle.\n";
			}
		}
		dfs_stack.pop(current_vertex);
	}
	
	/*if(cycle)
		cout << "\n\nThe graph can't be topologically sorted because it is not a DAG.\n\n";
	else
	{
		cout << "\n\nThe graph vertices topologically sorted are: ";
		for(int i=0; i<numVerticies; i++)
		{
			cout << topoSorted[i] << "  ";
		}
	}*/
	
	cout << endl << endl;
	inFile.close();
	
	return 0;
}