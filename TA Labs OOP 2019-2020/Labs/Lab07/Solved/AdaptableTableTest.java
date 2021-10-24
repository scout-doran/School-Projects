import java.util.ArrayList;
import java.util.Iterator;

public class AdaptableTableTest
{

   public static void main(String[] args)
   {
      TableInterface ht = new TableSTBased();  
      CD[] cds = readMusic("cds.txt");

      for (int i = 0; i < cds.length; i++)
      {
         try
         {
            ht.tableInsert(cds[i]);
         }
         catch(TableException te)
         {
            System.out.println(te.getMessage());
         }
      }

      System.out.println(ht.tableRetrieve("Leading Vision"));
      displayTable(ht);
	  /*
      System.out.println(ht.tableRetrieve("The Dying Wonders of The World"));
      //displayTable(ht);
      System.out.println(ht.tableDelete("The Apostasy"));
      displayTable(ht);
      System.out.println(ht.tableDelete("Shadows In The Light"));
      //displayTable(ht);
      System.out.println(ht.tableRetrieve("At Dusk And Forever"));
      displayTable(ht);
      System.out.println(ht.tableRetrieve("A Sylphe's Ascension"));
      //displayTable(ht);
      System.out.println(ht.tableDelete("Mirrorworlds"));
      displayTable(ht);
      System.out.println(ht.tableRetrieve("Portals To Uphobia"));
      displayTable(ht);
      System.out.println(ht.tableRetrieve("Swampsong"));
      System.out.println();
      System.out.println("Swampsong should be the root.");
      displayTable(ht);
      System.out.println(ht.tableRetrieve("From Your Grave"));
      displayTable(ht);
      System.out.println(ht.tableDelete("Serenity in Fire"));
      //displayTable(ht);
      System.out.println(ht.tableRetrieve("Haven"));
      displayTable(ht);
      System.out.println(ht.tableRetrieve("Spirits And August Light"));
      //displayTable(ht);
      System.out.println(ht.tableDelete("Shadows In The Light"));
      displayTable(ht);
*/
      for (int i = 0; i < cds.length; i++)
      {
         System.out.println(ht.tableDelete(cds[i].getKey()));
         System.out.println(ht.tableSize());
      }

      System.out.println();
      System.out.println();
      displayTable(ht);
      System.out.println(ht.tableSize());
   }

   public static void displayTable(TableInterface ti)
   {
      Iterator iter = ti.iterator();
      while(iter.hasNext())
      {
         System.out.println(iter.next());
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
