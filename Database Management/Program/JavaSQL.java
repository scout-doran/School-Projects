import java.sql.*;
import string;

public class JavaSQL {
    public static void main(String args[]) {
        try {
            Statement stmt;           
            ResultSet rs;

            // Register the JDBC driver for MySQL
            Class.forName("org.mariadb.jdbc.Driver");
            // Define URL of satabase server
            String url = "jdbc:mysql://localhost:3306";
            // Get a connection to the database
            Connection con = DriverManager.getConnection(url, "root", "coursework");
            // Get statement object
            stmt = con.createStatement();
            if(stmt.execute("DROP DATABASE IF EXISTS TTU;")){
                con.close();
            }
            if(stmt.execute("CREATE DATABASE TTU;")){
                con.close();
            }
            

            Connection c = DriverManager.getConnection(url + "/" + "TTU","root", "coursework");
            stmt = c.createStatement();
            if(stmt.execute("DROP TABLE IF EXISTS students")){
                c.close();
            }
            if(stmt.execute("CREATE TABLE students" +
                                    "(tnumber char(8) primary key," + 
                                    "firstname varchar(20) not NULL," + 
                                    "lastname varchar(20) not NULL," + 
                                    "dateofbirth date," + 
                                    "credits numeric(3,0), index(lastname)) ENGINE=INNODB;")){
                c.close();
            }
            if(stmt.execute("INSERT INTO students VALUES('00001234', 'Joe', 'Smith', '1950-08-12', 35);")){
                c.close();
            }
            rs = stmt.executeQuery("SELECT * FROM students;");
            c.close();

            // Use the methods of class ResultSet in a loop to display all of the data in
            // the database
            System.out.println("Display all results: ");
            // NOTE: DO NOT USE: \t to align columns
            // USE: JAVA format command
            while (rs.next()) {
                String lastname = rs.getString("students.lastname");
                String firstname = rs.getString("students.firstname");
                String tnumber = rs.getString("students.tnumber");
                String dateofbirth = rs.getString("students.dateofbirth");
                String credits = rs.getString("students.credits");
                System.out.println("--------------------------------------------------------------------------------------");
                System.out.printf("%-22s%-22s%-22s%-22s%-22s\n", "TNumber", "FirstName", "LastName", "DateOfBirth","Credits");
                System.out.println("--------------------------------------------------------------------------------------");
                System.out.printf("%-22d%-22d%-22d%-22d%-22d\n", tnumber, firstname, lastname, dateofbirth, credits);
                System.out.println("--------------------------------------------------------------------------------------");
            }
            c.close();
            rs.close();
            stmt.close();

        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}
