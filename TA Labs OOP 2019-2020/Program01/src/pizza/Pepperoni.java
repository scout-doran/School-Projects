package pizza;

public class Pepperoni extends DecoratedPizza
{
	
	public Pepperoni(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.99;
	}
	public String toString() 
	{
		return ((super.toString()) + "pepperoni\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'P';
	}
	
}