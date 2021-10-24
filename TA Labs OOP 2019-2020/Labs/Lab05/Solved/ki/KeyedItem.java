package ki;

public abstract class KeyedItem
{
	/*Comparable interface is used to order 
	  the objects of the user-defined class. 
	  This interface is found in java.lang package 
	  and contains only one method named compareTo(Object). 
	  It provides a single sorting sequence only, 
	  i.e., you can sort the elements on the basis
	  of single data member only.**/
   private Comparable searchKey;
  
   public KeyedItem(Comparable key) 
   {
      searchKey = key;
   }  

   public Comparable getKey() 
   {
      return searchKey;
   }  

   public String toString()
   {
      return searchKey.toString();
   }
}