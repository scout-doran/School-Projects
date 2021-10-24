#include "BasicSort.h"

void selectionSort (int array[], const int size)
{
	int min;
	int swap;
	
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap = array[min];
		array[min] = array[i];
		array[i] = swap;	
	}
}