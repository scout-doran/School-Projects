import java.util.ArrayList;
import java.util.List;

public class MasterMindAIMiniMax implements MasterMindAI
{
   private MasterMind game;
   private List<Guess> viable_solutions;
   private static List<Guess> all_guesses = allGuesses();

   public MasterMindAIMiniMax(MasterMind game)  
   {
      this.game = game;
   }

   public void reset()
   {
      viable_solutions = null;
   }

   private Guess bestGuess(List<Guess> possible_guesses, int guess_id)
   {
      //all guesses coming in here are consistent with all past results (all are viable solutions)
      Guess best_guess = possible_guesses.get(0);  //these guesses do not have the correct guess id
      int best_num_eliminated = 0;

      //want to select the guess that will eliminate the most guesses from the viable list
      for (Guess guess : all_guesses)  //loop over all possible guesses (may or may not be viable solutions)
      {
         int smallest_num_eliminated = 2500;

         //loop over all possible results (black and white buttons)
         //for comparing guess to a viable solution

         //possible black buttons
         for (int i = 0; i <= 4; i++)
         {
            //possible white buttons
            for (int j = 0; j <= 4 - i; j++)
            {
               int num_eliminated = 0;

               //for each possible result, count up the number of guesses that will be eliminated
               //this innermost loop is smaller each time this method is called
               for (Guess pretend_secret : possible_guesses)  //loop over all viable solutions
               {
                  int[] trial_result = game.getResult(guess, pretend_secret);
                  if ((trial_result[0] != i) || (trial_result[1] != j))
                  {
                     num_eliminated++;
                  }
               }

               //remember the smallest number of guesses eliminated, associate this value with guess
               //conservative estimate (minimax)
               if (num_eliminated < smallest_num_eliminated)
               {
                  smallest_num_eliminated = num_eliminated;
               }
            }
         }

         //of all possible guesses, need to select the guess that generated the 
         //largest (smallest number of eliminations)
         //have we improved the number of guesses that will be eliminated by using guess?
         if (smallest_num_eliminated > best_num_eliminated)
         {
            best_num_eliminated = smallest_num_eliminated;
            best_guess = guess;
         }
      }

      Guess next_guess = new Guess(guess_id);  //insert the correct guess_id
      List<Integer> colors = best_guess.getGuessIDs();
      for (int color : colors)
      {
         next_guess.addGuess(color);  //transfer the colors to the guess with the correct guess id
      }
      return next_guess;
   }

   public Guess nextGuess(int guess_id)
   {
      List<Guess> guesses = game.getGuesses();  //get the guess history from the MasterMind game
      int num_guesses = guesses.size();
      Guess next_guess = null;

      if (viable_solutions == null)
      {
         viable_solutions = allGuesses();
         if (num_guesses > 0)
         {
            viable_solutions = eliminateGuesses(viable_solutions);
            next_guess = bestGuess(viable_solutions, guess_id);
         }
         else
         {
            //used the below line to compute the best initial guess, then hardcoded it
            //nextGuess = bestGuess(viable_solutions, guess_id);
            //the random guess is no longer random, but the best initial guess (always the same)
            next_guess = makeRandomGuess(guess_id);
         }
      }
      else
      {
         viable_solutions = eliminateGuesses(viable_solutions);
         next_guess = bestGuess(viable_solutions, guess_id);
      }

      return next_guess;
   }

   //remove any guesses that are inconsistent with all current results
   //actually, include any guesses that are consistent
   private List<Guess> eliminateGuesses(List<Guess> possible_guesses)
   {
      List<Guess> new_guesses = new ArrayList<Guess>();

      for (Guess guess : possible_guesses)
      {
         boolean candidate = analyzeGuess(guess);
         if (candidate)
         {
            new_guesses.add(guess);
         }
      }
      return new_guesses;
   }

   //make sure that a given viable guess is consistent with all previous results
   //if it isn't, it can be eliminated
   private boolean analyzeGuess(Guess next_guess)
   {
      List<Guess> guesses = game.getGuesses();  //guess history from the game

      //loop over all previous guesses
      //just need the most recent guess
      int num_guesses = guesses.size();

      //previous guess compared to the secret guess (obtain the int array through the game ref)
      //result history computed using the game ref
      Guess prev_guess = guesses.get(num_guesses - 1);
      int[] prev_result = game.getResult(prev_guess);  
      int prev_num_black = prev_result[0];
      int prev_num_white = prev_result[1];

      //next guess is compared to previous guesses, NOT the secret guess
      //checking for consistency between a proposed next guess and the secret guess
      int[] next_result = game.getResult(next_guess, prev_guess);
      int next_num_black = next_result[0];
      int next_num_white = next_result[1];

      //determine if the next guess and the secret guess give consistent results
      if ((prev_num_black != next_num_black) || (prev_num_white != next_num_white))
      {
         return false;
      }

      return true;
   }

   private static Guess makeRandomGuess(int guess_id)
   {
      Guess random_guess = new Guess(guess_id);
/*
      Random random = Random.getRandomNumberGenerator();
      for (int i = 1; i <= 4; i++)
      {
         int random_int = random.randomInt(1, 7);
         randomGuess.addGuess(random_int);
      }
*/

      //the best initial guess is four different colors (eliminates 1819 of 2401)
      random_guess.addGuess(1);
      random_guess.addGuess(2);
      random_guess.addGuess(3);
      random_guess.addGuess(4);
      return random_guess;
   }

   private static List<Guess> allGuesses()
   {
      List<Guess> all_guesses = new ArrayList<Guess>();

      for (int i = 1; i <= 7; i++)
      {
         for (int j = 1; j <= 7; j++)
         {
            for (int k = 1; k <= 7; k++)
            {
               for (int l = 1; l <= 7; l++)
               {
                  Guess guess = new Guess(1);  //the parameter is the Guess number, irrelevant to the AI
                  guess.addGuess(i);
                  guess.addGuess(j);
                  guess.addGuess(k);
                  guess.addGuess(l);
                  all_guesses.add(guess);
               }
            }
         }
      }

      return all_guesses;
   }
}