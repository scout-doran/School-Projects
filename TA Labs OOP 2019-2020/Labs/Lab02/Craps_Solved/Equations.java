import matrix.*;

public class Equations
{

   public static void main(String[] args)
   {
/*
      MatrixOperationsInterface A = MatrixCreator.create(3, 3);
      A.setElement(1, 1, 1.6);
      A.setElement(1, 2, 2.4);
      A.setElement(1, 3, -3.7);
      A.setElement(2, 1, 17.6);
      A.setElement(2, 2, -5.6);
      A.setElement(2, 3, 0.05);
      A.setElement(3, 1, -2);
      A.setElement(3, 2, 2);
      A.setElement(3, 3, 25.3);

      MatrixOperationsInterface x = MatrixCreator.create(3, 1);
      x.setElement(1, 1, 1);
      x.setElement(2, 1, 4);
      x.setElement(3, 1, 9);

      MatrixOperationsInterface b = A.multiply(x);
      System.out.println(b);
*/
		
      MatrixOperationsInterface A = MatrixCreator.create(3, 3);
      A.setElement(1, 1, 1.6);
      A.setElement(1, 2, 2.4);
      A.setElement(1, 3, -3.7);
      A.setElement(2, 1, 17.6);
      A.setElement(2, 2, -5.6);
      A.setElement(2, 3, 0.05);
      A.setElement(3, 1, -2);
      A.setElement(3, 2, 2);
      A.setElement(3, 3, 25.3);

      MatrixOperationsInterface b = MatrixCreator.create(3, 1);
      b.setElement(1, 1, -22.10);
      b.setElement(2, 1, -4.35);
      b.setElement(3, 1, 233.70);

      MatrixOperationsInterface Ainv = A.inverse();
      MatrixOperationsInterface x = Ainv.multiply(b);

      System.out.println(x);
   }

}