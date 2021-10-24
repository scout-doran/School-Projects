import java.util.ArrayList;

public class BestCDs implements Command
{
   private ArrayList<CD> best = new ArrayList<CD>();

   public void execute(Object item)
   {
      CD cd = (CD) item;
      if (cd.getRating() == 10)
      {
         System.out.println(cd);
         best.add(cd);
      }
   }

   public ArrayList<CD> getBestCDs()
   {
      ArrayList<CD> temp = best;
      best = new ArrayList<CD>();
      return temp;
   }
}
