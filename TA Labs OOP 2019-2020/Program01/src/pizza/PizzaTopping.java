package pizza;

public class PizzaTopping extends DecoratedPizza
{
	private String topping;
	private String letter;
	private double cost;

	public PizzaTopping(DecoratedPizza pizza_component, String topping_string, String topping_letter, double topping_cost)
	{
		super(pizza_component);
		topping = topping_string;
		letter = topping_letter;
		cost = topping_cost;		
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + cost;
	}
	
	public String toString() 
	{
		return ((super.toString()) + topping);
	}
	
	public String getImage() 
	{
		return (super.getImage()) + letter;
	}
}