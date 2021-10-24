import ki.KeyedItem;
import java.util.ArrayList;

public class CD extends KeyedItem<Integer>
{
   private String title;
   private String img;
   private ArrayList<Song> songs;
   private int numTracks;  //used by addSong
   private int rating;

   public CD (String title, String artist, int year, int rating, int tracks)
   {
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

