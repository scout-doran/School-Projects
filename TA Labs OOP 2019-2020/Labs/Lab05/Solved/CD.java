import ki.KeyedItem;
import java.util.ArrayList;

public class CD extends KeyedItem
{
   private String title;
   private String img;
   private ArrayList<Song> songs;
   private int numTracks;  //used by addSong
   private int rating;

   public CD (String title, String artist, int year, int rating, int tracks)
   {
	  //complete the constructor with respect to extending KeyedItem
	  //(use the primitive wrapper class for integers, the Integer class)
	  //super can be used to refer immediate parent class of an instance variable
	  /*Integer class for the primitive type int which 
	    contains several methods to effectively deal with a int value like 
		converting it to a string representation, and vice-versa. An object 
		of Integer class can hold a single int value.*/
      super(new Integer(year));
	  

      this.title = title;
      img = artist + " - " + title + ".jpg";
      numTracks = tracks;
      songs = new ArrayList<Song>();

      if (rating > 0 && rating <= 10)
      {
         this.rating = rating;
      }
      else
      {
         this.rating = 5;
      }
   }

   //Song is immutable, so this is safe
   public Song getSong(int index)
   {
      if (index >= 0 && index < songs.size())
      {
         return songs.get(index);
      }
      else
      {
         return null;
      }
   }

   public void addSong(String title, String length)
   {
      if (songs.size() < numTracks)
      {
         songs.add(new Song(title, length));
      }
   }
   
   //NO WORK BELOW
   
   public int getNumberOfTracks()
   {
      return songs.size();
   }

   public String getTitle()
   {
      return title;
   }

   public int getRating()
   {
      return rating;
   }


   public String toString()
   {
      return title + "  " + getKey() + "  " + rating + "  " + getNumberOfTracks();
   }

   public void writeCD(FileIO file)
   {
      if (rating == 10)
      {
         file.writeLine("         <li>" + "<b>" + title + "</b>" + "</li>");
      }
      else
      {
         file.writeLine("         <li>" + title + "</li>");
      }

      file.writeLine("         <center><img src = \"art\\" + img + "\"></center>");
      file.writeLine("         <ul>");
      file.writeLine("            <li>Year: " + getKey() + "</li>");
      file.writeLine("            <li>Rating: " + rating + "</li>");
      file.writeLine("            <li>Tracks:</li>");

      file.writeLine("<table border = 0>");
      file.writeLine("<tr><td>Track&nbsp;&nbsp;&nbsp;</td><td>Title</td><td>Length&nbsp;&nbsp;</td></tr>");
      int count = 0;
      for (Song song : songs)
      {
         file.writeLine("<tr>");
         song.writeSong(file, ++count);
         file.writeLine("</tr>");
      }
      file.writeLine("</table>");

      file.writeLine("         </ul>");
   }
}
