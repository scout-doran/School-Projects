import java.awt.*;
import java.awt.image.*;
import javax.imageio.*;
import java.io.*;

class ImageLoader
{
   private static ImageLoader il = new ImageLoader();
   private Toolkit toolkit;

   //singleton design pattern hides the constructor
   private ImageLoader() 
   {
      toolkit = Toolkit.getDefaultToolkit();
   }

   //the only way to get at the singleton reference
   public static ImageLoader getImageLoader()
   {
      return il;
   }
   
   public Image getImage(String file)
   {
      int len = file.length();
      Image img = null;   

      try
      {
         BufferedImage bi = ImageIO.read(getClass().getResource(file));
         img = toolkit.createImage(bi.getSource());

         if (file.charAt(len - 1) == 'f')  //gifs only
         {
            img = highlightImage(img);
         }
      } 
      catch (IOException e){}
      
      return img;
   }

   public Image highlightImage(Image src)
   {
      ImageFilter filter = getFilter();
      FilteredImageSource fis = new FilteredImageSource(src.getSource(), filter);
      return toolkit.createImage(fis);
   }

   public ImageFilter getFilter()
   {
      return new TransparencyFilter(Color.WHITE);  //specify the desired filter
   }
}

class TransparencyFilter extends RGBImageFilter
{
    // the color we are looking for... Alpha bits are set to opaque
    public int markerRGB;
 
    public TransparencyFilter(Color color)  //the transparent color
    {
       markerRGB = (color.getRGB() | 0xFF000000);
    }

    public int filterRGB(int x, int y, int rgb) 
    {
        if ((rgb | 0xFF000000) == markerRGB) 
        {
           // Mark the alpha bits as zero - transparent
           return 0x00FFFFFF & rgb;
        }
        else 
        {
           // nothing to do
           return rgb;
        }
    }
}
