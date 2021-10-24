package pizza;

public class Sausage extends DecoratedPizza
{
	
	public Sausage(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.99;
	}
	public String toString() 
	{
		return ((super.toString()) + "sausage\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'S';
	}
	
}