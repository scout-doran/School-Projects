import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class AirportDB {

    private ArrayList<Airport> list;

    public AirportDB(){

        list = new ArrayList<Airport>();
        File file = new File("data/data_airports.csv");
        try {
            Scanner scan = new Scanner(file);
            while (scan.hasNextLine()){
                String data = scan.nextLine();
                Airport airport = new Airport(data);
                list.add(airport);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

    public Airport findAirportByName(String name){

        Airport result = null;
        boolean found = false;
        for (int i = 0; i < list.size() && !found; i++){
            Airport item = list.get(i);
            if (item.getName().toLowerCase().contentEquals(name.toLowerCase())){
                result = item;
                found = true;
            }
        }
        return result;
    }

    public Airport findAirportByCode(String code){

        Airport result = null;
        boolean found = false;
        for (int i = 0; i < list.size() && !found; i++){
            Airport item = list.get(i);
            if (item.getIATA().toLowerCase().contentEquals(code.toLowerCase())){
                result = item;
                found = true;
            }
        }
        return result;
    }

    public ArrayList<Airport> findAirportByCity(String city){

        ArrayList<Airport> result = new ArrayList<Airport>();
        for (int i = 0; i < list.size(); i++){
            Airport ap = list.get(i);
            if (ap.getCity().toLowerCase().contains(city.toLowerCase())){
                result.add(ap);
            }
        }
        return result;
    }

}
