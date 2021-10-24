#include <iostream>
#include <fstream>
#include "GraphList.h"

using namespace std;

int main()
{
	int numVerticies;
	int v1, v2;
	ifstream inFile;
	char filename[25];
	
	inFile.open("graph.txt");
	if(!inFile)
	{
		cout << "\n\nSorry.  That file doesn't exist!\n\n";
		exit(1);
	}
	inFile >> numVerticies;
	cout << "\n\nThere are " << numVerticies << " vertices in the graph.\n";
	
	GraphList myGraphList(numVerticies);
	
	
	while(inFile >> v1)
	{
		inFile >> v2;
		cout << "\nAdding an edge from " << v1 << " to " << v2 << ".";
		myGraphList.addEdge(v1, v2);
	}

	cout << "\n\nAdjacency List...\n";
	myGraphList.printGraph();
	
	inFile.close();
	
	return 0;
}