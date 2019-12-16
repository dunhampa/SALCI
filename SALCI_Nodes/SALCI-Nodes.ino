//SALCI Non-Master nodes that send data to Main Controller
//Update teh Wire begin address manually for each 
//additional node. For example, Wire.begin(2) then 
//Wire.begin(3) etc

#include <Wire.h>
#define NUMDATA 12 

byte byteData[2 * NUMDATA]; //= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//test

void setup()
{
  //Serial.begin(115200);
  Wire.begin(3);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
int aData;  
  for(int i = 0; i < NUMDATA; i++){
    aData = analogRead(i);
    
    byteData[i*2 + 1] = ((aData >> 8)  & 0xFF);
    byteData[i*2] = (aData & 0xFF);
    
   // memcpy((void *)byteData[i*2], (void *) analogRead(i), sizeof(int));
  }
  
}

void requestEvent()
{/*
  int aData;  
  for(int i = 0; i < NUMDATA; i++){
    aData = analogRead(i);
    
    byteData[i*2 + 1] = ((aData >> 8)  & 0xFF);
    byteData[i*2] = (aData & 0xFF);
  }
  */
 
  Wire.write(byteData, 2 * NUMDATA);
}
