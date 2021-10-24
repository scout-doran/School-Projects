import queue.*;

class BinaryTreeIterator implements TreeIterator
{
   private TreeNode root;  
   private QueueInterface items;       

   public BinaryTreeIterator(TreeNode root) 
   {
      this.root = root;
      items = new QueueLinked();
   } 

   public boolean hasNext() 
   {
      return !items.isEmpty();
   }  

   public Object next() throws TreeException
   {
      try 
      {
         return items.dequeue();
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
      items.dequeueAll();
      preorder(root);
   } 

   public void setInorder() 
   {
      items.dequeueAll();
      inorder(root);
   }  

   public void setPostorder() 
   {
      items.dequeueAll();
      postorder(root);
   }   

   private void preorder(TreeNode tNode) 
   {
      if (tNode != null) 
      {  
         items.enqueue(tNode.getItem());
         preorder(tNode.getLeft());
         preorder(tNode.getRight());
      } 
   } 

   private void inorder(TreeNode tNode) 
   {
      if (tNode != null) 
      {  
         inorder(tNode.getLeft());
         items.enqueue(tNode.getItem());
         inorder(tNode.getRight());
      }
   }  

   private void postorder(TreeNode tNode) 
   {
      if (tNode != null) 
      {  
         postorder(tNode.getLeft());
         postorder(tNode.getRight());
         items.enqueue(tNode.getItem());
      } 
   } 

   public void setLevelorder()
   {
	   //(if the root is null, don't do anything). 
      if (root != null)
      {
		  //Start by placing the root TreeNode on the local queue 
         QueueInterface<TreeNode> q = new QueueLinked<TreeNode>();
         q.enqueue(root); //add to queue

		// Loop until the local queue is empty.
         while (!q.isEmpty())
         {
			 //When a TreeNode is pulled from the local queue, 
			 //extract and place its item on the instance variable queue
            TreeNode tNode = q.dequeue(); //remove from queue
            items.enqueue(tNode.getItem());

			//In order to get a level order traversal, 
			//the left TreeNode, if present, will need to be processed first, 
			//and then the right TreeNode, if present. 
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