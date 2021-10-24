import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class BlackJackGUI extends CenterFrame
{
   public BlackJackGUI(int width, int height, Drawable d)
   {      
      super (width, height, "Black Jack!");

      setLayout(new BorderLayout());
      setSize(width, height);
      setResizable(false);

      DrawPanel draw = new DrawPanel();  
      //the BlackJackGame is registered with the Draw panel
      draw.setDrawable(d);

      add(draw, BorderLayout.CENTER);
   }
}
