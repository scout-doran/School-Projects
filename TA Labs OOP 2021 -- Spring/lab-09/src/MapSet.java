import java.util.Iterator;
import java.util.TreeSet;

public class MapSet<T>{

    private TreeSet<KeyValuePair<T>> collection;

    public MapSet(){
        collection = new TreeSet<>();
    }

    /**
     * Create and add a KeyValuePair object to the collection
     * @param key
     * @param value
     * @return true if the element is successfully added
     */
    public boolean add(String key, T value){
        return collection.add(new KeyValuePair<>(key, value));
    }

    /**
     * Return the "Value" part of a KeyValuePair for the given object indexed by "key"
     * @param key
     * @return
     */
    public T getValue(String key){
        T result = null;
        for (KeyValuePair<T> e : collection){
            if (e.getKey().equals(key))
                result = e.getValue();
        }
        return result;
    }

    /**
     * Return true if a KeyValuePair object indexed by the input "key" exists in the collection
     * @param key
     * @return
     */
    public boolean contains(String key){
        boolean result = false;
        for (KeyValuePair<T> e : collection){
            if (e.getKey().equals(key))
                result = true;
        }
        return result;
    }

    /**
     * Return the iterator for the embedded collection
     * @return
     */
    public Iterator<KeyValuePair<T>> getIterator(){
        return collection.iterator();
    }

}
