/*
 * Using to test SALCI once wired up with 16 inputs and sensors
 * Can used to find bad wiring, etc
 * 
 * Open serial plotter to verify (Tools -> Serial Plotter)
 * 
 * Then you have to wait until the first display is update 
 * (15-30seconds) so that the plotter shows the correct range
 * 
 * Ref both these, one online the other is a basic sketh
 https://learn.adafruit.com/experimenters-guide-for-metro/circ08-using%20the%20arduino%20serial%20plotter
 http://www.arduino.cc/en/Tutorial/AnalogInput
 */

#include <Wire.h>
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

  // begin the serial monitor @ 9600 baud
  Serial.begin(9600);
}
 
void loop() {
  // read the value from the sensor:
  
  sensorValue = analogRead(A0);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A1);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A2);
    Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A3);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A4);
    Serial.print(sensorValue);
  Serial.print(",");
  
   sensorValue = analogRead(A5);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A6);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A7);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A8);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A9);
    Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A10);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A11);
  Serial.print(sensorValue);
  Serial.print(",");
  
   sensorValue = analogRead(A12);
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A13);
  Serial.print(sensorValue);
  Serial.print(",");
  
  sensorValue = analogRead(A14);
  Serial.print(sensorValue);
  Serial.print(",");


  sensorValue = analogRead(A15);
  Serial.println(sensorValue);
  
  delay(20);
}
