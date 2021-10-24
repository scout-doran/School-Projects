
#include <iostream>
#include <iomanip>
#include "Permutation.h"
#include "Random.h"
#include <cstdlib>
using namespace std;

int* initPermuation (int n)
{
	int low = 1;
	int high = 52;
	int number;
	int* deck = new int[n];
	//number = n;
	
	for(int i = 0; i < n; i++)
	{
		number = getRandomInt(low, high);
		cout << number << endl; 
		deck[i] = number;
	}
	return deck; 
}

int nextPermutation (int* cards, int& deckSize)
{
	/*int number;
	cards [13]= {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
	for (int i = 0; i < 13; i++)
		{
			int high = cards[13];
			int low = cards[0];
			number = getRandomInt(low, high);
			cards[i] = number;
				
		}
		
	int suits;
	suits [4] = {"Clubs", "Diamonds", "Hearts", "Spades"}; 
	for (int j = 0; j < 3; j++)
		{
			int high = suits[3];
			int low = suits[0];
			int random_suit;
			random_suit = getRandomInt(low, high);
			suits[j] = random_suit;
				
		}*/
	
	int n;
	
	//int* deck = new int [deckSize];
	n = getRandomInt(0, deckSize - 1);
	//for(int i = 0; i < deckSize; i++)
	//{
		int myNum = cards[n];
		//cout << n << endl;
		//removePermutation(cards, deckSize, myNum);
	//}
	
	//delete[] deck;
	return myNum;
}

void removePermutation (int* deck, int deckSize, int card)
{
	int* deck2 = new int [deckSize - 1];
	int newDeckSize = deckSize - 1;
	
	for(int i = 0; i < deckSize; i++)
	{
		deck2[i] = deck[i];
		card = deck2[i];
	}
	//delete[] deckSize;
	
	cout << card << endl;
}
