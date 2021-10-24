import java.awt.BorderLayout;

public class MasterMindGUI extends CenterFrame
{
   public MasterMindGUI(int width, int height, Drawable d)
   {      
      super (width, height, "Master Mind");

      setLayout(new BorderLayout());
      setSize(width, height);
      setResizable(false);

      DrawPanel draw = new DrawPanel();
      draw.setDrawable(d);
      add(draw, BorderLayout.CENTER);

      setVisible(true);
   }
}