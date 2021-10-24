import java.util.Iterator;

public class TableSTBased implements TableInterface 
{
   private SearchTreeInterface st;  // binary search tree that contains the table’s items
   private int size;                // number of items in the table

   public TableSTBased() 
   {  
      st = new AdaptableBinarySearchTree();  //duplicates not allowed with this constructor
      size = 0;
   } 
  
   public boolean tableIsEmpty() 
   {
      return size == 0;
   }  
   
   public int tableSize() 
   {
      return size;
   }  

   public KeyedItem tableRetrieve(Comparable searchKey) 
   {
      return st.retrieve(searchKey);
   } 
  
   public void tableInsert(KeyedItem item) throws TableException 
   { 
      try
      {
         st.insert(item);
         size++;
      }
      catch(TreeException e)
      {
         throw new TableException("Insertion failed, duplicate key found.");
      }
   } 

   public boolean tableDelete(Comparable searchKey) 
   {
      try 
      {
         st.delete(searchKey);
         size--;
         return true;
      }  
      catch (TreeException e) 
      {
         return false;
      }  
   } 

   public Iterator iterator()
   {
      TreeIterator iter = st.iterator();
      iter.setLevelorder();
      //iter.setInorder();
      return iter;
   }
} 