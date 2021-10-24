#include <iostream>
#include <fstream>
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Stack.h"

using namespace std;

int main()
{
	//get filename from user
	
	//open file & make sure it exists
	
	//read in # of vertices from file
	

	//create the matrix object (calling the constructor & sending # of vertices)
	
	//use loop to read in both vertices & then call the matrix object's addEdge function
	
	cout << "\n\nAdjacency Matrix:\n";
	//call the matrix object's printGraph function
		
	cout << "\n\nNow topogocially sorting graph.\n";
	
	//create a stack object to use for DFS
	
	//create a boolean array to keep track of what has been visited

	//create an integer array to hold the topologically sorted vertices

	//set the starting index for topologically sorted array at end of the array (last element)
	
	//use for loop to initialize all elements of visited array to false.
	
	//call the matrix object's getFirstVertex function to get the first vertex that we should begin with in the graph and save it in an integer variable (I called mine first)
	
	//push first vertex on stack
	int current_vertex;
	bool cycle = false;
	
	while(!dfs_stack.isEmpty())//while stack isn't empty
	{
		//call the stack's peek function to get the current vertex and save in an integer (I called my integer current_vertex)
		
		//set the visited array at the current_vertex index to true (mark this vertex as visited)

		bool startover = false;
		for(int i=0; i<numVerticies || startover == true; i++)
		{
			if(startover == true) //we do this if in our last iteration we pushed a vertex to the stack (and marked it as visited)
			{
				i = 0;
				startover = false;
			}
			/*******************The following is code to push a new vertex on the stack & mark as visited******************/
			//			check if there IS an edge between the current_vertex and i.  Also check if we have NOT visited vertex i.  If both are true then do the following:
			//				push the vertex (i) to the stack 
			//				set the vertex i to true in the visited array
			//				set the current_vertex to vertex (i)
			//				set the startover boolean value to true

			
			/*******************The following is code to check for a cycle*************************************************/
			//			check if there is an edge between current_vertex and i.  Also check if we HAVE a visited vertex i.  Also call the stack's find function to see if vertex i is still in the stack.
			//			if all of this is true, then we have a cycle
			//				you can use a boolean variable here (I called mine cycle) and set it to true if you found a cycle
		}
		//pop the stack
		//add the current_vertex to the topologicallySorted array & then decrement the index for this array.
	}
	
	/*PRINT RESULTS*/
	//if cycle then print out that graph cant be sorted
	//otherwise, print out the topological sort array.
	

	
	return 0;
}