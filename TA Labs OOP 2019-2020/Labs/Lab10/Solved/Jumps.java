import java.util.ArrayList;

public class Jumps
{

   private static int[] jump_ids = {1, 2, 4, 1, 3, 6, 2, 4, 7, 2, 5, 9, 3, 6, 10, 3, 5, 8, 4, 7, 11, 4, 8, 13, 4, 2, 1, 4, 5, 6, 5, 9, 14, 5, 8, 12, 6, 3, 1, 6, 10, 15, 6, 9, 13, 6, 5, 4, 7, 4, 2, 7, 8, 9, 8, 5, 3, 8, 9, 10, 9, 5, 2, 9, 8, 7, 10, 6, 3, 10, 9, 8, 11, 7, 4, 11, 12, 13, 12, 8, 5, 12, 13, 14, 13, 12, 11, 13, 9, 6, 13, 8, 4, 13, 14, 15, 14, 13, 12, 14, 9, 5, 15, 10, 6, 15, 14, 13};
   private ArrayList<Jump> jumps;
   private Pegs pegs;

   public Jumps(Pegs pegs)
   {
      this.pegs = pegs;
      jumps = new ArrayList<Jump>();

      for (int i = 0; i < 108; i+= 3)
      {
         Jump jump = new Jump(jump_ids[i], jump_ids[i + 1], jump_ids[i + 2]);
         jumps.add(jump);
      }
   }

   public ArrayList<Jump> getJumps(int start)
   {
      ArrayList<Jump> possible_jumps = new ArrayList<Jump>();

      for (Jump jump : jumps)
      {
         if (jump.getStart() == start && jump.isValidJump(pegs))
         {
            possible_jumps.add(jump);
         }
      }

      return possible_jumps;
   }

   public Jump getJumps(int start, int end)
   {
      for (Jump jump : jumps)
      {
         if (jump.getStart() == start && jump.getEnd() == end && jump.isValidJump(pegs))
         {
            return jump;
         }
      }

      return null;
   }

   public ArrayList<Jump> getValidJumps()
   {
      ArrayList<Jump> validJumps = new ArrayList<Jump>();
      for (Jump jump : jumps)
      {
         if (jump.isValidJump(pegs))
         {
            validJumps.add(jump);
         }
      }

      return validJumps;
   }
}