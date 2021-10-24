
public class Crust
{
   private char size;
   private CrustType crustType;  

   private static final double SMALLCOST = 5.99;
   private static final double MEDCOST = 7.99;
   private static final double LARGECOST = 9.99;

   public Crust(char size, CrustType crustType)
   {
      this.size = size;
      this.crustType = crustType;
   }

   public String getCrust()
   {
      return crustType.toString();
   }

   public char getSize()
   {
      return size;
   }

   public double pizzaCost()
   {
      double pizzaCost = 0;

      //calculate pizza cost based on size of pie
      switch (size)
      {
         case 'S':
            pizzaCost += SMALLCOST;
            break;
         case 'M':
            pizzaCost += MEDCOST;
            break;
         case 'L':
            pizzaCost += LARGECOST;
            break;
      }

      pizzaCost += crustType.cost();

      return pizzaCost;
   }

   public String toString()  //return the current pizza configuration
   {
      String pizzaConfig;
      pizzaConfig = "Size: " + size + "\r\nCrust: " + crustType.toString() + "\r\nToppings:\r\n";
      return pizzaConfig;
   }
}