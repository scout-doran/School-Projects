import java.util.ArrayList;

public class WorstCDs implements Command
{
   private ArrayList<CD> worst = new ArrayList<CD>();
   private int worst_rating = 10;

   public void execute(Object item)
   {
      CD cd = (CD) item;
      int rating = cd.getRating();

      if (rating == worst_rating)
      {
         worst.add(cd);
      }
      else if (rating < worst_rating)
      {
         worst_rating = rating;
         worst = new ArrayList<CD>();
         worst.add(cd);
      }
   }

   public ArrayList<CD> getWorstCDs()
   {
      ArrayList<CD> temp = worst;
      worst = new ArrayList<CD>();
      worst_rating = 10;
      return temp;
   }
}