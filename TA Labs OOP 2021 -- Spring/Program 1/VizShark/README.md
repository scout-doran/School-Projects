(starting code)
### Dependencies
Add the following to the CLASSPATH ($LIB is local library directory location)
* Link to [GraphStream](https://graphstream-project.org/download/) for download
    * $LIB/gs-core-2.0.jar
    * $LIB/gs-algo-2.0.jar
    * $LIB/gs-ui-javafx-2.0.jar
* Link to [javafx SDK](https://gluonhq.com/products/javafx/) for download
    * $LIB/javafx-sdk-11.0.2/lib/javafx-swt.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.base.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.controls.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.fxml.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.graphics.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.media.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.swing.jar
    * $LIB/javafx-sdk-11.0.2/lib/javafx.web.jar

Set CLASSPATH in Linux or MacOS
```bash
export CLASSPATH=$LIB/gs-core-2.0.jar:$LIB/gs-ui-javafx-2.0.jar:$LIB/javafx-sdk-11.0.2/lib/javafx-swt.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.base.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.controls.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.fxml.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.graphics.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.media.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.swing.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.web.jar
```
    
### Files
```data``` directory contains sample data for project

```style.css``` stylesheet for the graphs

```src``` sources for the project

### Build
Compile in Linux or MacOS, generating output in ```out``` directory.
```bash
javac -cp $CLASSPATH -d out src/*.java
```
Note: last built with Java 11

### Run
The system must be run in two stages:
1. Start the VizSharkClient application
2. Start the GeneratorServer application