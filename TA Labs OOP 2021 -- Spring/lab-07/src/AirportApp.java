import java.util.ArrayList;

public class AirportApp {

    /**
     * Usage: java AirportApp --iata code | --name "Airport Name" | --city "City"
     * @param args
     */
    public static void main(String args[]){

        // TODO: Surround this code with a try catch that handles the AirportException thrown
        // by the AirportApp constructor.
        try {
            AirportApp aa = new AirportApp(args);
        } catch (AirportException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * This method should be modified to throw an AirportException if the
     * search methods return false
     * @param args
     */
    public AirportApp(String args[]) throws AirportException {
        /*
                                  ^
         TODO: Modify the signature with "throws AirportException"

        */

        String msg = "Searching for Cookeville International Airport...\n" +
                "Exception (AirportDB Search: No airport found with name Cookeville International Airport)";
        AirportException ex = new AirportException(msg);

        String cmd = args[0];
        String value = args[1];
        if (args.length >= 2){
            AirportDB db = new AirportDB();
            System.out.println("Searching for " + value + "...");
            if (cmd.contentEquals("--iata")){
                Airport ap = db.findAirportByCode(value);
                if (ap != null){
                    System.out.println(ap);
                } else {
                    // TODO: Change this code so that it throws an AirportException instead of printing the error
                    throw ex;
                    //String message = "No airport found with IATA code " + value;
                    //System.out.println(message);
                }
            } else if (cmd.contentEquals("--name")){
                Airport ap = db.findAirportByName(value);
                if (ap != null){
                    System.out.println(ap);
                } else {
                    // TODO: Change this code so that it throws an AirportException instead of printing the error
                    throw ex;
                    //String message = "No airport found with name " + value;
                    //System.out.println(message);
                }
            } else if (cmd.contentEquals("--city")){
                ArrayList<Airport> list = db.findAirportByCity(value);
                if (list.size() > 0) {
                    System.out.println(list);
                } else {
                    // TODO: Change this code so that it throws an AirportException instead of printing the error
                    throw ex;
                    //String message = "No airports found for " + value;
                    //System.out.println(message);
                }
            }
        } else {
            System.err.println("Usage: java AirportApp --iata code | --name \"Airport Name\" | --city \"City\"");
        }
    }

}
