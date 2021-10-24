#!/bin/bash
 
echo What is your Tech username?
read username
 
git clone https://gitlab.csc.tntech.edu/csc2310-sp21-students/${username}/${username}-lab-midterm.git
 
mkdir ${username}-lab-midterm/lib && cd ${username}-lab-midterm/lib
 
wget https://github.com/graphstream/gs-core/releases/download/2.0/gs-core-2.0.jar
wget https://github.com/graphstream/gs-algo/releases/download/2.0/gs-algo-2.0.jar
wget https://github.com/graphstream/gs-ui-javafx/releases/download/2.0/gs-ui-javafx-2.0.jar
wget https://download2.gluonhq.com/openjfx/11.0.2/openjfx-11.0.2_linux-x64_bin-sdk.zip
unzip openjfx-11.0.2_linux-x64_bin-sdk.zip && rm openjfx-11.0.2_linux-x64_bin-sdk.zip
 
LIB=/home/vagrant/Desktop/${username}-lab-midterm/lib
 
echo export $LIB >> ~/.profile
 
echo export CLASSPATH=$LIB/gs-core-2.0.jar:$LIB/gs-algo-2.0.jar:$LIB/gs-ui-javafx-2.0.jar:$LIB/javafx-sdk-11.0.2/lib/javafx-swt.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.base.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.controls.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.fxml.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.graphics.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.media.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.swing.jar:$LIB/javafx-sdk-11.0.2/lib/javafx.web.jar >> ~/.profile
 
