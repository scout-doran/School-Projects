#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<algorithm> //for reverse and swap function
using namespace std;

bool LtoR = true; //left to right 
bool RtoL = false; //right to left

//To find num permutations needed to be executed
int factorial(int n) { 
   if ((n==0)||(n==1))
      return 1; 
   else{
	   return n*factorial(n-1);
   }
}

void lexicograpic(vector<char> strArray){
	int I, J;
	int size = strArray.size();
	bool isDone = false;
	int numPermutations = 1;
	
	while(isDone == false){
		
		//start one left from the end of the array 
		//if found break
		for (int i = size-2; i >= 0; i--)
		{
			if (strArray[i] < strArray[i+1])
			{
				I = i;
				break;
			}
		}
		
		//start at end of array and search until you reach I
		//if found break
		for (int j = size-1; j > I; j--)
		{
			if(strArray[I] < strArray[j])
			{
				J = j;
				break;
			}
			
		}
		
		//display permutation and increment counter
		cout << numPermutations << ":";
		cout << setw(8);
		for(int index = 0; index < size; index++){
			cout << strArray[index];			
		}
		numPermutations++;
		
		
		//swap and reverse
		swap(strArray[I], strArray[J]);
		reverse(strArray.begin() + I+1, strArray.begin() + size);
		
		//check to see if we are finished
		int fact = factorial(size);
		if(numPermutations == fact+1){
			isDone = true;
		}
		else{
			isDone = false;
			//If not finished display I and J
			cout <<  setw(10) <<"I: " << I << setw(5) << "	J: " << J << endl;
		
		}
	}	
}

//Find the largest mobile integer 
int findMobile(vector<char> strArray, bool direction[]) 
{ 
	int prevMobile;
	int k;	//mobile 
	int size = strArray.size();
	for (int i = 0; i < size; i++) 
	{ 
		if (direction[i] == RtoL && i!=0) 
		{ 
			if (strArray[i] > strArray[i+1] && strArray[i] > prevMobile) 
			{  
				k = strArray[i];
				prevMobile = k; 
			} 
		} 

		if (direction[i] == LtoR && i!=size) 
		{ 
			if (strArray[i] > strArray[i-1] && strArray[i] > prevMobile) 
			{ 
				k = strArray[i]; 
				prevMobile = k;
			} 
		} 
	}
	return k; 
} 

int findPosition(vector<char> strArray, int size, int mobile) 
{ 
	for (int i = 0; i < size; i++){
		if (strArray[i] == mobile){
			return i + 1;
		} 
	}
} 

void johnsonTotter(vector<char> strArray){

	int size = strArray.size();
	bool direction[size];
	int fact = factorial(size);
	string arrowArray[size];
	
	// initially all directions are set to right to left 
	for (int i = 0; i < size; i++){
		direction[i] = RtoL;
		arrowArray[i] = "<-";
	}
	
	int mobile; 
	int positionOfMobile; 
	for(int count = 1; count < fact+1; count++){	
	
		//display arrows and permutation
		cout << count << ":" << endl;
		cout << setw(11);
		for (int i = 0; i < size; i++){
			cout << arrowArray[i];
		}
		cout << endl;
		cout << setw(10);
		for (int i = 0; i < size; i++){
			cout << " ";
			cout << strArray[i];
		}
		cout << endl; 
		
		//get mobile and its position in array
		mobile = findMobile(strArray, direction);
		positionOfMobile = findPosition(strArray, size, mobile);
		
		//change direction for elements greater than largest mobile int 
		for (int i = 0; i < size; i++) 
		{ 
			if (strArray[i] > strArray[positionOfMobile-1]) 
			{ 
		
				if(direction[i] == LtoR){
					arrowArray[i] = "<-";
					direction[i] = RtoL;
				}
				if(direction[i] == RtoL){
					arrowArray[i] = "->";
					direction[i] = LtoR;
			 	}
			} 
		}
		
		//swap according to the direction  
		if (direction[positionOfMobile] == RtoL){
			swap(strArray[positionOfMobile-1], strArray[positionOfMobile-2]); 
			swap(direction[positionOfMobile-1], direction[positionOfMobile-2]); 
			
		}
		else if (direction[positionOfMobile] == LtoR){
			swap(strArray[positionOfMobile+1], strArray[positionOfMobile+2]); 
			swap(direction[positionOfMobile+1], direction[positionOfMobile+2]); 
		}		
	}
}	

int main(){
	string str;
	
	//get string
	cout << "Enter in a string: ";
	cin >> str;
	
	//Length of str
	int size = str.size();
	
	//put the string into an array list of characters
	vector<char> strArray(size);
	for(int index = 0; index < size; index++)
	{
		strArray[index] = str[index];
	}	
	
	//Display johnsonTotter 
	cout << endl;
	cout << "JOHNSON TROTTER:" << endl;
	johnsonTotter(strArray);
	
	//Display lexicographic order
	cout << endl;
	cout << endl;
	cout << "LEXICOGRAPHIC ORDER:" << endl;
	lexicograpic(strArray);
	
	return 0;
}