-injars "C:\_Current\2120\Labs\06-Tree Sort\bst_original.jar"
-outjars "C:\_Current\2120\Labs\06-Tree Sort\bst.jar"

-libraryjars 'C:\Program Files\Java\jre6\lib\rt.jar'
-libraryjars 'C:\_Current\2120\Labs\06-Tree Sort\ki.jar'
-dontskipnonpubliclibraryclasses
-ignorewarnings

# Keep - Applications. Keep all application classes that have a main method.
-keepclasseswithmembers public class * {
    public static void main(java.lang.String[]);
}

# Keep names - Native method names. Keep all native class/method names.
-keepclasseswithmembernames class * {
    native <methods>;
}

-keepnames class bst.BinarySearchTree
-keepclassmembernames class bst.BinarySearchTree
-keepnames class bst.TreeIterator
-keepclassmembernames class bst.TreeIterator
-keepnames class bst.TreeException