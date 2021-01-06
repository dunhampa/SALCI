//#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
    //The serial that comes through the USB 
    Serial1.begin(115200);
    //The serial com that comes through a convert
    //attached to pins 18 and 19 on Mega 
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Saying hello to serial Usb Native:
  Serial.println("Hello Serial 0 (Native), its me the Arduino");

  //Saying hello through Serial #1 which is through the converter:
  Serial1.println("Hello Serial1. From Serial Converter");

  //Half a second between hellos
  delay(500);
  

  

}
