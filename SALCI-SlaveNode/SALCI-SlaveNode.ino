// MultiButtonMIDI.ino
// Driving MIDI using a Multiple Buttons
// Rob Ives 2012
// This code is released into the Public Domain.
 
#include <MIDI.h>
#include <Serial.h>

 
int keyispressed[16]; //Is the key currently pressed?
int noteisplaying[16]; //Is the Note currently playing?
unsigned char data1; //data from chip 1
unsigned char data2; //data from chip 2
short pinval[8];
boolean pinon[8];
boolean pintog[8]={1,1,1,1,1,1,1,1};
boolean lastval;
int keyval[8]={65,59,0,0,0,0,0,0};

short calibrated_val[8] = {850, 850, 850, 850, 850, 850, 850, 850};
double threshold = 0.1;

String command = "";
 
void  setup() //The Setup Loop
{

  MIDI.begin(); //initialise midi library
  delay(1000);
  Serial.begin(115200);
  
  calibrate();
}
//---------------------------------------------
void loop() //the main loop
{
  int i;
  delay(100);
  for(i=0; i<8; i++)
  
  {
  
    pinval[i]=analogRead(i);
    lastval=pinon[i];
    //Serial.print("pinoutlast:");
    ///Serial.println(pinon[i]);
    pinon[i] = pinval[i] > calibrated_val[i]  * ( 1 + threshold );
    //Serial.println("pinout now:");
    //Serial.print(pinon[i]);
    //Serial.print("Lastval:");
    //Serial.println(lastval);
    //Serial.print("On Now:");
    //Serial.println(pinon[i]);
    pintog[i]= (lastval ^ pinon[i]);
    
  }
  //delay(2000);
//}

    for(i=0; i<8; i++)
  {
 
    if (pinon[i]){
        //if(pintog[i])
        //if(1)
        {
       MIDI.sendNoteOn(keyval[i],map(pinval[i],750, 1023, 0, 127),1);
      //MIDI.sendNoteOn(i*2+60,map(pinval[i],0, 1023, 0, 127),i%2+1);
        }

      }
    else
   {
     if(pintog[i]){
       //if(1){
      MIDI.sendNoteOff(keyval[i],127,1);
     // MIDI.sendNoteOff(i*2+60,0,i%2+1);
        //MIDI.sendNoteOff(i*2+60,0,i%2+1);
      
   } 
   //MIDI.sendControlChange(7, map(pinval[i],600, 1023, 0, 127),i%2+1);
   }
  }
  
  checkSerial();  // Check if command on serial port
}  

void calibrate() {
    // request data from all slaves multiple time 
    // average values and save to calibrated_val[]
}

void checkSerial() { 
  if(Serial.peek() != '\t' ) return;  // look for control byte from processing
  
  Serial.read();  // consume '\t'

  delay(10);      // enough delay
  
  while(Serial.available() > 0) {
    char inChar = Serial.read();  
  
    if(inChar == '\n') break;    
      
    if(inChar != '\r') command += inChar;
  
    delay(1);
  }
  
  Serial.flush();  // Got command, empty rest of buffer
 
   if(command == "start cmd+data") {
      digitalWrite(11, HIGH);
       
       //Parse config data!
       
       delay(4000);
       digitalWrite(11, LOW);
       
     } else if(command == "CALIBRATE") {
       
       digitalWrite(CALIBRATE_PIN, HIGH);
       
       calibrate(); // Calibrate here!
       
       delay(4000);
       digitalWrite(CALIBRATE_PIN, LOW);
     }
     command = "";
}


