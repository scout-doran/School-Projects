import queue.*;

class BinaryTreeIterator implements TreeIterator
{
   private TreeNode root;  
   private QueueInterface queue;       

   public BinaryTreeIterator(TreeNode root) 
   {
      this.root = root;
      queue = new QueueLinked();
   } 

   public boolean hasNext() 
   {
      return !queue.isEmpty();
   }  

   public Object next() throws TreeException
   {
      try 
      {
         return queue.dequeue();
      }  
      catch (QueueException e) 
      {
         throw new TreeException("End of tree traversal.");
      }  
   }  

   public void remove() throws UnsupportedOperationException 
   {
      throw new UnsupportedOperationException();
   }  

   public void setPreorder() 
   {
      queue.dequeueAll();
      preorder(root);
   } 

   public void setInorder() 
   {
      queue.dequeueAll();
      inorder(root);
   }  

   public void setPostorder() 
   {
      queue.dequeueAll();
      postorder(root);
   }   

   private void preorder(TreeNode tNode) 
   {
      if (tNode != null) 
      {  
         queue.enqueue(tNode.getItem());
         preorder(tNode.getLeft());
         preorder(tNode.getRight());
      } 
   } 

   private void inorder(TreeNode tNode) 
   {
      if (tNode != null) 
      {  
         inorder(tNode.getLeft());
         queue.enqueue(tNode.getItem());
         inorder(tNode.getRight());
      }
   }  

   private void postorder(TreeNode tNode) 
   {
      if (tNode != null) 
      {  
         postorder(tNode.getLeft());
         postorder(tNode.getRight());
         queue.enqueue(tNode.getItem());
      } 
   } 

  public void setLevelorder()
  {
     if (root != null)
     {
        QueueInterface q = new QueueLinked();
        q.enqueue(root);

        while (!q.isEmpty())
        {
           TreeNode tNode = (TreeNode) q.dequeue();
           queue.enqueue(tNode.getItem());

           TreeNode left = tNode.getLeft();
           TreeNode right = tNode.getRight();

           if (left != null)
           {
              q.enqueue(left);
           }

           if (right != null)
           {
              q.enqueue(right);
           }
        }
     }
  }
}  