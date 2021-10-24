#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;  

class Creature
{
	private:
		int idNum;
		string name; //name of creature
		string description; //description of creature
		int lifePoints;
		int hitPoints;
		
		
	public:
		Creature();
		Creature(int, string, string, int, int);
		
		//accessor functions
		int getID() const;
		string getName() const;
		string getDescription() const;
		int getLifePoints() const;
		int getHitPoints() const;
		
		//mutator functions
		void setID(int);
		void setName(string);
		void setDescription(string);
		void setLifePoints(int);
		void setHitPoints(int);
		
		//print functions
		void printCreature();
		void printCreatureToFile(string);
		
		friend ostream &operator << (ostream &strm, Creature &a)
		{
			strm << "ID: " << a.idNum << ", ";
			strm << "NAME: " << a.name;
			return strm;
		}		
};


#endif
