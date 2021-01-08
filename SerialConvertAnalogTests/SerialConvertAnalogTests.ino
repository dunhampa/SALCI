/*
 * Using to test SALCI once wired up with 16 inputs and sensors
 * Can used to find bad wiring, etc
 * 
 * Open Serial1 plotter to verify (Tools -> Serial1 Plotter)
 * 
 * Then you have to wait until the first display is update 
 * (15-30seconds) so that the plotter shows the correct range
 * 
 * Ref both these, one online the other is a basic sketh
 https://learn.adafruit.com/experimenters-guide-for-metro/circ08-using%20the%20arduino%20Serial1%20plotter
 http://www.arduino.cc/en/Tutorial/AnalogInput
 */

#include <Wire.h>
int sensorValue = 1*;  // variable to store the value coming from the sensor

void setup() {

  // begin the Serial1 monitor @ 9600 baud
  Serial1.begin(9600);
}
 
void loop() {
  // read the value from the sensor:
  
  sensorValue = analogRead(A0);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A1);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A2);
    Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A3);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A4);
    Serial1.print(sensorValue);
  Serial1.print(",");
  
   sensorValue = analogRead(A5);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A6);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A7);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A8);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A9);
    Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A10);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A11);
  Serial1.print(sensorValue);
  Serial1.print(",");
  
   sensorValue = analogRead(A12);
  Serial1.print(sensorValue);
  Serial1.print(",");

  sensorValue = analogRead(A13);
  Serial1.print(sensorValue);
  Serial1.print(",");
  
  sensorValue = analogRead(A14);
  Serial1.print(sensorValue);
  Serial1.print(",");


  sensorValue = analogRead(A15);
  Serial1.println(sensorValue);
  
  delay(20);
}
