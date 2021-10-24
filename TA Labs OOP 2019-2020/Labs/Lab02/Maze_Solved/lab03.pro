-injars "c:\Boshart\_Current\2120\2121\03-Maze Recursion\lab03_original.jar"
-outjars "c:\Boshart\_Current\2120\2121\03-Maze Recursion\lab03.jar"

-libraryjars 'C:\Program Files\Java\jre7\lib\rt.jar'
-ignorewarnings

# Keep - Applications. Keep all application classes that have a main method.
-keepclasseswithmembers public class * {
    public static void main(java.lang.String[]);
}

# Keep names - Native method names. Keep all native class/method names.
-keepclasseswithmembernames class * {
    native <methods>;
}
