package pizza;

public class PizzaBuilder
{
	//private CrustType crust_type;
	//private CrustSize crust_size;
	
	private Crust crust;
	private DecoratedPizza topLink;
	char crust_size;
	String crust_type;
	
	//create a Crust and a Pizza using that Crust based on the user's specifications (the Pizza is now ready for toppings)
	protected void buildPizza()
	{
		crust = new Crust(crust_size, crust_type);
		topLink = new Pizza(crust);
	}
	
	public PizzaBuilder() //start with a small, thin pizza with no toppings as the default
	{
		crust_size = 'S';
		String crust_type = "THIN";
		crust = new Crust(crust_size, crust_type);
		topLink = new Pizza(crust);
	}
	
	//returns true if the input was valid ("S" or "small", etc., not case sensitive)
	public boolean setSize(char try_size) 
	{
		if (try_size == 'S' || try_size == 'M' || try_size == 'L')
		{
			crust_size = try_size;
			buildPizza();
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	public boolean setCrust(String try_crust) //("thin", "hand", or "pan", not case sensitive)
	{
		try_crust = try_crust.toUpperCase();
		if (try_crust.contentEquals("THIN") || try_crust.contentEquals("HAND") || try_crust.contentEquals("PAN"))
		{
			crust_type = try_crust;
			buildPizza();
			return true;
		}
		else 
		{
			return false;
		}
	}
	//compare the topping abbreviation to topping_char to determine which topping to add (using void here is convenient for the PizzaDriver, ignore invalid abbreviations)
	public void addTopping(char topping_char) 
	{
		//if the toplink is not a Pizza or PizzaTopping do not allow topping to be added
		if (!(topLink instanceof Pizza || topLink instanceof PizzaTopping))
			return;
		
		
		if (topping_char =='P')
		{
			//topLink = new Pepperoni(topLink);
			topLink = PizzaToppingFactory.addPepperoni(topLink);
		}
		else if (topping_char =='S')
		{
			//topLink = new Sausage(topLink);
			topLink = PizzaToppingFactory.addSausage(topLink);
		}
		else if (topping_char =='O')
		{
			//topLink = new Onions(topLink);
			topLink = PizzaToppingFactory.addOnions(topLink);
		}
		else if (topping_char =='G')
		{
			//topLink = new GreenPeppers(topLink);
			topLink = PizzaToppingFactory.addGreenPeppers(topLink);
		}
		else if (topping_char =='M')
		{
			//topLink = new Mushrooms(topLink);
			topLink = PizzaToppingFactory.addMushrooms(topLink);
		}
		else if (topping_char =='H')
		{
			//topLink = new Ham(topLink);
			topLink = PizzaToppingFactory.addHam(topLink);
		}
		else if (topping_char =='A')
		{
			//topLink = new Pineapple(topLink);
			topLink = PizzaToppingFactory.addPineapple(topLink);
		}
		else
			return;
		
	}
	public void addDiscount(String msg, double discount)
	{
		//disallows adding discounts after fees
		if (!(topLink instanceof Pizza || topLink instanceof PizzaTopping || topLink instanceof PizzaDiscount))
			return;
		
		topLink = new PizzaDiscount(topLink, msg, discount);
	}
	
	public void addFee(String msg, double discount)
	{
		topLink = new PizzaFee(topLink, msg, discount);
	}
	
	
	//return the final DecoratedPizza and reset to the default pizza if another pizza is desired
	public DecoratedPizza pizzaDone() 
	{
		DecoratedPizza done = topLink;
		
		crust_size = 'S';
		String crust_type = "THIN";
		buildPizza();
		
		return done;
	}
	
}