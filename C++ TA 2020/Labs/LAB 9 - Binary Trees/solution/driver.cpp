/*
	Title:  driver.cpp
	Author:  April Crockett
	Date:  11/9/2018
	Purpose:  demonstrate a binary tree
*/
#include <iostream>
#include "AT_Cast.h" //Adventure Time Cast class
#include "BinaryTree.h"
using namespace std;

int main()
{
	int num = 0;
	BinaryTree<AT_Cast> tree;	// create a BinaryTree object

	AT_Cast castMember1(1021, "Finn");   // put data into object
	tree.insertNode(castMember1);						// put object into tree
	AT_Cast castMember2(1057, "Jake");
	tree.insertNode(castMember2);
	AT_Cast castMember3(2486, "Ice King");
	tree.insertNode(castMember3);
	AT_Cast castMember4(3769, "Princess Bubblegum");
	tree.insertNode(castMember4);
	AT_Cast castMember5(1017, "Lumpty Space Princess");
	tree.insertNode(castMember5);
	AT_Cast castMember6(1275, "Cinnamon Bun");
	tree.insertNode(castMember6);
	AT_Cast castMember7(1899, "Peppermint Butler");
	tree.insertNode(castMember7);
	AT_Cast castMember8(4218, "Marceline");
	tree.insertNode(castMember8);
	AT_Cast castMember9(1214, "BMO");
	tree.insertNode(castMember9);

	// Display the cast members.
	cout << "\n\nHere are the cast members of Adventure Time:\n\n";
	cout << "IN ORDER TRAVERSAL----------------------------------------------\n";
	tree.displayInOrder();
	
	cout << "PRE ORDER TRAVERSAL----------------------------------------------\n";
	tree.displayPreOrder();
	
	cout << "POST ORDER TRAVERSAL----------------------------------------------\n";
	tree.displayPostOrder();

	return 0;
}