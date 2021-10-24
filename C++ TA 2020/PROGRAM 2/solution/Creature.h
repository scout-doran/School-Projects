#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <fstream>
using namespace std;  

class Creature
{
	private:
		string name; //name of creature
		string description; //description of creature
		int lifePoints;
		int hitPoints;
		
		
	public:
		Creature();
		Creature(string, string, int, int);
		
		//accessor functions
		string getName() const;
		string getDescription() const;
		int getLifePoints() const;
		int getHitPoints() const;
		
		//mutator functions
		void setName(string);
		void setDescription(string);
		void setLifePoints(int);
		void setHitPoints(int);
		
		//print functions
		void printCreature();
		void printCreatureToFile(string);
};


#endif
