import java.awt.Graphics;
import java.awt.Image;

public class Board
{
   private static Image boardImage = ImageLoader.getImageLoader().getImage("images/triangle_peg_board.jpg");

   public Board()  
   {
   }

   public void draw(Graphics g)
   {
      g.drawImage(boardImage, 0, 0, null);
   }
}