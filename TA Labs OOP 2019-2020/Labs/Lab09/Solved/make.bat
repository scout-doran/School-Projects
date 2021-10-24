@echo off
cls

javac -cp .;queue.jar AVLTest.java
java  -ea -cp .;queue.jar AVLTest
::comp out.txt lab10.txt <no.txt