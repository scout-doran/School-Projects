import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class TSharkDataTest {

    private TSharkData data1;
    private TSharkData data2;
    private TSharkData data3;
    private TSharkData data4;

    @Before
    public void setUp(){
    }

    @Test
    public void getFrameNumber() {
        data1 = new TSharkData("8,\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Frame Number", "8", data1.getFrameNumber());
        data2 = new TSharkData("5,\"1.436394000\",\"UDP\",\"17\",\"192.168.68.105\",\"192.168.68.255\",,,\"889\",\"889\"");
        assertEquals("Frame Number", "5", data2.getFrameNumber());
        data3 = new TSharkData("6,\"1.536100000\",\"ARP\",,,,,,,");
        assertEquals("Frame Number", "6", data3.getFrameNumber());
        data4 = new TSharkData("9,\"1.779635000\",\"DNS\",\"17\",\"192.168.68.126\",\"71.10.216.1\",,,\"60389\",\"53\"");
        assertEquals("Frame Number", "9", data4.getFrameNumber());
    }

    @Test
    public void getFrameTime() {
        data1 = new TSharkData("\"8\",1.774700000,\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Frame Time", "1.774700000", data1.getFrameTime());
        data2 = new TSharkData("\"5\",1.436394000,\"UDP\",\"17\",\"192.168.68.105\",\"192.168.68.255\",,,\"889\",\"889\"");
        assertEquals("Frame Time", "1.436394000", data2.getFrameTime());
        data3 = new TSharkData("\"6\",1.536100000,\"ARP\",,,,,,,");
        assertEquals("Frame Time", "1.536100000", data3.getFrameTime());
        data4 = new TSharkData("\"9\",1.779635000,\"DNS\",\"17\",\"192.168.68.126\",\"71.10.216.1\",,,\"60389\",\"53\"");
        assertEquals("Frame Time", "1.779635000", data4.getFrameTime());
    }

    @Test
    public void getProtocol() {
        data1 = new TSharkData("\"8\",\"1.774700000\",TCP,\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Protocol", "TCP", data1.getProtocol());
        data2 = new TSharkData("\"5\",\"1.436394000\",UDP,\"17\",\"192.168.68.105\",\"192.168.68.255\",,,\"889\",\"889\"");
        assertEquals("Protocol", "UDP", data2.getProtocol());
        data3 = new TSharkData("\"6\",\"1.536100000\",ARP,,,,,,,");
        assertEquals("Protocol", "ARP", data3.getProtocol());
        data4 = new TSharkData("\"9\",\"1.779635000\",DNS,\"17\",\"192.168.68.126\",\"71.10.216.1\",,,\"60389\",\"53\"");
        assertEquals("Protocol", "DNS", data4.getProtocol());
    }

    @Test
    public void getProtocolID() {
        data1 = new TSharkData("\"8\",\"1.774700000\",\"TCP\",6,\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Protocol ID", "6", data1.getProtocolID());
        data2 = new TSharkData("\"5\",\"1.436394000\",\"UDP\",17,\"192.168.68.105\",\"192.168.68.255\",,,\"889\",\"889\"");
        assertEquals("Protocol ID", "17", data2.getProtocolID());
        data3 = new TSharkData("\"6\",\"1.536100000\",\"ARP\",,,,,,,");
        assertEquals("Protocol ID", "", data3.getProtocolID());
        data4 = new TSharkData("\"9\",\"1.779635000\",\"DNS\",17,\"192.168.68.126\",\"71.10.216.1\",,,\"60389\",\"53\"");
        assertEquals("Protocol ID", "17", data4.getProtocolID());
    }

    @Test
    public void getSrcIP() {
        data1 = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",192.168.68.126,\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Source IP", "192.168.68.126", data1.getSrcIP());
        data2 = new TSharkData("\"5\",\"1.436394000\",\"UDP\",\"17\",192.168.68.105,\"192.168.68.255\",,,\"889\",\"889\"");
        assertEquals("Source IP", "192.168.68.105", data2.getSrcIP());
        data3 = new TSharkData("\"6\",\"1.536100000\",\"ARP\",,,,,,,");
        assertEquals("Source IP", "", data3.getSrcIP());
        data4 = new TSharkData("\"9\",\"1.779635000\",\"DNS\",\"17\",192.168.68.126,\"71.10.216.1\",,,\"60389\",\"53\"");
        assertEquals("Source IP", "192.168.68.126", data4.getSrcIP());
    }

    @Test
    public void getSrcPort() {
        data1 = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",55358,\"443\",,");
        assertEquals("Source Port", "55358", data1.getSrcPort());
        data2 = new TSharkData("\"5\",\"1.436394000\",\"UDP\",\"17\",\"192.168.68.105\",\"192.168.68.255\",889,\"889\"");
        assertEquals("Source Port", "889", data2.getSrcPort());
        data3 = new TSharkData("\"6\",\"1.536100000\",\"ARP\",,,,,,,");
        assertEquals("Source Port", "", data3.getSrcPort());
        data4 = new TSharkData("\"9\",\"1.779635000\",\"DNS\",\"17\",\"192.168.68.126\",\"71.10.216.1\",60389,\"53\"");
        assertEquals("Source Port", "60389", data4.getSrcPort());
    }

    @Test
    public void getDstIP() {
        data1 = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",52.114.159.112,\"55358\",\"443\",,");
        assertEquals("Destination IP", "52.114.159.112", data1.getDstIP());
        data2 = new TSharkData("\"5\",\"1.436394000\",\"UDP\",\"17\",\"192.168.68.105\",192.168.68.255,,,\"889\",\"889\"");
        assertEquals("Destination IP", "192.168.68.255", data2.getDstIP());
        data3 = new TSharkData("\"6\",\"1.536100000\",\"ARP\",,,,,,,");
        assertEquals("Destination IP", "", data3.getDstIP());
        data4 = new TSharkData("\"9\",\"1.779635000\",\"DNS\",\"17\",\"192.168.68.126\",71.10.216.1,,,\"60389\",\"53\"");
        assertEquals("Destination IP", "71.10.216.1", data4.getDstIP());
    }

    @Test
    public void getDstPort() {
        data1 = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",443,,");
        assertEquals("Destination Port", "443", data1.getDstPort());
        data2 = new TSharkData("\"5\",\"1.436394000\",\"UDP\",\"17\",\"192.168.68.105\",\"192.168.68.255\",\"889\",889");
        assertEquals("Destination Port", "889", data2.getDstPort());
        data3 = new TSharkData("\"6\",\"1.536100000\",\"ARP\",,,,,,,");
        assertEquals("Destination Port", "", data3.getDstPort());
        data4 = new TSharkData("\"9\",\"1.779635000\",\"DNS\",\"17\",\"192.168.68.126\",\"71.10.216.1\",\"60389\",53");
        assertEquals("Destination Port", "53", data4.getDstPort());
    }
}