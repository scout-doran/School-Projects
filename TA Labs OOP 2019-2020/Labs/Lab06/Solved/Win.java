import java.awt.Graphics;
import java.awt.Color;
import java.awt.Font;
import java.awt.Image;

public class Win extends ModalDialog
{
   private Image backgroundImage;
   private Guess secret;

   public Win(Guess secret)  //the guess_id for secret should be 1 for correct drawing in the dialog box
   {      
      super(276, 175, "Won!");
      backgroundImage = ImageLoader.getImageLoader().getImage("images/dialog_back.jpg");
      this.secret = secret;
      setVisible(true);
   }

   public void draw(Graphics g, int width, int height)
   {
     g.setColor(Color.black);
     g.drawImage(backgroundImage, 0, 0, null);

     Font verdana_25 = new Font("Verdana", Font.BOLD, 25);
     g.setFont(verdana_25);
     g.drawString("You Won!", 65, 110);
     secret.draw(g);
   }
}