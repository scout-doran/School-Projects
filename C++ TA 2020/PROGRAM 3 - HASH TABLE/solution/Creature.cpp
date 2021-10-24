#include "Creature.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Creature::Creature()
{
	
}

Creature::Creature(int id, string n, string d, int life, int hit)
{
	idNum = id;
	name = n; //name of creature
	description = d; //description of creature
	lifePoints = life;
	hitPoints = hit;
}

int Creature::getID() const
{
	return idNum;
}
string Creature::getName() const
{
	return name;
}
string Creature::getDescription() const
{
	return description;
}
int Creature::getLifePoints() const
{
	return lifePoints;
}
int Creature::getHitPoints() const
{
	return hitPoints;
}


void Creature::setID(int id)
{
	idNum = id;
}
void Creature::setName(string n)
{
	name = n;
}
void Creature::setDescription(string desc)
{
	description = desc;
}
void Creature::setLifePoints(int life )
{
	lifePoints = life;
}
void Creature::setHitPoints(int hit)
{
	hitPoints = hit;
}


void Creature::printCreature()
{
	bool flag;
	cout << setprecision(2) << fixed;
	cout << "ID:\t" << idNum << endl;
	cout << "NAME:\t" << name << endl;
	
	//print out the description with some word wrapping
	int len = description.length();
	cout << "DESCRIPTION:\n";
	for(int y = 0; y < len; y++)  //go through each character of the description
	{
		if(y%60 == 0 && y != 0) //once we reach the 60th character we are at the point where we want to go to the next line
		{
			//time to add a newline.
			flag = true;
		}
		if(y == 0)
		{
			cout << "\t ";  //this will indent the first line of the description
		}
		if(flag == true && description[y] == ' ')  //dont start a new line until the word is finished, though (determined by a space).
		{
			cout << "\n\t"; //start new line & indent the line
			flag = false;
		}
			
		cout << description[y]; //print out the character
	}
	cout << endl << endl;								
	cout << "LIFE POINTS:\t" << lifePoints << endl;
	cout << "HIT POINTS:\t" << hitPoints << endl << endl;	
}

void Creature::printCreatureToFile(string fileName)
{
	ofstream file;
	file.open(fileName.c_str(), ios::app);
	if(file)
	{
		file << idNum << "\r\n";
		file << name << "\r\n";
		file << description << "\r\n"; 
		file << lifePoints << "\r\n";
		file << hitPoints << "\r\n";
		file.close();
		file.clear();
		cout << name << " was printed to " << fileName << "\n";
	}
	else
	{
		cout << "\n\nCreature could not be printed to file because file couldn't be opened.\n\n";
	}
}