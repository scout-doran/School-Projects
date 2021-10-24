package pizza;

public class PizzaDiscount extends DecoratedPizza
{
	private String message;
	private double dis;
	
	public PizzaDiscount(DecoratedPizza pizza_component, String msg, double discount) //discount is assumed to be between 0.0 and 1.0
	{
		super(pizza_component);
		message = msg;
		dis = discount;
		
	}
	
	public double pizzaCost() 
	{
		
		return ((super.pizzaCost()) * (1 - dis));
	}
	
	public String toString() 
	{
		return ((super.toString()) + message + "\n");
	}
}