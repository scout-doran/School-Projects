import java.awt.Graphics;

public class MasterMind implements Drawable
{
   private Board board;
   private Guesses guesses;
   private Guess secret;
   private boolean play;
   private MasterMindAI[] ais;
   private MasterMindAI current_ai;

   //DO THIS
   //entry point
   public static void main(String[] args)
   {
      //0 = human player, 1 = random based, 2 = consistent based, and 3 = minimax based
      int ai_int = 0;  //human player is the default

	  //DO THIS
	  //if a command line argument exists, parse it as an integer, store it in ai_int
      //use try-catch and catch two appropriate exceptions
      try
      {
         ai_int = Integer.parseInt(args[0]);
      }
      catch (ArrayIndexOutOfBoundsException aioobe)
      {
         ai_int = 0;
      }
      catch (NumberFormatException nfe)
      {
         ai_int = 0;
      }

      SimpleDialogs sd = SimpleDialogs.getSimpleDialogs();
      sd.useSystemStyle();
      MasterMind mm = new MasterMind(ai_int);
   }

   public void keyPressed(char key)
   {
      int ai_int = (int) key - 48;
      if (current_ai != null)
      {
         setAI(ai_int);
      }
   }
   
   //DO THIS
   //this program exhibits dynamic changeability
   //it can be completely reconfigured by user input while the program is running!
   public MasterMind(int ai_int)
   {
      ais = new MasterMindAI[3];
	  //populate the array with each type of MasterMindAI
	  /**
	   The this keyword refers to the current object.
	   It can be used to refer to an instance variable of current class. 
	   It can be used to invoke or initiate a current class constructor. 
	   ***It can be passed as an argument in the method call
	  */
      ais[0] = new MasterMindAIRandom(this);
      ais[1] = new MasterMindAIConsistent(this);
      ais[2] = new MasterMindAIMiniMax(this);
	  //set the ai based on the value passed to the constructor
      setAI(ai_int);

      reset();

	  //create and show the GUI
      MasterMindGUI mmgui = new MasterMindGUI(457, 679, this);
      mmgui.setVisible(true);
   }
   
   //DO THIS
   public void setAI(int ai_int)
   {
      if (ai_int < 1 || ai_int > 3)
      {
         current_ai = null; //the human player will make the next guess
      }
      else
      {
         current_ai = ais[ai_int - 1];
      }
   }

   

   public void reset()
   {
      secret = new Guess(1);  //guess_id of 1 for drawing in modal dialog box
      Random random = Random.getRandomNumberGenerator();
      for (int i = 1; i <= 4; i++)
      {
         int random_int = random.randomInt(1, 7);
         secret.addGuess(random_int);
      }

      board = new Board();
      guesses = new Guesses();
      play = true;
      ((MasterMindAIMiniMax) ais[2]).reset();
   }

   //report result when comparing a guess to the solution
   public int[] getResult(Guess guess)
   {
      return guess.reportResult(secret);
   }

   //report result when comparing two guesses to each other (first parameter tested against the second parameter)
   public int[] getResult(Guess one, Guess two)
   {
      return one.reportResult(two);
   }

   public java.util.List<Guess> getGuesses()
   {
      return guesses.getGuesses();
   }

   public void draw(Graphics g, int width, int height)
   {
      board.draw(g);
      guesses.draw(g, secret);
   }

   public void mouseClicked(int x, int y) 
   {
      if (play)
      {
         if (current_ai == null)
         {
            guesses.isColorSelected(x, y);
         }
         else
         {
            guesses.guessAI(current_ai);
         }

         if (guesses.win(secret))
         {
            Win win = new Win(secret);
            play = false;
         }
         else if (guesses.lose(secret))
         {
            Lose lose = new Lose(secret);
            play = false;
         }
      }

      else
      {
         reset();
      }
   }
}