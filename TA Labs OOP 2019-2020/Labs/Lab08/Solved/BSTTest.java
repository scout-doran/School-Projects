import java.util.ArrayList;
import java.util.Iterator;

public class BSTTest
{

   public static void main(String[] args)
   {
      SearchTreeInterface bst = new BinarySearchTree();  
      bst.insert(new CD("M", "A", 0, 0, 0));
      bst.insert(new CD("A", "A", 0, 0, 0));
      bst.insert(new CD("Z", "A", 0, 0, 0));
      bst.insert(new CD("Y", "A", 0, 0, 0));
      System.out.println(((BinarySearchTree) bst).isBalanced());

      System.out.println();
      
      bst = new BinarySearchTree();  
      CD[] cds = readMusic("cds.txt");
      Comparable key = null;

      for (int i = 0; i < cds.length; i++)
      {
         bst.insert(cds[i]);
      }
 
      System.out.println(((BinarySearchTree) bst).height());
      System.out.println(((BinarySearchTree) bst).isBalanced());
      
      System.out.println();

      try
      {
         key = cds[75].getKey();
         bst.insert(cds[75]);
      }
      catch(TreeException te)
      {
         System.out.println(key.toString() + " is a duplicate and cannot be added");
      }


      System.out.println();
 
      System.out.println(((BinarySearchTree) bst).height());
      System.out.println(((BinarySearchTree) bst).isBalanced());
      
      System.out.println();

      TreeIterator iter = bst.iterator();
      iter.setInorder();
      while(iter.hasNext())
      {
         System.out.println(iter.next());
      }

      System.out.println();

      for (int i = 0; i < 100; i++)
      {
         System.out.println(bst.retrieve(cds[i].getKey()));

         try
         {
            key = cds[i].getKey();
            bst.delete(key);
         }
         catch(TreeException te)
         {
            System.out.println(key.toString() + "not found");
         }
      }

      System.out.println();

      System.out.println(((BinarySearchTree) bst).height());
      System.out.println(((BinarySearchTree) bst).isBalanced());

      System.out.println();

      try
      {
         key = cds[62].getKey();
         bst.delete(key);
      }
      catch(TreeException te)
      {
         System.out.println(key.toString() + " not found");
      }
   }

   private static CD[] readMusic(String fileName)
   {
      FileIO file = new FileIO(fileName, FileIO.FOR_READING);
      String str = file.readLine();
      ArrayList<CD> cds = new ArrayList<CD>();
      while (!file.EOF())
      {
         String title = file.readLine();
         int year = Integer.parseInt(file.readLine());
         int rating = Integer.parseInt(file.readLine());
         int numTracks = Integer.parseInt(file.readLine());
         CD cd = new CD(title, str, year, rating, numTracks);

         cds.add(cd);
         int tracks = 1;

         while (tracks <= numTracks)
         {
            String temp = file.readLine();
            String[] line = temp.split(",");
            String len = line[0];
            String songTitle = line[1];
            cd.addSong(songTitle, len);
            tracks++;
         }

         str = file.readLine();
      }

      CD[] cds_array = new CD[cds.size()];
      int i = 0;
      for(CD cd : cds)
      {
         cds_array[i] = cds.get(i);
         i++;
      }
      return cds_array;
   }

}
