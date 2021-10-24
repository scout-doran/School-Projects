
public class CrapsDice
{
   private SingleDie d1;
   private SingleDie d2;

   public CrapsDice()
   {
      d1 = new SingleDie(6);
      d2 = new SingleDie(6);
   }

   public int roll()
   {
      return d1.roll() + d2.roll();
   }
}