@echo off
cls

set THE_PATH=%1:
set path=%THE_PATH%\Java\bin;c:\Windows
set classpath=%THE_PATH%\Java\;.

::javac -cp %classpath% MasterMind.java
java -cp %classpath% MasterMind 0
