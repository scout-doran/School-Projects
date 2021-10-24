
public class PegGameOverState implements PegState
{
   private Pegs pegs;

   public PegGameOverState(Pegs pegs)
   {
      this.pegs = pegs;
   }

   public void mouseClicked(int x, int y)
   {
      int select = pegs.findSelectedSlot(x, y);  
      if (select == -1)
      {
         select = pegs.findSelectedPeg(x, y);
      }

      if (select > -1)
      {
         pegs.startGame(select);
         PegState first = pegs.getFirstClickState();
         pegs.setCurrentState(first);
      }
   }
}