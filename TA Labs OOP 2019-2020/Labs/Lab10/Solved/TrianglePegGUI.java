import java.awt.BorderLayout;

public class TrianglePegGUI extends CenterFrame
{
   public TrianglePegGUI(int width, int height, Drawable d)
   {      
      super (width, height, "Triangle Peg Game");

      setLayout(new BorderLayout());
      setSize(width, height);
      setResizable(false);

      DrawPanel draw = new DrawPanel();

      draw.setDrawable(d);  //the MaharajaGame is registered with the Draw panel
      add(draw, BorderLayout.CENTER);

      setVisible(true);
   }
}