package pizza;


public class Crust
{
	private char size;
	private String type;
	
	public Crust(char crust_size, String crust_type)
	{
		size = crust_size;
		type = crust_type;
		
	}
	
	public double crustCost()
	{
		float cost = 0;
		if (size == 'S')
		{
			cost += CrustSize.S.cost();
		}
		else if (size == 'M')
		{
			cost += CrustSize.M.cost();
		}
		else if (size == 'L')
		{
			cost += CrustSize.L.cost();
		}
		
		if (type.contentEquals("THIN"))
		{
			cost+= CrustType.THIN.cost();
		}
		else if (type.contentEquals("HAND"))
		{
			cost+= CrustType.HAND.cost();
		}
		else if (type.contentEquals("PAN"))
		{
			cost+= CrustType.PAN.cost();
		}
		
		return cost;
	}
	
	public String toString()
	{
		String crust_state = new String("Size: " + size + "\n" + "Crust: " + type + "\n");
		return crust_state;
	}
	
	public String getCrust()
	{
		return type;
	}
	
	public char getSize()
	{
		return size;
	}
}