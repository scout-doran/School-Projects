import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class AVLTest
{

   public static void main(String[] args)
   {
      SearchTreeInterface bst = new AVLTree();  
      CD[] cds_array = readMusic("cds.txt");

      for (int i = 0; i < cds_array.length; i++)
      {
            bst.insert(cds_array[i]);
      }

      Command worst = new WorstCDs();
      Execute ex = (Execute) bst;
      ex.execute(worst);
      List<CD> cds = ((WorstCDs) worst).getWorstCDs();
      for (CD cd : cds)
      {
         System.out.println(cd);
      }

      Command longest = new LongestSong();
      ex.execute(longest);
      Song song = ((LongestSong) longest).getLongestSong();
      System.out.println(song.getTitle() + " " + song.getLength());
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
