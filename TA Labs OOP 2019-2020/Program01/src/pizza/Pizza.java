package pizza;

public class Pizza extends DecoratedPizza
{
	private Crust crust;
	
	public Pizza(Crust crust)
	{
		super();
		this.crust = crust;
	}
	
	public double pizzaCost() 
	{
		return crust.crustCost();
	}
	public String toString() 
	{
		return (crust.toString() + "Toppings:\n");
	}
	public String getImage() 
	{
		String imageName = new String();
		return (imageName + crust.getSize());
	}
	
}