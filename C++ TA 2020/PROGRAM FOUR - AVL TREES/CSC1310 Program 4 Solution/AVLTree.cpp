// Implementation file for the AVLTree class
#include <iostream>
#include "AVLTree.h"
using namespace std;

void AVLTree::displayTree()
{
	display(root, 1);
}

/*************************************************************
Function:  	height
Purpose:  	Find the height of a BST and return it
**************************************************************/
int AVLTree::height(TreeNode *nodePtr) 
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
int AVLTree::diff(TreeNode *nodePtr)
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
void AVLTree::balance(TreeNode *&nodePtr)
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

void AVLTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
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

void AVLTree::insertNode(string n, Professor* p)
{
   TreeNode *newNode = NULL;	// Pointer to a new node.

   // Create a new node
   newNode = new TreeNode;
   newNode->name = n;
   newNode->prof = p;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void AVLTree::destroySubTree(TreeNode *nodePtr)
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

Professor* AVLTree::searchNode(string n)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->name == n)
         return nodePtr->prof;
      else if (n < nodePtr->name)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return NULL;
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void AVLTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->name << endl;
      displayInOrder(nodePtr->right);
   }
}
