// SALCI Standalone
// SALCI: Sensor Array Light Controlled Instrument

//created by Peter Dunham

// Referenced:
// MultiButtonMIDI.ino
// Driving MIDI using a Multiple Buttons
// Rob Ives 2012
// This code is released into the Public Domain.

#include "MIDI.h"
#include "panel.h"
#include <string.h>



//boolean pintog[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
boolean pintog[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
boolean lastval[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int keyval[16]={65,59,57,69,67,60,62,64,71,72,74,76,45,47,48,50};
//int keyval1[12]={24,26,28,29,31,33,35,36,38,40,41,43};
//int keyval2[12]={45,47,48,50,52,53,55,57,59,60,62,64};

PANEL* Panel1;
 
void  setup() //The Setup Loop
{
    
  
    MIDI.begin(); //initialise midi library
    delay(1000); 
    Serial.begin(115200);
    delay(500);

  
    Panel1=(PANEL *)malloc(sizeof(PANEL));
    
    //Setting channel
    Panel1->channel=1;

    //Setting Toggles
    Panel1->toggle =1; //if 1 then midi sounds will be toggle off after a time period

    
    memcpy(Panel1->keyval,keyval,16*sizeof(int)); //Setting Keyvalues
    memcpy(Panel1->pintog,pintog,16*sizeof(boolean)); //Is senor midi note currently firing? Defaulting to yes, so default behavior is to turn off
    memcpy(Panel1->lastval,lastval,16*sizeof(boolean)); //Last value - last command to say if midi note firing

    //memcpy(Panel1->anIns,anInsTop,arraySize*sizeof(int));
    //memcpy(Panel2->anIns,anInsMiddle,arraySize*sizeof(int));
    //memcpy(Panel3->anIns,anInsBottom,arraySize*sizeof(int));
      
    calibrateSelf(Panel1);
    

}
//---------------------------------------------
void loop() //the main loop
{
    //Structs to hold all options for panel
  
    getSelfData(Panel1);
    generateMidi(Panel1,150);
    
   
    delay(50);
    

}


  



void generateMidi (PANEL* singlePanel, int changeTrigger){
//Turns MIDI Notes on and off accordingly 

   int i;
   
   for(i=0; i<16; i++)
    {
      
      //Setting up toggle option:
      if(singlePanel->toggle)
      {
        //only actively set pintog if toggle option is false
        singlePanel->pintog[i]= (singlePanel->lastval[i] ^ (singlePanel->data[i]>singlePanel->ambient[i]+changeTrigger));
      }//75 was good
      else
      {
        //set pintog to true, so it will be continually sending data
        singlePanel->pintog[i]=1;
       }
        
       
       if (singlePanel->data[i]>singlePanel->ambient[i]+changeTrigger)
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
           
        }
    }
    Serial.flush();//note sure why
}

void getSelfData(PANEL* singlePanel)
{
  int i;
  for( i = 0; i < 16; i++)
  {
        singlePanel->data[i] = analogRead(i);
  }
}
void calibrateSelf(PANEL* p) {
   
    int i = 0;
 
    
    for(i=0; i< 16; i++)
      p->ambient[i] = analogRead(i);   
}
