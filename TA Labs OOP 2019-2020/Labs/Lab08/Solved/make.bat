@echo off
cls

javac -cp .;queue.jar *.java
java -ea -cp .;queue.jar BSTTest >out.txt
comp out.txt lab9.txt <no.txt
