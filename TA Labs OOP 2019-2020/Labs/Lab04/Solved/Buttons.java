import java.awt.Graphics;
import java.awt.Image;
import java.util.ArrayList;

public class Buttons
{
   //pre-load highlight images
   private static Image[] buttonImages = {ImageLoader.getImageLoader().getImage("images/deal_yellow.jpg"), ImageLoader.getImageLoader().getImage("images/stand_yellow.jpg"), ImageLoader.getImageLoader().getImage("images/hit_yellow.jpg"), ImageLoader.getImageLoader().getImage("images/double_yellow.jpg"),ImageLoader.getImageLoader().getImage("images/split_yellow.jpg")};
   private static int[] buttonHotSpots = {43, 546, 134, 546, 225, 546, 317, 546, 409, 546};

   //all of the buttons are the same size
   private static int x_offset = 41;
   private static int y_offset = 16;
   private int tol = 20;

   private ArrayList<Button> buttons;

   public Buttons()  
   {
      buttons = new ArrayList<Button>();
      for (int i = 0; i <= 4; i++)
      {
         Button button = new Button(i + 1, buttonHotSpots[2*i], buttonHotSpots[2*i + 1], buttonImages[i], x_offset, y_offset, tol);
         buttons.add(button);
      }
   }

   public void disableDeal()
   {
      setHighLight(1, false);
      setEnabled(1, false);
   }

   public void resetEnabledsToTrue()
   {
      setEnabled(2, true);
      setEnabled(3, true);
      setEnabled(4, true);
   }

   public void setSplitEnabled(boolean enabled)
   {
      setEnabled(5, enabled);
   }

   public void noDoubleDown()
   {
      setEnabled(4, false);
   }

   public void highLight(char optimal)
   {
      if (optimal == 'S')
      {
         setHighLight(2, true);
      }

      else if (optimal == 'H')
      {
         setHighLight(3, true);
      }

      else if (optimal == 'D')
      {
         setHighLight(4, true);
      }

      else if (optimal == 'P')
      {
         setHighLight(5, true);
      }
   }

   public void resetColors()
   {
      setHighLight(1, false);  
      setHighLight(2, false);
      setHighLight(3, false);
      setHighLight(4, false);
      setHighLight(5, false);   
   }

   public void resetForNextGame()
   {
      setEnabled(1, true);  //deal is the only enabled button at this point
      setHighLight(1, true);
      setEnabled(2, false);
      setEnabled(3, false);
      setEnabled(4, false);
      setEnabled(5, false);
   }

   public int findButtonClicked(int x, int y)
   {
      int button_id = -1;
 
      for (Button button : buttons)
      {
         if (button.isButtonClicked(x, y))
         {
            button_id = button.getButtonID();
            break;
         }
      }

      return button_id;
   }

   public void setEnabled(int button_id, boolean enabled)
   {
      buttons.get(button_id - 1).setEnabled(enabled);
   }

   public void setHighLight(int button_id, boolean highlight)
   {
      buttons.get(button_id - 1).setHighLight(highlight);
   }

   public void draw(Graphics g)
   {
      for (Button button : buttons)
      {
         button.draw(g);
      }
   }
}
