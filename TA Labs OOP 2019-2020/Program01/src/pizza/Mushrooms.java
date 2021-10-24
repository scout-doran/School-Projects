package pizza;

public class Mushrooms extends DecoratedPizza
{
	
	public Mushrooms(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.79;
	}
	public String toString() 
	{
		return ((super.toString()) + "mushrooms\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'M';
	}
	
}