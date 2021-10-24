import java.util.ArrayList;

public class Jump
{
   private int start;
   private int middle;
   private int end;

   public Jump(int start, int middle, int end)
   {
      this.start = start;
      this.middle = middle;
      this.end = end;
   }

   public int getStart()
   {
      return start;
   }

   public int getEnd()
   {
      return end;
   }

   public boolean isValidJump(Pegs pegs)
   {
      Peg jump_peg = pegs.getPeg(start);
      if (jump_peg == null) return false;   //must be occupied

      Peg under_peg = pegs.getPeg(middle);
      if (under_peg == null) return false;  //must be occupied

      Peg land_peg = pegs.getPeg(end);
      if (land_peg != null) return false;   //must be open

      return true;
   }

   public boolean jump(Pegs pegs)
   {
      if (!isValidJump(pegs)) return false;

      Peg jump_peg = pegs.getPeg(start);    //jump to the new board location
      jump_peg.setLocation(end);

      Peg under_peg = pegs.getPeg(middle);  //remove from board
      under_peg.setLocation(-1);

      return true;
   }
}