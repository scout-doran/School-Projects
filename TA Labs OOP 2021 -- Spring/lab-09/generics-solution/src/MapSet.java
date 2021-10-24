import java.util.Iterator;
import java.util.TreeSet;

public class MapSet<T>{

    private TreeSet<KeyValuePair<T>> collection;

    public MapSet(){
        collection = new TreeSet<>();
    }

    public boolean add(String key, T value){
        return collection.add(new KeyValuePair<>(key, value));
    }

    public T getValue(String key){
        T result = null;
        for (KeyValuePair<T> e : collection){
            if (e.getKey().equals(key))
                result = e.getValue();
        }
        return result;
    }

    public boolean contains(String key){
        boolean result = false;
        for (KeyValuePair<T> e : collection){
            if (e.getKey().equals(key))
                result = true;
        }
        return result;
    }

    public Iterator<KeyValuePair<T>> getIterator(){
        return collection.iterator();
    }

}
