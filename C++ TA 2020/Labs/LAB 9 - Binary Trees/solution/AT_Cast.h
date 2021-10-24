/////////////////////////////
// AT_Cast class
/////////////////////////////
#ifndef AT_CAST_H
#define AT_CAST_H

#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

class AT_Cast
{

	private:
		int castID;
		string name;

	public:

		AT_Cast(int id = 0, string n = "None" ) 
		{
			castID = id;
			name = n;
		}

		void setID(int n)
		{
			castID = n;
		}

		void setName(string str)
		{
			name = str;
		}

		int getID()
		{
			return this->castID;
		}

		string getName()
		{
			return this->name;
		}
		
		bool operator < (const AT_Cast& member)
		{
			return this->castID < member.castID;
		}
		
		friend ostream &operator << (ostream &strm, AT_Cast &member)
		{
			strm << "Cast ID Number: " << member.castID << "\tName: " << member.name << endl;
			return strm;
		}

};

#endif