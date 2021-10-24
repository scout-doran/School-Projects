import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public abstract class ModalDialog extends JDialog implements Drawable, ActionListener
{

   public ModalDialog(int width, int height, String str)
   {      
      super();
      setModal(true);
      setTitle(str);
      setResizable(false);

      setLayout(new BorderLayout());
      center(width, height);

      DrawPanel draw = new DrawPanel();
      draw.setDrawable(this);

      add(draw, BorderLayout.CENTER);

      JButton btn = new JButton("OK");
      add(btn, BorderLayout.SOUTH);
      btn.addActionListener(this);
      btn.setBackground(Color.white);

      setDefaultCloseOperation(DISPOSE_ON_CLOSE);
   }

   public void actionPerformed(ActionEvent ae)
   {
      dispose();
   }

   private void center(int width, int height)
   {
      setSize(width, height);

      //center the window
      Dimension screenSize = getToolkit().getScreenSize();
      int screenWidth = screenSize.width;
      int screenHeight = screenSize.height;
      setLocation(screenWidth/2 - width/2, screenHeight/2 - height/2);
   }

   public abstract void draw(Graphics g, int width, int height);
   public void mouseClicked(int x, int y){}  //this window doesn't repsond to mouse clicks
   public void keyPressed(char key){}

}