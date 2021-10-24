import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;

public class AirportApp {

    /**
     * Usage: java AirportApp --iata code | --name "Airport Name" | --city "City"
     * @param args
     */
    public static void main(@NotNull String args[]){

        String cmd = args[0];
        String value = args[1];

        if (args.length >= 2){
            AirportDB db = new AirportDB();
            if (cmd.contentEquals("--iata")){
                Airport ap = db.findAirportByCode(value);
                if (ap != null){
                    System.out.println(ap);
                } else {
                    System.out.println("No airport found with IATA code " + value);
                }
            } else if (cmd.contentEquals("--name")){
                Airport ap = db.findAirportByName(value);
                if (ap != null){
                    System.out.println(ap);
                } else {
                    System.out.println("No airport found with name " + value);
                }
            } else if (cmd.contentEquals("--city")){
                ArrayList<Airport> list = db.findAirportByCity(value);
                if (list.size() > 0) {
                    System.out.println(list);
                } else {
                    System.out.println("No airports found for " + value);
                }
            }

        } else {
            System.err.println("Usage: java AirportApp --iata code | --name \"Airport Name\" | --city \"City\"");
        }
    }

}
