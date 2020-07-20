#include <EEPROM.h>

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


   
};


SalciConfig* customVar;

void setup(){

  
  int eeAddress = 0; //EEPROM address to start reading from

  Serial.begin( 9600 );
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  //Serial.print( "Read float from EEPROM: " );

  //Get the float data from the EEPROM at position 'eeAddress'
  //EEPROM.get( eeAddress, f );
  //Serial.println( f, 3 );  //This may print 'ovf, nan' if the data inside the EEPROM is not a valid float.

  // get() can be used with custom structures too.
  //eeAddress = sizeof(float); //Move address to the next byte after float 'f'.
  //SalciConfig customVar; //Variable to store custom object read from EEPROM.
  customVar=(SalciConfig *)malloc(sizeof(SalciConfig));
  EEPROM.get( 0, customVar );

  Serial.println( "------------------------------" );
  Serial.println( "Read SALCI Config From EEPROM" );
  Serial.println( "------------------------------" );
  Serial.print("Configuration Name: ");
  Serial.println( customVar->myname);

  Serial.print("Toggle MIDI (1=On, 0=Off): ");
  Serial.println( customVar->toggle );
  Serial.println( customVar->anIns[1] );
}

void loop(){ /* Empty loop */ }
