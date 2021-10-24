import java.util.ArrayList;

public class PegGameAI
{
   private static PegGameAI pgai = new PegGameAI();
   private static int[] jump_ids = {1, 2, 4, 1, 3, 6, 2, 4, 7, 2, 5, 9, 3, 6, 10, 3, 5, 8, 4, 7, 11, 4, 8, 13, 4, 2, 1, 4, 5, 6, 5, 9, 14, 5, 8, 12, 6, 3, 1, 6, 10, 15, 6, 9, 13, 6, 5, 4, 7, 4, 2, 7, 8, 9, 8, 5, 3, 8, 9, 10, 9, 5, 2, 9, 8, 7, 10, 6, 3, 10, 9, 8, 11, 7, 4, 11, 12, 13, 12, 8, 5, 12, 13, 14, 13, 12, 11, 13, 9, 6, 13, 8, 4, 13, 14, 15, 14, 13, 12, 14, 9, 5, 15, 10, 6, 15, 14, 13};

   private PegGameAI()
   {}

   public static PegGameAI getPegGameAI()
   {
      return pgai;
   }

   public int getBestMove(ArrayList<Peg> board)
   {
      int[] pegs = new int[15];
      for (Peg peg : board)
      {
         int loc = peg.getLocation();
         if (loc > 0)
         {
            pegs[loc - 1] = 1;
         }
      }

      int depth = 1;
      int select = recGetBestMove(pegs, depth);
      return select;
   }

   public int recGetBestMove(int[] pegs, int depth)
   {
      //are there any more valid jumps?
      int num_jumps = countValidJumps(pegs);
      if (num_jumps == 0) 
      {
         int remaining_pegs = countPegs(pegs);
         return remaining_pegs;  //should be one for an optimal solution
      }

      //look at all possible jumps
      int least_pegs = 100;
      int best_move = -1;
      for (int i = 1; i <= 36; i++)
      {
         if (least_pegs == 1) break;  //no point in searching further

         if (validJump(i, pegs))
         {
            int[] copy = copyPegs(pegs);
            jump(i, copy);
            int current_pegs = recGetBestMove(copy, depth + 1);
            if (current_pegs < least_pegs) 
            {
               least_pegs = current_pegs;
               best_move = jump_ids[3*(i - 1)];
            }
         }
      }

      if (depth == 1)
      {
         return best_move;
      }
      else
      {
         return least_pegs;
      }
   }

   public int countPegs(int[] pegs)
   {
      int count = 0;
      for (int i = 1; i <= 15; i++)
      {
         if (pegs[i - 1] == 1)
         {
            count++;
         }
      }
      return count;
   }

   public int countValidJumps(int[] pegs)
   {
      int count = 0;
      for (int i = 1; i <= 36; i++)
      {
         if (validJump(i, pegs))
         {
            count++;
         }
      }
      return count;
   }

   public void jump(int jump_id, int[] pegs)
   {
      int i = 3*(jump_id - 1);
      int start = jump_ids[i];
      int middle = jump_ids[i + 1];
      int end = jump_ids[i + 2];

      pegs[start - 1] = 0;
      pegs[middle - 1] = 0;
      pegs[end - 1] = 1;
   }

   public boolean validJump(int jump_id, int[] pegs)  //jump ids run from 1 to 36
   {
      int i = 3*(jump_id - 1);
      int start = jump_ids[i];
      int middle = jump_ids[i + 1];
      int end = jump_ids[i + 2];

      if (pegs[start - 1] == 0) return false;
      if (pegs[middle - 1] == 0) return false;
      if (pegs[end - 1] == 1) return false;

      return true;
   }

   public int[] copyPegs(int[] pegs)
   {
      int[] copy = new int[15];
      for (int i = 1; i <= 15; i++)
      {
         copy[i - 1] = pegs[i - 1];
      }
      return copy;
   }
}