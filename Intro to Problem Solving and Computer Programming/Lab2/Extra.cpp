//Scout Doran
#include "Extra.h"
#include <iostream>
#include <fstream>

using namespace std;

Students* readFile(const char* filename)
{
	ifstream inFile;
	inFile.open(filename);
	int numGrades;
	inFile >> numGrades;
	
	Students* s = createStudents();
	
	string name;
	float score;
	Student* stud;
	while(!inFile.eof())
	{
		inFile.ignore();
		getline(inFile, name);
		stud = createStudent(name, numGrades);
		for (int i = 0; i < numGrades; i++)
		{
			inFile >> score;
			addGrade(stud, score);
		}
		addStudent(s, stud);
		
	}
	
	inFile.close();
	return s;
}

void addGrade(Student* s, float scores)
{
	int current = s->scores->currentValue;
	s->scores->array[current] = scores;
	s->scores->currentValue++;

}

void addStudent (Students* ss, Student* student)
{
	int current = ss->current;
	int max = ss->maxSize;

	if (max == current)
		resize (ss);
	ss->students[current] = student;
	ss->current++;
}

float* testAverage(Students* ss)
{
	float sum = 0;
	int currentValue = ss->current;
	int average = ss->students[0]->scores->max;
	float* avg = new float[average];
	for (int i = 0; i < ss->students[0]->scores->currentValue; i++)
	{
		for (int j = 0; j < currentValue; j++)
		{
			sum += ss->students[j]->scores->array[i];
		}
		avg[i] = sum/currentValue;
		sum = 0;
	}
	return avg;
}

void curvedGrade (Students* ss, int t, int curve, float testAverage)
{
	
	int current = ss->current;
	float gradeAfter = curve - testAverage;
	for (int i = 0; i < current; i++)
	{ 
		ss->students[i]->scores->array[t] = ss->students[i]->scores->array[t] + gradeAfter;
	}
}

void displayAverage(float* avg, Students* ss, float curve)
{
	int numOfAvgs = ss->students[0]->scores->currentValue;
	char useCurve;
	for (int i = 0; i < numOfAvgs; i++)
	{
		cout << fixed << showpoint << setprecision(2);;
		cout << "Test " << i + 1 << " average is: " << avg[i] << ". ";
		
		if (avg[i] < curve)
		{
			do{
				cout << "Apply the curve? (y or n) ";
				cin >> useCurve;
				if(useCurve == 'y') 
				{
					curvedGrade(ss, avg[i], curve, i);
				}
				else if (useCurve == 'n')
				{
					continue;
				}
				else
				{
					cout << "Please enter y or n" << endl;
				}
			} while (useCurve != 'y' && useCurve != 'n');
		}
		
		else
		{
			cout << "Doesn't need curve" << endl;
		}
	}
}