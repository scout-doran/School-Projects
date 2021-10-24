import java.awt.Graphics;
import java.util.ArrayList;
import java.util.List;

public class Guesses
{
   private List<Guess> guesses;

   public Guesses()  
   {
      guesses = new ArrayList<Guess>();
   }

   public List<Guess> getGuesses()
   {
      return guesses;
   }

   public boolean win(Guess secret)
   {
      int num_guesses = guesses.size();
      if (num_guesses == 0) return false;
      Guess last_guess = guesses.get(num_guesses - 1);
      return last_guess.correct(secret);
   }

   public boolean lose(Guess secret)
   {
      int num_guesses = guesses.size();
      if (num_guesses == 0) return false;
      Guess last_guess = guesses.get(num_guesses - 1);
      return (!last_guess.correct(secret) && numGuesses() == 8);
   }

   public int numGuesses()
   {
      int num_guesses = guesses.size();
      if (num_guesses == 0) return 0;
      Guess last_guess = guesses.get(num_guesses - 1);
      if (last_guess.isFull())
      {
         return num_guesses;
      }
      else
      {
         return num_guesses - 1;
      }
   }

   public void guessAI(MasterMindAI ai)
   {
      int curr_guess = numGuesses() + 1;
      //the guess_id is necessary to draw the guess in the correct location
      Guess guess = ai.nextGuess(curr_guess);
      guesses.add(guess);
   }

   //the current guess and the new color for that guess
   public void addGuess(int guess_color_id)  
   {
      Guess guess;
      int num_guesses = guesses.size();

      if (num_guesses == 0)
      {
         guess = new Guess(1);
         guesses.add(guess);
      }
      else
      {
         guess = guesses.get(num_guesses - 1);  //get the last guess out

         //may need to create a new Guess
         if (guess.isFull() && num_guesses <= 7)
         {
            guess = new Guess(num_guesses + 1);
            guesses.add(guess);
         }
      }

      //add the new color to the guess
      guess.addGuess(guess_color_id);
   }

   //get the colors guessed so that buttons can be processed
   public List<Integer> getGuessIDs(int guess_id)
   {
      Guess guess = guesses.get(guess_id - 1);
      return guess.getGuessIDs();
   }

   public void draw(Graphics g, Guess secret)
   {
      for (Guess guess : guesses)
      {
         guess.draw(g, secret);  
      }
   }

   public void isColorSelected(int x, int y)
   {
      int color_selected = -1;
      for (int i = 1; i <= 7; i++)
      {
          boolean select = MasterMindColor.isColorSelected(i, x, y);
          if (select)
          {
             color_selected = i;
             break;
          }
      }

      if (color_selected == -1) return;

      addGuess(color_selected);
   }
}