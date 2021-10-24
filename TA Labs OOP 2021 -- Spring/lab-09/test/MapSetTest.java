import org.junit.Before;
import org.junit.Test;

import java.util.Iterator;

import static org.junit.Assert.*;

public class MapSetTest {

    private MapSet<String> set;

    @Before
    public void setup(){
        set = new MapSet<>();
        set.add("Kirk", "James");
        set.add("Janeway", "Kathryn");
        set.add("Archer", "Jonathan");
        set.add("Sisko", "Benjamin");
    }

    @Test
    public void add() {
        assertTrue("add test pt 1", set.add("Picard", "Jean-Luc"));
        assertFalse("add test pt 2", set.add("Picard", "Jean-Luc"));
    }

    @Test
    public void getValue() {
        assertTrue("getValue pt 1", set.getValue("Archer").contentEquals("Jonathan"));
        assertFalse("getValue pt 2", set.getValue("Archer").contentEquals("James"));
    }

    @Test
    public void contains() {
        assertTrue("contains pt 1", set.contains("Kirk"));
        assertFalse("contains pt 2", set.contains("Smith"));
    }

    @Test
    public void getIterator() {
        Iterator iterator = set.getIterator();
        assertNotNull("iterator pt 1", iterator);
    }
}