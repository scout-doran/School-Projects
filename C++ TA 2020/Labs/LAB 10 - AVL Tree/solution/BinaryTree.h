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
		int height(TreeNode *nodePtr);
		int diff(TreeNode *nodePtr);
		void balance(TreeNode *&nodePtr);

		/**************************************************************    ROTATIONS    *******************************

		/**************************************************************
		Function: 	ll_rotation
		Purpose:	Perform LEFT-LEFT rotation on this parent node
		***************************************************************/
		TreeNode* ll_rotation(TreeNode *parent)
		{
			TreeNode *nodePtr;
			nodePtr = parent->right;
			parent->right = nodePtr->left;
			nodePtr->left = parent;
			return nodePtr;
		}

		/**************************************************************
		Function: 	rr_rotation
		Purpose:	Perform RIGHT-RIGHT rotation on this parent node
		***************************************************************/
		TreeNode* rr_rotation(TreeNode *parent)
		{
			TreeNode *nodePtr;
			nodePtr = parent->left;
			parent->left = nodePtr->right;
			nodePtr->right = parent;
			return nodePtr;
		}

		/**************************************************************
		Function: 	lr_rotation
		Purpose:	Perform LEFT-RIGHT rotation on this parent node
		***************************************************************/
		TreeNode* lr_rotation(TreeNode *parent)
		{
			TreeNode *nodePtr;
			nodePtr = parent->left;
			parent->left = ll_rotation(nodePtr);
			return rr_rotation(parent);
		}

		/**************************************************************
		Function: 	rl_rotation
		Purpose:	Perform RIGHT-LEFT rotation on this parent node
		***************************************************************/
		TreeNode* rl_rotation(TreeNode *parent)
		{
			TreeNode *nodePtr;
			nodePtr = parent->right;
			parent->right = rr_rotation(nodePtr);
			return ll_rotation(parent);
		}


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