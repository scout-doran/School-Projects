import java.util.ArrayList;
import java.util.Iterator;

public class AVLTest
{

   public static void main(String[] args)
   {
      SearchTreeInterface avl = new AVLTree();  
      CD[] cds = readMusic("cds.txt");

      for (int i = 0; i < cds.length; i++)
      {
            avl.insert(cds[i]);
      }

      for (int i = 0; i < cds.length; i++)
      {
         System.out.println(avl.retrieve(cds[i].getKey()));

         try
         {
            avl.delete(cds[i].getKey());
         }
         catch(TreeException te)
         {
			System.out.println("not found");
         }
      }
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
