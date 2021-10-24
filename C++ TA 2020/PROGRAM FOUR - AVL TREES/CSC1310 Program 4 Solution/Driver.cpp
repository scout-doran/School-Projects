/*********************************************************************************
 *     Title:   Driver.cpp                                                   *
 *     Author:  April Crockett                                                   *
 *     Date:    October 29, 2020                                                 *
 *********************************************************************************/

#include "AVLTree.h"
#include "Professor.h"
#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(AVLTree*);

int main()
{
	char choice;
	int option;
	string name;
	int numKrabbyPatties, total;
	Professor* teacher;
	
	//Create a tree.
	AVLTree profTree;
	
	//read data from file
	readFromFile(&profTree);
	
	do{
		cout << "\nWhich Computer Science professor do you want details about?\n";
		profTree.displayInOrder();	
		cout << "\nTYPE PROFESSOR NAME:  ";
		getline(cin, name);

		//find this professor
		teacher = profTree.searchNode(name);
		if(teacher != NULL)
			cout << *teacher;
		else
			cout << "\nThat teacher is not in the AVL Tree.";	
		
		
		cout << "\n\nWould you like to search another?(y/n)  ";
		cin >> choice;
		cin.ignore();
		
	}while(choice == 'y' || choice == 'Y');
	
	return 0;
}

void readFromFile(AVLTree* tree)
{
	int num = 0;
	string name;
	string course;
	string temp;
	bool clearGrading;
	bool goodFeedback;
	bool caring;
	bool reachable;
	bool toughGrader;
	bool lectureHeavy;
	bool attendance;
	Professor * newProf;
	
	ifstream infile;
	infile.open("ProfessorData.txt");
	if(!infile)
	{
		cout << "\nSorry!  Can't read professor data from file!\n";
		exit(0);
	}
	else
	{
		while(getline(infile,name,'$'))
		{
			getline(infile, course, '$');
			getline(infile, temp, '$'); clearGrading = temp[0]-48;
			getline(infile, temp, '$'); goodFeedback = temp[0]-48;
			getline(infile, temp, '$'); caring = temp[0]-48;
			getline(infile, temp, '$'); reachable = temp[0]-48;
			getline(infile, temp, '$'); toughGrader = temp[0]-48;
			getline(infile, temp, '$'); lectureHeavy = temp[0]-48;
			getline(infile, temp, '$'); attendance = temp[0]-48;
			
			//create a new Professor
			newProf = new Professor(name, course, clearGrading, goodFeedback,caring, reachable, toughGrader, lectureHeavy, attendance);
			
			//insert into tree
			tree->insertNode(name, newProf);
			num++;
		}
		cout << "\n\nThere were " << num << " professors added from the file.\n\n";
		infile.close();
	}
}