import org.junit.Before;
import org.junit.Test;

import java.io.File;
import java.util.Scanner;

import static org.junit.Assert.*;

public class AirportTest {

    public String data[];

    @Before
    public void setUp() throws Exception {

        data = new String[] {
                "1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"\n",
                "2,\"Madang Airport\",\"Madang\",\"Papua New Guinea\",\"MAG\",\"AYMD\",-5.20707988739,145.789001465,20,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"\n",
                "3,\"Mount Hagen Kagamuga Airport\",\"Mount Hagen\",\"Papua New Guinea\",\"HGU\",\"AYMH\",-5.826789855957031,144.29600524902344,5388,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"\n",
                "4,\"Nadzab Airport\",\"Nadzab\",\"Papua New Guinea\",\"LAE\",\"AYNZ\",-6.569803,146.725977,239,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"\n",
                "104,\"Pitt Meadows Airport\",\"Pitt Meadows\",\"Canada\",\\N,\"CYPK\",49.21609878540039,-122.70999908447266,11,-8,\"A\",\"America/Vancouver\",\"airport\",\"OurAirports\"",
                "641,\"Harstad/Narvik Airport, Evenes\",\"Harstad/Narvik\",\"Norway\",\"EVE\",\"ENEV\",68.491302490234,16.678100585938,84,1,\"E\",\"Europe/Oslo\",\"airport\",\"OurAirports\"",
                "5562,\"Robin Hood Doncaster Sheffield Airport\",\"Doncaster, Sheffield\",\"United Kingdom\",\"DSA\",\"EGCN\",53.4805378105,-1.01065635681,55,0,\"E\",\"Europe/London\",\"airport\",\"OurAirports\"",
                "11743,\"La Grande-4 Airport\",\"La Grande-4\",\"Canada\",\"YAH\",\"CYAH\",53.754699707,-73.6753005981,1005,\\N,\\N,\\N,\"airport\",\"OurAirports\""
        };

    }

    @Test
    public void getName() {

        Airport airport = new Airport(data[0]);
        assertEquals("Name test", "Goroka Airport", airport.getName());
        airport = new Airport(data[5]);
        assertEquals("Comma Name test", "Harstad/Narvik Airport, Evenes", airport.getName());
    }

    @Test
    public void getCity() {

        Airport airport = new Airport(data[1]);
        assertEquals("City test", "Madang", airport.getCity());
        airport = new Airport(data[6]);
        assertEquals("City test", "Doncaster, Sheffield", airport.getCity());

    }

    @Test
    public void getIATA() {
        Airport airport = new Airport(data[2]);
        assertEquals("IATA test", "HGU", airport.getIATA());
        airport = new Airport(data[4]);
        assertEquals("IATA test", "\\N", airport.getIATA());
    }

    @Test
    public void getLatLon(){
        Airport airport = new Airport(data[2]);
        assertTrue("Latitude", -5.826789855957031 == airport.getLatitude());
        assertTrue("Longitude", 144.29600524902344 == airport.getLongitude());
        //-5.826789855957031,144.29600524902344

    }

    @Test
    public void getGMT(){
        Airport airport = new Airport(data[6]);
        assertTrue("GMT good", airport.getGmt() == 0);
        airport = new Airport(data[7]);
        assertTrue("GMT bad", airport.getGmt() == -24);
    }

}