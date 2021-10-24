#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <iomanip>
using namespace std;

class Professor
{
	private:
		string name;
		string course;
		bool clearGrading;
		bool goodFeedback;
		bool caring;
		bool reachable;
		bool toughGrader;
		bool lectureHeavy;
		bool attendance;
	public:
		Professor(string n, string course, bool cG, bool gF, bool c, bool r, bool tG, bool lH, bool a){
			this->name = n;
			this->course = course;
			this->clearGrading = cG;
			this->goodFeedback = gF;
			this->caring = c;
			this->reachable = r;
			this->toughGrader = tG;
			this->lectureHeavy = lH;
			this->attendance = a;
		}
		friend ostream &operator << (ostream &strm, Professor &p)
		{
			strm << endl << endl;
			strm << setw(30) << "Professor:" << setw(20) << p.name << endl;
			strm << setw(30) << "Course:" << setw(20) << p.course << endl;
			strm << setw(30) << "Clear Grading Criteria:" << setw(20);
			if(p.clearGrading == 0) strm << "no"; else strm << "yes";
			strm << endl;
			strm << setw(30) << "Provides Good Feedback:" << setw(20);
			if(p.goodFeedback == 0) strm << "no"; else strm << "yes";
			strm << endl;
			strm << setw(30) << "Caring:" << setw(20);
			if(p.caring == 0) strm << "no"; else strm << "yes";
			strm << endl;
			strm << setw(30) << "Reachable Outside of Class:" << setw(20);
			if(p.reachable == 0) strm << "no"; else strm << "yes";
			strm << endl;
			strm << setw(30) << "Tough Grader:" << setw(20);
			if(p.toughGrader == 0) strm << "no"; else strm << "yes";
			strm << endl;
			strm << setw(30) << "Lecture Heavy:" << setw(20);
			if(p.lectureHeavy == 0) strm << "no"; else strm << "yes";
			strm << endl;
			strm << setw(30) << "Attendance Mandatory:" << setw(20);
			if(p.attendance == 0) strm << "no"; else strm << "yes";
			strm << endl;
			
			return strm;
		}
		
};
#endif