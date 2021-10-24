
#if !defined PERMUTATION
#define PERMUTATION

// Creates a dynamic array of size n, initializes it with 
// the correct values and returns the array to the user
int* initPermuation (int n);    

// Receives the currect card array and the size of the array, 
// returns the next "card". Deck size is passed as a reference 
// variable so it can be modified
int nextPermutation (int* cards, int& deckSize);
  
// Removes the index at card from the array. This function 
// is called by nextPermutation and is never called by the user.
void removePermutation (int* deck, int deckSize, int card);   

#endif