#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;


class BinaryTree
{
	private:
		struct TreeNode
		{
			string name;
			int krabbyPatty;
			TreeNode* left;
			TreeNode* right;
		};
		
		TreeNode* root;
		
		// Private member functions
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		//void deleteNode(string n, TreeNode *&);
		//void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void display(TreeNode *ptr, int level);
		void getTotal(TreeNode *nodePtr, int &total);
		void getMost(TreeNode *nodePtr, string& n, int& mostPatties);
		void getLeast(TreeNode *nodePtr, string& n, int& leastPatties);


	public:
		// Constructor
		BinaryTree()
		{ 
			root = NULL; 
		}

		// Destructor
		~BinaryTree()
		{ 
			destroySubTree(root); 
		}

		// Binary tree operations
		void insertNode(string, int);
		int searchNode(string);
		//void remove(string);

		void displayInOrder() const
		{  
			displayInOrder(root); 
		}
		
		void getLeastNumPatties(string&, int&);
		void getMostNumPatties(string&, int&);
		int getTotalNumPatties();
		void displayTree();

};


#endif