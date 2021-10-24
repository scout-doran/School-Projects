
public class PegSecondClickState implements PegState
{
   private Pegs pegs;
   private int start;  //remember which peg was clicked on (info forwarded from PegFirstClickState)

   public PegSecondClickState(Pegs pegs)
   {
	   //update pegs

      start = -1;
   }

   //method called by PegFirstClickState
   public void setStart(int start)
   {
      this.start = start;
   }

   public void mouseClicked(int x, int y)
   {
      //find which slot was clicked on for the second mouse click
      int end = 

      Jump jump = pegs.getJump(start, end);

      //perform the jump
      //check for end of game
      if (jump != null)  
      {

		jump.jump(pegs);
         pegs.incrementTurn();
         if (pegs.gameOver())
         {
            //set current state to game over
			
			
			
			
            return;
         }
      }

      //reset to the first click state

	  
	  
	start = -1;

   }
}