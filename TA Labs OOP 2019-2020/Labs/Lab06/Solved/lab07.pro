-injars "c:\Boshart\_Current\2120\Labs\07-Master Mind\lab07_original.jar"
-outjars "c:\Boshart\_Current\2120\Labs\07-Master Mind\lab07.jar"

-dontskipnonpubliclibraryclasses
-libraryjars 'c:\Program Files\Java\jre6\lib\rt.jar'
-ignorewarnings

# Keep - Applications. Keep all application classes that have a main method.
-keepclasseswithmembers public class * {
    public static void main(java.lang.String[]);
}

# Keep names - Native method names. Keep all native class/method names.
-keepclasseswithmembernames class * {
    native <methods>;
}
