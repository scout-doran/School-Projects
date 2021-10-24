### Practice Problem: Airport Data
The data directory contains a file with information about airports around the world. The codex/meta-data for the data is as follows:

* index
* name
* city
* country
* IATA code
* ICAO code
* latitude
* longitude
* elevation
* gmt
* ?
* timezone
* airport
* OurAirports

Most of the fields are strings except for the index, latitude, longitude, elevation, and the code following elevation (which is unknown).

Things to try (write code == write test + write code):

* Write the code to read the data line by line in a main method. Suggestion: write a class called "AirportApp" with the main method contained in it.
    * ``public static void main(String args[])``
    * Use the ``File`` class to read data from a file contained in the data directory.
* Create the following classes
    * An ``Airport`` class that contains the fields for storing the data listed above
    * An ``AirportDB`` class that stores the full list of airports.
* Write the methods needed to parse the airport data into ``Airport`` objects and the ``AirportDB``
* Write methods in the ``AirportDB`` for finding specific airports and returning things like the latitude and longitude, or the full data for the airport.
* Write a command-line program for searching for airport information. 