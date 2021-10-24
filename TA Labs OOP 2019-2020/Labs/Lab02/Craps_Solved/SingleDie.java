import java.util.Random;

public class SingleDie
{
   private static Random rand = new Random();
   private int numSides;

   public SingleDie()
   {
      numSides = 6;
   }

   public SingleDie(int ns)
   {
      numSides = ns;
   }

   public int roll()
   {
      int roll = rand.nextInt(numSides) + 1;
      return roll;
   }
}