import java.util.ArrayList;

public class TreeSortDriver
{

   private static CD[] readMusic(String fileName)
   {
      //DO THIS complete this method using the FileIO class
	  //create a new FileIO object for reading
      FileIO file = 
      String str = 
      ArrayList<CD> cds = new ArrayList<CD>();

      while (              ) //while we are not at the end of the file
      {
		 //file.readLine() will parse one line of the file at a time
         String title = 
         int year = Integer.parseInt(            );
         int rating = Integer.parseInt(          );
         int numTracks = Integer.parseInt(         );
         CD cd = new CD(title, str, year, rating, numTracks);

         cds.add(cd);
         int tracks = 1;

         while (tracks <= numTracks)
         {
            String track_str = 
            String[] pieces =     //divide the string up into two pieces by splitting on a comma (use the String split method)
            String len = pieces[0];
            String songTitle = pieces[1];
            cd.addSong(songTitle, len);
            tracks++;
         }

         str = 
      }


      //create a CD[] of the correct size (cds.size()) and populate it using a for-each statement
      CD[] cds_array = 






      return cds_array;
   }
   
   public static void main (String[] args)
   {
      //use the Keyboard class, try-catch, and a while loop to continue calling readMusic 
      //until a valid file name is entered
      //as checked exceptions have been converted to unchecked exceptions, 
      //you must remember to do this with end user input, the compiler will not help you







      //once you have the array of CDs back from readMusic, sort them
      //and print them out to make sure that they are sorted




   }
}