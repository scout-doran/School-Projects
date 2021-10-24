-injars "C:\Boshart\_Current\2120\Labs\11-Triangle Peg Solitaire\lab11_original.jar"
-outjars "C:\Boshart\_Current\2120\Labs\11-Triangle Peg Solitaire\lab11.jar"

-dontskipnonpubliclibraryclasses
-libraryjars 'C:\Program Files\Java\jre6\lib\rt.jar'
-ignorewarnings

# Keep - Applications. Keep all application classes that have a main method.
-keepclasseswithmembers public class * {
    public static void main(java.lang.String[]);
}

# Keep names - Native method names. Keep all native class/method names.
-keepclasseswithmembernames class * {
    native <methods>;
}
