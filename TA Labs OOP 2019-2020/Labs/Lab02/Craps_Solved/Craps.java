public class Craps
{

   public static int playCraps(int num_rolls)
   {
      int count = 0;
      int craps = 0;
      CrapsDice cd = new CrapsDice(); //Create an instance of CrapsDice (To get access to method called roll in class CrapsDice)
      while (count < num_rolls) 
      {
         int result = cd.roll();
         if (result == 2 || result == 3 || result == 12)
         {
            craps++;
         }
         count++;
      }
      return craps;
   }

   public static void main(String[] args)
   {
      int num_rolls = 752;
      int count = playCraps(num_rolls);
      System.out.println( "" + ((double) count/num_rolls * 100) + "%"); // find percentage
   }

}