
#include <EEPROM.h>
struct SalciConfig {
  char configName[30];
  int  midiChannel;
  bool toggle_on;
  int toggle_delay;
  int threshold;
  bool threshold_above;
  bool threshold_below; 
  bool analog_ins_active[16];
  int midi_keys[16];
  float field1;
  int field2;
  char name[10];
  int vals[2];
};


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  float f = 123.456f;  //Variable to store in EEPROM.
  int eeAddress = 0;   //Location we want the data to be put.


  //One simple call, with the address first and the object second.
  EEPROM.put(eeAddress, f);

  Serial.println("Written float data type!");

  /** Put is designed for use with custom structures also. **/

  //Data to store.
  SalciConfig customVar = {
    "This is the First Config",
    //midiChannel:
    13,
    //toggle on:
    0,
    //toggle delay (in ms)
    250,
    //threshold:
    150,
    //threshold_above:
    1,
    //threshold_below:
    0,
    //analogs in are active:
    {1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
    //midi key values
    {65,59,57,69,67,60,62,64,71,72,74,76,99,99,99,99},
    //next is a float:
    3.14f,
    550L,
    "Working!",
    {330, 125}
  };

  eeAddress += sizeof(float); //Move address to the next byte after float 'f'.

  EEPROM.put(eeAddress, customVar);
  Serial.print("Written custom data type! \n\nView the example sketch eeprom_get to see how you can retrieve the values!");
}

void loop() {   /* Empty loop */ }
