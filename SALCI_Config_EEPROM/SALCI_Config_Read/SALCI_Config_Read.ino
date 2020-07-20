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

void setup(){

  float f = 0.00f;   //Variable to store data read from EEPROM.
  int eeAddress = 0; //EEPROM address to start reading from

  Serial.begin( 9600 );
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print( "Read float from EEPROM: " );

  //Get the float data from the EEPROM at position 'eeAddress'
  EEPROM.get( eeAddress, f );
  Serial.println( f, 3 );  //This may print 'ovf, nan' if the data inside the EEPROM is not a valid float.

  // get() can be used with custom structures too.
  eeAddress = sizeof(float); //Move address to the next byte after float 'f'.
  SalciConfig customVar; //Variable to store custom object read from EEPROM.
  EEPROM.get( eeAddress, customVar );

  Serial.println("----------------------------");
  Serial.println("Reading SALCI Config");
  Serial.println("----------------------------");
  
  Serial.print("Config Name: ");
  Serial.println(customVar.configName);

  Serial.print("Midi Channel: ");
  Serial.println(customVar.midiChannel);

  Serial.print("Toggle Setting ON=1 OFF=0: ");
  Serial.println(customVar.toggle_on);

  Serial.print("Toggle Delay (in millsecs): ");
  Serial.println(customVar.toggle_delay);

  Serial.print("Threshold (DAC Counts): ");
  Serial.println(customVar.threshold);

  Serial.print("Will Threshold activativate on increases 1=YES: ");
  Serial.println(customVar.threshold_above);

  Serial.print("Will Threshold activativate on decreases 1=YES: ");
  Serial.println(customVar.threshold_below);

  Serial.print("A0: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[0]);
  Serial.print("A1: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[1]);
  Serial.print("A2: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[2]);
  Serial.print("A3: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[3]);
  Serial.print("A4: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[4]);
  Serial.print("A5: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[5]);
  Serial.print("A6: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[6]);
  Serial.print("A7: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[7]);
  Serial.print("A8: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[8]);
  Serial.print("A9: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[9]);
  Serial.print("A10: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[10]);
  Serial.print("A11: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[11]);
  Serial.print("A12: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[12]);
  Serial.print("A13: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[13]);
  Serial.print("A14: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[14]);
  Serial.print("A15: Analog In Active: ");
  Serial.println(customVar.analog_ins_active[15]);

  Serial.print("For A0 Midi Key Value: ");
  Serial.println(customVar.midi_keys[0]);
  Serial.print("For A1 Midi Key Value: ");
  Serial.println(customVar.midi_keys[1]);
  Serial.print("For A2 Midi Key Value: ");
  Serial.println(customVar.midi_keys[2]);
  Serial.print("For A3 Midi Key Value: ");
  Serial.println(customVar.midi_keys[3]);
  Serial.print("For A4 Midi Key Value: ");
  Serial.println(customVar.midi_keys[4]);
  Serial.print("For A5 Midi Key Value: ");
  Serial.println(customVar.midi_keys[5]);
  Serial.print("For A6 Midi Key Value: ");
  Serial.println(customVar.midi_keys[6]);
  Serial.print("For A7 Midi Key Value: ");
  Serial.println(customVar.midi_keys[7]);
  Serial.print("For A8 Midi Key Value: ");
  Serial.println(customVar.midi_keys[8]);
  Serial.print("For A9 Midi Key Value: ");
  Serial.println(customVar.midi_keys[9]);
  Serial.print("For A10 Midi Key Value: ");
  Serial.println(customVar.midi_keys[10]);
  Serial.print("For A11 Midi Key Value: ");
  Serial.println(customVar.midi_keys[11]);
  Serial.print("For A12 Midi Key Value: ");
  Serial.println(customVar.midi_keys[12]);
  Serial.print("For A13 Midi Key Value: ");
  Serial.println(customVar.midi_keys[13]);
  Serial.print("For A14 Midi Key Value: ");
  Serial.println(customVar.midi_keys[14]);
  Serial.print("For A15 Midi Key Value: ");
  Serial.println(customVar.midi_keys[15]);


  
  Serial.println( customVar.field1 );
  Serial.println( customVar.field2 );
  Serial.println( customVar.name );
  Serial.println( customVar.vals[0] );
  Serial.println( customVar.vals[1] );
}

void loop(){ /* Empty loop */ }
 
