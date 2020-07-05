/*
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
  Serial.println(sensorValue);
  
  delay(20);
}
