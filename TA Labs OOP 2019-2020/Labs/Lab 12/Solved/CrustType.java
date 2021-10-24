
public enum CrustType
{
    THIN (0.00),
    HAND (0.50),
    PAN  (1.00);

    private final double extraCost;   

    CrustType(double extra) 
    {
        extraCost = extra;
    }

    public double cost()   { return extraCost; }
}
