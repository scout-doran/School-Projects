import matrix.*;

/**
 *   Given a player's cards and the dealer's up card, this class finds the desired move 
 *   for a blackjack player based on the strategy given in a file (typically the optimal strategy).  
 */
public class BlackJackStrategy
{
   /** 
    *  A 2D array representing the optimal strategy read in from a file. 
    *  A 1 indicates a stand, a 2 indicates a hit, a 3 indicates a double, and a 4 indicates a split.
    */
   private BasicMatrixInterface strategy;

   /**
    *  Extracts the desired move (excluding splits) from the strategy array for hard and soft hands.
    *  Use the hand value to make it easier to identify the necessary row from the strategy array.
    *  Returns a 'S' if the correct play is to stand.
    *  Returns an 'H' if the correct play is to hit.
    *  Returns a 'D' if the correct play is to double.
    *  Hint: if the player's hand is soft, you need to add 7 to the player's hand value to get the row for the correct play, 
	*  otherwise 2 should be subtracted from the hand value.
    *  Hint: if the dealer's up card is an Ace (which has the value of 1) you need to extract the correct play from column 9, 
	*  otherwise a 2 should be subtracted from the up-card value.
    *  Note: the game will interpret a 'D' as an 'H' if the hand cannot be doubled.
    *  This class only has the responsibility of reading from the matrix.
    */
   public char getMove(BlackJackHand player, BlackJackHand dealer) 
   {
      int up_card = dealer.upCard();

      char optimal = 'S';

      int row = 0;
      int col = 0;
      int player_value = player.handValue();


	//DO THIS

	  if (player.isSoft())
      {
         row =   //everything but the ace value
      }
      else
      {
         row = 
      }

      if (up_card == 1)  //dealer is showing an ace
      {
         col = 
      }
      else
      {
         col =
      }

	  //adding 1's as the strategy matrix is 1-based
      int move = (int) strategy.getElement(row + 1, col + 1);

      if (move == 3)
      {
         optimal = 
      }
      else if (move == 2)
      {
         optimal = 
      }
      else
      {
         optimal =  
      }

      return optimal;
   }

   /**
    *  Determines if a split is the desired move if the first two cards in a hand have the same value.
    *  Use the (modified) hand value to make it easier to identify the necessary row from the strategy matrix.
    *  Returns a false if a split is not the correct play or true if a split is the correct play according to the strategy.
	*  Hint: if the player's hand is soft, you need to extract the correct play from row 38, 
	*  otherwise 27 should be added to the face value.
    *  Hint: if the dealer's up card is an Ace (which has the value of 1) you need to extract the correct play from column 9, 
	*  otherwise a 2 should be subtracted from the up-card value.
    */
   public boolean shouldSplit(BlackJackHand player, BlackJackHand dealer)
   {
      int up_card = dealer.upCard();

      boolean should_split = false;
      int row = 0;
      int col = 0;


	//DO THIS
	  if (player.canSplit())
      {
         if (up_card == 1)
         {
            col = 
         }
         else
         {
            col = 
         }

         int face = player.handValue()/2;

         if (player.isSoft())  //a pair of aces
         {
            row = 
         }
         else
         {
            row = 
         }

		 //adding 1's as the strategy matrix is 1-based
         int move = (int) strategy.getElement(row + 1, col + 1);
		 
         if (move == 4)
         {
            should_split = 
         }
      }

      return should_split;
   }

   /** Reads the strategy in from a file. */
   public BlackJackStrategy(String fileName)
   {
      strategy = MatrixCreator.create(39, 10);

      FileIO file = new FileIO(fileName, FileIO.FOR_READING);

      int rows = strategy.getNumRows();
      int cols = strategy.getNumColumns();

      for (int i = 1; i <= rows; i++)
      {
         for (int j = 1; j <= cols; j++)
         {
            String line = file.readLine();
            int strategy_int = Integer.parseInt(line);
            strategy.setElement(i, j, strategy_int);
         }
      }
      
      file.close();
   }
}