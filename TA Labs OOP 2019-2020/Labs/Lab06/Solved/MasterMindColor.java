import java.awt.Graphics;
import java.awt.Image;

public class MasterMindColor
{
   private static Image[] guessColorImages = {ImageLoader.getImageLoader().getImage("images/red_guess.jpg"), ImageLoader.getImageLoader().getImage("images/green_guess.jpg"), ImageLoader.getImageLoader().getImage("images/blue_guess.jpg"), ImageLoader.getImageLoader().getImage("images/purple_guess.jpg"),ImageLoader.getImageLoader().getImage("images/yellow_guess.jpg"), ImageLoader.getImageLoader().getImage("images/black_guess.jpg"), ImageLoader.getImageLoader().getImage("images/white_guess.jpg")};
   private static int[] guessColorHotSpots = {253, 583, 236, 564, 210, 561, 185, 570, 165, 588, 168, 615, 194, 623};

   private static int x_offset = 31;
   private static int y_offset = 31;

   private Image guessColorImage;
   private int x_loc;
   private int y_loc;
   private int guess_color_id;

   public String toString()
   {
      return "" + guess_color_id;
   }

   public MasterMindColor(int guess_color_id, int x_loc, int y_loc)  
   {
      this.guess_color_id = guess_color_id;
      this.x_loc = x_loc;
      this.y_loc = y_loc;

      guessColorImage = guessColorImages[guess_color_id - 1];
   }

   public static boolean isColorSelected(int guess_color_id, int x, int y)
   {
      final int TOL = 10;

      int index = guess_color_id - 1;
      int x_click = guessColorHotSpots[2*index];
      int y_click = guessColorHotSpots[2*index + 1];  

      boolean x_test = Math.abs(x_click - x) <= TOL;
      boolean y_test = Math.abs(y_click - y) <= TOL;

      return x_test && y_test;
   }
   
   public int getGuessColorID()
   {
      return guess_color_id;
   }

   public void draw(Graphics g)
   {
      int x_upper_left = x_loc - x_offset;
      int y_upper_left = y_loc - y_offset;

      g.drawImage(guessColorImage, x_upper_left, y_upper_left, null);
   }
}