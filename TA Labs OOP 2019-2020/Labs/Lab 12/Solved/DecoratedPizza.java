import java.awt.Graphics;
import java.awt.Image;

/*
 *  The purpose of this class is to allow pizzas with any number and combination of 
 *  toppings to have a common type, DecoratedPizza (polymorphism).
 *  This allows the addition of new toppings to the menu to be greatly simplified (Decorater design pattern).
 *  Individual toppings (and the base pizza) extend this class.  
 *  Using the inherited DecoratedPizza instance variable, the toppings should form a linked list, with
 *  a "base" Pizza object terminating the linked list.
 */
public abstract class DecoratedPizza implements Drawable
{
   private static final ImageLoader il = ImageLoader.getImageLoader();

   /*
    *  A reference to the next DecoratedPizza (base pizza or topping) in the linked list.  
    *  For the base pizza, this reference will be null.
    */
   private DecoratedPizza pizza;  

   /* The base Pizza object will use this constructor, as the base pizza is the end of the linked DecoratedPizzas. */
   public DecoratedPizza()
   {
      pizza = null;
   }

   /* Toppings will use this constructor, creating the linked list of DecoratedPizzas. */
   public DecoratedPizza(DecoratedPizza pizza)
   {
      this.pizza = pizza;
   }

   /* Child classes will need access to their reference (the next DecoratedPizza in the linked list). */
   protected DecoratedPizza getPizza()
   {
      return pizza;
   }

   /* 
    *  The cost of the pizza (toppings call this method on their DecoratedPizza reference and add
    *  their own cost to the result).
    */
   public abstract double pizzaCost();
   public abstract String getImage();
	
   public void draw(Graphics g, int width, int height)
   {
      String imageFile = "images/" + getImage() + ".jpg";
	  System.out.println(imageFile);
      Image image = il.getImage(imageFile);
      g.drawImage(image, 0, 0, null);
   }
}