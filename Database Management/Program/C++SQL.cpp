#include <stdlib.h>
#include <iostream>
#include <mysql.h>
#include <stdio.h>
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "coursework"
#define DATABASE "TTU"

int main(){
    MYSQL *connect = mysql_init(NULL);

    if(!connect){
        std::cout << "MySQL Intialization failed";
        return 1;
    } 
    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
    if(connect){
        std::cout << "connection Succeeded" << std::endl;
    }
    else{
        std::cout << "connection failed" << std::endl;
        mysql_close(connect);
        exit(1);
    }

    //MODIFY THE CODE TO INSERT 4 MORE ROWS AND PRINT THEM
    //       NOTE: DO NOT USE \t to align columns
    if(mysql_query(connect, "INSERT INTO students(tnumber,firstname,lastname,dateofbirth,credits) VALUES('00003256', 'John', 'Doe', '1970-07-15', 119);")){
        mysql_close(connect);
        exit(1);
    }
    if(mysql_query(connect, "INSERT INTO students(tnumber,firstname,lastname,dateofbirth,credits) VALUES('00001423', 'Mary', 'Smith', '1992-01-01', 15);")){
        mysql_close(connect);
        exit(1);
    }
    if(mysql_query(connect, "INSERT INTO students(tnumber,firstname,lastname,dateofbirth,credits) VALUES('00015366', 'William', 'Williamson', '1991-05-23', 60);"))(
        mysql_close(connect);
        exit(1);
    )
    if(mysql_query(connect, "INSERT INTO students(tnumber,firstname,lastname,dateofbirth,credits) VALUES('00012345', 'Katie', 'Did', '1992-09-27', 45);")){
        mysql_close(connect);
        exit(1);
    }
    if(mysql_query(connect, "SELECT * FROM students;")){
        mysql_close(connect);
        exit(1);
    }
    
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    unsigned int i = 0;
    res_set = mysql_store_result(connect);
    unsigned int numrows = mysql_num_rows(res_set);
    cout << "-----------------------------------------------------------" << endl;
    cout << left << "TNumber   FirstName   LastName   DateOfBirth   Credits" << endl;
    cout << "-----------------------------------------------------------" << endl;
    while((row = mysql_fetch_row(*res_set)) != NULL){
        std::cout << row[i] << std::endl;
        i++;
    }
    cout << "-----------------------------------------------------------" << endl;
    mysql_close(connect);

    return 0;
}