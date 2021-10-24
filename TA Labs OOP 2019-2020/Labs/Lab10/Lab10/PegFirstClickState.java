import java.util.ArrayList;

public class PegFirstClickState implements PegState
{
   private Pegs pegs;

   public PegFirstClickState(Pegs pegs)
   {
	   //update pegs
       
   }

   public void mouseClicked(int x, int y)
   {
      //find out which peg was clicked on (call a method in Pegs)
      int select = 

      //get the list of possible jumps from Pegs (method in pegs)
      ArrayList<Jump> possible_jumps = 
      int num_jumps = 

      if (num_jumps == 1)
      {
         //only one possible jump, so complete the jump
         Jump jump = possible_jumps.get(0);
         jump.jump(pegs);
         pegs.incrementTurn();
         if (pegs.gameOver())
         {
			 //set current state to GameOverState






         }
      }

      //the jump cannot be completed until a legal empty slot has also been clicked on
      else if (num_jumps > 1)
      {
         //set the state to PegSecondClickState:
		 //get the second click state (store in a variable of type PegState)
		 //set the selected peg back to start (a PegSecondClickState method)
		 //and then set the current state to second click state








      }
   }
}