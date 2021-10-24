#include iostream
#include cma
using namespace std;

int interpolationSearch(int array*, int low, int high, int key) 
{
	int pos;
	if(low <= high){
		pos = low + floor((key-array[low]) * (high-low))/(array[high] - array[low]);
	}
	
}

int main()
{
	int searchKey = 10;
	int array[] = {2,3,4,10, 40}
}