package pizza;
import util.Keyboard;

public class PizzaDriver
{
	private static int menu() //show the menu choices, wait for and return the valid selection
	{
		Keyboard k = Keyboard.getKeyboard();
		int inputInt;
		do
		{
			System.out.println();
			System.out.println("1. Meat Lover's");
			
			System.out.println("2. Veggie Lover's");

			System.out.println("3. Hawaiian");

			System.out.println("4. Build Your Own");

			System.out.println();
			inputInt = k.readInt("Select from the above: ");
			System.out.println();
		
		}while (inputInt > 4 && inputInt < 1);
		
		return inputInt;
		
	}
	//request the crust size, wait for a valid response confirmation from PizzaBuilder
	private static void requestSize(PizzaBuilder pizza_builder) 
	{
		Keyboard k = Keyboard.getKeyboard();
		String input;
		do
		{
			System.out.println();
			input = k.readString("What size pizza (S/M/L)? ");
			input = input.toUpperCase();
			System.out.println();
		}while (!(pizza_builder.setSize(input.charAt(0))));
		
	}
	//request the crust type, wait for a valid response confirmation from PizzaBuilder
	private static void requestCrust(PizzaBuilder pizza_builder) 
	{
		Keyboard k = Keyboard.getKeyboard();
		String input;
		do
		{
			System.out.println();
			input = k.readString("What type of crust (thin/hand/pan)? ");
			System.out.println();
		}while (!(pizza_builder.setCrust(input)));
	}
	//ask for toppings until Done indicated (invalid toppings are ignored)
	private static void requestToppings(PizzaBuilder pizza_builder) 
	{
		Keyboard k = Keyboard.getKeyboard();
		String input;
		do
		{
			System.out.println();
			input = k.readString("(P)epperoni,(O)nions,(G)reen Peppers,(S)ausage,(M)ushrooms,(D)one");
			input = input.toUpperCase();
			pizza_builder.addTopping(input.charAt(0));
			
		}while (!(input.contentEquals("D")));
		
	}
	//display the pizza and its total cost
	private static void showOrder(DecoratedPizza dec_pizza) 
	{
		double cost = dec_pizza.pizzaCost();
		java.text.DecimalFormat twoDecimals = new java.text.DecimalFormat("#.##");
		System.out.println("Your pizza:");
		System.out.println(dec_pizza.toString());
		System.out.println();
		System.out.println("The cost of your pizza is $" + twoDecimals.format(cost));
	}
	//allow the user to order multiple pizzas if desired, call the other methods, track total cost and number of pizzas
	public static void main (String[] args) 
	{
		Keyboard k = Keyboard.getKeyboard();
		
		String input;
		String finalInput;
		int menuSelection = 0;
		double total_cost = 0;
		int pizzaNum = 0;
		do
		{
			System.out.println();
			input = k.readString("Would you like to order a pizza (y/n)? ");
			System.out.println();
			input = input.toUpperCase();
		}while (!(input.contentEquals("Y") || input.contentEquals("N")));
		
		
		
		do
		{
			PizzaBuilder pizza_builder = new PizzaBuilder();
			if (input.contentEquals("Y"))
			{
				menuSelection= PizzaDriver.menu();
			}
			else if (input.contentEquals("N"))
			{
				return;
			}
			
			if(menuSelection == 1)
			{
				pizza_builder = new MeatLover();
				PizzaDriver.requestSize(pizza_builder);
				PizzaDriver.requestCrust(pizza_builder);
				
			}
			else if(menuSelection == 2)
			{
				pizza_builder = new VeggieLover();
				PizzaDriver.requestSize(pizza_builder);
				PizzaDriver.requestCrust(pizza_builder);
			}
			else if(menuSelection == 3)
			{
				pizza_builder = new Hawaiian();
				PizzaDriver.requestSize(pizza_builder);
				PizzaDriver.requestCrust(pizza_builder);
			}
			else
			{
				PizzaDriver.requestSize(pizza_builder);
				PizzaDriver.requestCrust(pizza_builder);
				PizzaDriver.requestToppings(pizza_builder);
			}
			System.out.println();
			System.out.println();
			do
			{
				System.out.println();
				input = k.readString("Are you a senior citizen (y/n)? ");
				System.out.println();
				input = input.toUpperCase();
			}while (!(input.contentEquals("Y") || input.contentEquals("N")));
			
			
			if (input.contentEquals("Y"))
			{
					pizza_builder.addDiscount("senior discount", 0.1);
			}
			
			
			do
			{
				System.out.println();
				input = k.readString("Do you need this pizza delivered (y/n)? ");
				System.out.println();
				System.out.println();
				input = input.toUpperCase();
			}while (!(input.contentEquals("Y") || input.contentEquals("N")));
			
			if (input.contentEquals("Y"))
			{
				pizza_builder.addFee("delivery", 2.50);
			}
			
			DecoratedPizza pizzaDone = pizza_builder.pizzaDone();
			total_cost += pizzaDone.pizzaCost();
			pizzaNum++;
			PizzaDriver.showOrder(pizzaDone);
			
			
			do
			{
				
				System.out.println();
				finalInput = k.readString("Would you like to order another pizza (y/n)? ");
				finalInput = finalInput.toUpperCase();
				
			}while (!(finalInput.contentEquals("Y") ||finalInput.contentEquals("N")));
			
			
			if (finalInput.contentEquals("Y"))
			{
				input = finalInput;
			}
			
			}while (finalInput.contentEquals("Y"));
		
		java.text.DecimalFormat twoDecimals = new java.text.DecimalFormat("#.##");
		System.out.println();
		System.out.println();
		System.out.println("You ordered " + pizzaNum + " pizza(s) for a grand total of $" + twoDecimals.format(total_cost) + ".");
		
		
		
		
	}
}