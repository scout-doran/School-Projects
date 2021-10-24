import java.util.Iterator;

public class Driver {

    public static void main(String args[]){
        MapSet<String> mm = new MapSet<>();

        mm.add("Gannod", "Jerry");
        mm.add("Kenobi", "Obi-Wan");
        mm.add("Andor", "Cassian");
        mm.add("Vader", "Darth");
        mm.add("Vader", "Anakin");

        Iterator iter = mm.getIterator();

        while(iter.hasNext()){
            System.out.println(iter.next());
        }

        System.out.println(mm.getValue("Kenobi"));
        System.out.println(mm.getValue("Smith"));

    }

}
