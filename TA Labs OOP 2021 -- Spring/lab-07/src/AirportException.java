public class AirportException extends Exception {

    public AirportException() {
        super();
    }

    public AirportException(String message) {
        super(message);
    }

    @Override
    public String getMessage() {
        return "AirportDB Search: " + super.getMessage();
    }

    @Override
    public String toString() {
        return this.getMessage();
    }
}
