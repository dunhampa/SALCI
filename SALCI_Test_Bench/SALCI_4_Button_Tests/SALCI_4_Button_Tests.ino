
/*
 * This script is used to test 4 external buttons in SALCI setups
 * The buttons are pulled up to 5V (using 10k resistor) 
 * So here it should return 0 if button is working
 * 
 * Used:https://create.arduino.cc/projecthub/muhammad-aqib/arduino-button-tutorial-using-arduino-digitalread-function-08adb5
 * For inspiration
 */


void setup() {
  
  Serial.begin(9600);

  // initialize the pushbutton pin as an input:
  // the numbers are specific to the inputs plugged in
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
}
void loop() {
  // read the state of the pushbutton value:
  int buttonOne= digitalRead(2);
  int buttonTwo= digitalRead(3);
  int buttonThree= digitalRead(4);
  int buttonFour= digitalRead(5);

  Serial.print(buttonOne);
  Serial.print(",");
  Serial.print(buttonTwo);
  Serial.print(",");
  Serial.print(buttonThree);
  Serial.print(",");
  Serial.println(buttonFour);

  
  // Show the state of pushbutton on serial monitor
  //Serial.println(buttonOne);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  // Added the delay so that we can see the output of button
  delay(2000);
}
