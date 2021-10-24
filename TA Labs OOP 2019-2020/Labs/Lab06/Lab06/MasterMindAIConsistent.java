import java.util.ArrayList;
import java.util.List;

public class MasterMindAIConsistent
{
   private MasterMind game;

   public MasterMindAIConsistent(MasterMind game)  
   {
      this.game = game;
   }

    //DO THIS
   public Guess nextGuess(int guess_id)
   {
      List<Guess> guesses = game.getGuesses();
      int num_guesses = guesses.size();
      Guess nextGuess = null;

      if (guesses.size() > 0)
      {
         Guess trialGuess = null;

         boolean good = false;
         //keep obtaining a random guess until you get one that works with all previous results
         //it is cheating to keep obtaining a random guess until you match the solution
		 //make a random guess and then analyze it







 
         nextGuess = trialGuess;  //found a good one
      }
      else
      {
         nextGuess = makeRandomGuess(guess_id);
      }

      return nextGuess;
   }
   
   //DO THIS
   //is the guess consistent with all previous results?
   //that is, if you compare your random guess to a previous guess, do you get the same number of black and white buttons?
   //don't just check your random guess against the secret guess until you get a good result
   private boolean analyzeGuess(Guess nextGuess)
   {
      List<Guess> guesses = game.getGuesses();  //get all previous guesses from the game
      int num_guesses = guesses.size();

      //loop over all previous guesses
      for (int i = 1; i < guesses.size(); i++) //note that i is starting at 1!
      {
		//previous guess compared to the secret guess (obtain the int array through the game ref)
		
		
		
		

		//next guess is compared to previous guesses, NOT the secret guess

		
		

		//if our previous number of black buttons is not equal to the next number black buttons
		//or if our previous number of white buttons is not equal to the next number of white buttons return false
		if ( 							)
         {
            return false;
         }
      }

      return true;
   }

  
 
   //DO THIS
   //use the Random class to make a randomly generated guess
   private static Guess makeRandomGuess(int guess_id)
   {
      Guess randomGuess = new Guess(guess_id);
      Random random = Random.getRandomNumberGenerator();











      return randomGuess;
   }
}