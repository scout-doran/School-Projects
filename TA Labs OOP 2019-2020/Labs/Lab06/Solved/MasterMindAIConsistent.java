import java.util.ArrayList;
import java.util.List;

public class MasterMindAIConsistent implements MasterMindAI
{
   private MasterMind game;

   public MasterMindAIConsistent(MasterMind game)  
   {
      this.game = game;
   }

   public Guess nextGuess(int guess_id)
   {
      List<Guess> guesses = game.getGuesses();
      int num_guesses = guesses.size();
      Guess next_guess = null;

      if (num_guesses > 0)
      {
         Guess trial_guess = null;

         boolean good = false;
		 //keep obtaining a random guess until you get one that works with all previous results
         //it is cheating to keep obtaining a random guess until you match the solution
         while(!good)
         {
            trial_guess = makeRandomGuess(guess_id);
            good = analyzeGuess(trial_guess);
         }
 
         next_guess = trial_guess;  //found a good one
      }
      else
      {
         next_guess = makeRandomGuess(guess_id);
      }

      return next_guess;
   }
  
   //make sure that the next guess, randomly generated, is consistent with all previous results
   //that is, if you compare your random guess to a previous guess, do you get the same number of black and white buttons?
   //don't just check your random guess against the secret guess until you get a good result
   private boolean analyzeGuess(Guess next_guess)
   {
      List<Guess> guesses = game.getGuesses();
      int num_guesses = guesses.size();

      //loop over all previous guesses
      for (int i = 1; i <= num_guesses; i++)
      {
         //previous guess compared to the secret guess (obtain the int array through the game ref)
         Guess prev_guess = guesses.get(i - 1);
         int[] prev_result = game.getResult(prev_guess);  
         int prev_num_black = prev_result[0];
         int prev_num_white = prev_result[1];

         //next guess is compared to previous guesses, NOT the secret guess
         int[] next_result = game.getResult(prev_guess, next_guess);
         int next_num_black = next_result[0];
         int next_num_white = next_result[1];

         if ((prev_num_black != next_num_black) || (prev_num_white != next_num_white))
         {
            return false;
         }
      }

      return true;
   }

   private static Guess makeRandomGuess(int guess_id)
   {
      Guess random_guess = new Guess(guess_id);
      Random random = Random.getRandomNumberGenerator();
      for (int i = 1; i <= 4; i++)
      {
         int random_int = random.randomInt(1, 7);
         random_guess.addGuess(random_int);
      }

      return random_guess;
   }
}