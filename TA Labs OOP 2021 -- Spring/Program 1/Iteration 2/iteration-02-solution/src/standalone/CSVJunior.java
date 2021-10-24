package standalone;

import org.graphstream.graph.Graph;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Processes data generated from TShark using the following command:
 *
 * tshark -T fields -e frame.number -e frame.time_relative -e _ws.col.Protocol -e ip.proto -e ip.src -e ip.dst -e tcp.srcport -e tcp.dstport -e udp.srcport -e udp.dstport -E header=n -E separator=, -E quote=d -E occurrence=f -i 1
 *
 */
public class CSVJunior extends GeneratorJunior {

    private String filename;

    public CSVJunior(Graph graph, String fn) {
        super(graph);
        this.filename = fn;
    }

    /**
     * Opens a file, creates a scanner object, and saves that to the super class scanner attribute with setScan
     */
    @Override
    public void begin() {
        File file = new File(filename);
        try {
            this.setScan(new Scanner(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
