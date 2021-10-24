import java.util.ArrayList;
import java.util.Iterator;

public class AVLDriver
{

   public static void main(String[] args)
   {
      SearchTreeInterface bst = new AVLTree();  
      CD[] cds_array = readMusic("cds.txt");

      for (int i = 0; i < cds_array.length; i++)
      {
            bst.insert(cds_array[i]);
      }
	  
	  System.out.println("");
	  System.out.println("Best CDs: ");
      Command best = new BestCDs();
      Execute ex = (Execute) bst;
      ex.execute(best);
      ArrayList<CD> cds = ((BestCDs) best).getBestCDs();
      for (CD cd : cds)
      {
         System.out.println(cd);
      }
	  
	  
	  //test WorstCDs & LongestSong
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
/*
      for (int i = 0; i < cds_array.length; i++)
      {
            bst.delete(cds_array[i].getKey());
      }
*/
   }

   private static CD[] readMusic(String fileName)
   {
      FileIO file = new FileIO(fileName, FileIO.FOR_READING);
      String str = file.readLine();
      ArrayList<CD> cds = new ArrayList<CD>();
      while (!file.EOF())
      {
         String title = file.readLine();
         int year = Integer.parseInt(file.readLine());
         int rating = Integer.parseInt(file.readLine());
         int numTracks = Integer.parseInt(file.readLine());
         CD cd = new CD(title, str, year, rating, numTracks);

         cds.add(cd);
         int tracks = 1;

         while (tracks <= numTracks)
         {
            String temp = file.readLine();
            String[] line = temp.split(",");
            String len = line[0];
            String songTitle = line[1];
            cd.addSong(songTitle, len);
            tracks++;
         }

         str = file.readLine();
      }

      CD[] cds_array = new CD[cds.size()];
      int i = 0;
      for(CD cd : cds)
      {
         cds_array[i] = cds.get(i);
         i++;
      }
      return cds_array;
   }
}
