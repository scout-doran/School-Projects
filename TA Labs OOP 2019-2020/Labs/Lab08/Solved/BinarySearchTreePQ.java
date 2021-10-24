
public class BinarySearchTreePQ extends BinarySearchTree
{ 
   private final boolean duplicates;
   private final boolean direction;

   public BinarySearchTreePQ(boolean dupes, boolean dir)
   {
      super();
      duplicates = dupes;
      direction = dir;
   }

   protected TreeNode insertDuplicate(TreeNode tNode, KeyedItem item)
   {
      if (!duplicates)
      {
         throw new TreeException ("Cannot add duplicate.");
      }
      else
      {
         //duplicates are allowed, but which direction do we go to insert them?
         if (!direction)  //dir=false, go left to insert duplicates
         {
            tNode = insertLeft(tNode, item);
         }
         else  //go right to insert duplicates (stable)
         {
            tNode = insertRight(tNode, item);
         }
      }

      return tNode;
   }
} 