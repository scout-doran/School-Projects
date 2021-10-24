import java.awt.*;
import java.awt.image.*;

public class TransparencyFilter extends RGBImageFilter
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