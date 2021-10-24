 #include <iostream>
 #include <cstdlib>

 using namespace std;
 
 int calculateGCD(int m, int n)
 {
	int RofM; // holds the value of the remainder of m
	int RofN; // holds the value of the remainder of n 
	int min;
	
	//find minimum of m and n
	if (m<n)
	{
		min = m;
	}
	else{
		min = n;
	}
	
	//Start GCD process
	RofM = m%min;
	RofN = n%min;
	while(RofM !=0 || RofN != 0)
	{
		min = min-1;
		RofM = m%min;
		RofN = n%min;
	}
	if(RofM == 0 && RofN ==0)
	{
		return min;
	}
	
 }
 
 int main(int argc, char* argv[])
 {
	 //Check that the user typed in enough arguments
	if(argc != 3)
	{
		cout << "\n\nUsage:  commandLine.exe integer integer\n";
		return 1; //exit program
	}
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0) //checks if if the GCD can't be found 
	{
		cout << "GCD(" << argv[1] << ", " << argv[2] << ") " << "is undefined" << endl;
	}
	//Find GCD and display
	else{
		int v = calculateGCD(atoi(argv[1]), atoi(argv[2]));
		cout << "GCD(" << argv[1] << ", " << argv[2] << ") " << "is " << v << endl;
	}
	return 0;
 }