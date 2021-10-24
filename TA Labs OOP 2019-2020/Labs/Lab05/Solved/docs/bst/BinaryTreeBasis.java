package bst;

/**
 * This abstract class contains implementation details that will be required
 * by both position-oriented and value-oriented data structures that use the binary tree rules.
 */
public abstract class BinaryTreeBasis
{
   private TreeNode root;

   public BinaryTreeBasis() 
   {
      root = null;
   }  

   public boolean isEmpty() 
   {
      return root == null;
   }  

   public void makeEmpty() 
   {
      root = null;
   }  

   /**
    * Returns the item stored in the root node.
    */
   public Object getRootItem() throws TreeException 
   {
      if (root == null) 
      {
         throw new TreeException("Empty tree");
      }
      else 
      {
         return root.getItem();
      } 
   }  

   protected TreeNode getRootNode()
   {
      return root;
   }

   protected void setRootNode(TreeNode tNode)
   {
      root = tNode;
   }

   /** 
    *  Returns the iterator for the Binary Tree. <br>
    *  The iterator will need to be set to a particular traversal (inorder, preorder, postorder).
    *  If a traversal is not specified, the iterator will be empty.
    */
   public TreeIterator iterator()
   {
      return new BinaryTreeIterator(root);
   }
}  
