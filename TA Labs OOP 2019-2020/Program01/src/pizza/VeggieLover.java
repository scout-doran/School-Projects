package pizza;

public class VeggieLover extends PizzaBuilder
{
	public VeggieLover()
	{
		super();
	}
	
	protected void buildPizza()
	{
		super.buildPizza();
		super.addTopping('O');
		super.addTopping('M');
		super.addTopping('G');
		
	}
}