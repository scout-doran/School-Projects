import javax.swing.JList;
import java.util.ArrayList;
import java.awt.dnd.*;
import java.awt.datatransfer.*;

public class ToppingList extends JList implements DragGestureListener, DropTargetListener
{
   //DO THIS
   //constructor, etc.
   
   private ArrayList<String> toppings;
   private ToppingSelected tsl;  //interface type
   
	public ToppingList(ToppingSelected tsl)
   {
      //call JList's constructor
	  
	  //reset 
	  
	  //update the listener tsl
	  
   }




   //interface method to recognize the start of a drag event and track the drag as it proceeds
   public void dragGestureRecognized(DragGestureEvent dge) 
   {
      if (getSelectedIndex() == -1) return;  //no valid selection, ignore the drag

	  //DO THIS!
      //wrap the the selected value (JList method) up into a new ToppingTransferable object
	  ToppingTransferable transferable =
 

      //start the dragging process
      //extract the drag source out from the event object
      DragSource dragSource = dge.getDragSource();  

      //a copy of the dragged object placed inside the drag source
      //track the drag process
      dragSource.startDrag(dge, DragSource.DefaultCopyDrop, transferable, null);
   }

   //interface method to respond to a drop event
   public void drop(DropTargetDropEvent dtde) 
   {
      //get the dropped object and try to figure out what it is
      Transferable transfer = dtde.getTransferable();
	  
	  //DO THIS
      //get the possible flavors for the dropped object (ToppingTransferable method)

      DataFlavor[] flavors =   

      String addTopping;
      try
      {
         //poll the flavors to determine the object being dropped
         //the drop target does not know from where the object has been dragged
         //the object can thus be of several different types
         //in our case, however, only one object type is allowed or expected--  a String reference

         //DO THIS
		 //grab the transfer data within the first index of the DataFlavor array (ToppingTransferable method)
         addTopping = 

      }
      //the flavor is not the correct type
      catch (UnsupportedFlavorException ufe)
      {
         dtde.rejectDrop();  
         return;
      }
      catch (java.io.IOException ioe)
      {
         dtde.rejectDrop();
         return;
      }

      //accept copy drops...
      dtde.acceptDrop(DnDConstants.ACTION_COPY);

      //if we made it this far, everything worked.
      dtde.dropComplete(true);

      //DO THIS 
	  remove the topping



   }
   
   
   //called upon a successful drop
   public void removeTopping(String topping)
   {
      toppings.remove(topping);
      //notify listener
      tsl.toppingSelected(topping);
      //reset the JList data with one fewer topping
      setListData(toppings.toArray());
   }

   public void reset()
   {
      toppings = new ArrayList<String>();
      toppings.add("pepperoni");
      toppings.add("onions");
      toppings.add("green peppers");
      toppings.add("sausage");
      toppings.add("mushrooms");

      setListData(toppings.toArray());
   }
   

   public void dragEnter(DropTargetDragEvent dtde) {}
   public void dragExit(DropTargetEvent dte) {}
   public void dragOver(DropTargetDragEvent dtde) {}
   public void dropActionChanged(DropTargetDragEvent dtde) {}
}