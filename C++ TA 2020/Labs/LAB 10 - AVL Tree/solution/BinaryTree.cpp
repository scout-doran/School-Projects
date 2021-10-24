// Implementation file for the BinaryTree class
#include <iostream>
#include "BinaryTree.h"
using namespace std;

void BinaryTree::displayTree()
{
	display(root, 1);
}

void BinaryTree::display(TreeNode *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
		
        cout << endl;
        if (ptr == root)
			cout<<"ROOT-> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"       ";
        cout<< (ptr->name).substr(0, 2);
		
		
        display(ptr->left, level + 1);
    }
}

/*************************************************************
Function:  	height
Purpose:  	Find the height of a BST and return it
**************************************************************/
int BinaryTree::height(TreeNode *nodePtr) 
{
    int h = 0;
    if (nodePtr != NULL)
    {
        int l_height = height(nodePtr->left);
        int r_height = height(nodePtr->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/************************************************************
Function:  	diff
Purpose:   	Find the HEIGHT DIFFERENCE between the 
			left & right subtrees 
*************************************************************/
int BinaryTree::diff(TreeNode *nodePtr)
{
    int l_height = height(nodePtr->left);
	//cout << "\nLeft sub-tree height of node " << nodePtr->name << " is " << l_height;
    int r_height = height(nodePtr->right);
	//cout << "\nRight sub-tree height of node " << nodePtr->name << " is " << r_height;
    int b_factor= l_height - r_height;
	//cout << "\nBalance factor of node " << nodePtr->name << " is " << b_factor << endl;
    return b_factor;
}

/************************************************************
Function:  	balance
Purpose:   	Balance the tree into an AVL Tree
*************************************************************/
void BinaryTree::balance(TreeNode *&nodePtr)
{
    int bal_factor = diff (nodePtr);
    if (bal_factor > 1)
    {
        if (diff(nodePtr->left) > 0)  // 2, 1  RIGHT-RIGHT
		{
			nodePtr = rr_rotation(nodePtr);
			//cout << "\nRIGHT rotation";
		}
        else							// 2, -1 LEFT-RIGHT
		{
            nodePtr = lr_rotation(nodePtr);
			//cout << "\nLEFT-RIGHT rotation";
		}
    }
    else if (bal_factor < -1)
    {
        if (diff (nodePtr->right) > 0) // -2, 1 RIGHT-LEFT
		{
            nodePtr = rl_rotation(nodePtr);
			//cout << "\nRIGHT-LEFT rotation";
		}
        else 							// -2, -1 LEFT LEFT
		{
            nodePtr = ll_rotation(nodePtr);
			//cout << "\nLEFT Rotation";
		}
    }
}


//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
	{
		nodePtr = newNode;				// Insert the node.
	}
	else if (newNode->name < nodePtr->name)
	{
		insert(nodePtr->left, newNode);	// Search the left branch
		balance(nodePtr);
	}
	else
	{
		insert(nodePtr->right, newNode);	// Search the right branch
		balance(nodePtr);
	}
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void BinaryTree::insertNode(string n, int numPatties)
{
   TreeNode *newNode = NULL;	// Pointer to a new node.

   // Create a new node and store customer name & number of Krabby Patties
   newNode = new TreeNode;
   newNode->name = n;
   newNode->krabbyPatty = numPatties;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode);
   // balance(root);     WRONG!!!!!
   //display(root, 1);
   cout << endl << endl;
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
/*
	searchNode determines if a customer is present in   
	the tree. If so, the function returns the number of Krabby Patties    
	Otherwise, it returns -1.                     
*/

int BinaryTree::searchNode(string n)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->name == n)
         return nodePtr->krabbyPatty;
      else if (n < nodePtr->name)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return -1;
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->name << endl;
      displayInOrder(nodePtr->right);
   }
}

void BinaryTree::getLeastNumPatties(string& n, int& leastPatties)
{
	//set the least patties to root's # of Krabby Patties
	leastPatties = root->krabbyPatty;
	n = root->name;
	getLeast(root, n, leastPatties);
}

void BinaryTree::getLeast(TreeNode *nodePtr, string& n, int& leastPatties)
{
	if(nodePtr)
	{
		getLeast(nodePtr->left, n, leastPatties);
		if(nodePtr->krabbyPatty < leastPatties)
		{	
			n = nodePtr->name;
			leastPatties = nodePtr->krabbyPatty;
		}
		getLeast(nodePtr->right, n, leastPatties);		
	}
}
void BinaryTree::getMostNumPatties(string& n, int& mostPatties)
{
	//set the most patties to root's # of Krabby Patties
	mostPatties = root->krabbyPatty;
	n = root->name;
	getMost(root, n, mostPatties);
}

void BinaryTree::getMost(TreeNode *nodePtr, string& n, int& mostPatties)
{
	if(nodePtr)
	{
		getMost(nodePtr->left, n, mostPatties);
		if(nodePtr->krabbyPatty > mostPatties)
		{	
			n = nodePtr->name;
			mostPatties = nodePtr->krabbyPatty;
		}
		getMost(nodePtr->right, n, mostPatties);		
	}
}

int BinaryTree::getTotalNumPatties()
{
	int total = 0;
	getTotal(root, total);
	return total;
}

void BinaryTree::getTotal(TreeNode *nodePtr, int &total)
{
	if(nodePtr)
	{
		getTotal(nodePtr->left, total);
		total = total + nodePtr->krabbyPatty;
		getTotal(nodePtr->right, total);
	}
}