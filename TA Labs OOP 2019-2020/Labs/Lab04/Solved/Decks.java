
/**
 *  Represents one or more decks of cards.
 */ 
public class Decks
{
   /** An array of Cards representing multiple complete decks of the standard 52 deck of cards. */
   private Card[] decks;  
   /**  The number of Cards remaining in the deck. */
   private int count;
   /**  The number of Decks. */
   private int numDecks;

   /**  The total number of Cards. */
   private final int SIZE; 
   /**  The size of a standard deck of cards. */
   public final int STANDARD_DECK_SIZE = 52;

   /**
    *  Constructor to create several copies of the standard 52 deck of cards and to shuffle them all together.
    */
	/*pass in the number of decks in the parameters*/
   public Decks(int num)
   {
      if (num > 0 && num < 10)
      {
         numDecks = num;
      }
      else
      {
         numDecks = 1;
      }

      SIZE =  STANDARD_DECK_SIZE * numDecks;
      decks = new Card[SIZE];

	  //First loop is going through the number of decks
	  // The second loop keeps track of the number of decks that are
	  // created and calls the card constructor to create a specific card in a 52 card deck.
	  // Passing in 1 to 13 will create a Spade, 14 to 26 will create a Heart, etc.
      int count = 0;
      for (int x = 0; x < numDecks; x++)
      {
		  //DO THIS
         for (int y = 1; y <= STANDARD_DECK_SIZE; y++)
         {
            decks[count] = new Card(y);
            count++;
         }
      }

      shuffle();  //mix them up
   }

   /**
    *  Shuffles the Cards by selecting a random location for each Card.
    *  Create a new array of Cards.  
    *  Move each Card in the original Deck to a random location in the new Deck.
    *  Set count so that all of the cards are available again.
    */
   public void shuffle()
   {
      Card[] shuffled_deck = new Card[SIZE];

      //use Permutation instead
      Permutation p = new Permutation(SIZE, SIZE);

	  //Goes through the decks shuffling each card
      for (int i = 1; i <= SIZE; i++)
      {
         int shuffle_index = p.next();
         shuffled_deck[shuffle_index - 1] = decks[i - 1];
      }

      decks = shuffled_deck;
      //reset the count as all the cards are available to be dealt again 
      count = SIZE - 1;  
   }

   
   
   /**
    *  Returns the next Card in the Deck.  If the Deck is empty, the Deck is shuffled.
    *  Use your count instance variable to determine which Card to return.
    *  Decrement count.
    */
   public Card deal()
   {
      Card current = null;

      if (count == -1)
      {
         shuffle();
      }
      current = decks[count];
      count = count - 1;

      return current;
   }

   /**
    *  Returns the number of Cards remaining in the Deck.
    */
   public int getCount()
   {
      return count + 1;
   }

   /**
    *  Returns the number of Decks.
    */
   public int getNumDecks()
   {
      return numDecks;
   }

   
   /**
    *  Lists the Cards remaining in the Deck.
    */
   public String toString()
   {
      String temp = "";

      for (int x = count; x >= 0; x--)
      {
         temp += decks[x] + "\r\n";
      }

      return temp;
   }
}
