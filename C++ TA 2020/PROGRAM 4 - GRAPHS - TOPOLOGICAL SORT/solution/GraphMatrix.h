#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <iostream>
using namespace std;

class GraphMatrix
{
	private:
		int ** vertexMatrix;
		int numVertices;
		int numEdges;
		
	public:
		GraphMatrix(int numV)
		{
			numVertices = numV;
			numEdges = 0;
			vertexMatrix = new int*[numV];
			
			for(int i=0; i<numVertices; i++)
			{
				vertexMatrix[i] = new int[numVertices];
			}
			
			for(int i=0; i<numVertices; i++)
			{
				for(int j=0; j<numVertices; j++)
					vertexMatrix[i][j] = 0; //set all elements to zero until we know that there is an edge
			}
		}
		~GraphMatrix()
		{
			for(int i=0; i<numVertices; i++)
			{
				delete[] vertexMatrix[i];
			}
			delete[] vertexMatrix;	
		}
		
		/*
			Function addEdge()
			Input:  two vertices, which are integers where v1 has a directed edge toward v2-1
			Output: none
			Purpose:  to create an edge between v1 to v2
		*/
		void addEdge(int v1, int v2)
		{
			if(vertexMatrix[v1][v2] == 0) //no edge created yet
				numEdges++;
			vertexMatrix[v1][v2] = 1;
		}
		
		void delEdge(int v1, int v2)
		{
			if(vertexMatrix[v1][v2] != 0)
				numEdges--;
			vertexMatrix[v1][v2] = 0;
		}
		void printGraph()
		{
			for(int i=0; i<numVertices; i++)
			{
				for(int j=0; j<numVertices; j++)
				{
					if(vertexMatrix[i][j] != INT_MAX)
						cout << vertexMatrix[i][j];
					else
						cout << "I";
					cout << "\t";
				}
				cout << endl;
			}
		}
		int getFirstVertex()
		{

			int firstVertex = 0;
			for(int i=0; i<numVertices; i++)
			{
				bool foundAnEdge = false;
				for(int j=0; j<numVertices; j++)
				{
					//cout << "\nChecking vertexMatrix["<<j<<"]["<<i<<"], which is " << vertexMatrix[j][i] << endl;
					if(vertexMatrix[j][i] != 0)
						foundAnEdge = true;
				}
				if(!foundAnEdge)
				{
					firstVertex = i;
					//cout << "\n\nFirst Vertex is " << firstVertex << endl;
				}
			}

			return firstVertex;
			
		}
		bool isThereAnEdge(int r, int c)
		{
			if(vertexMatrix[r][c] == 1)
				return true;
			else
				return false;
		}
};

#endif