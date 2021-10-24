import java.util.Scanner;

public class Airport {

    private int index;
    private String name;
    private String city;
    private String country;
    private String IATA;
    private String ICAO;
    private double latitude;
    private double longitude;
    private int elevation;
    private double gmt;
    private String unknown;
    private String timezone;

    public Airport(){

    }

    public Airport(Airport original) {
        this.index = original.index;
        this.name = original.name;
        this.city = original.city;
        this.country = original.country;
        this.IATA = original.IATA;
        this.ICAO = original.ICAO;
        this.latitude = original.latitude;
        this.longitude = original.longitude;
        this.elevation = original.elevation;
        this.gmt = original.gmt;
        this.unknown = original.unknown;
        this.timezone = original.timezone;
    }

    public Airport(String data){
        Scanner scan = new Scanner(data);
        scan.useDelimiter(",");

        this.index = scan.nextInt();

        // Handle odd comma cases
        String temp = scan.next();
        if (temp.lastIndexOf("\"") == 0){
            String restOfName = scan.next();
            temp = temp + "," + restOfName + "\"";
        }
        this.name = temp.replace("\"", "");

        temp = scan.next();
        if (temp.lastIndexOf("\"") == 0) {
            String restOfName = scan.next();
            temp = temp + "," + restOfName + "\"";
        }
        this.city = temp.replace("\"", "");;

        this.country = scan.next().replace("\"", "");;
        this.IATA = scan.next().replace("\"", "");;
        this.ICAO = scan.next().replace("\"", "");;
        this.latitude = scan.nextDouble();
        this.longitude = scan.nextDouble();
        this.elevation = scan.nextInt();

        String tempGMT = scan.next();
        if (!tempGMT.contentEquals("\\N")){
            this.gmt = Double.parseDouble(tempGMT);
        } else {
            this.gmt = -24;
        }

        this.unknown = scan.next().replace("\"", "");;
        this.timezone = scan.next().replace("\"", "");;
    }

    public String toString(){
        return this.name + ", (" + this.getIATA() + ")";
    }

    public int getIndex() {
        return index;
    }

    public String getName() {
        return name;
    }

    public String getCity() {
        return city;
    }

    public String getCountry() {
        return country;
    }

    public String getIATA() {
        return IATA;
    }

    public String getICAO() {
        return ICAO;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public int getElevation() {
        return elevation;
    }

    public double getGmt() {
        return gmt;
    }

    public String getTimezone() {
        return timezone;
    }

    /**
     * Computes the distance between two airports
     * @param a airport
     * @param b airport
     * @param unit "M" miles, "K" kilometers, or "N" nautical miles
     * @return distance between the two airports
     */
    public static double distance(Airport a, Airport b, String unit){

        double lat1 = a.getLatitude();
        double lat2 = b.getLatitude();
        double lon1 = a.getLongitude();
        double lon2 = b.getLongitude();

        if ((lat1 == lat2) && (lon1 == lon2)) {
            return 0;
        }
        else {
            double theta = lon1 - lon2;
            double dist = Math.sin(Math.toRadians(lat1)) * Math.sin(Math.toRadians(lat2)) + Math.cos(Math.toRadians(lat1)) * Math.cos(Math.toRadians(lat2)) * Math.cos(Math.toRadians(theta));
            dist = Math.acos(dist);
            dist = Math.toDegrees(dist);
            dist = dist * 60 * 1.1515;
            if (unit.equals("K")) {
                dist = dist * 1.609344;
            } else if (unit.equals("N")) {
                dist = dist * 0.8684;
            }
            return (dist);
        }
    }

    /**
     * Computes whether two airports are close to each other
     * @param o
     * @return true if input airport is within 25 miles of the airport
     */
    public boolean closeTo(Object o){

        if (!(o instanceof Airport)) {
            return false;
        } else {
            if (Airport.distance(this, ((Airport)o), "M") <= 25){
                return true;
            } else {
                return false;
            }
        }
    }

}
