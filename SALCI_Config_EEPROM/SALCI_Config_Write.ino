#include <EEPROM.h>

struct MyObject {
  float field1;
  byte field2;
  char name[10];
};

//Define for each analog in available on your arduino model, we'll specify if used for Midi later
//This is 16 for Arduino Mega 3560
#define arraySize 16

struct SalciConfig {
    
    //Help
    char myname[10];
    
    
    //Midi Channel
   int channel;

    //Should a midi key be toggled off, if stuck on
    bool toggle;
    
    //Ms to Delay in Toggle (if toggle is true)
    int toggle_delay;
    
    //by analog input counts
    double sensitivity;
    
    //if this analog in being used as a MIDI sensor?
    bool anIns[arraySize];

    //Midi key for each sensor used
     int keyval[arraySize];

    //Not EEPROM
    //int data[arraySize];

    //Not EEPROM
    //int ambient[arraySize];

    //NOT EEPROM
    //bool lastval[arraySize];

    //NOT EEPROM
    //bool pintog[arraySize];
   
};

SalciConfig* thisConfig;

  MyObject customVar = {
    3.14f,
    65,
    "Working!"
  };


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  //float f = 123.456f;  //Variable to store in EEPROM.
  int eeAddress = 0;   //Location we want the data to be put.


  //One simple call, with the address first and the object second.
  //EEPROM.put(eeAddress, f);

  Serial.println("Written float data type!");

  /** Put is designed for use with custom structures also. **/

  //Getting config setup
  //allocating memory
  thisConfig=(SalciConfig *)malloc(sizeof(SalciConfig));
   
  //Setting channels
  memcpy(thisConfig->myname,"Holler   ",10*sizeof(char));
  thisConfig->channel=1;
  //Do we want toggling behavior
  thisConfig->toggle=0;  
   
   //currently not in use:
  thisConfig->toggle_delay=100;
  thisConfig->sensitivity=150;

  //turn off inputs you aren't using so that they won't float and cause problems
  boolean thisAnIns[arraySize]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  memcpy(thisConfig->anIns,thisAnIns,arraySize*sizeof(bool));

  int keyval[12]={65,59,57,69,67,60,62,64,71,72,74,76};
  memcpy(thisConfig->keyval,keyval,arraySize*sizeof(int));
  
  //eeAddress += sizeof(float); //Move address to the next byte after float 'f'.

  EEPROM.put(eeAddress, thisConfig);
  Serial.print("Written custom data type! \n\nView the example sketch eeprom_get to see how you can retrieve the values!");
  Serial.print(thisConfig->toggle);
  Serial.print(thisConfig->myname);
}

void loop() {   /* Empty loop */ }
