@echo off
cls

set PATH="c:\Program Files\Java\jdk1.7.0_06\bin"
set CLASSPATH="c:\Program Files\Java\jre7";.;matrix.jar

javac -cp %CLASSPATH% Equations.java
java -cp %CLASSPATH% Equations