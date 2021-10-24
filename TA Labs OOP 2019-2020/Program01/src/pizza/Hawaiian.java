package pizza;

public class Hawaiian extends PizzaBuilder
{
	public Hawaiian()
	{
		super();
	}
	
	protected void buildPizza()
	{
		super.buildPizza();
		super.addTopping('H');
		super.addTopping('A');
		
	}
}