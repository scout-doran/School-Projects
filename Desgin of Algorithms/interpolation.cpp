#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 5;

int interpolationSearch(int *arr, int lo, int hi, int key);

int main()
{
	int arr[] = {10, 14, 15, 16, 17};
	int key = 16;
	cout << "\n\nARRAY: ";
	for(int i=0; i<SIZE; i++)
		cout << arr[i] << "  ";
	cout << "\n";
	int result = interpolationSearch(arr, 0, SIZE-1, key);
	
	if(result == -1)
		cout << "\nCould not find key " << key << " in array.\n";
	else
		cout << "\nFound key " << key << " at index " << result << endl;
	
	return 0;
}

int interpolationSearch(int *arr, int lo, int hi, int key)
{
	int pos;
	
	if(lo <= hi)
	{
		pos = lo + floor(((key-arr[lo])*(hi-lo))/(arr[hi]-arr[lo]));
		cout << "\npos is " << pos;
		
		if(arr[pos] == key)
			return pos;
		else if(arr[pos] > key)
		{
			cout << "\narr[pos] " << arr[pos] << " is larger then key " << key;
			return interpolationSearch(arr, lo, pos-1, key);
		}
		else
		{
			cout << "\narr[pos] " << arr[pos] << " is smaller then key " << key;
			return interpolationSearch(arr, pos+1, hi, key);
		}
	}
	return -1;
}