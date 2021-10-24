import java.awt.Graphics;
import java.awt.Image;

public class Peg
{
   private static Image[] pegImages = {ImageLoader.getImageLoader().getImage("images/red_peg.gif"), ImageLoader.getImageLoader().getImage("images/magenta_peg.gif"), ImageLoader.getImageLoader().getImage("images/green_peg.gif")};
   private static int[] pegCoords = {266, 86, 220, 162, 313, 162, 178, 235, 266, 235, 359, 235, 127, 313, 220, 313, 313, 313, 407, 313, 90, 387, 178, 387, 266, 387, 359, 387, 444, 387};

   private static int x_offset = 17;  //image offsets to find upper left corner of image from image center (images are 34 x 24)
   private static int y_offset = 17;

   private int loc;  //remember where this peg is located on the board (-1 if removed)
   private Image pegImage;
   private int peg_id;

   public Peg(int loc)  
   {
      this.loc = loc;
      peg_id = loc;
      pegImage = pegImages[0];  
   }

   public void setImage(int img)
   {
      pegImage = pegImages[img];
   }

   //use the peg's current location for this test
   public boolean isPegClicked(int x, int y)
   {
      if (loc == -1) return false;

      final int TOL = 10;  //radius of 10 pixels is the hot spot for the pegs
      int x_center = pegCoords[2*(loc - 1)];
      int y_center = pegCoords[2*(loc - 1) + 1];

      boolean x_test = Math.abs(x_center - x) <= TOL;
      boolean y_test = Math.abs(y_center - y) <= TOL;

      return x_test && y_test;
   }

   //to determine if an empty slot has been selected, use the fixed
   //slot locations (peg_id instead of loc)
   public boolean isSlotClicked(int x, int y)
   {
      final int TOL = 10;  //radius of 10 pixels is the hot spot for the pegs
      int x_center = pegCoords[2*(peg_id - 1)];
      int y_center = pegCoords[2*(peg_id - 1) + 1];

      boolean x_test = Math.abs(x_center - x) <= TOL;
      boolean y_test = Math.abs(y_center - y) <= TOL;

      return x_test && y_test;
   }

   public int getLocation()
   {
      return loc;
   }

   public void setLocation(int new_loc)
   {
      loc = new_loc;
   }

   public void draw(Graphics g)
   {
      if (loc == -1) return;  //removed from peg board

      int x_upper_left = pegCoords[2*(loc - 1)] - x_offset;
      int y_upper_left = pegCoords[2*(loc - 1) + 1] - y_offset;

      g.drawImage(pegImage, x_upper_left, y_upper_left, null);
   }
}