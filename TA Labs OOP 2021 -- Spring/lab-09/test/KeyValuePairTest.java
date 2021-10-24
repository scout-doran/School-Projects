import org.junit.Test;

import static org.junit.Assert.*;

public class KeyValuePairTest {
    @Test
    public void getKey() {
        KeyValuePair<String> kvp = new KeyValuePair<>("Hello", "World");
        assertEquals("kvp key", "Hello", kvp.getKey());
    }

    @Test
    public void getValue() {
        KeyValuePair<String> kvp = new KeyValuePair<>("Hello", "World");
        assertEquals("kvp value", "World", kvp.getValue());
    }

    @Test
    public void testToString() {
        KeyValuePair<String> kvp = new KeyValuePair<>("Hello", "World");
        assertEquals("kvp toString", "Hello -> World", kvp.toString());
    }

    @Test
    public void compareTo() {
        KeyValuePair<String> kvp = new KeyValuePair<>("Hello", "World");
        assertTrue("equal", kvp.compareTo(new KeyValuePair<>("Hello", "World")) == 0);
        assertTrue("less", kvp.compareTo(new KeyValuePair<>("Honey Badger", "Don't Care")) < 0);
        assertTrue("greater", kvp.compareTo(new KeyValuePair<>("Apple", "Computer")) > 0);
    }
}