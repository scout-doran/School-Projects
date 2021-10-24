import java.util.Iterator;
import bst.*;
import ki.KeyedItem;

public class TreeSort
{
   //convenience method
   public static KeyedItem[] treeSort(KeyedItem[] sort)
   {
      int n = sort.length;
      return treeSort(sort, n);
   }

   public static KeyedItem[] treeSort(KeyedItem[] sort, int n)
   {
      //easier to use a KeyedItem array than Comparable
      if (n > sort.length || n <= 0)
      {
         n = sort.length;
      }

      //a balanced tree ensures logn inserts for nlogn sort
      BinarySearchTree tree = new BinarySearchTree(true, true);  //allow duplicates and put duplicates on the right for FIFO order

      //need to use the Class class as the actual array type may be a subtype of KeyedItem
      Class cls = sort.getClass().getComponentType();
      KeyedItem[] temp = (KeyedItem[]) java.lang.reflect.Array.newInstance(cls, n);
 
      // fill up the search tree
      for (int i = 0; i < n; i++)
      {
         tree.insert(sort[i]); 
      }

      TreeIterator iter = tree.iterator();
      iter.setInorder();

      int i = 0;  //pull sorted stuff out of the tree
      while(iter.hasNext())
      {
         temp[i] = (KeyedItem) iter.next(); //make sure to cast as a keyedItem
         i++;
      }
    
      return temp;
   }
}
