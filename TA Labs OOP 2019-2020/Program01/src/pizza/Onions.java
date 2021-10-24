package pizza;

public class Onions extends DecoratedPizza
{
	
	public Onions(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.79;
	}
	public String toString() 
	{
		return ((super.toString()) + "onions\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'O';
	}
	
}