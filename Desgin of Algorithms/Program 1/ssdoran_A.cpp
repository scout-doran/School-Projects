 #include <iostream>
 #include <cstdlib>

 using namespace std;
 
 int calculateGCD(int m, int n)
 {
	 if (m != 0 )
	 { 
		return calculateGCD(n%m, m);
	 }
	 return n;
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