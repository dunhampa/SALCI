
//sender test

#include <Wire.h>


#include <Wire.h>
#define NUMDATA 4 

byte byteData[2 * NUMDATA]; //= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//test

void setup()
{
  Wire.begin(3);                // join i2c bus with address #3
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
{
  Wire.write(byteData, 2 * NUMDATA);
}
