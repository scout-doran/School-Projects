
//Scout Doran and Paula Brown
#include <iostream>
#include "permutation.h"
#include "Random.h"
using namespace std;

int main()
{
	int n;
	int x;
	int* deck;
	int deckSize;
	int card;
	int newCard;
	int low = 0;
	int high = 51;
	bool Draw = true;
	int draw;
	
	cout << "Input the size of the deck " << endl; 
	cin >> n;
	cout << "" << endl;
	
	seedRandom();
	
	cout << "your deck is " << endl;
	deck = initPermuation(n);
	cout << "" << endl;
	
	card = nextPermutation(deck, n);
	
	while(Draw == 1)
	{
		cout << "do you want to draw a card (1 = yes, 0 = no)" <<endl;
		cin >> draw; 
		x++;
		
		if(draw == 1 && x < n)
		{
			cout << "your new card is ";
			removePermutation(deck, deckSize, card);
			
			cout << "do you want to draw again" << endl;
			cin >> Draw;
		}
		else if(x == n && x == 0)
		{
			cout << "No more cards" << endl;
			break;
		}
		else 
		{
			break;
		}
	}
	
	
	delete[] deck;
	//delete[] n;
	
	return 0; 
}