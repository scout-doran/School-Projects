package bst;
import java.util.Iterator;

/**
 * This interface defines method signatures for three nonlinear traversals
 * typically used by tree-based data structures.
 */
public interface TreeIterator extends Iterator
{
   /**
    *  Sets the traversal to be inorder (sorted order for a BST). <br>
    */
   public void setInorder();

   /**
    *  Sets the traversal to be preorder. <br>
    */
   public void setPreorder();

   /**
    *  Sets the traversal to be postorder. <br>
    */
   public void setPostorder();
}