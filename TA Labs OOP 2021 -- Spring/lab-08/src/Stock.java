public class Stock implements Comparable<Stock> {
    private String company_name;
    private double open_price;
    private double high_price;
    private double low_price;
    private double close_price;
    private double adj_close_price;
    private double volume;
    private String quote;

    public Stock(String company_name, double open_price, double high_price, double low_price, double close_price, double adj_close_price, double volume, String quote) {
        this.company_name = company_name;
        this.open_price = open_price;
        this.high_price = high_price;
        this.low_price = low_price;
        this.close_price = close_price;
        this.adj_close_price = adj_close_price;
        this.volume = volume;
        this.quote = quote;
    }

    public String getCompany_name() {
        return company_name;
    }

    public void setCompany_name(String company_name) {
        this.company_name = company_name;
    }

    public double getOpen_price() {
        return open_price;
    }

    public void setOpen_price(double open_price) {
        this.open_price = open_price;
    }

    public double getHigh_price() {
        return high_price;
    }

    public void setHigh_price(double high_price) {
        this.high_price = high_price;
    }

    public double getLow_price() {
        return low_price;
    }

    public void setLow_price(double low_price) {
        this.low_price = low_price;
    }

    public double getClose_price() {
        return close_price;
    }

    public void setClose_price(double close_price) {
        this.close_price = close_price;
    }

    public double getAdj_close_price() {
        return adj_close_price;
    }

    public void setAdj_close_price(double adj_close_price) {
        this.adj_close_price = adj_close_price;
    }

    public double getVolume() {
        return volume;
    }

    public void setVolume(double volume) {
        this.volume = volume;
    }

    public String getQuote() {
        return quote;
    }

    public void setQuote(String quote) {
        this.quote = quote;
    }

    @Override
    public String toString() {
        return this.getQuote() + " / " + this.getClose_price();
    }

    @Override
    public int compareTo(Stock stock) {
        return Double.compare(this.getClose_price(), stock.getClose_price());
    }
}