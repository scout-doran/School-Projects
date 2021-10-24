import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

public class AirportDBTest {

    private AirportDB db;

    @Before
    public void setUp() throws Exception {
        db = new AirportDB();
    }

    @Test
    public void findAirportByName() {

        Airport ap = db.findAirportByName("Nashville International Airport");
        assertEquals("Name test", "Nashville International Airport", ap.getName());
        ap = db.findAirportByName("Los Angeles International Airport");
        System.out.println(ap);
        assertEquals("Name test", "Los Angeles International Airport", ap.getName());
        ap = db.findAirportByName("Cookeville International Airport");
        assertNull("Null Test", ap);

    }

    @Test
    public void findAirportByCode() {

        Airport ap = db.findAirportByCode("BNA");
        assertEquals("Code test", "Nashville International Airport", ap.getName());
        ap = db.findAirportByCode("bna");
        assertEquals("Code test", "Nashville International Airport", ap.getName());
    }

    @Test
    public void findAirportByCity() {
        ArrayList<Airport> list = db.findAirportByCity("Los Angeles");
        assertTrue("City test", list.size() >= 1);
    }

    @Test
    public void isReflexive(){

        ArrayList<Airport> list = db.findAirportByCity("Detroit");
        Airport ap0 = list.get(0);
        Airport ap1 = list.get(1);
        Airport ap2 = list.get(2);

    }

    @Test
    public void isSymmetric(){

        ArrayList<Airport> list = db.findAirportByCity("Detroit");
        Airport ap0 = list.get(0);
        Airport ap1 = list.get(1);
        Airport ap2 = list.get(2);

    }

    @Test
    public void isTransitive(){

        ArrayList<Airport> list = db.findAirportByCity("Detroit");
        Airport ap0 = list.get(0);
        Airport ap1 = list.get(1);
        Airport ap2 = list.get(2);
        // DTW
        // DET
        // YIP
        assertTrue("ap0->ap1", ap0.closeTo(ap1));
        assertTrue("ap0->ap2", ap0.closeTo(ap2));
        assertFalse("ap1->ap2", ap1.closeTo(ap2));

    }


}