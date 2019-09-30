// SALCI Master Code 
// Sensor Array Light Controlled Instrument

//created by Peter Dunham, Cameron Dashti, and Brian Rupert 


//#include </Users/peterdunham/Documents/Arduino/libraries/MIDI/MIDI.h>
#include "MIDI.h"
#include "panel.h"
#include <string.h>

//array of booleans type to load into each panel if note should be toggled
//boolean pintog[12]={1,1,1,1,1,1,1,1,1,1,1,1};
boolean pintog[12]={0,0,0,0,0,0,0,0,0,0,0,0};

//array of boolean type to key track of last value
boolean lastval[12]={1,1,1,1,1,1,1,1,1,1,1,1};

//array of midi notes for each panel - expecting 3
int keyval[12]={65,59,57,69,67,60,62,64,65,59,57,69};

//had some bad ones //bottom with usb and charger side
int anInsBottom[12]={0,1,2,3,4,5,6,7,8,9,10,12};
//middle is good
int anInsMiddle[12]={0,1,2,3,4,5,6,7,8,9,10,11};
int anInsTop[12]={0,1,2,3,4,6,7,8,9,10,11,12};
 
PANEL* Panel1;

 
void  setup() //The Setup Loop
{
    
    MIDI.begin(); //initialise midi library
    delay(5000);
    Serial.begin(115200);
    delay(500);
    //Wire.begin();
    delay(500);

     
    Panel1=(PANEL *)malloc(sizeof(PANEL));
    Panel1->addr=1;
    Panel1->channel=1;
    Panel1->toggle =1;

    //Setting Keyvalues
    memcpy(Panel1->keyval,keyval,12*sizeof(int));
    memcpy(Panel1->pintog,pintog,12*sizeof(boolean));
    memcpy(Panel1->lastval,lastval,12*sizeof(boolean));
    memcpy(Panel1->anIns,anInsBottom,12*sizeof(int));
    
    calibrateSelf(Panel1);
    delay(500);
    
}
//---------------------------------------------
void loop() //the main loop
{
    //Structs to hold all options for panel
  
    //getPanelData(Panel1);
    //calibrateSelf(Panel1);
    getSelfData(Panel1);
    generateMidi(Panel1);
    
    

    
    delay(200);
    

}







void generateMidi (PANEL* singlePanel){
//Turns MIDI Notes on and off accordingly 

   int i;
   
   for(i=0; i<12; i++)
    {
      
      //Setting up toggle option:
      if(singlePanel->toggle)
      {
        //only actively set pintog if toggle option is false
        singlePanel->pintog[i]= (singlePanel->lastval[i] ^ (singlePanel->data[i]>singlePanel->ambient[i]+55));
      }//75 was good
      else
      {
        //set pintog to true, so it will be continually sending data
        singlePanel->pintog[i]=1;
       }
        
       
       if (singlePanel->data[i]>singlePanel->ambient[i]+55)
       {
            singlePanel->lastval[i]=1;
            if(singlePanel->pintog[i])
            {
              MIDI.sendNoteOn(singlePanel->keyval[i],map(singlePanel->data[i],750, 1023, 65, 127),singlePanel->channel);  
            }
        }
        else
        {
           singlePanel->lastval[i]=0;  
           if (singlePanel->pintog[i])
           {
                MIDI.sendNoteOff(singlePanel->keyval[i],127,singlePanel->channel);  
            }
            //MIDI.sendControlChange(7, map(pinval[i],600, 1023, 0, 127),i%2+1);
        }
    }
    Serial.flush();//note sure why
}



void getSelfData(PANEL* singlePanel)
{
  int i;
  for( i = 0; i < 12; i++)
  {
        singlePanel->data[i] = analogRead(singlePanel->anIns[i]);
  }
}
void calibrateSelf(PANEL* p) {
   
    int i = 0;
  
    for(i=0; i< 12; i++){
      p->ambient[i] = analogRead(p->anIns[i]);   
      Serial.print("Value for");
      //String mystring = String(i, DEC);
      Serial.print(p->anIns[i]);
      Serial.print(": ");
      Serial.println(analogRead(p->anIns[i]));
      Serial.flush();
    }
      
}
