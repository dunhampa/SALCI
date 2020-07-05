#include <Wire.h>

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start Serial for output
}

void loop()
{


  getSenderData();
  
  Serial.println("Hello");
  delay(500);
}

void getSenderData() {
//Gets sensor data for one grid

    //Byte Array to get raw bytes
    byte ICdataAsBytes[8];
    int i = 0;
  
    Wire.requestFrom(3,8);    // request 6 bytes from slave device #2
    
    while(Wire.available())    // slave may send less than requested
        ICdataAsBytes[i++] = Wire.read();

    int *tempData =(int*)&ICdataAsBytes;
    
    for( i = 0; i < 4; i++)
        Serial.println(tempData[i]);
    
}
