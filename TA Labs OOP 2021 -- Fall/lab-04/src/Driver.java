import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Driver {

    public static void main(String[] args) {

        ArrayList<TSharkData> list = new ArrayList<TSharkData>();

        File f = new File(args[0]);
        try {
            Scanner scan = new Scanner(f);
            while (scan.hasNext()){
                String line = scan.nextLine();
                list.add(new TSharkData(line));
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

}
