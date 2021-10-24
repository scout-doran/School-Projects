import java.awt.Graphics;
import java.awt.Image;

public class Button
{
   private static Image[] buttonImages = {ImageLoader.getImageLoader().getImage("images/black_button.gif"), ImageLoader.getImageLoader().getImage("images/white_button.gif")};

   private static int x_offset = 13;
   private static int y_offset = 13;

   private Image buttonImage;
   private int x_loc;
   private int y_loc;

   public Button(int button_id, int x_loc, int y_loc)  
   {
      this.x_loc = x_loc;
      this.y_loc = y_loc;

      buttonImage = buttonImages[button_id];
   }

   public void draw(Graphics g)
   {
      int x_upper_left = x_loc - x_offset;
      int y_upper_left = y_loc - y_offset;

      g.drawImage(buttonImage, x_upper_left, y_upper_left, null);
   }
}