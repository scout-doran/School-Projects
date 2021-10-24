import java.awt.Graphics;

public class TrianglePegSolitaire implements Drawable
{
   private Pegs pegs;
   private Board board;

   //entry point
   public static void main(String[] args)
   {
      SimpleDialogs.useSystemStyle();
      TrianglePegSolitaire tpj = new TrianglePegSolitaire();
   }

   public TrianglePegSolitaire()
   {
      pegs = new Pegs(13);  //the open location is passed to the constructor
      board = new Board();

      TrianglePegGUI tpgui = new TrianglePegGUI(535, 463, this);
      tpgui.setVisible(true);
   }

   public void draw(Graphics g, int width, int height)
   {
      board.draw(g);
      pegs.draw(g);
   }

   public void mouseClicked(int x, int y) 
   {
      pegs.mouseClicked(x, y);
   }
}