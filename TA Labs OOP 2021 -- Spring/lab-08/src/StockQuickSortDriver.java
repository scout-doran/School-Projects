import java.util.ArrayList;

public class StockQuickSortDriver {

    public static void sort(Comparable[] a) {
        quicksort(a, 0, a.length - 1);
    }

    private static void quicksort(Comparable[] a, int lo, int hi) {
        if (lo >= hi) return;
        int pi = partition(a, lo, hi);
        quicksort(a, lo, pi - 1);
        quicksort(a, pi + 1, hi);
    }

    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo + 1;
        int j = hi;

        while (i <= j) {
            if (a[i].compareTo(a[lo]) <= 0) {
                i++;
            } else if (a[j].compareTo(a[lo]) > 0) {
                j--;
            } else if (j < i) {
                break;
            } else
                swap(a, i, j);
        }
        swap(a, lo, j);
        return j;
    }

    private static void swap(Object[] a, int i, int j) {
        Object tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        String file_name = "data/stock_data.csv";

        //Stock[] stocks = new Stock[100];
        Stock[] stocks = null;
        try {
            stocks = readStocks(file_name);
        } catch (FileIOException ex) {
            System.out.println(ex.getMessage());
        }

        sort(stocks);

        assert stocks != null;
        for (Stock stock : stocks) {
            System.out.println(stock);
        }
    }

    private static Stock[] readStocks(String fileName) {
        FileIO file = new FileIO(fileName, FileIO.FOR_READING);
        ArrayList<Stock> stocks = new ArrayList<>();
        String row = file.readLine(); // Reads the headers of the dataset file
        // Now we start reading each of the data records

        /*
        * Incorrect Line of code: while (!file.EOF() ) {
        *
        * Link to solution: https://stackoverflow.com/questions/19219738/end-of-file-nullpointer+exception
        *
        * vvv Correct line of code below vvv
        */
        while (file.readLine() != null) {
            row = file.readLine();
            String[] stock_data = row.split(",");
            String company_name = stock_data[0];
            double open_price = Double.parseDouble(stock_data[1]);
            double high_price = Double.parseDouble(stock_data[2]);
            double low_price = Double.parseDouble(stock_data[3]);
            double close_price = Double.parseDouble(stock_data[4]);
            double adj_close_price = Double.parseDouble(stock_data[5]);
            double volume = Double.parseDouble(stock_data[6]);
            String quote = stock_data[7];
            Stock stock = new Stock(company_name, open_price, high_price, low_price, close_price, adj_close_price, volume, quote);
            stocks.add(stock);
        }

        Stock[] stocks_array = new Stock[stocks.size()];
        int i = 0;
        for (Stock stock : stocks) {
            stocks_array[i] = stock;
            i++;
        }
        return stocks_array;
    }
}