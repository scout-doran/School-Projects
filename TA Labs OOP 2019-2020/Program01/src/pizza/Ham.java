package pizza;

public class Ham extends DecoratedPizza
{
	
	public Ham(DecoratedPizza npi)
	{
		super(npi);
	}
	
	public double pizzaCost() 
	{
		
		return (super.pizzaCost()) + 0.89;
	}
	public String toString() 
	{
		return ((super.toString()) + "ham\n");
	}
	public String getImage() 
	{
		return (super.getImage()) + 'H';
	}
	
}