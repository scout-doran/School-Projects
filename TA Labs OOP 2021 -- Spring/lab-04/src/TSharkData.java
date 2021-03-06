import java.util.Scanner;

public class TSharkData {

    private String frameNumber;
    private String frameTime;
    private String protocol;
    private String protocolID;
    private String srcIP;
    private String srcPort;
    private String dstIP;
    private String dstPort;
    //Add dummy var

    public TSharkData(String data){
        /*Scanner obj = new Scanner(data);
        obj.useDelimiter(",");
        frameNumber = obj.next();
        frameTime = obj.next();
        protocol = obj.next();
        protocolID = obj.next();
        srcIP = obj.next();
        dstIP = obj.next();
        srcPort = obj.next();
        dstPort = obj.next();*/
        Scanner scan = new Scanner(data);
        scan.useDelimiter(",");
        frameNumber = scan.next().replace("\"","");
        frameTime = scan.next().replace("\"","");
        protocol = scan.next().replace("\"","");
        protocolID = scan.next().replace("\"","");
        srcIP = scan.next().replace("\"","");
        dstIP = scan.next().replace("\"","");

        // Each of the following pairs might be empty
        String sPort, dPort;
        sPort = scan.next().replace("\"","");
        dPort = scan.next().replace("\"","");
        if (sPort.contentEquals("")) {
            sPort = scan.next().replace("\"", "");
            if (!sPort.contentEquals(""))
                dPort = scan.next().replace("\"","");
        }
        srcPort = sPort;
        dstPort = dPort;
    }

    public String getFrameNumber() {
        return frameNumber;
    }

    public String getFrameTime() {
        return frameTime;
    }

    public String getProtocol() {
        return protocol;
    }

    public String getProtocolID() {
        return protocolID;
    }

    public String getSrcIP() {
        return srcIP;
    }

    public String getSrcPort() {
        return srcPort;
    }

    public String getDstIP() {
        return dstIP;
    }

    public String getDstPort() {
        return dstPort;
    }

}
