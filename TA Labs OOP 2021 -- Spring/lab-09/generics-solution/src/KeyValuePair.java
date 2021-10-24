public class KeyValuePair <T> implements Comparable <KeyValuePair<T>>{

    private String key;
    private T value;

    public KeyValuePair(String k, T v){
        this.key = k;
        this.value = v;
    }

    public String getKey(){
        return this.key;
    }

    public T getValue(){
        return this.value;
    }

    public String toString(){
        return this.key.toString() + " -> " + this.value.toString();
    }

    @Override
    public int compareTo(KeyValuePair<T> o) {
        return this.key.compareTo(o.key);
    }
}
