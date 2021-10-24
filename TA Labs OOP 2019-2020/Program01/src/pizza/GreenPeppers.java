package pizza;

public class GreenPeppers extends DecoratedPizza
{
	
	public GreenPeppers(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.69;
	}
	public String toString() 
	{
		return ((super.toString()) + "green peppers\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'G';
	}
	
}