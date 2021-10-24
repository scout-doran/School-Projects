import java.lang.*;
import org.junit.*;
import org.jsoup.Jsoup;
import org.jsoup.helper.Validate;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;

public class JsoupDemo {
    @Test
    public static void main(String args[]) throws IOException {
        String url = "https://ttuss1.tntech.edu/PROD/bwckctlg.p_display_courses?term_in=202180&one_subj=CSC&sel_crse_strt=1300&sel_crse_end=1300&sel_subj=&sel_levl=&sel_schd=&sel_coll=&sel_divs=&sel_dept=&sel_attr=";
        // fetch the document over HTTP
        Document doc = Jsoup.connect(url).get();
        //doc.outputSettings(new Document.OutputSettings().prettyPrint(false));//makes html() preserve linebreaks and spacing
        //doc.select("br").append("\n");

        String titleStr = doc.getElementsByClass("nttitle").text();
        String bodyStr = doc.getElementsByClass("ntdefault").text();

        System.out.println(titleStr);
        //TO DO: replace all <br> tags with \n
        System.out.println(bodyStr);
    }

    public JsoupDemo(IOException e) throws IOException {
        e.printStackTrace();
    }
}
