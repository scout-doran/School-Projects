package pizza;

public abstract class DecoratedPizza
{
	private DecoratedPizza next_pizza_item;
	
	
	public DecoratedPizza()
	{
		next_pizza_item = null;
	}
	
	public DecoratedPizza(DecoratedPizza npi)
	{
		next_pizza_item = npi;
	}
	
	public double pizzaCost() //get the cost from the "next_pizza_item" DecoratedPizza
	{
		return next_pizza_item.pizzaCost();
	}
	
	public String toString()
	{
		return next_pizza_item.toString();
	}
	
	public String getImage()
	{
		return next_pizza_item.getImage();
	}
	
	
	
	
}