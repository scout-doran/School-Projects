@echo off
del *.class
javac LabManager.java
jar cf manager.jar LabManager.class LabManagerView.class LabManagerView$1.class LabManagerView$LabManagerListener.class EasyGridBag.class FixFrame$1.class FixFrame$FixRepaint.class FixFrame.class
..\..\..\jexepack.exe @jexepack.ini