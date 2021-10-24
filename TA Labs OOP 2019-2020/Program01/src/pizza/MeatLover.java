package pizza;

public class MeatLover extends PizzaBuilder
{
	public MeatLover()
	{
		super();
	}
	
	protected void buildPizza()
	{
		super.buildPizza();
		super.addTopping('P');
		super.addTopping('S');
		super.addTopping('H');
		
	}
}