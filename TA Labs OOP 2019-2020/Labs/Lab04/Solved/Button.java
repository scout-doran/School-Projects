import java.awt.Graphics;
import java.awt.Image;

public class Button
{
   private Image buttonImage;
   private int x_loc;
   private int y_loc;
   private int x_offset;
   private int y_offset;
   private int button_id;
   private boolean highlight;  //yellow button image is only drawn when that button is the optimal move
   private boolean enabled;
   private int tol;

   public Button(int button_id, int x_loc, int y_loc, Image buttonImage, int x_offset, int y_offset, int tol)  
   {
      this.button_id = button_id;

      this.x_loc = x_loc;
      this.y_loc = y_loc;

      this.buttonImage = buttonImage;

      this.x_offset = x_offset;
      this.y_offset = y_offset;
      this.tol = tol;

      highlight = false;
      enabled = false;
   }

   public boolean isButtonClicked(int x, int y)
   {
      if (!enabled) return false;

      int index = button_id - 1;
      int x_click = x_loc;
      int y_click = y_loc;

      boolean x_test = Math.abs(x_click - x) <= tol;
      boolean y_test = Math.abs(y_click - y) <= tol;

      return x_test && y_test;
   }
   
   public int getButtonID()
   {
      return button_id;
   }

   public void setHighLight(boolean highlight)
   {
      this.highlight = highlight;
   }

   public void setEnabled(boolean enabled)
   {
      this.enabled = enabled;
   }

   public void draw(Graphics g)
   {
      if (highlight)
      {
         int x_upper_left = x_loc - x_offset;
         int y_upper_left = y_loc - y_offset;

         g.drawImage(buttonImage, x_upper_left, y_upper_left, null);
      }
   }
}
