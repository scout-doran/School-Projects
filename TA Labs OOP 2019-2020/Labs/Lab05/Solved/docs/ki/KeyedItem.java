package ki;

public abstract class KeyedItem
{
  private Comparable searchKey;
  
  public KeyedItem(Comparable key) 
  {
    searchKey = key;
  }  

  public Comparable getKey() 
  {
    return searchKey;
  }  

  public String toString()
  {
     return searchKey.toString();
  }
}