import java.util.ArrayList;

public class TreeSortDriver
{

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
         cds_array[i] = cd;
         i++;
      }
      return cds_array;
   }

   public static void main (String[] args)
   {
	  //use the Keyboard class, try-catch, and a while loop to continue calling readMusic 
      //until a valid file name is entered
      //as checked exceptions have been converted to unchecked exceptions, 
      //you must remember to do this with end user input, the compiler will not help you

      Keyboard key = Keyboard.getKeyboard();
      String file_name = key.readString("Enter the file with the cd information: ");
      boolean valid_file = false;
      CD[] cds = null;

      while(!valid_file)
      {
         try
         {
            cds = readMusic(file_name);
            valid_file = true;
         }
         catch (FileIOException fioe)
         {
            System.out.println(fioe.getMessage());
            file_name = key.readString("Enter the file with the cd information: ");
         }
      }

	  //once you have the array of CDs back from readMusic, sort them
      //and print them out to make sure that they are sorted
      cds = (CD[]) TreeSort.treeSort(cds);  //without the Array class reflection, problem here

      for (CD cd : cds)
      {
         System.out.println(cd);
      }
   }
}