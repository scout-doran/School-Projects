//Kendall Land and Allyson Jones
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.dnd.*;
import java.net.URL;
import java.net.MalformedURLException;

//You will need to implement ToppingSelected and Drawable as well
public class PizzaGUI extends CenterFrame implements ActionListener, ToppingSelected, Drawable 
{
   private DecoratedPizza pizza = new Pizza();
   
   public static void main (String[] args)
   {
      PizzaGUI pg = new PizzaGUI(800, 425);
   }

   public void draw(Graphics g, int width, int height)
   {
      pizza.draw(g, width, height);
   } 
   
   private JPanel controls;
   private DrawPanel pizzaPanel;

   private JRadioButton small;
   private JRadioButton medium;
   private JRadioButton large;

   private JRadioButton thin;
   private JRadioButton handtossed;
   private JRadioButton deepdish;

   private JLabel pizzaCrust;
   private JLabel pizzaSize;
   private JLabel pizzaToppings;

   private JButton btn;

   private JCheckBox mushrooms;
   private JCheckBox pepperoni;
   private JCheckBox peppers;
   private JCheckBox onions;
   private JCheckBox sausage;
   
   private ToppingList lstToppings;

   public PizzaGUI(int width, int height)
   {  
      super (width, height, "Pizza Time!");
      pizzaPanel = new DrawPanel();
      pizzaPanel.setBackground(Color.white);
	  pizzaPanel.setDrawable(this);

      setResizable(false);
      setUp(width, height);
      setVisible(true);
   }
   
	

   private void setUp(int width, int height)
   {
      setBackground(Color.white);

      controls = new JPanel();
      controls.setBackground(Color.white);
      setLayout(new GridLayout(1, 2));
      add(pizzaPanel);
      add(controls);

      small = new JRadioButton("S", true);
      small.setBackground(Color.white);
      medium = new JRadioButton("M");
      medium.setBackground(Color.white);
      large = new JRadioButton("L");
      large.setBackground(Color.white);
      ButtonGroup size = new ButtonGroup();
      size.add(small);
      size.add(medium);
      size.add(large);

	  //DO THIS (add action listeners to small, medium, and large)
	  //if one of these check boxes is changed, the pizza is rebuilt and redrawn
	  small.addActionListener(this);
	  medium.addActionListener(this);
	  large.addActionListener(this);
	  
	  
      thin = new JRadioButton("Thin", true);
      thin.setBackground(Color.white);
      handtossed = new JRadioButton("Hand-Tossed");
      handtossed.setBackground(Color.white);
      deepdish = new JRadioButton("Deep Dish");
      deepdish.setBackground(Color.white);
      ButtonGroup crust = new ButtonGroup();
      crust.add(thin);
      crust.add(handtossed);
      crust.add(deepdish);

      btn = new JButton("Order!");
      btn.setBackground(Color.white);

      pizzaSize = new JLabel("Select Pizza Size:");
      pizzaCrust = new JLabel("Select Pizza Crust:");
      pizzaToppings = new JLabel("Select Pizza Toppings:");

      mushrooms = new JCheckBox("Mushrooms");
      mushrooms.setBackground(Color.white);
      pepperoni = new JCheckBox("Pepperoni");
      pepperoni.setBackground(Color.white);
      sausage = new JCheckBox("Sausage");
      sausage.setBackground(Color.white);
      onions = new JCheckBox("Onions");
      onions.setBackground(Color.white);
      peppers = new JCheckBox("Green Peppers");
      peppers.setBackground(Color.white);

      EasyGridBag bag = new EasyGridBag(6, 3, controls);
      controls.setLayout(bag);
      bag.fillCellCenterWithinCell(1, 1, pizzaSize);

      bag.fillCellAlignWithinCell(2,1,GridBagConstraints.WEST,small);
      bag.fillCellAlignWithinCell(3,1,GridBagConstraints.WEST,medium);
      bag.fillCellAlignWithinCell(4,1,GridBagConstraints.WEST,large);
      bag.fillCellAlignWithinCell(1,1,GridBagConstraints.WEST,pizzaSize);

      bag.fillCellAlignWithinCell(1,2,GridBagConstraints.WEST,pizzaCrust);
      bag.fillCellAlignWithinCell(2,2,GridBagConstraints.WEST,thin);
      bag.fillCellAlignWithinCell(3,2,GridBagConstraints.WEST,handtossed);
      bag.fillCellAlignWithinCell(4,2,GridBagConstraints.WEST,deepdish);

      bag.fillCellAlignWithinCell(1,3,GridBagConstraints.WEST,pizzaToppings);

      //this next code will be commented out and replaced with a JList, lstToppings
      //bag.fillCellAlignWithinCell(2,3,GridBagConstraints.WEST,pepperoni);
      //bag.fillCellAlignWithinCell(3,3,GridBagConstraints.WEST,onions);
      //bag.fillCellAlignWithinCell(4,3,GridBagConstraints.WEST,peppers);
      //bag.fillCellAlignWithinCell(5,3,GridBagConstraints.WEST,sausage);
      //bag.fillCellAlignWithinCell(6,3,GridBagConstraints.WEST,mushrooms);

      //bag.fillCellWithRowColSpan(2, 3, 5, 1, GridBagConstraints.BOTH, lstToppings);

      bag.fillCellCenterWithinCell(6, 2, btn);
      btn.addActionListener(this);  //a JFrame can listen for events on itself
      btn.setActionCommand("Order");
   
	  lstToppings = new ToppingList(this);
   
      bag.fillCellAlignWithinCell(1, 3, GridBagConstraints.WEST, pizzaToppings);
      bag.fillCellWithRowColSpan(2, 3, 5, 1, GridBagConstraints.BOTH, lstToppings);
   
      //DO THIS
      //add some drag and drop setup statements here
	  //ToppingList tl = new ToppingList(this);
	  DragSource dragSource = DragSource.getDefaultDragSource();
	  dragSource.createDefaultDragGestureRecognizer(lstToppings, DnDConstants.ACTION_COPY, lstToppings);
	  DropTarget dropTarget = new DropTarget(pizzaPanel, lstToppings);
	  



      pizza = buildPizza();  //build and display the default pizza
   }

   //DO THIS
   //complete this build pizza method
   public DecoratedPizza buildPizza()
   {
      //call methods to build the pizza
	  DecoratedPizza pizza = new Pizza();
      setCrust((Pizza) pizza);
      setSize((Pizza) pizza);
      pizza = setToppings(pizza);

      repaint();  //paints the DrawPanel, which calls draw here in the GUI, which draws the newly configured pizza
      return pizza;
   }

   public void setCrust(Pizza pizza)
   {
      if (thin.isSelected())
      {
         pizza.setCrust("thin");
      }
      else if (handtossed.isSelected())
      {
         pizza.setCrust("hand");
      }
      else
      {
         pizza.setCrust("pan");
      }
   }

   public void setSize(Pizza pizza)
   {
      if (small.isSelected())
      {
         pizza.setSize('S');
      }
      else if (medium.isSelected())
      {
         pizza.setSize('M');
      }
      else
      {
         pizza.setSize('L');
      }
   }

   public DecoratedPizza setToppings(DecoratedPizza pizza)
   {

      if (pepperoni.isSelected())
      {
         pizza = new Pepperoni(pizza);
      }

      if (onions.isSelected())
      {
         pizza = new Onions(pizza);
      }

      if (peppers.isSelected())
      {
         pizza = new Peppers(pizza);
      }

      if (sausage.isSelected())
      {
         pizza = new Sausage(pizza);
      }

      if (mushrooms.isSelected())
      {
         pizza = new Mushrooms(pizza);
      }

      return pizza;
   }

   public void actionPerformed(ActionEvent ae)
   {
      //the pizza has been ordered, so now we make it
      if (ae.getActionCommand().equals("Order"))
      {
         String temp = pizza.toString();
         java.text.DecimalFormat fmt = new java.text.DecimalFormat("0.00");
         temp = temp + "$" + fmt.format(pizza.pizzaCost());
         SimpleDialogs.normalOutput(temp, "Pizza Order");
		 
         //reset some stuff
		 resetToppings();
		 lstToppings.reset();
      }
      //called after each interaction with the GUI to make sure the latest pizza is displayed
      pizza = buildPizza();
	  
   }
   
   public void resetToppings()
   {	  
      pepperoni.setSelected(false);
      onions.setSelected(false);
      peppers.setSelected(false);
      sausage.setSelected(false);
      mushrooms.setSelected(false);
   }
   
   public void toppingSelected(String topping)
   {
      if (topping.equals("pepperoni"))
      {
         pepperoni.setSelected(true);
      }

      else if (topping.equals("onions"))
      {
         onions.setSelected(true);
      }

      else if (topping.equals("green peppers"))
      {
         peppers.setSelected(true);
      }

      else if (topping.equals("sausage"))
      {
         sausage.setSelected(true);
      }

      else if (topping.equals("mushrooms"))
      {
         mushrooms.setSelected(true);
      }

      pizza = buildPizza();
   }
}