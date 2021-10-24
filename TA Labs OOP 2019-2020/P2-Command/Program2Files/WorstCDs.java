import java.util.ArrayList;

public class WorstCDs implements Command
{
   private ArrayList<CD> worst = new ArrayList<CD>();
   private int worst_rating = 10;

   public void execute(Object item)
   {
      CD cd = (CD) item;
      int rating = 

      if (rating == worst_rating)
      {
        //add the cd to the worst ArrayList
		
		
      }
      else if (rating < worst_rating)
      {
         //update worst_rating, instantiate worst to a new ArrayList, and then add the cd
		 
		 
		 
      }
   }

   public ArrayList<CD> getWorstCDs()
   {
      
	  
	  
	  
   }
}