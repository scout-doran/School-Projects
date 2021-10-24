-injars "c:\Boshart\_Current\2120\Labs\13-Law of Demeter\manager_original.jar"
-outjars "c:\Boshart\_Current\2120\Labs\13-Law of Demeter\manager.jar"

-libraryjars 'c:\Program Files\Java\jre6\lib\rt.jar'
-dontskipnonpubliclibraryclasses

# Keep - Applications. Keep all application classes that have a main method.
-keepclasseswithmembers public class * {
    public static void main(java.lang.String[]);
}

# Keep names - Native method names. Keep all native class/method names.
-keepclasseswithmembernames class * {
    native <methods>;
}
