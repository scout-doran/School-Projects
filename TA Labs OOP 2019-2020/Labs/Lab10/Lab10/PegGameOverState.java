
public class PegGameOverState implements PegState
{
   private Pegs pegs;

   public PegGameOverState(Pegs pegs)
   {
 	   //update pegs 
	   
   }

   public void mouseClicked(int x, int y)
   {
	  //find which slot was selected 
      int select =  
      if (select == -1)
      {
		  //find which peg was selected
         select = 
      }

      if (select > -1)
      {
       //reset the game to the first click state:
	   //start the game with the selected peg
	   //get the first click state
	   //and then make it your current state
	 

	 
      }
   }
}