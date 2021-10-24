package pizza;

public class Pineapple extends DecoratedPizza
{
	
	public Pineapple(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.89;
	}
	public String toString() 
	{
		return ((super.toString()) + "pineapple\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'A';
	}
	
}