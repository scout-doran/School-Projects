package standalone;

import org.graphstream.graph.Graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class TSharkJunior extends GeneratorJunior {

    private int networkInterface;

    public TSharkJunior(Graph g, int i){
        super(g);
        this.networkInterface = i;
    }

    /**
     * Opens a tshark process, creates a scanner object, and saves that to the super class scanner attribute with setScan
     */
    @Override
    public void begin(){
        String cmd = "tshark -T fields -e frame.number -e frame.time_relative -e _ws.col.Protocol -e ip.proto -e ip.src -e ip.dst -e tcp.srcport -e tcp.dstport -e udp.srcport -e udp.dstport -E header=n -E separator=, -E quote=d -E occurrence=f -i " + this.networkInterface;

        try {
            Process p = Runtime.getRuntime().exec(cmd);
            BufferedReader output = new BufferedReader(new InputStreamReader(p.getInputStream()), 512);
            this.setScan(new Scanner(output));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
