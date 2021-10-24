
public class AdaptableBinarySearchTree extends BinarySearchTree
{

   public AdaptableBinarySearchTree() 
   {
      super();
   } 

   public KeyedItem retrieve(Comparable searchKey) 
   {
      //return retrieveItem(getRootNode(), searchKey);
      try
      {
         setRootNode(retrieveItemAdapt(getRootNode(), searchKey));
         return (KeyedItem) getRootNode().getItem();
      } 
      catch (TreeException te) 
      {
         return null;
      }
   }   

   protected TreeNode retrieveItemAdapt(TreeNode tNode, Comparable searchKey)
   {
      KeyedItem treeItem;
      TreeNode subtree;

      if (tNode == null) 
      {
         //treeItem = null;
         throw new TreeException("Item not found.");
      }
      else 
      {
         KeyedItem nodeItem = (KeyedItem) tNode.getItem();
         int comparison = searchKey.compareTo(nodeItem.getKey());

         if (comparison == 0) 
         {
            // item is in the root of some subtree
            // this item will be moved up one level each time it is retrieved
            // the principal of temporal (spatial?) locality of data (retrieved once, likely to be retrieved again)
            //treeItem = nodeItem;
            return tNode;
         }
         else if (comparison < 0) 
         {
            // search the left subtree
            subtree = retrieveItemAdapt(tNode.getLeft(), searchKey);
            tNode.setLeft(subtree);
            tNode = rotateRight(tNode);
         }
         else  
         { 
            // search the right subtree
            subtree = retrieveItemAdapt(tNode.getRight(), searchKey);
            tNode.setRight(subtree);
            tNode = rotateLeft(tNode);
         }  
      }  

      return tNode; 
   }     

} 
