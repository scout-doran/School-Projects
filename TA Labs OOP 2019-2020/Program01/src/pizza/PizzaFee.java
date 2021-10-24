package pizza;

public class PizzaFee extends DecoratedPizza
{
	private String message;
	private double f;
	
	
	public PizzaFee(DecoratedPizza pizza_component, String msg, double fee)
	{
		super(pizza_component);
		message = msg;
		f = fee;
		
	}
	
	public double pizzaCost() 
	{
		
		return ((super.pizzaCost()) + f);
	}
	
	public String toString() 
	{
		return ((super.toString()) + message + "\n");
	}
}